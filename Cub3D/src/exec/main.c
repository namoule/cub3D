/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:27:04 by jealefev          #+#    #+#             */
/*   Updated: 2025/03/11 20:49:08 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"
#include <stdbool.h>

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc < 2)
		return (1);
	if (parsing(argv[1], &game) == 1)
		return (1);
	exec(argv[1], &game);
    close_game(&game);
	return (0);
}

