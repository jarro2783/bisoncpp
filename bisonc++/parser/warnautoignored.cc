#include "parser.ih"

void Parser::warnAutoIgnored(char const *typeOrField, 
                             AtDollar const &atd) const
{
    if (not warnNegativeIndex(typeOrField, atd))
    {
        string const &autoType = d_rules.sType();

        if (autoType.length())
        {
            wmsg.setLineNr(atd.lineNr());
            wmsg << &d_rules.lastProduction() << ": `" << atd.text() <<
                "' suppresses auto " << typeOrField << " `" << 
                autoType << "' of `" << d_rules.name() << "'." << endl;
        }
    }
}