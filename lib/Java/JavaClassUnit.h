#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "IClassUnit.h"

class JavaClassUnit : public IClassUnit
{
private:
    static const std::vector<std::string> AccessModifierNames;
    static const std::vector<std::string> ClassPrefixModifierNames;

    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> Members; // вектор векторов,
                                 // где каждый внутренний вектор содержит элементы класса
                                 // для определенного модификатора доступа

public:
    ~JavaClassUnit() override = default;

    explicit JavaClassUnit(const std::string &name,
                           Modifiers::ClassPrefixModifiers classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED);

    void add(const std::shared_ptr<Unit> &unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;
};

#endif // JAVACLASSUNIT_H