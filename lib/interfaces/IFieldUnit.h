#ifndef IFIELDUNIT_H
#define IFIELDUNIT_H

#include "Unit.h"
#include "Modifiers.h"
#include "utils.h"

#include <stdexcept>
#include <string>


class IFieldUnit : public Unit{     // класс для конструкции "поле класса"
protected:
    ArgumentTypes type;           // тип
    std::string name;           // название
    AccessModifiers accessModifier; // модификатор доступа (public, private, protected)



public:
    IFieldUnit(const std::string &name, const ArgumentTypes& type,
           const AccessModifiers& accessModifier = AccessModifiers::PRIVATE);

           
    Modifiers::AccessModifiers getAccessModifier() const;
    std::string getName() const;
    ArgumentTypes getType() const;

    std::string compile(unsigned int level = 0) const = 0;
};

#endif // IFIELDUNIT_H