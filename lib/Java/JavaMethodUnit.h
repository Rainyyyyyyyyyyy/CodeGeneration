#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include "IMethodUnit.h"

class JavaMethodUnit : public IMethodUnit
{
private:
    //Modifiers::AccessModifiers accessModifier; // модификатор доступа
public:
    explicit JavaMethodUnit(const std::string &name, const Modifiers::ArgumentTypes &returnType,
        const Modifiers::MethodPrefixModifiers &methodPrefixModifier = Modifiers::MethodPrefixModifiers::UNDEFINED
        // const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED
        );

    ~JavaMethodUnit() override = default;

    //void SetAccessModifier(const Modifiers::AccessModifiers &accessModifier) { this->accessModifier = accessModifier; }
    //inline const Modifiers::AccessModifiers &GetAccessModifier() const { return accessModifier; }

    std::string compile(unsigned int level) const override;
};

#endif // JAVAMETHODUNIT_H