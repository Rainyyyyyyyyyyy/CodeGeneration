#include "CSharpPrintOperatorUnit.h"

CSharpPrintOperatorUnit::CSharpPrintOperatorUnit(const std::string &text) : IPrintOperatorUnit(text) {}

std::string CSharpPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine(\"" + text + "\");\n";
}

