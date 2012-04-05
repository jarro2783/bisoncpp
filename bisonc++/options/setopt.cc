#include "options.ih"

string Options::setOpt(char const *option, string const &defaultSpec)
{
    string ret;

    d_arg.option(&ret, option);

    ret = ret.size() ? undelimit(ret) : defaultSpec;
        
    // if (ret.size())
    //     ret = undelimit(ret);
    // else //if (d_scannerInclude.size())
    //     ret = defaultSpec;

    return ret;
}
