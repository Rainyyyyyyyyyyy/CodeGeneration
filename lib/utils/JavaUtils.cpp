#include "JavaUtils.h"
#include <stdexcept>


std::string GetJavaArgumentTypeName(const Modifiers::ArgumentTypes &type)
{
    switch (type)
    {
    case Modifiers::ArgumentTypes::VOID:
        return "void";
    case Modifiers::ArgumentTypes::INT:
        return "int";
    case Modifiers::ArgumentTypes::DOUBLE:
        return "double";
    case Modifiers::ArgumentTypes::CHAR:
        return "char";
    case Modifiers::ArgumentTypes::STRING:
        return "String";
    case Modifiers::ArgumentTypes::BOOL:
        return "boolean";
    default:
        throw std::invalid_argument("Invalid argument type");
    }
}


std::string GetJavaAccessModifierName(const Modifiers::AccessModifiers &accessModifier)
{
    switch (accessModifier)
    {
    case Modifiers::AccessModifiers::PUBLIC:
        return "public";
    case Modifiers::AccessModifiers::PROTECTED:
        return "protected";
    case Modifiers::AccessModifiers::PRIVATE:
        return "private";
    case Modifiers::AccessModifiers::UNDEFINED:
        return "";
    default:
        throw std::invalid_argument("Invalid access modifier");
    }
}

std::string GetJavaClassPrefixModifierName(const Modifiers::ClassPrefixModifiers &classPrefixModifier)
{
    switch (classPrefixModifier)
    {
    case Modifiers::ClassPrefixModifiers::UNDEFINED:
        return "";
    case Modifiers::ClassPrefixModifiers::ABSTRACT:
        return "abstract";
    case Modifiers::ClassPrefixModifiers::FINAL:
        return "final";
    default:
        throw std::invalid_argument("Invalid class prefix modifier");
    }
}

std::string GetJavaMethodPrefixModifierName(const Modifiers::MethodPrefixModifiers &methodPrefixModifier){
    switch(methodPrefixModifier){
        case Modifiers::MethodPrefixModifiers::UNDEFINED:
            return "";
        case Modifiers::MethodPrefixModifiers::STATIC:
            return "static";
        case Modifiers::MethodPrefixModifiers::FINAL:
            return "final";
        case Modifiers::MethodPrefixModifiers::STATIC_FINAL:
            return "static final";
        default: 
            throw std::invalid_argument("Invalid method prefix modifier");
    }
}

std::string GetJavaArgumentPrefixModifierName(const Modifiers::ArgumentPrefixModifiers &argumentPrefixModifier){
    switch(argumentPrefixModifier){
        case Modifiers::ArgumentPrefixModifiers::UNDEFINED:
            return "";
        case Modifiers::ArgumentPrefixModifiers::FINAL:
            return "final";
        case Modifiers::ArgumentPrefixModifiers::STATIC:
            return "static";
        case Modifiers::ArgumentPrefixModifiers::STATIC_FINAL:
            return "static final";
        default:
            throw std::invalid_argument("Invalid argument prefix modifier");
    }
}