#ifndef MODIFIERS_H
#define MODIFIERS_H

#include "Unit.h"

namespace Modifiers
{
    enum class AccessModifiers : unsigned int
    { // модификаторы доступа член-функций и член-данных
        UNDEFINED = 0,
        PRIVATE = 1,                               // C++ C# Java
        PROTECTED = 1 << 1,                        // C++ C# Java
        PRIVATE_PROTECTED = PRIVATE | PROTECTED,   // C#
        INTERNAL = 1 << 3,                         // C#
        PROTECTED_INTERNAL = PROTECTED | INTERNAL, // C#
        PUBLIC = 1 << 4                            // C++ C# Java
    };

    enum class MethodPrefixModifiers : unsigned int
    {                                    // модификаторы методов
        UNDEFINED = 0,                   // C++ C# Java будет обрабатываться как "ничего"
        STATIC = 1 << 0,                 // C++ C# Java
        CONST = 1 << 1,                  // C++
        VIRTUAL = 1 << 2,                // C++ C#
        FINAL = 1 << 3,                  // Java
        VIRTUAL_CONST = VIRTUAL | CONST, // C++
        STATIC_CONST = STATIC | CONST,   // C++
        STATIC_FINAL = STATIC | FINAL    // Java
    };

    enum class ClassPrefixModifiers : unsigned int
    {                      // модификаторы классов
        UNDEFINED = 0,     // будет обрабатываться как "ничего"
        ABSTRACT = 1 << 5, // C#, Java
        FINAL = 1 << 6,    // C#, Java
    };

    enum class ArgumentTypes : unsigned int
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
        FINAL = 1 << 3,                // Java
        STATIC_FINAL = STATIC | FINAL, // Java
        READONLY = 1 << 4              // C#
    };

} // Modifiers

#endif // MODIFIERS_H
