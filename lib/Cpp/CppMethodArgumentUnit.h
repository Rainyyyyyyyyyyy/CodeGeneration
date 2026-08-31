#ifndef CPPMETHODARGUMENTUNIT_H
#define CPPMETHODARGUMENTUNIT_H

#include "IMethodArgumentUnit.h"

class CppMethodArgumentUnit : public IMethodArgumentUnit
{
public:
    explicit CppMethodArgumentUnit(const std::string &name,
                                   const ArgumentTypes &type = ArgumentTypes::UNDEFINED);

    ~CppMethodArgumentUnit() override = default;

    std::string compile(unsigned int level) const override;
};

#endif // CPPMETHODARGUMENTUNIT_H