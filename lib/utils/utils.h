#ifndef UTILS_H
#define UTILS_H

#include "Modifiers.h"

#include <string>
#include <vector>



/*
AccessModifiers //
MethodPrefixModifiers
ClassPrefixModifiers //
ArgumentTypes //
ArgumentPrefixModifiers
*/
// получить строку с названием из enum ArgumentTypes
std::string GetArgumentTypeName(Modifiers::ArgumentTypes type);

// получить строку с названием из enum AccessModifiers
std::string GetAccessModifierName(Modifiers::AccessModifiers accessModifier);

// получить строку с названием из enum ClassPrefixModifiers
std::string GetClassPrefixModifierName(Modifiers::ClassPrefixModifiers classPrefixModifier);

// получить строку с названием из enum MethodPrefixModifiers
std::string GetMethodPrefixModifierName(Modifiers::MethodPrefixModifiers methodPrefixModifier);

// получить строку с названием из enum ArgumentPrefixModifiers
std::string GetArgumentPrefixModifierName(Modifiers::ArgumentPrefixModifiers argumentPrefixModifier);


// проверка имени аргумента функции\поля класса
bool IsValidVariableName(const std::string &name);

// проверка имени класса
bool IsValidClassOrMethodName(const std::string &name);


#endif // UTILS_H