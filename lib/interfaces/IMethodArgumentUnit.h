#ifndef IFUUCARGUMENT_H
#define IFUNCARGUMENT_H

#include <string>
#include <vector>
#include <stdexcept>


#include "Modifiers.h"
#include "Unit.h";
#include "utils.h"



class IMethodArgumentUnit : public Unit {         // класс для конструкции "аргумент функции"
private:

    std::string type;           // тип
    std::string name;           // название
    
public:

    IMethodArgumentUnit(const std::string &name, const ArgumentTypes& type){
        if(IsValidVariableName(name) == false){     // если имя некорректно, то исключение
            throw std::invalid_argument("Invalid argument name: " + name);
        }
        this->type = GetArgumentTypeName(type);
        this->name = name;
    }

};



#endif // IFUNCARGUMENT_H