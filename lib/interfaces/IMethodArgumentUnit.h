#ifndef IMETHODARGUMENTUNIT_H
#define IMETHODARGUMENTUNIT_H

#include <string>
#include <vector>

#include "Modifiers.h"
#include "Unit.h"

class IMethodArgumentUnit : public Unit
{ // класс для конструкции "аргумент функции"
protected:
    Modifiers::ArgumentTypes type; // тип
    std::string name;   // название
    Modifiers::ArgumentPrefixModifiers prefixModifier; // префикс аргумента (static, const, ...)

public:
    explicit IMethodArgumentUnit(const std::string &name,
                                 const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                 const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    virtual ~IMethodArgumentUnit() = default;

    inline const Modifiers::ArgumentTypes &GetType() const { return type; }
    void SetType(const Modifiers::ArgumentTypes &type);

    inline const std::string &GetName() const { return name; }
    void SetName(const std::string &name);
    
    inline const Modifiers::ArgumentPrefixModifiers &GetPrefixModifier() const { return prefixModifier; }
    void SetPrefixModifier(const Modifiers::ArgumentPrefixModifiers &prefixModifier);

    std::string compile(unsigned int level = 0) const = 0;
};

#endif // IMETHODARGUMENTUNIT_H