#include "CppMethodArgumentUnit.h"

std::string CppMethodArgumentUnit::compile(unsigned int level) const {
    
        std::string result = generateShift(level)
            + GetArgumentTypeName(type) 
            + " " + getName();
        
            return result;    
    }