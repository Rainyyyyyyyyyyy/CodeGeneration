#ifndef IMETHODUNIT_H
#define IMETHODUNIT_H

#include "Unit.h"
#include "Modifiers.h"
#include "IMethodArgumentUnit.h"

class IMethodUnit : public Unit {         // класс для конструкции "метод класса"
protected:
    std::string name;                   // название метода
    Modifiers::AccessModifiers accessModifier;      // модификатор доступа
    std::vector<std::shared_ptr<IMethodArgumentUnit>> arguments; // вектор аргументов
    std::vector<std::shared_ptr<Unit>> body; // тело метода (вектор вложенных элементов)
    ArgumentTypes returnType;       // тип возвращаемого значения

public:

    IMethodUnit(const std::string &name, const ArgumentTypes &returnType,
                const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::PRIVATE)
        : name(name), returnType(returnType),
          accessModifier(accessModifier) {}

    std::string getName() const;
    const std::vector<std::shared_ptr<Unit>>& getBody() const;
    AccessModifiers getAccessModifier() const;
    ArgumentTypes getReturnType() const;
    const std::vector<std::shared_ptr<IMethodArgumentUnit>>& getArguments() const;

    std::string compile(unsigned int level = 0) const = 0;
    void addArgument(const std::shared_ptr<IMethodArgumentUnit>& argument);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
};


#endif // IMETHODUNIT_H