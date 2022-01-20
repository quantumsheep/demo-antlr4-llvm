cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(compiler)

find_package(LLVM 12 REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

include(ExternalProject)

set(ANTLR4_ROOT ${CMAKE_CURRENT_BINARY_DIR}/antlr4_runtime/src/antlr4_runtime)
set(ANTLR4_INCLUDE_DIRS ${ANTLR4_ROOT}/runtime/Cpp/runtime/src)
set(ANTLR4_GIT_REPOSITORY https://github.com/antlr/antlr4.git)

if(NOT DEFINED ANTLR4_TAG)
  # Set to branch name to keep library updated at the cost of needing to rebuild after 'clean'
  # Set to commit hash to keep the build stable and does not need to rebuild after 'clean'
  set(ANTLR4_TAG 4.9.3)
endif()

if(${CMAKE_GENERATOR} MATCHES "Visual Studio.*")
  set(ANTLR4_OUTPUT_DIR ${ANTLR4_ROOT}/runtime/Cpp/dist/$(Configuration))
elseif(${CMAKE_GENERATOR} MATCHES "Xcode.*")
  set(ANTLR4_OUTPUT_DIR ${ANTLR4_ROOT}/runtime/Cpp/dist/$(CONFIGURATION))
else()
  set(ANTLR4_OUTPUT_DIR ${ANTLR4_ROOT}/runtime/Cpp/dist)
endif()

if(MSVC)
  set(ANTLR4_STATIC_LIBRARIES
      ${ANTLR4_OUTPUT_DIR}/antlr4-runtime-static.lib)
  set(ANTLR4_SHARED_LIBRARIES
      ${ANTLR4_OUTPUT_DIR}/antlr4-runtime.lib)
  set(ANTLR4_RUNTIME_LIBRARIES
      ${ANTLR4_OUTPUT_DIR}/antlr4-runtime.dll)
else()
  set(ANTLR4_STATIC_LIBRARIES
      ${ANTLR4_OUTPUT_DIR}/libantlr4-runtime.a)
  if(MINGW)
    set(ANTLR4_SHARED_LIBRARIES
        ${ANTLR4_OUTPUT_DIR}/libantlr4-runtime.dll.a)
    set(ANTLR4_RUNTIME_LIBRARIES
        ${ANTLR4_OUTPUT_DIR}/libantlr4-runtime.dll)
  elseif(CYGWIN)
    set(ANTLR4_SHARED_LIBRARIES
        ${ANTLR4_OUTPUT_DIR}/libantlr4-runtime.dll.a)
    set(ANTLR4_RUNTIME_LIBRARIES
        ${ANTLR4_OUTPUT_DIR}/cygantlr4-runtime-4.9.2.dll)
  elseif(APPLE)
    set(ANTLR4_RUNTIME_LIBRARIES
        ${ANTLR4_OUTPUT_DIR}/libantlr4-runtime.dylib)
  else()
    set(ANTLR4_RUNTIME_LIBRARIES
        ${ANTLR4_OUTPUT_DIR}/libantlr4-runtime.so)
  endif()
endif()


if(${CMAKE_GENERATOR} MATCHES ".* Makefiles")
  # This avoids
  # 'warning: jobserver unavailable: using -j1. Add '+' to parent make rule.'
  set(ANTLR4_BUILD_COMMAND $(MAKE))
elseif(${CMAKE_GENERATOR} MATCHES "Visual Studio.*")
  set(ANTLR4_BUILD_COMMAND
      ${CMAKE_COMMAND}
          --build .
          --config $(Configuration)
          --target)
elseif(${CMAKE_GENERATOR} MATCHES "Xcode.*")
  set(ANTLR4_BUILD_COMMAND
      ${CMAKE_COMMAND}
          --build .
          --config $(CONFIGURATION)
          --target)
else()
  set(ANTLR4_BUILD_COMMAND
      ${CMAKE_COMMAND}
          --build .
          --target)
endif()

if(NOT DEFINED ANTLR4_WITH_STATIC_CRT)
  set(ANTLR4_WITH_STATIC_CRT ON)
endif()

if(ANTLR4_ZIP_REPOSITORY)
  ExternalProject_Add(
      antlr4_runtime
      PREFIX antlr4_runtime
      URL ${ANTLR4_ZIP_REPOSITORY}
      DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}
      BUILD_COMMAND ""
      BUILD_IN_SOURCE 1
      SOURCE_DIR ${ANTLR4_ROOT}
      SOURCE_SUBDIR runtime/Cpp
      CMAKE_CACHE_ARGS
          -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
          -DWITH_STATIC_CRT:BOOL=${ANTLR4_WITH_STATIC_CRT}
          # -DCMAKE_CXX_STANDARD:STRING=17 # if desired, compile the runtime with a different C++ standard
          # -DCMAKE_CXX_STANDARD:STRING=${CMAKE_CXX_STANDARD} # alternatively, compile the runtime with the same C++ standard as the outer project
      INSTALL_COMMAND ""
      EXCLUDE_FROM_ALL 1)
else()
  ExternalProject_Add(
      antlr4_runtime
      PREFIX antlr4_runtime
      GIT_REPOSITORY ${ANTLR4_GIT_REPOSITORY}
      GIT_TAG ${ANTLR4_TAG}
      DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}
      BUILD_COMMAND ""
      BUILD_IN_SOURCE 1
      SOURCE_DIR ${ANTLR4_ROOT}
      SOURCE_SUBDIR runtime/Cpp
      CMAKE_CACHE_ARGS
          -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
          -DWITH_STATIC_CRT:BOOL=${ANTLR4_WITH_STATIC_CRT}
          # -DCMAKE_CXX_STANDARD:STRING=17 # if desired, compile the runtime with a different C++ standard
          # -DCMAKE_CXX_STANDARD:STRING=${CMAKE_CXX_STANDARD} # alternatively, compile the runtime with the same C++ standard as the outer project
      INSTALL_COMMAND ""
      EXCLUDE_FROM_ALL 1)
endif()

# Separate build step as rarely people want both
set(ANTLR4_BUILD_DIR ${ANTLR4_ROOT})
if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.14.0")
  # CMake 3.14 builds in above's SOURCE_SUBDIR when BUILD_IN_SOURCE is true
  set(ANTLR4_BUILD_DIR ${ANTLR4_ROOT}/runtime/Cpp)
endif()

ExternalProject_Add_Step(
    antlr4_runtime
    build_static
    COMMAND ${ANTLR4_BUILD_COMMAND} antlr4_static
    # Depend on target instead of step (a custom command)
    # to avoid running dependent steps concurrently
    DEPENDS antlr4_runtime
    BYPRODUCTS ${ANTLR4_STATIC_LIBRARIES}
    EXCLUDE_FROM_MAIN 1
    WORKING_DIRECTORY ${ANTLR4_BUILD_DIR})
ExternalProject_Add_StepTargets(antlr4_runtime build_static)

add_library(antlr4_static STATIC IMPORTED)
add_dependencies(antlr4_static antlr4_runtime-build_static)
set_target_properties(antlr4_static PROPERTIES
                      IMPORTED_LOCATION ${ANTLR4_STATIC_LIBRARIES})

ExternalProject_Add_Step(
    antlr4_runtime
    build_shared
    COMMAND ${ANTLR4_BUILD_COMMAND} antlr4_shared
    # Depend on target instead of step (a custom command)
    # to avoid running dependent steps concurrently
    DEPENDS antlr4_runtime
    BYPRODUCTS ${ANTLR4_SHARED_LIBRARIES} ${ANTLR4_RUNTIME_LIBRARIES}
    EXCLUDE_FROM_MAIN 1
    WORKING_DIRECTORY ${ANTLR4_BUILD_DIR})
ExternalProject_Add_StepTargets(antlr4_runtime build_shared)

add_library(antlr4_shared SHARED IMPORTED)
add_dependencies(antlr4_shared antlr4_runtime-build_shared)
set_target_properties(antlr4_shared PROPERTIES
                      IMPORTED_LOCATION ${ANTLR4_RUNTIME_LIBRARIES})
if(ANTLR4_SHARED_LIBRARIES)
  set_target_properties(antlr4_shared PROPERTIES
                        IMPORTED_IMPLIB ${ANTLR4_SHARED_LIBRARIES})
endif()

message("LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include src ${ANTLR4_INCLUDE_DIRS})

set(TARGET_WebAssembly WebAssemblyCodeGen WebAssemblyAsmParser WebAssemblyDesc WebAssemblyInfo)
set(TARGET_XCore XCoreCodeGen XCoreDesc XCoreInfo)
set(TARGET_SystemZ SystemZCodeGen SystemZAsmParser SystemZDesc SystemZInfo) 
set(TARGET_Sparc SparcCodeGen SparcAsmParser SparcDesc SparcInfo) 
set(TARGET_RISCV RISCVCodeGen RISCVAsmParser RISCVDesc RISCVInfo) 
set(TARGET_PowerPC PowerPCCodeGen PowerPCAsmParser PowerPCDesc PowerPCInfo) 
set(TARGET_NVPTX NVPTXCodeGen NVPTXDesc NVPTXInfo) 
set(TARGET_MSP430 MSP430CodeGen MSP430AsmParser MSP430Desc MSP430Info) 
set(TARGET_Mips MipsCodeGen MipsAsmParser MipsDesc MipsInfo) 
set(TARGET_Lanai LanaiCodeGen LanaiAsmParser LanaiDesc LanaiInfo) 
set(TARGET_Hexagon HexagonCodeGen HexagonAsmParser HexagonDesc HexagonInfo) 
set(TARGET_BPF BPFCodeGen BPFAsmParser BPFDesc BPFInfo) 
set(TARGET_ARM ARMCodeGen ARMAsmParser ARMDesc ARMUtils ARMInfo) 
set(TARGET_AMDGPU AMDGPUCodeGen AMDGPUAsmParser AMDGPUDesc AMDGPUUtils AMDGPUInfo)
set(TARGET_X86 X86CodeGen X86AsmParser X86Desc X86Info)
set(TARGET_AArch64 AArch64CodeGen AArch64AsmParser AArch64Desc AArch64Utils AArch64Info)
set(TARGET_AVR AVRCodeGen AVRAsmParser AVRDesc AVRInfo)

set(TARGETS_TO_BUILD "WebAssembly" "XCore" "SystemZ" "Sparc" "RISCV" "PowerPC" "NVPTX" "MSP430" "Mips" "Lanai" "Hexagon" "BPF" "ARM" "AMDGPU" "X86" "AArch64" "AVR")

set(LLVM_TARGETS)
foreach (target IN ITEMS ${TARGETS_TO_BUILD})
    list(APPEND LLVM_TARGETS "${TARGET_${target}}")
endforeach(target)

llvm_map_components_to_libnames(llvm_libs 
    TextAPI
    OrcJIT
    JITLink
    ObjectYAML
    WindowsManifest
    Coverage
    TableGen
    LTO
    Passes
    ObjCARCOpts
    Coroutines
    LibDriver
    XRay
    ${LLVM_TARGETS}
    MIRParser
    ipo
    Instrumentation
    Vectorize
    Linker
    IRReader
    AsmParser
    Symbolize
    DebugInfoPDB
    FuzzMutate
    LineEditor
    MCA
    DebugInfoGSYM
    GlobalISel
    SelectionDAG
    AsmPrinter
    DebugInfoDWARF
    MCJIT
    Interpreter
    ExecutionEngine
    RuntimeDyld
    CodeGen
    Target
    ScalarOpts
    InstCombine
    AggressiveInstCombine
    TransformUtils
    BitWriter
    Analysis
    ProfileData
    DlltoolDriver
    Option
    Object
    MCParser
    MC
    DebugInfoCodeView
    DebugInfoMSF
    BitReader
    Core
    Remarks
    BinaryFormat
    BitstreamReader
    Support
    Demangle
)

target_link_libraries(${PROJECT_NAME} antlr4_static ${llvm_libs})
