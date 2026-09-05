#include "CppFieldUnit.h"

const std::vector<std::string> CppFieldUnit::AccessModifiersNames = {"public", "protected", "private"};

CppFieldUnit::CppFieldUnit(const std::string &name, const ArgumentTypes &type,
                           const AccessModifiers &accessModifier)
    : IFieldUnit(name, type, accessModifier) {}

std::string CppFieldUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = generateShift(level) + GetArgumentTypeName(type) + ' ' + name + ";\n";
    return result;
}