#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H

#include "IPrintOperatorUnit.h"

class CSharpPrintOperatorUnit : public IPrintOperatorUnit
{
public:
    CSharpPrintOperatorUnit(const std::string &text);
    std::string compile(unsigned int level) const override;
};

#endif // CSHARPPRINTOPERATORUNIT_H