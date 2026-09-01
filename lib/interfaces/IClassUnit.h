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


    Modifiers::ClassPrefixModifiers GetClassPrefix() const;
    std::string getName() const;

protected:

    std::string name;                                           // имя класса
    Modifiers::ClassPrefixModifiers classPrefixModifier;        // префик класса (public, private, abstract ...)
    
        
};

#endif // ICLASSUNIT_H