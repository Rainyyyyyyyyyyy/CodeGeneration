#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "IMethodUnit.h"

class CSharpMethodUnit : public IMethodUnit
{
private:
    //Modifiers::AccessModifiers accessModifier; // модификатор доступа
public:
    explicit CSharpMethodUnit(const std::string &name, const Modifiers::ArgumentTypes &returnType,
        const Modifiers::MethodPrefixModifiers &methodPrefixModifier = Modifiers::MethodPrefixModifiers::UNDEFINED
        // const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED
        );

    ~CSharpMethodUnit() override = default;

    //void SetAccessModifier(const Modifiers::AccessModifiers &accessModifier) { this->accessModifier = accessModifier; }
    //inline const Modifiers::AccessModifiers &GetAccessModifier() const { return accessModifier; }

    std::string compile(unsigned int level) const override;
};

#endif // CSHARPMETHODUNIT_H