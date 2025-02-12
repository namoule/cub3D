/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:01:10 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/12 18:50:10 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub.h"

static int get_passed_lines(int fd)
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

int check_and_make_map(t_data *game, int new_fd)
{
    int i = 0;
    while(1) //on recupere les lignes
    {
        game->map.map[i] = ft_strdup(get_next_line(new_fd)); //on les copies
        if(!game->map.map[i])
        {
            game->map.map[i] = NULL;
            break;
        }
		if(is_dir(letter_in_line(game, i)) == true)
        {
            if(game->joueur.dir != 0)
                return(printf("Error !\nJust one position and direction please..."), 1);
            game->joueur.dir = letter_in_line(game, i); // ici on recupere la direction
            game->joueur.y = i+1; // ici en partie la position
        }
		else if(is_map(game->joueur.dir) == false && is_dir(game->joueur.dir) == false)
			return(printf("Error !\nWrong letter in map [%c]...\n", game->joueur.dir), 1);//freetab(game->map.map, i - 1), 1);
        i++;
    }
    return(0);
}

int get_map(int fd, char *tmp, t_data *game, int passed_lines)
{
    int count = 0;
    int map_size;
    int new_fd;

    map_size = get_passed_lines(fd);
	game->map.map = malloc(sizeof(char *) *  (map_size + 2)); //avec le fd actuel on va aller a bout du fichier pour allouer 
	new_fd = open(game->file_name, O_RDONLY); //ave le nouveau fd on va revenir sur les lignes deja passees pour aller a celles quon a pas copiees
	while(passed_lines > 1) // ici on passe les lignes dont on a pas besoin...
	{
		get_next_line(new_fd);
		passed_lines--;
	}
    if(check_and_make_map(game, new_fd) == 1)
        return(1);
    return(0);
}

int catch_texture(int fd, t_data *game)
{
	int count = 0;
	int check = 0;
    char *line = get_next_line(fd);
    while (line)
    {
        count++;
        if (parse_line(line) != 0) //checker si cest une ligne qui pourrait etre une ligne de texture
        {
            if(check_text(line, game) == -1) // si oui on va checker les textures
				return(-1); // si probleme dans les textures retourner -1 si tableau vide ou autre
        }
        else
        {
            if(all_inited(game) == true && line_not_empty(line) == true) // si toutes les textures ont etees initiees
                return(get_map(fd, line, game, count)); // on recupere la map
        }
        line = get_next_line(fd);
    }
    return (1);
}