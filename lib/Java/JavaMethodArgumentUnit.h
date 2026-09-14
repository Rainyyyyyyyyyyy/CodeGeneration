#ifndef JAVA_METHODARGUMENTUNIT_H
#define JAVA_METHODARGUMENTUNIT_H

#include "IMethodArgumentUnit.h"

class JavaMethodArgumentUnit : public IMethodArgumentUnit
{
private:
    // Modifiers::AccessModifiers accessModifier;
public:
    explicit JavaMethodArgumentUnit(const std::string &name,
                                   const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                   const Modifiers::ArgumentPrefixModifiers &argumentPrefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    ~JavaMethodArgumentUnit() override = default;


    //void SetAccessModifier(const Modifiers::AccessModifiers &accessModifier) { this->accessModifier = accessModifier; }
    // inline const Modifiers::AccessModifiers &GetAccessModifier() const { return accessModifier; }

    std::string compile(unsigned int level) const override;
    
};

#endif // JAVA_METHODARGUMENTUNIT_H