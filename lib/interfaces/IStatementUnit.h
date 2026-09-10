#ifndef ISTATEMENTUNIT_H
#define ISTATEMENTUNIT_H

#include "Unit.h"

class IStatementUnit : public Unit
{ // базовый класс для конструкции "элемент тела функции"
// (оператор вывода, локальная переменная, ...( иные здесь не реализованы))
public:
    virtual ~IStatementUnit() override = default;

    std::string compile(unsigned int level = 0) const override = 0;

};

#endif // ISTATEMENTUNIT_H
