#ifndef IMETHODUNIT_H
#define IMETHODUNIT_H

#include <memory>

#include "Unit.h"
#include "Modifiers.h"
#include "IMethodArgumentUnit.h"
#include "IStatementUnit.h"

class IMethodUnit : public Unit
{ // класс для конструкции "метод класса"
protected:
    std::string name;                                            // название метода
    Modifiers::AccessModifiers accessModifier;                   // модификатор доступа
    Modifiers::MethodPrefixModifiers methodPrefixModifier;         // префикс метода (static, const, virtual ...)
    std::vector<std::shared_ptr<IMethodArgumentUnit>> arguments; // вектор аргументов
    std::vector<std::shared_ptr<IStatementUnit>> body;           // тело метода
    Modifiers::ArgumentTypes returnType;                                    // тип возвращаемого значения

public:
    explicit IMethodUnit(const std::string &name, const Modifiers::ArgumentTypes &returnType,
                         const Modifiers::AccessModifiers &accessModifier = Modifiers::AccessModifiers::UNDEFINED,
                         const Modifiers::MethodPrefixModifiers &methodPrefixModifier = Modifiers::MethodPrefixModifiers::UNDEFINED);

    virtual ~IMethodUnit() = default;

    inline const std::string &GetName() const { return name; }
    void SetName(const std::string &name){ this->name = name;}

    inline const std::vector<std::shared_ptr<IStatementUnit>> &GetBody() const { return body; }

    inline const Modifiers::AccessModifiers &GetAccessModifier() const { return accessModifier; }
    void SetAccessModifier(const Modifiers::AccessModifiers &accessModifier) { this->accessModifier = accessModifier;}

    inline const Modifiers::ArgumentTypes &GetReturnType() const { return returnType; }
    void SetReturnType(const Modifiers::ArgumentTypes &returnType);


    inline const Modifiers::MethodPrefixModifiers &GetMethodPrefixModifier() const { return methodPrefixModifier; }
    void SetMethodPrefixModifier(const Modifiers::MethodPrefixModifiers &methodPrefixModifier);
    
    inline const std::vector<std::shared_ptr<IMethodArgumentUnit>> &GetArguments() const { return arguments; }

    std::string compile(unsigned int level = 0) const = 0;
    void addArgument(const std::shared_ptr<IMethodArgumentUnit> &argument);
    void addBody(const std::shared_ptr<IStatementUnit> &statement);
};

#endif // IMETHODUNIT_H