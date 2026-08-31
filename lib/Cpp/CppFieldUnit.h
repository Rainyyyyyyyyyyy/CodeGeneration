#ifndef CPPFIELDUNIT_H
#define CPPFIELDUNIT_H

#include "IFieldUnit.h"

class CppFieldUnit : public IFieldUnit
{
private:
    const static std::vector <std::string> AccessModifiersNames;
public:
    CppFieldUnit(const std::string &name, const ArgumentTypes &type,
                 const AccessModifiers &accessModifier = AccessModifiers::PRIVATE)
                 : IFieldUnit(name, type, accessModifier) {}

    std::string compile(unsigned int level) const;
};

#endif // CPPFIELDUNIT_H