#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include "IPrintOperatorUnit.h"

class JavaPrintOperatorUnit : public IPrintOperatorUnit
{
public:
    JavaPrintOperatorUnit(const std::string &text);
    std::string compile(unsigned int level) const override;

private:
    std::string text;
};

#endif // JAVAPRINTOPERATORUNIT_H