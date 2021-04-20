#include "Scope.hpp"

using namespace FooLang;

llvm::Value *Scope::setVariable(std::string name, llvm::Value *value)
{
    this->variables[name] = value;
    return value;
}

llvm::Value *Scope::getVariable(std::string name)
{
    try
    {
        return this->variables.at(name);
    }
    catch (std::out_of_range)
    {
        return nullptr;
    }
}
