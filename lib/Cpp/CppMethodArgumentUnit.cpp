#include "CppMethodArgumentUnit.h"
#include "utils.h"
#include "CppUtils.h"
#include <stdexcept>

CppMethodArgumentUnit::CppMethodArgumentUnit(const std::string &name,
                                             const Modifiers::ArgumentTypes &type,
                                             const Modifiers::ArgumentPrefixModifiers &prefixModifier)
    : IMethodArgumentUnit(name, type, prefixModifier) {}

std::string CppMethodArgumentUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    {
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = generateShift(level) + GetCppArgumentTypeName(type) + " " + GetName();

    return result;
}