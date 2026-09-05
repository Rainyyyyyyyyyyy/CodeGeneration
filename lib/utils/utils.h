#ifndef UTILS_H
#define UTILS_H

#include "Modifiers.h"

#include <string>
#include <vector>

using namespace Modifiers;

/*
AccessModifiers //
MethodPrefixModifiers
ClassPrefixModifiers //
ArgumentTypes //
ArgumentPrefixModifiers
*/
// получить строку с названием из enum ArgumentTypes
std::string GetArgumentTypeName(ArgumentTypes type);

// получить строку с названием из enum AccessModifiers
std::string GetAccessModifierName(AccessModifiers accessModifier);

// получить строку с названием из enum ClassPrefixModifiers
std::string GetClassPrefixModifierName(ClassPrefixModifiers classPrefixModifier);

// получить строку с названием из enum MethodPrefixModifiers
std::string GetMethodPrefixModifierName(MethodPrefixModifiers methodPrefixModifier);

// получить строку с названием из enum ArgumentPrefixModifiers
std::string GetArgumentPrefixModifierName(ArgumentPrefixModifiers argumentPrefixModifier);


// проверка имени аргумента функции\поля класса
bool IsValidVariableName(const std::string &name);

// проверка имени класса
bool IsValidClassOrMethodName(const std::string &name);


#endif // UTILS_H