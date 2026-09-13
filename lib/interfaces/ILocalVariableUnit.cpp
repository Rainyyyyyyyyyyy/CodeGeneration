#include "ILocalVariableUnit.h"

ILocalVariableUnit::ILocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                       const Modifiers::ArgumentPrefixModifiers &prefixModifier)
                       {
                        this->name = name;
                        this->type = type;
                        this->prefixModifier = prefixModifier;
                       }

void ILocalVariableUnit::SetType(const Modifiers::ArgumentTypes &type)
{
    this->type = type;
}

void ILocalVariableUnit::SetName(const std::string &name)
{
    this->name = name;
}
void ILocalVariableUnit::SetPrefixModifier(const Modifiers::ArgumentPrefixModifiers &prefixModifier)
{
    this->prefixModifier = prefixModifier;
}
