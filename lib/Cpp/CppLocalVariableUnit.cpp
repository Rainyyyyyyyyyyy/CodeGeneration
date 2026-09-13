#include "CppLocalVariableUnit.h"

#include "utils.h"

namespace {
    size_t GetArgumentTypeIndex(const Modifiers::ArgumentTypes &type)
    {
        return static_cast<size_t>(type);
    }

    size_t GetArgumentPrefixModifierIndex(const Modifiers::ArgumentPrefixModifiers &modifier)
    {
        return static_cast<size_t>(modifier);
    }
}

/*enum class ArgumentTypes : unsigned int
    { // типы аргументов функции
        UNDEFINED = 0,
        INT = 1,
        DOUBLE = 2,
        CHAR = 3,
        STRING = 4,
        BOOL = 5,
        VOID = 6
    };

    enum class ArgumentPrefixModifiers : unsigned int
    { // префиксы аргументов функции
        UNDEFINED = 0,
        STATIC = 1 << 0,               // C++ C# Java
        CONST = 1 << 1,                // C++ C#
        STATIC_CONST = STATIC | CONST, // C++
        MUTABLE = 1 << 2,              // C++
        FINAL = 1 << 3,                // Java (для полей)
        STATIC_FINAL = STATIC | FINAL, // Java
        READONLY = 1 << 4              // C# 
    };*/
const std::vector<std::string> CppLocalVariableUnit::ArgumentTypesNames = {
    "undefined", // 0
    "int",       // 1
    "double",    // 2
    "char",      // 3
    "std::string", // 4
    "bool",      // 5
    "void"       // 6
};
const std::vector<std::string> CppLocalVariableUnit::ArgumentPrefixModifierNames = {
    "undefined", // 0
    "static",    // 1
    "const",     // 2
    "static const", // 3
    "mutable"    // 4
};
CppLocalVariableUnit::CppLocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                         const Modifiers::ArgumentPrefixModifiers &prefixModifier)
                         : ILocalVariableUnit(name, type, prefixModifier) {}

std::string CppLocalVariableUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    // Handle prefix modifiers
    /*if (prefixModifier == Modifiers::ArgumentPrefixModifiers::STATIC)
        result += "static ";
    else if (prefixModifier == Modifiers::ArgumentPrefixModifiers::CONST)
        result += "const ";
    else if (prefixModifier == Modifiers::ArgumentPrefixModifiers::STATIC_CONST)
        result += "static const ";
    else if (prefixModifier == Modifiers::ArgumentPrefixModifiers::MUTABLE)
        result += "mutable ";
    */
   result += GetArgumentPrefixModifierName(prefixModifier) + " " + GetArgumentTypeName(type) + " " + name + ";\n";
    // Handle type
    /*switch (type)
    {
        case Modifiers::ArgumentTypes::INT:
            result += "int ";
            break;
        case Modifiers::ArgumentTypes::DOUBLE:
            result += "double ";
            break;
        case Modifiers::ArgumentTypes::CHAR:
            result += "char ";
            break;
        case Modifiers::ArgumentTypes::STRING:
            result += "std::string ";
            break;
        case Modifiers::ArgumentTypes::BOOL:
            result += "bool ";
            break;
        case Modifiers::ArgumentTypes::VOID:
            result += "void ";
            break;
        default:
            result += "auto "; // Default to auto for undefined types
            break;
    }
    */
    // Add variable name and semicolon
    //result += name + ";";

    return result;
}