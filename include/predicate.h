#pragma once
#include "type.h"

namespace ratio::core
{
  class atom;

  class predicate : public type
  {
  public:
    ORATIOCORE_EXPORT predicate(core &cr, const std::string &name, std::vector<field_ptr> args);
    predicate(const predicate &orig) = delete;

    ORATIOCORE_EXPORT virtual expr new_instance(); // creates a new instance of this type..

    ORATIOCORE_EXPORT void apply_rule(atom &a); // applies the rule associated to this predicate to the given atom..

  private:
    std::vector<field *> args; // the arguments of this predicate..
  };
  
  using predicate_ptr = std::shared_ptr<predicate>;
} // namespace ratio::core
