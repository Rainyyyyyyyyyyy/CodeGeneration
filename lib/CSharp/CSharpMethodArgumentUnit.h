#ifndef CSHARP_METHODARGUMENTUNIT_H
#define CSHARP_METHODARGUMENTUNIT_H

#include "IMethodArgumentUnit.h"

class CSharpMethodArgumentUnit : public IMethodArgumentUnit
{
private:
    // Modifiers::AccessModifiers accessModifier;
public:
    explicit CSharpMethodArgumentUnit(const std::string &name,
                                   const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                   const Modifiers::ArgumentPrefixModifiers &argumentPrefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    ~CSharpMethodArgumentUnit() override = default;


    //void SetAccessModifier(const Modifiers::AccessModifiers &accessModifier) { this->accessModifier = accessModifier; }
    // inline const Modifiers::AccessModifiers &GetAccessModifier() const { return accessModifier; }

    std::string compile(unsigned int level) const override;
    
};

#endif // CSHARP_METHODARGUMENTUNIT_H