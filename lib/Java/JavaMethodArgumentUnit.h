#ifndef JAVA_METHODARGUMENTUNIT_H
#define JAVA_METHODARGUMENTUNIT_H

#include "IMethodArgumentUnit.h"

class JavaMethodArgumentUnit : public IMethodArgumentUnit
{
private:
public:
    explicit JavaMethodArgumentUnit(const std::string &name,
                                   const Modifiers::ArgumentTypes &type = Modifiers::ArgumentTypes::UNDEFINED,
                                   const Modifiers::ArgumentPrefixModifiers &argumentPrefixModifier = Modifiers::ArgumentPrefixModifiers::UNDEFINED);

    ~JavaMethodArgumentUnit() override = default;



    std::string compile(unsigned int level) const override;
    
};

#endif // JAVA_METHODARGUMENTUNIT_H