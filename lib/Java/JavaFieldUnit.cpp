#include "JavaFieldUnit.h"
#include "utils.h"

#include <stdexcept>


const std::vector<std::string> JavaFieldUnit::AccessModifiersNames = {"public", "protected", "private"};


JavaFieldUnit::JavaFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                        const Modifiers::AccessModifiers &accessModifier,
                        const Modifiers::ArgumentPrefixModifiers &prefixModifier)
    : IFieldUnit(name, type, accessModifier, prefixModifier) {}


std::string JavaFieldUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = generateShift(level) + GetAccessModifierName(accessModifier) + ' ' +
                         GetArgumentPrefixModifierName(prefixModifier) + ' ' +
                         GetArgumentTypeName(type) + ' ' + name + ";\n";
    return result;
}
