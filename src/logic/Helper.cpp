#include "Helper.hpp"

llvm::Value *FooLang::Helpers::printf(
    const std::unique_ptr<llvm::Module> &llvm_module,
    llvm::IRBuilder<> &builder,
    const std::string &format,
    const std::vector<llvm::Value *> &values)
{
    auto &llvm_context = llvm_module->getContext();

    auto printf_type = llvm::FunctionType::get(llvm::Type::getVoidTy(llvm_context), {llvm::Type::getInt8PtrTy(llvm_context)}, true);
    auto function = llvm_module->getOrInsertFunction("printf", printf_type, llvm::AttributeList().addAttribute(llvm_context, 1U, llvm::Attribute::NoAlias));

    auto constant = llvm::ConstantDataArray::getString(llvm_context, format, true);
    auto global = new llvm::GlobalVariable(*llvm_module, llvm::ArrayType::get(llvm::Type::getInt8Ty(llvm_context), format.size() + 1), true, llvm::GlobalValue::PrivateLinkage, constant, ".str");
    global->setUnnamedAddr(llvm::GlobalValue::UnnamedAddr::Global);
    global->setAlignment(llvm::Align(1));

    auto zero = llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm_context), 0);

    std::vector<llvm::Value *> args = {
        builder.CreateGEP(global, {zero, zero}),
    };

    args.insert(args.end(), values.begin(), values.end());

    return builder.CreateCall(function, args);
}
