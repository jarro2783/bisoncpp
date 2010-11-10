#include "parser.ih"

    // I've seen the begin of a rule. If not yet defined, do so
    // now, and prepare for productions.
void Parser::openRule(string *ruleNamePtr)
{
    NonTerminal *nt = requireNonTerminal(*ruleNamePtr);
                                                // rule must start with N

    if (nt)
    {                                           // quit if not
        if 
        (
            not d_rules.newRule(nt, 
                                d_scanner.sourceName(), d_scanner.lineno())
        )
        {
            Rules::FileInfo const &fileInfo = d_rules.fileInfo(nt);
    
            lineMsg(wmsg) << "Extending rule `" << *ruleNamePtr << 
                        "', first defined in `" << fileInfo.first << 
                        "' (" << fileInfo.second << ")" << endl;
        }
        d_rules.addProduction();
    }
    delete ruleNamePtr;
}
