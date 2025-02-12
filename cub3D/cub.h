/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:49:30 by jealefev          #+#    #+#             */
/*   Updated: 2025/02/12 18:22:26 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "./Libft/libft.h"
# include "error.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
#include <stdbool.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif
#ifndef WIDTH
#define WIDTH 1024
#endif
#ifndef HEIGHT
#define HEIGHT 1024
#endif


typedef struct s_player
{
	int			x;
	int			y;
	char		dir;
}				t_player;

typedef struct s_map
{
	void *n_text;
	void *s_text;
	void *e_text;
	void *w_text;
	char *n_text_name;
	char *s_text_name;
	char *e_text_name;
	char *w_text_name;
	
	int f_col;
	int c_col;
	char *f_col_name;
	char *c_col_name;
	char		**map;
}				t_map;

typedef struct s_image
{
	int			image_width;
	int			image_lenght;
	void		*image;
	void		*image2;
	void		*perso;
}				t_image;

typedef struct s_data
{
	t_image		img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx_ptr;
	void		*window;
	char *file_name;
	t_map		map;
	t_player	joueur;
}				t_data;


int	key_ex(int val_key, t_data *game);
char	**gnl(char *path, t_data *game);
void	ft_error(t_data *game, char *str);
int	close_win(t_data *game);
int parse_cub(int argc, char **argv, t_data *game);
void    draw_line(void *img, int x1, int y1, int x2, int y2, int color, t_data *data);
char	*get_next_line(int fd);
int parse_args(int argc, char **argv, t_data *game);
void init_data(t_data *game);
int parsing(char *argv, t_data *game);
char *less_n(char *str);
int fill_map(t_data *game, int fd);
bool all_inited(t_data *game);
void	deal_error(t_data *game, char *str);
int catch_texture(int fd, t_data *game);
void freetab(char **tab, int alloc_lines);
bool is_map(char c);
bool is_dir(char c);
void free_buffer(char **buffer);
bool line_not_empty(char *str);
int parse_line(char *str);
int check_text(char *line, t_data *game);
char letter_in_line(t_data *game, int index);
void *give_ptr_img(char *img, t_data *game, char *code);
bool wall_map(char **map);
#endif
