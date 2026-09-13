#include "JavaMethodArgumentUnit.h"

#include "utils.h"
#include "JavaUtils.h"

#include <stdexcept>

JavaMethodArgumentUnit::JavaMethodArgumentUnit(const std::string &name,
                                   const Modifiers::ArgumentTypes &type,
                                   const Modifiers::ArgumentPrefixModifiers &argumentPrefixModifier)
    : IMethodArgumentUnit(name, type, argumentPrefixModifier)
{
}

std::string JavaMethodArgumentUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    {
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = GetJavaArgumentTypeName(type) + " " + GetName();

    return result;
}