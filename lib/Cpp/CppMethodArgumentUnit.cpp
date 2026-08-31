#include "CppMethodArgumentUnit.h"

CppMethodArgumentUnit::CppMethodArgumentUnit(const std::string &name, const ArgumentTypes &type)
    : IMethodArgumentUnit(name, type) {}

std::string CppMethodArgumentUnit::compile(unsigned int level) const
{

    std::string result = generateShift(level) + GetArgumentTypeName(type) + " " + getName();

    return result;
}