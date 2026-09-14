#include "IClassUnit.h"
#include "utils.h"
#include <stdexcept>

IClassUnit::IClassUnit(const std::string &name,
                       const Modifiers::ClassPrefixModifiers &classPrefixModifier
                       // , const Modifiers::AccessModifiers &accessModifier
)
{
    this->name = name;
    // this->AccessModifier = accessModifier;
    this->classPrefixModifier = classPrefixModifier;
}
