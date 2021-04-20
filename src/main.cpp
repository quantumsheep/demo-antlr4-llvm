#include "KaleidoscopeJIT.hpp"
#include "grammar/Visitor.hpp"

#include <llvm/Passes/PassBuilder.h>
#include <llvm/Support/TargetSelect.h>

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/JITSymbol.h>

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

    llvm::orc::KaleidoscopeJIT J;
    J.addModule(std::move(visitor.module));
    auto *Main = (int (*)())(intptr_t)llvm::cantFail(J.findSymbolNoMangle("main").getAddress());

    Main();

    return 0;
}
