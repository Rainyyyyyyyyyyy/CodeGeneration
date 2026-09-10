#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "IClassUnit.h"

class CppClassUnit : public IClassUnit
{
private:
    static const std::vector<std::string> AccessModifierNames;

    
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> Members; // вектор векторов,
                                 // где каждый внутренний вектор содержит элементы класса
                                 // для определенного модификатора доступа

public:
    ~CppClassUnit() override = default;

    //explicit CppClassUnit(const std::string &name,
    //                    Modifiers::ClassPrefixModifiers classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED);
    explicit CppClassUnit(const std::string& name,
            const Modifiers::ClassPrefixModifiers &classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED);
     
    void addMember(const std::shared_ptr<Unit> &unit,
                   Modifiers::AccessModifiers accessModifier) override;
    std::string compile(unsigned int level = 0) const override;
};

#endif // CPPCLASSUNIT_H