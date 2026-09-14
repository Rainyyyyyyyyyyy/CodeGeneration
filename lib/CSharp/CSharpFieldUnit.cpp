#include "CSharpFieldUnit.h"
#include "utils.h"
#include "CSharpUtils.h"


#include <stdexcept>


//const std::vector<std::string> CSharpFieldUnit::AccessModifiersNames = {"public", "protected", "private"};


CSharpFieldUnit::CSharpFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                       const Modifiers::ArgumentPrefixModifiers &prefixModifier)
    : IFieldUnit(name, type, prefixModifier
                 // , accessModifier
                 ) { }


std::string CSharpFieldUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    { // если имя некорректно, то исключение
        throw std::invalid_argument("Invalid argument name: " + name);
    }
    std::string result = generateShift(level) +
                         // GetCSharpAccessModifierName(accessModifier) + ' ' +
                         GetCSharpArgumentPrefixModifierName(prefixModifier) + ' ' +
                         GetCSharpArgumentTypeName(type) + ' ' + name + ";\n";
    return result;
}
