#ifndef IMETHODARGUMENTUNIT_H
#define IMETHODARGUMENTUNIT_H

#include <string>
#include <vector>
#include <stdexcept>


#include "Modifiers.h"
#include "Unit.h"
#include "utils.h"



class IMethodArgumentUnit : public Unit {         // класс для конструкции "аргумент функции"
protected:

    ArgumentTypes type;           // тип
    std::string name;           // название
    
public:

    IMethodArgumentUnit(const std::string &name, const ArgumentTypes& type);

    virtual ~IMethodArgumentUnit() = default;

    ArgumentTypes getType() const;
    std::string getName() const;

    std::string compile(unsigned int level=0) const = 0;

};



#endif // IMETHODARGUMENTUNIT_H