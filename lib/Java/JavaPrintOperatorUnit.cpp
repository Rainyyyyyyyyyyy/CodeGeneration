#include "JavaPrintOperatorUnit.h"

JavaPrintOperatorUnit::JavaPrintOperatorUnit(const std::string &text) : IPrintOperatorUnit(text) {}

std::string JavaPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println(\"" + text + "\");\n";
}

