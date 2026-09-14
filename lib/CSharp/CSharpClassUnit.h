#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H

#include <vector>

#include "IClassUnit.h"

class CSharpClassUnit : public IClassUnit
{
private:
    // static const std::vector<std::string> AccessModifierNames;
    // static const std::vector<std::string> ClassPrefixModifierNames;

    // Modifiers::ClassPrefixModifiers classPrefixModifier; // префик класса (abstract, final, "")
    // Modifiers::AccessModifiers AccessModifier;             // модификатор доступа (public, private, protected)
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> Members;             // вектор,
                                 // где каждый внутренний вектор содержит элементы класса
                                 // для определенного модификатора доступа

public:
    ~CSharpClassUnit() override = default;

    explicit CSharpClassUnit(const std::string &name,
                           const Modifiers::ClassPrefixModifiers &classPrefixModifier = Modifiers::ClassPrefixModifiers::UNDEFINED
                           // const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED
                           );

    void addMember(const std::shared_ptr<Unit> &unit,
                   const Modifiers::AccessModifiers &accessModifier) override;
    std::string compile(unsigned int level = 0) const override;
};

#endif // CSHARPCLASSUNIT_H