#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "IClassUnit.h"


class CppClassUnit : public IClassUnit {
private:
    static const std::vector<std::string> AccessModifierNames;
    using Fields = std::vector < std::shared_ptr < Unit > >;
    std::vector<Fields> fields;

public:

    ~CppClassUnit() override;
    CppClassUnit(const std::string &name,
                 Modifiers::ClassModifiers AccMod = Modifiers::ClassModifiers::UNDEFINED)
        : IClassUnit(name), fields(3) {}
    
    void add(const std::shared_ptr <Unit> &unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
    
};


#endif // CPPCLASSUNIT_H