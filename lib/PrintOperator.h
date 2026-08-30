#ifndef PRINTOPERATOR_H
#define PRINTOPERATOR_H

#include "Unit.h"

#include <vector>

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ); // : m_text( text )  { }
    std::string compile( unsigned int level = 0 ) const; 
private:
    std::string m_text;
};

#endif // PRINTOPERATOR_H
