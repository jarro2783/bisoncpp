#include "parser.ih"

void Parser::setPrecedence(int type)
{
    Symbol *sp = 0;     // to prevent `sp uninitialized' warning by the
                        // compiler 

    switch (type)
    {
        case IDENTIFIER:
            sp = d_symtab.lookup(d_matched);
        break;

        case QUOTE:
            sp = d_symtab.lookup(d_scanner.canonicalQuote());
        break;
    }        

    if (sp && sp->isTerminal())
        d_rules.setPrecedence(Terminal::downcast(sp));
    else
        emsg << "`%prec " << d_matched << "': `" << d_matched << 
                "' must be a declared terminal token" << endl;
}


