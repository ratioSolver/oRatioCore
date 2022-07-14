#include "item.h"
#include "type.h"

namespace ratio::core
{
    item::item(type &tp) : tp(tp) {}

    complex_item::complex_item(type &tp) : item(tp), env(std::make_shared<env>(tp.get_core())) {}

    std::optional<expr> complex_item::get(const std::string &name) noexcept
    {
        if (const auto at_xpr = vars.find(name); at_xpr != vars.cend())
            return at_xpr->second;
        else
            return {};
    }
} // namespace ratio::core