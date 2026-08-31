#ifndef ICLASSUNIT_H
#define ICLASSUNIT_H

#include <memory>
#include <vector>

#include "Unit.h"
#include "Modifiers.h"

/*
ClassUnit::ClassUnit( const std::string& name ) : m_name( name ) {
    m_fields.resize( ACCESS_MODIFIERS.size() );
}


void ClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}
*/
class IClassUnit : public Unit {
// private:
//     std::string name;                               // имя класса
//     Modifiers::ClassModifiers classModifier;        // модификатор класса (abstract, final, abstract final)

    //using Fields = std::vector <std::shared_ptr < Unit > >;
    //std::vector <Fields> fields;

    //static const std::vector< std::string > ACCESS_MODIFIERS; // = { "public", "protected", "private" };
public:
    IClassUnit(const std::string& name, ClassModifiers classModifier = ClassModifiers::UNDEFINED);
    virtual ~IClassUnit() = default;
    virtual std::string compile( unsigned int level = 0 ) const override = 0;

    virtual void add(const std::shared_ptr <Unit> &, Flags flags) = 0;


    Modifiers::ClassModifiers getClassModifier() const;

    std::string getName() const;

protected:

    std::string name;                               // имя класса
    Modifiers::ClassModifiers classModifier;        // модификатор класса (abstract, final, abstract final)
    
        
};

#endif // ICLASSUNIT_H