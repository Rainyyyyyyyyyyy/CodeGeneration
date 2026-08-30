#ifndef UTILS_H
#define UTILS_H

#include "Modifiers.h"

#include <string>
#include <vector>

using namespace Modifiers;


// получить строку с названием из enum ArgumentTypes
std::string GetArgumentTypeName(ArgumentTypes type);

// получить строку с названием из enum AccessModifiers
std::string GetAccessModifierName(AccessModifiers accessModifier);

// проверка имени аргумента функции\поля класса
bool IsValidVariableName(const std::string &name);


#endif // UTILS_H