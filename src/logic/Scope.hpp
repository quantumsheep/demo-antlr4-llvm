#include <llvm/IR/Value.h>
#include <string>
#include <unordered_map>

namespace FooLang
{
class Scope
{
public:
    std::unordered_map<std::string, llvm::Value *> variables;

    llvm::Value *setVariable(std::string name, llvm::Value *);

    llvm::Value *getVariable(std::string name);
};
} // namespace FooLang
