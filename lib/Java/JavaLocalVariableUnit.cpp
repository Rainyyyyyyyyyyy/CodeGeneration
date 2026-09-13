#include "JavaLocalVariableUnit.h"

#include "utils.h"
#include "JavaUtils.h"

#include <stdexcept>

#include <iostream>


// namespace {
//     size_t GetArgumentTypeIndex(const Modifiers::ArgumentTypes &type)
//     {
//         return static_cast<size_t>(type);
//     }

//     size_t GetArgumentPrefixModifierIndex(const Modifiers::ArgumentPrefixModifiers &modifier)
//     {
//         return static_cast<size_t>(modifier);
//     }
// }


// const static std::vector<std::string> ArgumentTypesNames = {"int", "double", "char", "String", "boolean"};
// const static std::vector<std::string> ArgumentPrefixModifierNames = {"static", "final", "static final"};


JavaLocalVariableUnit::JavaLocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                         const Modifiers::ArgumentPrefixModifiers &prefixModifier)
                         : ILocalVariableUnit(name, type, prefixModifier) {}



std::string JavaLocalVariableUnit::compile(unsigned int level) const
{
    if (IsValidVariableName(name) == false)
    {
        throw std::invalid_argument("Invalid variable name: " + name);
    }
    std::string result = generateShift(level) + GetJavaArgumentPrefixModifierName(prefixModifier) + " " + GetJavaArgumentTypeName(type) + " " + name + ";\n";
    return result;
}
