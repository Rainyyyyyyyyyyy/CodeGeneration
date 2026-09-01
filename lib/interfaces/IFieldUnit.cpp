#include "IFieldUnit.h"

IFieldUnit::IFieldUnit(const std::string &name, const ArgumentTypes &type,
                        const Modifiers::AccessModifiers &accessModifier,
                        const Modifiers::ArgumentPrefixModifiers &prefixModifier)
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    if(type == ArgumentTypes::VOID)
    {
        throw std::invalid_argument("Invalid field type: " + GetArgumentTypeName(type));
    }
    this->type = type;
    this->name = name;
    this->accessModifier = accessModifier;
    this->prefixModifier = prefixModifier;
}

Modifiers::ArgumentPrefixModifiers IFieldUnit::getPrefixModifier() const
{
    return prefixModifier;
}

Modifiers::AccessModifiers IFieldUnit::getAccessModifier() const
{
    return accessModifier;
}

std::string IFieldUnit::getName() const
{
    return name;
}

ArgumentTypes IFieldUnit::getType() const
{
    return type;
}