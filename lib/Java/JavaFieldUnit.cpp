#include "JavaFieldUnit.h"
#include "utils.h"
#include "JavaUtils.h"


#include <stdexcept>


JavaFieldUnit::JavaFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                       const Modifiers::ArgumentPrefixModifiers &prefixModifier)
    : IFieldUnit(name, type, prefixModifier) { }


std::string JavaFieldUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = generateShift(level) +
                         GetJavaArgumentPrefixModifierName(prefixModifier) + ' ' +
                         GetJavaArgumentTypeName(type) + ' ' + name + ";\n";
    return result;
}
