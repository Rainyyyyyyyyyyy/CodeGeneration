#include "Unit.h"

/* generateShift() - Вспомогательная функция-член всего лишь
        возвращает строку, состоящую из нужного числа пробелов. Результат
        зависит от уровня вложенности.
*/
std::string Unit::generateShift(unsigned int level) const
{
    static const auto DEFAULT_SHIFT = " ";
    std::string result;
    for (unsigned int i = 0; i < level; ++i)
    {
        result += DEFAULT_SHIFT;
    }
    return result;
}
