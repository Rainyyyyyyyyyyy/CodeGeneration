#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "Unit.h"

#include <vector>

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector< std::string > ACCESS_MODIFIERS; //= { "public", "protected", "private" };
public:
    explicit ClassUnit( const std::string& name ); 

    void add( const std::shared_ptr< Unit >& unit, Flags flags ); 
    /*{
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}*/

    std::string compile( unsigned int level = 0 ) const;

private:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    // vector < vector < Unit* > >
    std::vector< Fields > m_fields;
};

#endif // CLASSUNIT_H
