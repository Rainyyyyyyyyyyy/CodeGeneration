#ifndef ICLASSUNIT_H
#define ICLASSUNIT_H

#include <memory>
#include <vector>

#include "Unit.h"
#include "Modifiers.h"

class IClassUnit : public Unit {

public:
    explicit IClassUnit(const std::string& name,
            const Modifiers::ClassPrefixModifiers &classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED);

    virtual ~IClassUnit() = default;
    virtual std::string compile( unsigned int level = 0 ) const override = 0;

    virtual void add(const std::shared_ptr <Unit> &, Flags flags) = 0;


    inline const Modifiers::ClassPrefixModifiers &GetClassPrefix() const { return classPrefixModifier; }
    inline Unit::Flags GetClassPrefixAsFlags() const { return static_cast<Unit::Flags>(classPrefixModifier); }
    void SetClassPrefix(const Modifiers::ClassPrefixModifiers &classPrefixModifier);
    
    inline const Modifiers::AccessModifiers &GetAccessModifier() const { return AccessModifier; }
    inline Unit::Flags GetAccessModifierAsFlags() const { return static_cast<Unit::Flags>(AccessModifier); }
    void SetAccessModifier(const Modifiers::AccessModifiers &accessModifier);

    inline const std::string &GetName() const { return name; }
    void SetName(const std::string &name);

protected:

    std::string name;                                           // имя класса
    Modifiers::ClassPrefixModifiers classPrefixModifier;        // префик класса (abstract, final, "")
    Modifiers::AccessModifiers AccessModifier;                  // модификатор доступа (public
        
};

#endif // ICLASSUNIT_H