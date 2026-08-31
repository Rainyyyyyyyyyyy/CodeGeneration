#ifndef MODIFIERS_H
#define MODIFIERS_H

#include "Unit.h"

namespace Modifiers{
    enum class AccessModifiers : Unit::Flags {   // модификаторы доступа член-функций и член-данных
        UNDEFINED = 0,
        PRIVATE = 1,                    // C++ C# Java
        PRIVATE_PROTECTED = 1<<1,       // C#
        FILE = 1<<2,                    // C#
        PROTECTED = 1<<3,               // C++ C# Java
        INTERNAL = 1<<4,                // C#
        PROTECTED_INTERNAL = 1<<5,      // C#
        PUBLIC = 1<<6                   // C++ C# Java
    };

    enum class MethodModifiers : Unit::Flags{  // модификаторы методов
        UNDEFINED = 0,                         
        STATIC = 1 << 0,                                     
        CONST = 1 << 1,                                      
        VIRTUAL = 1 << 2,                                    
        FINAL = 1 << 3,                                      
        ABSTRACT = 1 << 4,                                  
        STATIC_CONST = STATIC | CONST,                          //  STATIC + CONST
    //STATIC_VIRTUAL = STATIC | VIRTUAL,                      // STATIC + VIRTUAL
    //STATIC_FINAL = STATIC | FINAL,                          // STATIC + FINAL
    //STATIC_ABSTRACT = STATIC | ABSTRACT,                    // STATIC + ABSTRACT
        STATIC_FINAL_ABSTRACT = STATIC | FINAL | ABSTRACT,      // STATIC + FINAL + ABSTRACT
        FINAL_CONST = FINAL | CONST,                            // FINAL + CONST
    //FINAL_ABSTRACT = FINAL | ABSTRACT                       // FINAL + ABSTRACT
        VIRTUAL_CONST = VIRTUAL | CONST,                        // VIRTUAL + CONST
        VIRTUAL_FINAL = VIRTUAL | FINAL,                        // VIRTUAL + FINAL
        VIRTUAL_ABSTRACT = VIRTUAL | ABSTRACT,                  // VIRTUAL + ABSTRACT
        VIRTUAL_CONST_ABSTRACT = VIRTUAL | CONST | ABSTRACT     // VIRTUAL + CONST + ABSTRACT
    };

    enum class ClassModifiers : Unit::Flags{  // модификаторы классов
        UNDEFINED = 0,
        ABSTRACT = 1 << 5,
        FINAL = 1 << 6,
        ABSTRACT_FINAL = ABSTRACT | FINAL
    };


    enum class ArgumentTypes : Unit::Flags{  // типы аргументов функции
        UNDEFINED = 0,
        INT = 1,
        DOUBLE = 2,
        CHAR = 3,
        STRING = 4,
        BOOL = 5
    };
    
} // Modifiers





#endif // MODIFIERS_H
