#include <llvm/IR/Value.h>
#include <string>
#include <unordered_map>

namespace FooLang
{
class Scope
{
public:
    std::unordered_map<std::string, llvm::Value *> variables;

    llvm::Function *currentFunction = nullptr;

    Scope(llvm::Function *_currentFunction = nullptr) : currentFunction(_currentFunction) {}

    llvm::Value *setVariable(const std::string &name, llvm::Value *);

    llvm::Value *getVariable(const std::string &name);
};
} // namespace FooLang
