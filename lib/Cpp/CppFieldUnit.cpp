#include "CppFieldUnit.h"




const std::vector<std::string> CppFieldUnit::AccessModifiersNames = { "public", "protected", "private" };


std::string CppFieldUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + GetArgumentTypeName(type) + ' ' + name + ";\n";
    return result;
}