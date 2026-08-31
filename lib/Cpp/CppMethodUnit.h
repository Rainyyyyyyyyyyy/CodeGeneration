#ifndef CPP_METHOD_UNIT_H
#define CPP_METHOD_UNIT_H

#include "IMethodUnit.h"


/*
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
*/
class CppMethodUnit : public IMethodUnit {
public:
    CppMethodUnit(const std::string &name, const ArgumentTypes &returnType,
                const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::PRIVATE)
        : IMethodUnit(name, returnType, accessModifier) {}
        
    ~CppMethodUnit() override = default;

    std::string compile(unsigned int level=0) const override;
};
#endif // CPP_METHOD_UNIT_H