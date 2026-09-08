#ifndef IFIELDUNIT_H
#define IFIELDUNIT_H

#include "Unit.h"
#include "Modifiers.h"

#include <string>

class IFieldUnit : public Unit
{ // класс для конструкции "поле класса"
protected:
    Modifiers::ArgumentTypes type;                     // тип
    std::string name;                       // название
    Modifiers::AccessModifiers accessModifier;         // модификатор доступа (public, private, protected)
    Modifiers::ArgumentPrefixModifiers prefixModifier; // префикс аргумента (static, const, ...)

public:
    explicit IFieldUnit(const std::string &name, const Modifiers::ArgumentTypes &type,
                        const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED,
                        const Modifiers::ArgumentPrefixModifiers &prefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    virtual ~IFieldUnit() = default;

    inline const Modifiers::AccessModifiers &GetAccessModifier() const { return accessModifier; }
    inline Unit::Flags GetAccessModifierAsFlags() const { return static_cast<Unit::Flags>(accessModifier); }
    void SetAccessModifier(const Modifiers::AccessModifiers &accessModifier);

    inline const Modifiers::ArgumentPrefixModifiers &GetPrefixModifier() const { return prefixModifier; }
    inline Unit::Flags GetPrefixModifierAsFlags() const { return static_cast<Unit::Flags>(prefixModifier); }
    void SetPrefixModifier(const Modifiers::ArgumentPrefixModifiers &prefixModifier);
        
    inline const std::string &GetName() const { return name; }
    void SetName(const std::string &name);

    inline const Modifiers::ArgumentTypes &GetType() const { return type; }
    inline Unit::Flags GetTypeAsFlags() const { return static_cast<Unit::Flags>(type); }
    void SetType(const Modifiers::ArgumentTypes &type);

    std::string compile(unsigned int level = 0) const = 0;
};

#endif // IFIELDUNIT_H