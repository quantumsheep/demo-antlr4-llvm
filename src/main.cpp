#include "CLIManager.hpp"
#include "JIT.hpp"
#include "ObjectEmitter.hpp"
#include "grammar/Visitor.hpp"

#include <llvm/Support/TargetSelect.h>

int run(const FooLang::CLIManager &cli, FooLang::Visitor &visitor)
{
    auto jit = FooLang::JIT::create(visitor.module, visitor.llvm_context);

    auto entry = jit->lookup<int()>("main");
    if (!entry)
    {
        llvm::errs() << entry.takeError();
        return 1;
    }

    return entry.get()();
}

int compile(const FooLang::CLIManager &cli, FooLang::Visitor &visitor)
{
    std::string error;
    FooLang::ObjectEmitter::emit(visitor.module, cli.getOptionValue("-o", "output.o"), error);

    if (!error.empty())
    {
        llvm::errs() << error;
        return 1;
    }

    return 0;
}

int main(int argc, char **argv)
{
    FooLang::CLIManager cli(argc, argv);

    if (argc < 2 || cli.hasOption("--help") || cli.hasOption("-h"))
    {
        std::cerr << "Usage: compiler <file> [--help,-h] [--print-llvm] [--compile,-c [-o <path (default: output.o)>]]" << std::endl;
        return 1;
    }

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    FooLang::Visitor visitor;
    visitor.fromFile(argv[1]);

    if (cli.hasOption("--print-llvm"))
    {
        visitor.module->print(llvm::outs(), nullptr);
        std::cout << std::endl;
    }

    if (cli.hasOption("--compile") || cli.hasOption("-c"))
    {
        compile(cli, visitor);
    }
    else
    {
        run(cli, visitor);
    }

    return 0;
}
