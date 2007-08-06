#include "scanner.ih"

bool Scanner::popSource(yy_buffer_state *current)
{
    if (d_block)                // an open block exists at EOF
        lineMsg() << "EOF: Incomplete compound statement "
                    "starts at Line " << d_block.line() << fatal;

    if (d_state.empty())
        return false;

    yy_delete_buffer(current);
    yy_switch_to_buffer(d_state.top());
    d_state.pop();

    yylineno = d_fileInfo.back().second;
    d_fileInfo.pop_back();

    return true;
}
