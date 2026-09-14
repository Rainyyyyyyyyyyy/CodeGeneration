#ifndef UTILS_H
#define UTILS_H

#include "Modifiers.h"

#include <string>
#include <vector>



// проверка имени аргумента функции\поля класса
bool IsValidVariableName(const std::string &name);

// проверка имени класса
bool IsValidClassOrMethodName(const std::string &name);


#endif // UTILS_H