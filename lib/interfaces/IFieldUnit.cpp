#include <stdexcept>

#include "IFieldUnit.h"
#include "utils.h"

IFieldUnit::IFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                        const Modifiers::ArgumentPrefixModifiers &prefixModifier)

{
    this->type = type;
    this->name = name;
    this->prefixModifier = prefixModifier;
}

void IFieldUnit::SetName(const std::string &name)
{
    this->name = name;
}

void IFieldUnit::SetType(const Modifiers::ArgumentTypes &type)
{
    this->type = type;
}

void IFieldUnit::SetPrefixModifier(const Modifiers::ArgumentPrefixModifiers &prefixModifier)
{
    this->prefixModifier = prefixModifier;
}

