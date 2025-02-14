#include"../../cub.h"

bool is_dir(char c)
{
    if(c == 'N')
        return(true);
    if(c == 'S')
        return(true);
    if(c == 'E')
        return(true);
    if(c == 'W')
        return(true);
    return(false);
}

bool is_map(char c)
{
    if(c == '1' || c == '0' || c == ' ' || c == '\n' || c == '\0')
        return(true);
    return(false);
}

bool line_not_empty(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] != '\n' && str[i] != ' ' && str[i] != '\0')
            return(true);
        i++;
    }
    return(false);
}