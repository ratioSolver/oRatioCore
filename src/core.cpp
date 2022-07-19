#include "core.h"
#include "predicate.h"
#include <sstream>
#include <fstream>

namespace ratio::core
{
    ORATIOCORE_EXPORT core::core() : scope(*this), env(*this) {}

    ORATIOCORE_EXPORT void core::read(const std::string &script)
    {
        std::stringstream ss(script);
    }

    ORATIOCORE_EXPORT void core::read(const std::vector<std::string> &files)
    {
        for (const auto &f : files)
            if (std::ifstream ifs(f); ifs)
            {
            }
            else
                throw std::invalid_argument("cannot find file '" + f + "'");
    }

    ORATIOCORE_EXPORT expr new_bool() noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_bool(const bool &val) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_int() noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_int(const semitone::I &val) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_real() noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_real(const semitone::rational &val) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_time_point() noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_time_point(const semitone::rational &val) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_string() noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_string(const std::string &val) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr new_enum(type &tp, std::vector<expr> allowed_vals) { return nullptr; }

    ORATIOCORE_EXPORT expr negate(expr var) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr conj(const std::vector<expr> &exprs) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr disj(const std::vector<expr> &exprs) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr exct_one(const std::vector<expr> &exprs) noexcept { return nullptr; }

    ORATIOCORE_EXPORT expr add(const std::vector<expr> &exprs) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr sub(const std::vector<expr> &exprs) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr mult(const std::vector<expr> &exprs) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr div(const std::vector<expr> &exprs) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr minus(expr ex) noexcept { return nullptr; }

    ORATIOCORE_EXPORT expr lt(expr left, expr right) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr leq(expr left, expr right) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr eq(expr left, expr right) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr geq(expr left, expr right) noexcept { return nullptr; }
    ORATIOCORE_EXPORT expr gt(expr left, expr right) noexcept { return nullptr; }

    ORATIOCORE_EXPORT expr core::get(const std::string &name) noexcept
    {
        if (const auto at_xpr = vars.find(name); at_xpr != vars.cend())
            return at_xpr->second;
        else
            return nullptr;
    }

    ORATIOCORE_EXPORT type &core::get_type(const std::string &name) const
    {
        if (const auto at_tp = types.find(name); at_tp != types.cend())
            return *at_tp->second;

        // not found
        throw std::out_of_range(name);
    }
} // namespace ratio::core
