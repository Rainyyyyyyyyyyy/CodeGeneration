
#include "CSharpUtils.h"
#include "Modifiers.h"

#include <stdexcept>

const std::string GetCSharpArgumentTypeName(const Modifiers::ArgumentTypes &type)
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

const std::string GetCSharpArgumentPrefixModifierName(const Modifiers::ArgumentPrefixModifiers &modifier)
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

const std::string GetCSharpMethodPrefixModifierName(const Modifiers::MethodPrefixModifiers &modifier)
{
    switch (modifier)
    {
    case Modifiers::MethodPrefixModifiers::UNDEFINED:
        return "";
    case Modifiers::MethodPrefixModifiers::STATIC:
        return "static";
    case Modifiers::MethodPrefixModifiers::VIRTUAL:
        return "virtual";
    default:
        throw std::invalid_argument("Invalid method prefix modifier");
    }
}

const std::string GetCSharpAccessModifierName(const Modifiers::AccessModifiers &modifier)
{
    switch (modifier)
    {
    case Modifiers::AccessModifiers::UNDEFINED:
        return "";
    case Modifiers::AccessModifiers::PUBLIC:
        return "public";
    case Modifiers::AccessModifiers::PROTECTED:
        return "protected";
    case Modifiers::AccessModifiers::PRIVATE:
        return "private";
    case Modifiers::AccessModifiers::INTERNAL:
        return "internal";
    case Modifiers::AccessModifiers::PROTECTED_INTERNAL:
        return "protected internal";
    case Modifiers::AccessModifiers::PRIVATE_PROTECTED:
        return "private protected";
    default:
        throw std::invalid_argument("Invalid access modifier");
    }
}
