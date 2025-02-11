/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:01:10 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/10 23:13:24 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

static int check_text(char *line, t_data *game)
{
    if (!line)
        return (-1);
    
    char **tab = ft_split(line, ' ');
    if (!tab)
        return (-1);
    if (tab[0] && tab[1])
    {
        if (ft_strncmp("NO", tab[0], 3) == 0)
            game->map.n_text = give_ptr_img(less_n(tab[1]), game);
        else if (ft_strncmp("SO", tab[0], 3) == 0)
            game->map.s_text = give_ptr_img(less_n(tab[1]), game);
        else if (ft_strncmp("EA", tab[0], 3) == 0)
            game->map.e_text = give_ptr_img(less_n(tab[1]), game);
        else if (ft_strncmp("WE", tab[0], 3) == 0)
            game->map.w_text  = give_ptr_img(less_n(tab[1]), game);
        else if (ft_strncmp("F", tab[0], 2) == 0)
            game->map.f_col = (int)strtol(tab[1], NULL, 16); //a recoder ??
        else if (ft_strncmp("C", tab[0], 2) == 0)
            game->map.c_col = (int)strtol(tab[1], NULL, 16); // a recoder ??
    }
    return 0;
}

static int get_count(int fd)
{
    char *ptr;
    int count = 0;
    while(1)
    {
        ptr = get_next_line(fd);
        if(!ptr)
            break;
        count++;
    }
	return(count);
}

char letter_in_map(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] != '0' && str[i] != '1')
			return(str[i]);
		i++;
	}
	return(0);
}

int get_map(int fd, char *tmp, t_data *game, int passed_lines)
{
    int count = 0;
    int new_fd;
    int i = 0;

	game->map.map = malloc(sizeof(char *) *  (get_count(fd) + 1));
	new_fd = open(game->file_name, O_RDONLY);
	while(passed_lines > 0)
	{
		get_next_line(new_fd);
		passed_lines--;
	}
    while(1)
    {
        game->map.map[i] = ft_strdup(get_next_line(new_fd));
        if(!game->map.map[i])
        {
            game->map.map[i] = NULL;
            break;
        }
		game->joueur.dir = letter_in_map(game->map.map[i]);
        i++;
    }
    return(0);
}

static int check_map_started(char *str)
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

int fill_map(t_data *game, int fd)
{
    int count = 0;
    char *tmp = get_next_line(fd);
    while (tmp)
    {
        count++;
        if (check_map_started(tmp) != 0)
        {
            if (check_text(tmp, game))
                break;
        }
        else
            if(all_inited(game) == true)
                return(get_map(fd, tmp, game, count));
        tmp = get_next_line(fd);
    }
    return (1);
}

int	parse_cub(int argc, char **argv, t_data *game)
{
	int fd;
	fd = parse_args(argc, argv, game);
	game->file_name = ft_strdup(argv[1]);
	if(fd < 0)
		return(1);
	if(fill_map(game, fd) != 0)
		return(1);
	return (0);
}