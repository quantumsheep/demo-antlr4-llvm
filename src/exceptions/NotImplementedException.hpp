#include <stdexcept>

namespace FooLang
{
class NotImplementedException : public std::logic_error
{
public:
    NotImplementedException() : std::logic_error("Functionnality not yet implemented.") {}
};
} // namespace FooLang
