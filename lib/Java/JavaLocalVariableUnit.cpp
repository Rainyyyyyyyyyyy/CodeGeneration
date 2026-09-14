#include "JavaLocalVariableUnit.h"

#include "utils.h"
#include "JavaUtils.h"

#include <stdexcept>

#include <iostream>


JavaLocalVariableUnit::JavaLocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                         const Modifiers::ArgumentPrefixModifiers &prefixModifier)
                         : ILocalVariableUnit(name, type, prefixModifier) {}



std::string JavaLocalVariableUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    {
        throw std::invalid_argument("Invalid variable name: " + name);
    }
    std::string result = generateShift(level) + GetJavaArgumentPrefixModifierName(prefixModifier) + " " + GetJavaArgumentTypeName(type) + " " + name + ";\n";
    return result;
}
