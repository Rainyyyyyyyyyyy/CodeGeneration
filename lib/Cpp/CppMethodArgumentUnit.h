#ifndef CPPMETHODARGUMENTUNIT_H
#define CPPMETHODARGUMENTUNIT_H


#include "IMethodArgumentUnit.h"

class CppMethodArgumentUnit : public IMethodArgumentUnit {
    public:

    CppMethodArgumentUnit(const std::string &name, const ArgumentTypes& type)
        : IMethodArgumentUnit(name, type) {}


    std::string compile(unsigned int level) const override;
};

#endif // CPPMETHODARGUMENTUNIT_H