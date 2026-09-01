#ifndef IMETHODARGUMENTUNIT_H
#define IMETHODARGUMENTUNIT_H

#include <string>
#include <vector>
#include <stdexcept>

#include "Modifiers.h"
#include "Unit.h"
#include "utils.h"

class IMethodArgumentUnit : public Unit
{ // класс для конструкции "аргумент функции"
protected:
    ArgumentTypes type; // тип
    std::string name;   // название
    ArgumentPrefixModifiers prefixModifier; // префикс аргумента (static, const, ...)

public:
    explicit IMethodArgumentUnit(const std::string &name,
                                 const ArgumentTypes &type = ArgumentTypes::UNDEFINED,
                                 const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    virtual ~IMethodArgumentUnit() = default;

    ArgumentTypes getType() const;
    std::string getName() const;
    ArgumentPrefixModifiers getPrefixModifier() const;

    std::string compile(unsigned int level = 0) const = 0;
};

#endif // IMETHODARGUMENTUNIT_H