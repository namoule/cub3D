#include"../../cub.h"

int parse_line(char *str)
{
    int i = 0;
    if (!str)
        return (-1);

    while (str[i])
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'S' && 
            str[i] != 'E' && str[i] != 'W' && str[i] != ' ' && str[i] != '\n')
            return (1);
        i++;
    }
    return (0);
}

int check_text_bis(t_data *game, char **tab)
{
    if (ft_strncmp("F", tab[0], 2) == 0)
    {
        game->map.f_col = give_rgb(tab[1]);
        if(game->map.f_col == NULL)
            return(-1);

    }
    else if (ft_strncmp("C", tab[0], 2) == 0)
    {
        game->map.c_col = give_rgb(tab[1]);
        if(game->map.c_col == NULL)
            return(-1);
    }
    return(0);
}

int check_text(char *line, t_data *game)
{
    if (!line)
        return (-1);
    
    char **tab = ft_split(line, ' ');
    if (!tab)
        return (-1);
    if (tab[0] && tab[1])
    {
        if (ft_strncmp("NO", tab[0], 3) == 0)
            return(game->map.n_text = give_ptr_img(less_n(tab[1]), game, "NO"), 0);
        else if (ft_strncmp("SO", tab[0], 3) == 0)
            return(game->map.s_text = give_ptr_img(less_n(tab[1]), game, "SO"), 0);
        else if (ft_strncmp("EA", tab[0], 3) == 0)
            return(game->map.e_text = give_ptr_img(less_n(tab[1]), game, "EA"), 0);
        else if (ft_strncmp("WE", tab[0], 3) == 0)
            return(game->map.w_text  = give_ptr_img(less_n(tab[1]), game, "WE"), 0);
        else if(ft_strncmp("F", tab[0], 2) == 0 || ft_strncmp("C", tab[0], 2) == 0)
            return(check_text_bis(game, tab));
    }
    return 1;
}

char letter_in_line(t_data *game, int index)
{
	int i = 0;
    int j = 1;
	while(game->map.map[index][i])
	{
		if(is_dir(game->map.map[index][i]) == true && game->map.map[index][i] != '\0')
        {
            while(game->map.map[index][i+j])
            {
                if(is_dir(game->map.map[index][i+j]))
                    return(printf("many letters, not acceptable [%c] [%c]...\n", game->map.map[index][i], game->map.map[index][i+j]), -1);
                j++;
            }
            game->joueur.x = i; // ici je prends la position en x
			return(game->map.map[index][i]);
        }
		else if(is_map(game->map.map[index][i]) == false && game->map.map[index][i] != '\0')
			return(game->map.map[index][i]);
		i++;
	}
	return(0);
}