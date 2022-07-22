#pragma once
#include "scope.h"
#include "env.h"
#include "inf_rational.h"
#include <unordered_set>

namespace ratio::core
{
  class conjunction;
  class bool_item;
  class arith_item;
  class enum_item;
  class atom;
  class formula_statement;
  class method_declaration;
  class predicate_declaration;
  class typedef_declaration;

  class core : public scope, public env
  {
    friend class formula_statement;
    friend class method_declaration;
    friend class predicate_declaration;
    friend class typedef_declaration;

  public:
    ORATIOCORE_EXPORT core();
    core(const core &orig) = delete;
    ORATIOCORE_EXPORT virtual ~core();

    /**
     * @brief Parses the given riddle script.
     *
     * @param script The riddle script to parse.
     */
    ORATIOCORE_EXPORT virtual void read(const std::string &script);
    /**
     * @brief Parses the given riddle files.
     *
     * @param files The riddle files to parse.
     */
    ORATIOCORE_EXPORT virtual void read(const std::vector<std::string> &files);

    /**
     * @brief Creates a new boolean variable.
     *
     * @return expr The new boolean variable.
     */
    virtual expr new_bool() noexcept { return nullptr; }

    /**
     * @brief Creates a new boolean literal.
     *
     * @param val The value of the literal.
     * @return expr The new boolean literal.
     */
    ORATIOCORE_EXPORT expr new_bool(const bool &val) noexcept;

    /**
     * @brief Creates a new integer variable.
     *
     * @return expr The new integer variable.
     */
    virtual expr new_int() noexcept { return nullptr; }

    /**
     * @brief Creates a new integer literal.
     *
     * @param val The value of the literal.
     * @return expr The new integer literal.
     */
    ORATIOCORE_EXPORT expr new_int(const semitone::I &val) noexcept;

    /**
     * @brief Creates a new real variable.
     *
     * @return expr The new real variable.
     */
    virtual expr new_real() noexcept { return nullptr; }

    /**
     * @brief Creates a new real literal.
     *
     * @param val The value of the literal.
     * @return expr The new real literal.
     */
    ORATIOCORE_EXPORT expr new_real(const semitone::rational &val) noexcept;

    /**
     * @brief Creates a new time-point variable.
     *
     * @return expr The new time-point variable.
     */
    virtual expr new_time_point() noexcept { return nullptr; }

    /**
     * @brief Creates a new time-point literal.
     *
     * @param val The value of the literal.
     * @return expr The new time-point literal.
     */
    ORATIOCORE_EXPORT expr new_time_point(const semitone::rational &val) noexcept;

    /**
     * @brief Creates a new string variable.
     *
     * @return expr The new string variable.
     */
    virtual expr new_string() noexcept { return nullptr; }

    /**
     * @brief Creates a new string literal.
     *
     * @param val The value of the literal.
     * @return expr The new string literal.
     */
    ORATIOCORE_EXPORT expr new_string(const std::string &val) noexcept;

    /**
     * @brief Creates a new enumerative variable.
     *
     * @param tp The type of the enumerative variable.
     * @param allowed_vals The initial domain of the enumerative variable.
     * @return expr The new enumerative variable.
     */
    virtual expr new_enum([[maybe_unused]] type &tp, [[maybe_unused]] const std::vector<expr> &allowed_vals) { return nullptr; }
    /**
     * @brief Removes the `val` value from the `var` variable's domain.
     *
     * @param var The variable whose domain is to be shrinked.
     * @param val The value to be removed from the domain.
     */
    virtual void remove([[maybe_unused]] expr &var, [[maybe_unused]] expr &val) {}

    /**
     * @brief Computes, if not already present, the `name` field of the enumerative variable `var`, introducing proper constraints for managing consistency.
     *
     * @param var The enumerative variable whose field has to be computed.
     * @param name The name of the field which has to be computed.
     * @return expr The value ov the `name` field.
     */
    virtual expr get([[maybe_unused]] enum_item &var, [[maybe_unused]] const std::string &name) { return nullptr; }

    /**
     * @brief Creates an expression which is the negation of the given expression.
     *
     * @param var The expression to be negated.
     * @return expr The negated expression.
     */
    virtual expr negate([[maybe_unused]] const expr &var) noexcept { return nullptr; }
    /**
     * @brief Creates an expression which the conjunction of the given expressions.
     *
     * @param exprs The expressions of the conjunction.
     * @return expr The conjunction expression of the given expressions.
     */
    virtual expr conj([[maybe_unused]] const std::vector<expr> &exprs) noexcept { return nullptr; }
    /**
     * @brief Creates an expression which the disjunction of the given expressions.
     *
     * @param exprs The expressions of the disjunction.
     * @return expr The disjunction expression of the given expressions.
     */
    virtual expr disj([[maybe_unused]] const std::vector<expr> &exprs) noexcept { return nullptr; }
    /**
     * @brief Creates an expression which the exact-one of the given expressions.
     *
     * @param exprs The expressions of the exact-one.
     * @return expr The exact-one expression of the given expressions.
     */
    virtual expr exct_one([[maybe_unused]] const std::vector<expr> &exprs) noexcept { return nullptr; }

    virtual expr add([[maybe_unused]] const std::vector<expr> &exprs) noexcept { return nullptr; }
    virtual expr sub([[maybe_unused]] const std::vector<expr> &exprs) noexcept { return nullptr; }
    virtual expr mult([[maybe_unused]] const std::vector<expr> &exprs) noexcept { return nullptr; }
    virtual expr div([[maybe_unused]] const std::vector<expr> &exprs) noexcept { return nullptr; }
    virtual expr minus([[maybe_unused]] const expr &ex) noexcept { return nullptr; }

    virtual expr lt([[maybe_unused]] const expr &left, [[maybe_unused]] const expr &right) noexcept { return nullptr; }
    virtual expr leq([[maybe_unused]] const expr &left, [[maybe_unused]] const expr &right) noexcept { return nullptr; }
    virtual expr eq([[maybe_unused]] const expr &left, [[maybe_unused]] const expr &right) noexcept { return nullptr; }
    virtual expr geq([[maybe_unused]] const expr &left, [[maybe_unused]] const expr &right) noexcept { return nullptr; }
    virtual expr gt([[maybe_unused]] const expr &left, [[maybe_unused]] const expr &right) noexcept { return nullptr; }

    inline core &get_core() const override { return const_cast<core &>(*this); }

    ORATIOCORE_EXPORT expr get(const std::string &name) noexcept override;

    /**
     * @brief Evaluates the given boolean expression.
     *
     * @param x The boolean expression to evaluate.
     * @return semitone::lbool The value of the given boolean expression.
     */
    ORATIOCORE_EXPORT semitone::lbool bool_value([[maybe_unused]] const expr &x) const noexcept;
    virtual semitone::lbool bool_value([[maybe_unused]] const bool_item &x) const noexcept { return semitone::Undefined; }
    /**
     * @brief Evaluates the bounds of the given arithmetic expression.
     *
     * @param x The arithmetic expression to evaluate.
     * @return std::pair<semitone::inf_rational, semitone::inf_rational> The bounds of the given arithmetic expression.
     */
    ORATIOCORE_EXPORT std::pair<semitone::inf_rational, semitone::inf_rational> arith_bounds([[maybe_unused]] const expr &x) const noexcept;
    virtual std::pair<semitone::inf_rational, semitone::inf_rational> arith_bounds([[maybe_unused]] const arith_item &x) const noexcept { return std::make_pair<semitone::inf_rational, semitone::inf_rational>(semitone::inf_rational(semitone::rational::NEGATIVE_INFINITY), semitone::inf_rational(semitone::rational::POSITIVE_INFINITY)); }
    /**
     * @brief Evaluates the given arithmetic expression.
     *
     * @param x The arithmetic expression to evaluate.
     * @return semitone::inf_rational The value of the given arithmetic expression.
     */
    ORATIOCORE_EXPORT semitone::inf_rational arith_value([[maybe_unused]] const expr &x) const noexcept;
    virtual semitone::inf_rational arith_value([[maybe_unused]] const arith_item &x) const noexcept { return semitone::inf_rational(0); }
    /**
     * @brief Evaluates the given enumerative expression.
     *
     * @param x The arithmetic enumerative to evaluate.
     * @return std::unordered_set<expr> The current domain of the given enumerative expression.
     */
    ORATIOCORE_EXPORT std::unordered_set<expr> enum_value([[maybe_unused]] const expr &x) const noexcept;
    virtual std::unordered_set<expr> enum_value([[maybe_unused]] const enum_item &x) const noexcept { return std::unordered_set<expr>(); }

    /**
     * @brief Creates a new disjunction of conjunctions.
     *
     * @param conjs A vector of conjunctions representing the disjunction.
     */
    ORATIOCORE_EXPORT virtual void new_disjunction(const std::vector<std::unique_ptr<conjunction>> conjs);

    void assert_facts([[maybe_unused]] std::vector<expr> facts) {}

  private:
    virtual void new_atom([[maybe_unused]] atom &atm, [[maybe_unused]] const bool &is_fact) {}

  protected:
    ORATIOCORE_EXPORT void new_method(method_ptr m) noexcept;
    ORATIOCORE_EXPORT void new_type(type_ptr t) noexcept;
    ORATIOCORE_EXPORT void new_predicate(predicate_ptr p) noexcept;

  public:
    ORATIOCORE_EXPORT const field &get_field(const std::string &name) const override;
    ORATIOCORE_EXPORT method &get_method(const std::string &name, const std::vector<const type *> &ts) const override;
    const std::map<std::string, std::vector<method_ptr>> &get_methods() const noexcept override { return methods; }
    ORATIOCORE_EXPORT type &get_type(const std::string &name) const override;
    const std::map<std::string, type_ptr> &get_types() const noexcept override { return types; }
    ORATIOCORE_EXPORT predicate &get_predicate(const std::string &name) const override;
    const std::map<std::string, predicate_ptr> &get_predicates() const noexcept override { return predicates; }

  private:
    std::map<std::string, std::vector<method_ptr>> methods; // the methods, indexed by their name, defined within this core..
    std::map<std::string, type_ptr> types;                  // the inner types, indexed by their name, defined within this core..
    std::map<std::string, predicate_ptr> predicates;        // the inner predicates, indexed by their name, defined within this core..
  };

  class inconsistency_exception : public std::exception
  {
    const char *what() const noexcept override { return "an inconsistency has been found.."; }
  };

  class unsolvable_exception : public std::exception
  {
    const char *what() const noexcept override { return "the problem is unsolvable.."; }
  };
} // namespace ratio::core
