#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "IClassUnit.h"


class CppClassUnit : public IClassUnit {
private:
    static const std::vector<std::string> AccessModifierNames;
    using Fields = std::vector < std::shared_ptr < Unit > >;
    std::vector<Fields> Members; // вектор векторов, 
                        // где каждый внутренний вектор содержит элементы класса
                        // для определенного модификатора доступа

public:

    ~CppClassUnit() override;
    CppClassUnit(const std::string &name,
                 Modifiers::ClassModifiers AccMod = Modifiers::ClassModifiers::UNDEFINED)
        : IClassUnit(name), Members(AccessModifierNames.size()) {}
    
    void add(const std::shared_ptr <Unit> &unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
    
};


#endif // CPPCLASSUNIT_H