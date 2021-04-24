#include "JIT.hpp"
#include "grammar/Visitor.hpp"

#include <llvm/Passes/PassBuilder.h>
#include <llvm/Support/TargetSelect.h>

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/JITSymbol.h>

#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>

#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/ExecutionEngine/Orc/ThreadSafeModule.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: compiler <file> [--print-llvm]" << std::endl;
        return 1;
    }

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    FooLang::Visitor visitor;
    visitor.from_file(argv[1]);

    if (argc > 2 && (argv[2] == std::string("--print-llvm")))
    {
        visitor.module->print(llvm::outs(), nullptr);
        std::cout << std::endl;
    }

    auto jit = FooLang::JIT::create(visitor.module, visitor.llvm_context);

    auto entry = jit->lookup<int()>("main");
    if (!entry)
    {
        llvm::errs() << entry.takeError();
        return 1;
    }

    entry.get()();

    return 0;
}
