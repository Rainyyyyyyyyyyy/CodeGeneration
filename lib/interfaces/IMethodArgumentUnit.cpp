#include "IMethodArgumentUnit.h"

IMethodArgumentUnit::IMethodArgumentUnit(const std::string &name,
                                 const ArgumentTypes &type,
                                 const Modifiers::ArgumentPrefixModifiers &prefixModifier)
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    if(type == ArgumentTypes::VOID)
    {
        throw std::invalid_argument("Invalid argument type: " + GetArgumentTypeName(type));
    }
    this->type = type;
    this->name = name;
    this->prefixModifier = prefixModifier;
}
ArgumentTypes IMethodArgumentUnit::getType() const
{
    return type;
}

std::string IMethodArgumentUnit::getName() const
{
    return name;
}
ArgumentPrefixModifiers IMethodArgumentUnit::getPrefixModifier() const {
    return prefixModifier;
}