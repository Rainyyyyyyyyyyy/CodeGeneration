#ifndef IPRINTOPERATOR_H
#define IPRINTOPERATOR_H

#include "IStatementUnit.h"

class IPrintOperatorUnit : public IStatementUnit {
public:
    explicit IPrintOperatorUnit( const std::string& text ); // : m_text( text )  { }
    virtual ~IPrintOperatorUnit() = default;
    std::string compile( unsigned int level = 0 ) const override = 0; 

    void SetText(const std::string& text){ this->text = text;}
    inline const std::string &GetText() const { return text; }
protected:
    std::string text;
};

#endif // IPRINTOPERATOR_H
