#ifndef CPPPRINTOPERATOR_H
#define CPPPRINTOPERATOR_H

#include "IPrintOperatorUnit.h"

class CppPrintOperatorUnit : public IPrintOperatorUnit
{
public:
    explicit CppPrintOperatorUnit(const std::string &text);
    std::string compile(unsigned int level) const override;
};
#endif // CPPPRINTOPERATOR_H