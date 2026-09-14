#include "CppUtils.h"

#include <stdexcept>

const std::string GetCppArgumentTypeName(const Modifiers::ArgumentTypes &type)
{
    switch (type)
    {
    case Modifiers::ArgumentTypes::INT:
        return "int";
    case Modifiers::ArgumentTypes::DOUBLE:
        return "double";
    case Modifiers::ArgumentTypes::CHAR:
        return "char";
    case Modifiers::ArgumentTypes::STRING:
        return "std::string";
    case Modifiers::ArgumentTypes::BOOL:
        return "bool";
    case Modifiers::ArgumentTypes::VOID:
        return "void";
    default:
        throw std::invalid_argument("Invalid argument type"); // по умолчанию возвращаем int, если тип не определен
    }
}

const std::string GetCppArgumentPrefixModifierName(const Modifiers::ArgumentPrefixModifiers &modifier)
{
    switch (modifier)
    {
    case Modifiers::ArgumentPrefixModifiers::UNDEFINED:
        return "";
    case Modifiers::ArgumentPrefixModifiers::STATIC:
        return "static";
    case Modifiers::ArgumentPrefixModifiers::CONST:
        return "const";
    case Modifiers::ArgumentPrefixModifiers::STATIC_CONST:
        return "static const";
    case Modifiers::ArgumentPrefixModifiers::MUTABLE:
        return "mutable";
    default:
        throw std::invalid_argument("Invalid argument prefix modifier");
    }
}

const std::string GetCppMethodPrefixName(const Modifiers::MethodPrefixModifiers &modifier)
{
    switch (modifier)
    {
    case Modifiers::MethodPrefixModifiers::UNDEFINED:
        return "";
    case Modifiers::MethodPrefixModifiers::STATIC:
        return "static";
    case Modifiers::MethodPrefixModifiers::CONST:
        return "const";
    case Modifiers::MethodPrefixModifiers::VIRTUAL:
        return "virtual";
    case Modifiers::MethodPrefixModifiers::VIRTUAL_CONST:
        return "virtual const";
    case Modifiers::MethodPrefixModifiers::STATIC_CONST:
        return "static const";
    default:
        throw std::invalid_argument("Invalid method prefix modifier");
    }
}
