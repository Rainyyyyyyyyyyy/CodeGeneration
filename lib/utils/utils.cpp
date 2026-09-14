

#include "utils.h"

#include <stdexcept>

std::vector<char> InvalidSymbolsForArgumentName = {' ', '\t', '\n', '\r', '\f', '\v', '\0',
                                                   '_', '"', '\'', '\\', '!', '@', '#', '$', '*', '%', '^', '&', '(', ')',
                                                   '-', '+', '=', '[', ']', '{', '}', '|', '/', '?', ';', ':', '<', '>',
                                                   ',', '.', '~', '`'}; // список символов, которые не должны быть в
                                                                        // имени переменной\аргумента функции
bool IsValidVariableName(const std::string &name)
{
    if (name.empty())
        return false; // пустое имя
    if (name[0] == ' ')
        return false;
    if (name[0] >= '0' && name[0] <= '9')
        return false; // начинается с цифры

    size_t namesize = name.size();

    if (name[0] == '&')
    { // если первый символ & - это ссылка проверяем вид
        if (name.size() < 2)
            return false; // если имя состоит только из & - это невалидное имя
        if (name[1] >= '0' && name[1] <= '9')
            return false; // если второй символ цифра - это невалидное имя
        size_t symbol_count = 1;
        for (symbol_count; symbol_count < namesize; symbol_count++)
        { // проверка на остальные запрещённые символы
            for (char c : InvalidSymbolsForArgumentName)
            {
                if (name[symbol_count] == c)
                    return false;
            }
        }
        if (symbol_count == namesize)
            return true;
    }

    if (name[0] == '*')
    { // если первый символ * - это указатель, проверяем вид
        size_t pointer_count = 1;
        for (pointer_count; pointer_count < namesize; pointer_count++)
        {
            if (name[pointer_count] != '*')
                break;
        }
        if (pointer_count == namesize)
            return false; // если имя состоит только из символов "*"
        if (name[pointer_count] >= '0' || name[pointer_count] <= '9')
            return false; // указатель не может начинаться с цифры
        for (size_t i = pointer_count; i < namesize; i++)
        { // проверка на остальные запрещённые символы
            for (char c : InvalidSymbolsForArgumentName)
            {
                if (name[i] == c)
                    return false;
            }
        }
        if (pointer_count == namesize)
            return true;
    }

    for (size_t i = 0; i < namesize; i++)
    {
        for (char c : InvalidSymbolsForArgumentName)
        {
            if (name[i] == c)
                return false;
        }
    }
    return true;
}


// проверка имени класса
bool IsValidClassOrMethodName(const std::string &name)
{
    if (name.empty())
        return false; // пустое имя
    if (name[0] == ' ')
        return false;   // начинается с пробела
    if (name[0] >= '0' && name[0] <= '9')
        return false; // начинается с цифры

    size_t namesize = name.size();
    for (size_t i = 0; i < namesize; i++)
    {
        for (char c : InvalidSymbolsForArgumentName)
        {
            if (name[i] == c)
                return false;
        }
    }
    return true;
}
