/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:31:15 by jealefev          #+#    #+#             */
/*   Updated: 2023/11/17 11:12:13 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
       write(fd, s, ft_strlen(s));
       write(fd, "\n", 1);
}

// int main(int argc, char **argv)
// {
//     if(argc == 2)
//         ft_putendl_fd(argv[1], 1);
//     return(0);
// }