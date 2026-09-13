#include <stdexcept> 

#include "IFieldUnit.h"
#include "utils.h"

IFieldUnit::IFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                       const Modifiers::AccessModifiers &accessModifier,
                       const Modifiers::ArgumentPrefixModifiers &prefixModifier)
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    if (type == Modifiers::ArgumentTypes::VOID)
    {
        throw std::invalid_argument("Invalid field type: " + GetArgumentTypeName(type));
    }
    this->type = type;
    this->name = name;
    this->accessModifier = accessModifier;
    this->prefixModifier = prefixModifier;
}
