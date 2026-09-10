#include "JavaMethodArgumentUnit.h"

#include "utils.h"

#include <stdexcept>

JavaMethodArgumentUnit::JavaMethodArgumentUnit(const std::string &name, const Modifiers::ArgumentTypes &type)
    : IMethodArgumentUnit(name, type) {}

std::string JavaMethodArgumentUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    {
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = GetArgumentTypeName(type) + " " + GetName();

    return result;
}