#include "CSharpMethodArgumentUnit.h"

#include "utils.h"
#include "CSharpUtils.h"

#include <stdexcept>

CSharpMethodArgumentUnit::CSharpMethodArgumentUnit(const std::string &name,
                                                   const Modifiers::ArgumentTypes &type,
                                                   const Modifiers::ArgumentPrefixModifiers &argumentPrefixModifier)
    : IMethodArgumentUnit(name, type, argumentPrefixModifier) {}

std::string CSharpMethodArgumentUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    {
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = GetCSharpArgumentTypeName(type) + " " + GetName();

    return result;
}