#include "Modifiers.h"

#include <string>
#include <vector>

using namespace Modifiers;


// получить строку с названием из enum ArgumentTypes
std::string GetArgumentTypeName(ArgumentTypes type);


std::vector<char> InvalidSymbolsForArgumentName = {' ', '\t', '\n', '\r', '\f', '\v', '\0',
                                                   '_', '"', '\'', '\\', '!', '@', '#', '$', '*', '%', '^', '&', '(', ')',
                                                   '-', '+', '=', '[', ']', '{', '}', '|', '/', '?', ';', ':', '<', '>',
                                                   ',', '.', '~', '`'}; // список символов, которые не должны быть в
                                                                        // имени переменной\аргумента функции


// проверка имени аргумента функции\поля класса
bool IsValidVariableName(const std::string &name);