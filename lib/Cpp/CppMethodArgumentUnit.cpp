#include "CppMethodArgumentUnit.h"
#include "utils.h"
#include <stdexcept>


CppMethodArgumentUnit::CppMethodArgumentUnit(const std::string &name, const Modifiers::ArgumentTypes &type)
    : IMethodArgumentUnit(name, type) {}

std::string CppMethodArgumentUnit::compile(unsigned int level) const
{
    if(IsValidVariableName(name) == false){
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = generateShift(level) + GetArgumentTypeName(type) + " " + GetName();

    return result;
}