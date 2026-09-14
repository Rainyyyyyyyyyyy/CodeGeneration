#ifndef ICLASSUNIT_H
#define ICLASSUNIT_H

#include <memory>


#include "Unit.h"
#include "Modifiers.h"

class IClassUnit : public Unit
{

public:
    explicit IClassUnit(const std::string &name, 
                        const Modifiers::ClassPrefixModifiers &classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED);

    virtual ~IClassUnit() = default;
    virtual std::string compile(unsigned int level = 0) const override = 0;

    virtual void addMember(const std::shared_ptr<Unit> &unit,
                           const Modifiers::AccessModifiers &accessModifier) = 0;

    inline const Modifiers::ClassPrefixModifiers &GetClassPrefix() const { return classPrefixModifier; }
    void SetClassPrefix(const Modifiers::ClassPrefixModifiers &classPrefixModifier);

    inline const std::string &GetName() const { return name; }
    void SetName(const std::string &name);

protected:
    std::string name; // имя класса
    Modifiers::ClassPrefixModifiers classPrefixModifier;        // префик класса (abstract, final, "")
};

#endif // ICLASSUNIT_H