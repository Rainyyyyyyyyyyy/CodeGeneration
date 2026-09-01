#ifndef IPRINTOPERATOR_H
#define IPRINTOPERATOR_H

#include "Unit.h"

class IPrintOperatorUnit : public Unit {
public:
    explicit IPrintOperatorUnit( const std::string& text ); // : m_text( text )  { }
    virtual ~IPrintOperatorUnit() = default;
    std::string compile( unsigned int level = 0 ) const override = 0; 
protected:
    std::string text;
};

#endif // IPRINTOPERATOR_H
