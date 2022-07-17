#pragma once
#include "scope.h"
#include "rational.h"

namespace riddle::ast
{
  class statement;
} // namespace riddle::ast

namespace ratio::core
{
  class conjunction : public scope
  {
  public:
    conjunction(type &tp, semitone::rational cst, std::vector<std::unique_ptr<const riddle::ast::statement>> stmnts);
    conjunction(const conjunction &orig) = delete;

    inline semitone::rational get_cost() const noexcept { return cost; } // returns the cost for applying this conjunction..

  private:
    const semitone::rational cost;                                                    // the cost for applying this conjunction..
    const std::vector<std::unique_ptr<const riddle::ast::statement>> statements; // the statements within the conjunction's body..
  };
} // namespace ratio::core
