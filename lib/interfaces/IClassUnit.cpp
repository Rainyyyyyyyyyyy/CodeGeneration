#include "IClassUnit.h"
#include "utils.h"
#include <stdexcept>

IClassUnit::IClassUnit(const std::string &name,
                       const Modifiers::ClassPrefixModifiers &classPrefixModifier
)
{
    this->name = name;
    this->classPrefixModifier = classPrefixModifier;
}
