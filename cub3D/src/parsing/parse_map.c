#include "../../cub.h"

bool check_around(char **tab, int y, int x, int count)
{
    if (x + 1 < strlen(tab[y]) && (!tab[y][x + 1] || (tab[y][x + 1] == ' ') || tab[y][x + 1] == '\n' || tab[y][x + 1] == '\0'))
        return false;
    if (x - 1 >= 0 && (!tab[y][x] || (tab[y][x - 1] == ' ') || tab[y][x - 1] == '\n' || tab[y][x - 1] == '\0'))
        return false;
    if (y - 1 >= 0 && (!tab[y][x] || (tab[y - 1][x] == ' ') || tab[y - 1][x] == '\n' || tab[y - 1][x] == '\0'))
        return false;
    if (y + 1 < count && (!tab[y][x] || (tab[y + 1][x] == ' ') || tab[y + 1][x] == '\n' || tab[y + 1][x] == '\0'))
        return false;
    return true;
}

bool check_empty_line(char *line)
{
    int x = 0;
    while (line[x] != '\0')
    {
        if (line[x] != ' ' && line[x] != '\n')
            return false;
        x++;
    }
    if(x == 0)
        return false;
    return true;
}

bool is_dir(char c)
{
    return (c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

bool check_line(char **tab, int y, bool last_line_non_empty)
{
    if (check_empty_line(tab[y]))
        if (y != 0 && !last_line_non_empty)
            return false;
    return true;
}

bool is_map(char c)
{
    return (c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0');
}

bool just_deal_line(char **tab, int y, int x, int count)
{
    if (y == 0 || y == count - 1 || x == 0 || x == strlen(tab[y]) - 1)
        if (tab[y][x] == '0')
            return false;
    if (is_map(tab[y][x]) == true && check_around(tab, y, x, count) == false)
        return false;
    return true;
}

bool check_char(char c)
{
    return (c == '1' || c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0' || c == '\n' || c == '\0');
}

bool check_tab(char **tab, t_data *game)
{
    int y = 0;
    int x = 0;
    bool last_line_non_empty = false;
    int count = 0;
    while (tab[count])
        count++;
    while (tab[y])
    {
        if (!tab[y][x] || check_line(tab, y, last_line_non_empty) == false)
            return (printf("Erreur : ligne vide au milieu du tableau\n"), false);
        while (tab[y][x])
        {
            if(is_dir(tab[y][x]) == true && game->joueur.dir != 0)
                return(printf("already one game->joueur.dir %c\n", tab[y][x]), false);
            else if(is_dir(tab[y][x]) == true && game->joueur.dir == 0)
                game->joueur.dir = tab[y][x];
            if (check_char(tab[y][x]) == false)
                return (printf("Erreur : caractère invalide '%c' dans le tableau\n", tab[y][x]), false);
            else if (just_deal_line(tab, y, x, count) == false)
                return (printf("Erreur : case mal entourée ou bord mal formé !\n"), false);
            x++;
        }
        last_line_non_empty = !check_empty_line(tab[y]);
        x = 0;
        y++;
    }
    if(game->joueur.dir == 0)
        return(printf("Needs one player\n"), false);
    return(true);
}

