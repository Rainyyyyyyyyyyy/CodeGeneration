#include "CSharpLocalVariableUnit.h"

#include "utils.h"
#include "CSharpUtils.h"

#include <stdexcept>

#include <iostream>

CSharpLocalVariableUnit::CSharpLocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                                                 const Modifiers::ArgumentPrefixModifiers &prefixModifier)
    : ILocalVariableUnit(name, type, prefixModifier) {}

std::string CSharpLocalVariableUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    {
        throw std::invalid_argument("Invalid variable name: " + name);
    }
    std::string result = generateShift(level) + GetCSharpArgumentPrefixModifierName(prefixModifier) + " " + GetCSharpArgumentTypeName(type) + " " + name + ";\n";
    return result;
}
