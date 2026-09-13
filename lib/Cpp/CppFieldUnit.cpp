#include "CppFieldUnit.h"
#include "utils.h"
#include "CppUtils.h"


#include <stdexcept>



CppFieldUnit::CppFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                          const Modifiers::ArgumentPrefixModifiers &prefixModifier)
    : IFieldUnit(name, type, prefixModifier) {}

std::string CppFieldUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = generateShift(level) + GetCppArgumentTypeName(type) + ' ' + name + ";\n";
    return result;
}