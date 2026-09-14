#ifndef IFIELDUNIT_H
#define IFIELDUNIT_H

#include "Unit.h"
#include "Modifiers.h"

#include <string>

class IFieldUnit : public Unit
{ // класс для конструкции "поле класса"
protected:
    Modifiers::ArgumentTypes type;                     // тип
    std::string name;                                  // название
    Modifiers::ArgumentPrefixModifiers prefixModifier; // префикс аргумента (static, const, ...)

public:
    explicit IFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                        const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    virtual ~IFieldUnit() = default;

    inline const std::string &GetName() const { return name; }
    void SetName(const std::string &name);

    inline const Modifiers::ArgumentTypes &GetType() const { return type; }
    void SetType(const Modifiers::ArgumentTypes &type);

    inline const Modifiers::ArgumentPrefixModifiers &GetPrefixModifier() const { return prefixModifier; }
    void SetPrefixModifier(const Modifiers::ArgumentPrefixModifiers &prefixModifier);

    virtual std::string compile(unsigned int level = 0) const = 0;
};

#endif // IFIELDUNIT_H