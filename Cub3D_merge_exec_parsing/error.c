/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:08 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/10 21:46:11 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

void	deal_error(t_data *game, char *str)
{
	ft_putstr_fd(str, 1);
	free(game);
}

void	ft_error(t_data *game, char *str)
{
	write(1, str, (int)ft_strlen(str));
	close_win(game);
}