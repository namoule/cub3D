/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:49:30 by jealefev          #+#    #+#             */
/*   Updated: 2025/04/01 12:56:19 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./Libft/libft.h"
# include "error.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef WIDTH
#  define WIDTH 1200
# endif
# ifndef HEIGHT
#  define HEIGHT 800
# endif
/*
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif*/
# define ESC_KEY 65307
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
#define MINIMAP_RADIUS 150
#define SCALE 1

typedef struct s_ray
{
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	int		hit;
	double	deltadist_x;
	double	deltadist_y;
	double	cam_x;
	int		x;
	int		step_x;
	int		step_y;
	int		side;
	double	perpwall_dist;
	int		line_height;
	int		vertical_shift;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	int		*pixels;
}				t_ray;

typedef struct s_dda
{
	int			side;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_dda;

typedef struct s_render
{
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_render;

typedef struct s_player
{
	float		x;
	float		y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	char		dir;
	double		move_speed;
	double		rot_speed;
	double		angle;

}				t_player;

typedef struct s_map
{
	void	*n_text;
	void	*s_text;
	void	*e_text;
	void	*w_text;
	int		*n_text_adr;
	int		*s_text_adr;
	int		*e_text_adr;
	int		*w_text_adr;

	int		f_col;
	int		c_col;
	char	**map;

	int		height;
	int		width;
}				t_map;

typedef struct s_image
{
	int			image_width;
	int			image_lenght;
	void		*image;
	void		*image2;
	void		*perso;
}				t_image;

typedef struct s_minimap
{
	int			x;
	int			y;
	float		player_x;
	float		player_y;
	int			width;
	int			height;
	int			*pixels;
	int			color;	
	int			bg_color;

}				t_minimap;

typedef struct s_data
{
	t_image		img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx_ptr;
	void		*window;
	char		*file_name;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_minimap	minimap;
	int			key[88];
}				t_data;


int				key_ex(int val_key, t_data *game);
int				key_release(int keycode, t_data *game);

char			**gnl(char *path, t_data *game);
void			ft_error(t_data *game, char *str);
int				close_win(t_data *game);
int				parse_cub(int argc, char **argv, t_data *game);
char			*get_next_line(int fd);
int				parse_args(int argc, char **argv, t_data *game);
void			init_all(t_data *game);
int				parsing(char *argv, t_data *game);
char			*less_n(char *str);
int				fill_map(t_data *game, int fd);
bool			all_inited(t_data *game);
void			deal_error(t_data *game, char *str);
int				catch_texture(int fd, t_data *game);
void			freetab(char **tab, int alloc_lines);
bool			is_map(char c);
bool			is_dir(char c);
void			free_buffer(char **buffer);
bool			line_not_empty(char *str);
int				parse_line(char *str);
int				check_text(char *line, t_data *game);
char			letter_in_line(t_data *game, int index);
void			*give_ptr_img(char *img, t_data *game, char *code);
bool			wall_map(char **map);
bool			check_tab(char **tab, t_data *game);
bool			check_char_map(char **map, int y, int x);
bool			check_empty_line(char *line);
bool			check_around(char **tab, int y, int x, int count);
bool			line_not_empty(char *str);
bool			check_char(char c);
bool			just_deal_line(char **tab, int y, int x);
bool			is_map(char c);
bool			check_line(char **tab, int y, bool last_line_non_empty);
int				count_tab(char **tab);

int				exec(char *argv, t_data *game);
int				get_map(int fd, t_data *game, int passed_lines);

int				give_rgb(char *str);
int				close_game(t_data *game);
void			free_tab(char **tab);

void			init_keys(t_data *game);
void			settings(t_data *game);
void			set_player_orientation(t_data *game);

int				render_game(t_data *game);
void			raycasting(t_data *game, int x);

void			move_player(t_data *game);
void			rotate_right(t_data *game);
void			rotate_left(t_data *game);

void			minimap(t_data *game);

#endif
