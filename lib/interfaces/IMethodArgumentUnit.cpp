#include "IMethodArgumentUnit.h"
#include "utils.h"

#include <stdexcept>

IMethodArgumentUnit::IMethodArgumentUnit(const std::string &name,
                                         const Modifiers::ArgumentTypes &type,
                                         const Modifiers::ArgumentPrefixModifiers &prefixModifier)
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    if (type == Modifiers::ArgumentTypes::VOID)
    {
        throw std::invalid_argument("Invalid argument type: " + GetArgumentTypeName(type));
    }
    this->type = type;
    this->name = name;
    this->prefixModifier = prefixModifier;
}
