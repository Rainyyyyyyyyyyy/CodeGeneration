#include "IFieldUnit.h"

IFieldUnit::IFieldUnit(const std::string &name, const ArgumentTypes &type,
                       const AccessModifiers &accessModifier)
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    this->type = type;
    this->name = name;
    this->accessModifier = accessModifier;
}

Modifiers::AccessModifiers IFieldUnit::getAccessModifier() const
{
    return accessModifier;
}

std::string IFieldUnit::getName() const
{
    return name;
}