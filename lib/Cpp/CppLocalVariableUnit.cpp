#include "CppLocalVariableUnit.h"

#include "utils.h"
#include "CppUtils.h"
#include <stdexcept>

CppLocalVariableUnit::CppLocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                                           const Modifiers::ArgumentPrefixModifiers &prefixModifier)
    : ILocalVariableUnit(name, type, prefixModifier) {}

std::string CppLocalVariableUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    {
        throw std::invalid_argument("Invalid variable name: " + name);
    }
    std::string result = generateShift(level) + GetCppArgumentPrefixModifierName(prefixModifier) + " " + GetCppArgumentTypeName(type) + " " + name + ";\n";
    return result;
}