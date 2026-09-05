#ifndef MODIFIERS_H
#define MODIFIERS_H

#include "Unit.h"

namespace Modifiers
{
    enum class AccessModifiers : Unit::Flags
    { // модификаторы доступа член-функций и член-данных
        UNDEFINED = 0,
        PRIVATE = 1,                               // C++ C# Java
        PROTECTED = 1 << 1,                        // C++ C# Java
        PRIVATE_PROTECTED = PRIVATE | PROTECTED,   // C#
        FILE = 1 << 2,                             // C#
        INTERNAL = 1 << 3,                         // C#
        PROTECTED_INTERNAL = PROTECTED | INTERNAL, // C#
        PUBLIC = 1 << 4                            // C++ C# Java
    };

    enum class MethodPrefixModifiers : Unit::Flags
    {                                    // модификаторы методов
        UNDEFINED = 0,                   // будет обрабатываться как "ничего"
        STATIC = 1 << 0,                 // C++ C# Java
        CONST = 1 << 1,                  // C++ C#
        VIRTUAL = 1 << 2,                // C++ C# (только методы)
        VIRTUAL_CONST = VIRTUAL | CONST, // C++
        STATIC_CONST = STATIC | CONST,   // C++
    };
    // enum class MethodPostfixModifiers : Unit::Flags
    // { // постфиксы для методов
    //     // В КОНСТРУКТОРАХ РЕАЛИЗАЦИЙ (Cpp-, JAva-, Cs-MethodUnit рассмотреть невозможные комбинации и 
    //     //выбрасывать исключения!!!!!!!!!!//)
    //     UNDEFINED = 0, // будет обрабатываться как "ничего"
    //     CONST = 1 << 0,  // C++ C#
    //     FINAL = 1 << 3
    // };

    enum class ClassPrefixModifiers : Unit::Flags
    {                      // модификаторы классов
        UNDEFINED = 0,     // будет обрабатываться как "ничего"
        ABSTRACT = 1 << 5, // C#, Java
        FINAL = 1 << 6,    // C#, Java
    };

    // enum class ClassPostfixModifiers : Unit::Flags
    // {
    //     UNDEFINED = 0, // будет обрабатываться как "ничего"
    //     FINAL = 1 << 9,
    // };

    enum class ArgumentTypes : Unit::Flags
    { // типы аргументов функции
        UNDEFINED = 0,
        INT = 1,
        DOUBLE = 2,
        CHAR = 3,
        STRING = 4,
        BOOL = 5,
        VOID = 6
    };

    enum class ArgumentPrefixModifiers : Unit::Flags
    { // префиксы аргументов функции
        UNDEFINED = 0,
        STATIC = 1 << 0,               // C++ C# Java
        CONST = 1 << 1,                // C++ C#
        STATIC_CONST = STATIC | CONST, // C++
        MUTABLE = 1 << 2,              // C++
        FINAL = 1 << 3,                // Java (для полей)
        STATIC_FINAL = STATIC | FINAL, // Java
        READONLY = 1 << 4              // C# 
    };

} // Modifiers

#endif // MODIFIERS_H
