#pragma once

#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <memory>
#include <type_traits>

namespace FooLang
{
class JIT
{
private:
    std::unique_ptr<llvm::orc::LLJIT> lljit;

public:
    JIT(std::unique_ptr<llvm::orc::LLJIT> _lljit) : lljit(std::move(_lljit)) {}

    template <typename T, typename = std::enable_if_t<std::is_pointer<T>::value && std::is_function<std::remove_pointer_t<T>>::value>>
    llvm::Expected<T> lookup(const std::string &name)
    {
        auto symbol = this->lljit->lookup(name);

        if (!symbol)
        {
            return symbol.takeError();
        }

        return (T)symbol.get().getAddress();
    }

    template <typename T, typename = std::enable_if_t<std::is_function<T>::value>>
    inline llvm::Expected<T *> lookup(const std::string &name)
    {
        return this->lookup<T *>(name);
    }

    static llvm::Expected<JIT> create(std::unique_ptr<llvm::Module> &module, std::unique_ptr<llvm::LLVMContext> &context)
    {
        auto lljit = llvm::orc::LLJITBuilder().create();
        auto &jd = lljit.get()->getMainJITDylib();

        jd.addGenerator(llvm::cantFail(llvm::orc::DynamicLibrarySearchGenerator::GetForCurrentProcess('_')));

        if (!lljit)
        {
            return lljit.takeError();
        }

        if (auto err = lljit.get()->addIRModule(llvm::orc::ThreadSafeModule(std::move(module), std::move(context))))
        {
            return std::move(err);
        }

        return JIT(std::move(lljit.get()));
    }
};
} // namespace FooLang
