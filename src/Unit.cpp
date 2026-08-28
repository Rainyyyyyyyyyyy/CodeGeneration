#include "Unit.h"
#include <stdexcept>
    //Unit::~Unit() = default;
    /* add() - Виртуальная функция-член предназначена для добавления
            вложенных элементов (передача происходит через умный указатель)
            умный указатель std::shared_ptr).
    Также эта функция принимает параметр Flags.
    По умолчанию add() выбрасывает исключение.
    */
    void Unit::add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error( "Not supported" );
    }

    /* Compile() - Функция генерирует код на C++, соответствующий
            содержимому элемента.
        Результат возвращается в виде строки std::string.
        В качестве аргумента функция принимает параметр level, указывающий
            на уровень вложенности узла дерева.
        Это требуется для корректной расстановки отступов
            в начале строк генерируемого кода.
     */
    //std::string Unit::compile( unsigned int level = 0 ) const = 0;

    /* generateShift() - Вспомогательная функция-член всего лишь
            возвращает строку, состоящую из нужного числа пробелов. Результат
            зависит от уровня вложенности.
    */
    std::string Unit::generateShift( unsigned int level ) const {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
