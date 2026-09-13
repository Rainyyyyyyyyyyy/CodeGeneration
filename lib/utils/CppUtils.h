#ifndef CPP_UTILS_H
#define CPP_UTILS_H

#include "Modifiers.h"

std::string GetCppArgumentTypeName(Modifiers::ArgumentTypes type);

const std::string GetCppArgumentPrefixModifierName(const Modifiers::ArgumentPrefixModifiers &modifier);

#endif // CPP_UTILS_H

// std::string GetCppAccessModifierName(Modifiers::AccessModifiers accessModifier)
// {
//     switch (accessModifier)
//     {
//     case Modifiers::AccessModifiers::PUBLIC:
//         return "public";
//     case Modifiers::AccessModifiers::PROTECTED:
//         return "protected";
//     case Modifiers::AccessModifiers::PRIVATE:
//         return "private";
//     default:
//         throw std::invalid_argument("Invalid access modifier"); // по умолчанию возвращаем private, если модификатор не определен
//     }
// }