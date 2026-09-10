#ifndef ILOCALVARIABLEUNIT_H
#define ILOCALVARIABLEUNIT_H

#include "IStatementUnit.h"
#include "Modifiers.h"

class ILocalVariableUnit : public IStatementUnit
{ // класс для конструкции "локальная переменная"
protected:
    std::string name;                       // название
    Modifiers::ArgumentTypes type;                     // тип
    Modifiers::ArgumentPrefixModifiers prefixModifier; // префикс аргумента (static, const, ...)
public:
    ILocalVariableUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                       const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    virtual ~ILocalVariableUnit() = default;

    inline const Modifiers::ArgumentTypes &GetType() const { return type; }
    void SetType(const Modifiers::ArgumentTypes &type);

    inline const std::string &GetName() const { return name; }
    void SetName(const std::string &name);

    inline const Modifiers::ArgumentPrefixModifiers &GetPrefixModifier() const { return prefixModifier; }
    void SetPrefixModifier(const Modifiers::ArgumentPrefixModifiers &prefixModifier);

    virtual std::string compile(unsigned int level = 0) const override = 0;

};

#endif // ILOCALVARIABLEUNIT_H