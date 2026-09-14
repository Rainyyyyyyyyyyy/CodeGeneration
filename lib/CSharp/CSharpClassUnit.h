#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H

#include <vector>

#include "IClassUnit.h"

class CSharpClassUnit : public IClassUnit
{
private:
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> Members;             // вектор,
                                 // где каждый внутренний вектор содержит элементы класса
                                 // для определенного модификатора доступа

public:
    ~CSharpClassUnit() override = default;

    explicit CSharpClassUnit(const std::string &name,
                           const Modifiers::ClassPrefixModifiers &classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED);

    void addMember(const std::shared_ptr<Unit> &unit,
                   const Modifiers::AccessModifiers &accessModifier) override;
    std::string compile(unsigned int level = 0) const override;
};

#endif // CSHARPCLASSUNIT_H