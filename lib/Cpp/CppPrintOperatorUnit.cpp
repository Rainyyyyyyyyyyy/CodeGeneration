#include "CppPrintOperatorUnit.h"

CppPrintOperatorUnit::CppPrintOperatorUnit(const std::string &text) : IPrintOperatorUnit(text) {}

std::string CppPrintOperatorUnit::compile(unsigned int level) const
{
    if (text.empty())
    {   // если текст для вывода пуст, то выводим просто std::cout<<std::endl;
        return generateShift(level) + "std::cout<<std::endl;\n";
    }

    return generateShift(level) + "std::cout<<\"" + text + "\"<<std::endl;\n";
}