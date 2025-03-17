/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:34:53 by elsikira          #+#    #+#             */
/*   Updated: 2025/03/17 12:13:30 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void cast_ray(t_data *game, int x)
{
    double cameraX = 2 * x / (double)WIDTH - 1; // Map screen x to camera plane
    double rayDirX = game->joueur.dir_x + game->joueur.plane_x * cameraX;
    double rayDirY = game->joueur.dir_y + game->joueur.plane_y * cameraX;

    int mapX = (int)game->joueur.x;
    int mapY = (int)game->joueur.y;

    // Distance from one x-side or y-side to the next
    double deltaDistX = fabs(1 / rayDirX);
    double deltaDistY = fabs(1 / rayDirY);

    double sideDistX, sideDistY;
    int stepX, stepY;
    int hit = 0; // Did the ray hit a wall?
    int side;    // Was the wall hit on X or Y side?

    // Determine step direction and initial side distances
    if (rayDirX < 0)
    {
        stepX = -1;
        sideDistX = (game->joueur.x - mapX) * deltaDistX;
    }
    else
    {
        stepX = 1;
        sideDistX = (mapX + 1.0 - game->joueur.x) * deltaDistX;
    }
    if (rayDirY < 0)
    {
        stepY = -1;
        sideDistY = (game->joueur.y - mapY) * deltaDistY;
    }
    else
    {
        stepY = 1;
        sideDistY = (mapY + 1.0 - game->joueur.y) * deltaDistY;
    }

    // Perform DDA (step through grid until a wall is hit)
    while (hit == 0)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }
		if (mapX < 0 || mapX > game->map.width || mapY < 0 || mapY > game->map.height )
		{
    		printf("ERROR: mapX (%d) or mapY (%d) out of bounds!\n", mapX, mapY);
    		return;
		}
        if (game->map.map[mapY][mapX] == '1') // Check if hit a wall
            hit = 1;
    }

    // Calculate distance to wall
    double perpWallDist;
    if (side == 0)
        perpWallDist = (mapX - game->joueur.x + (1 - stepX) / 2) / rayDirX;
    else
        perpWallDist = (mapY - game->joueur.y + (1 - stepY) / 2) / rayDirY;

    // Determine height of wall slice
    int lineHeight = (int)(HEIGHT / perpWallDist);
	int	vertical_shift = 60;
    int drawStart = HEIGHT / 2 - lineHeight / 2 - vertical_shift;
    if (drawStart < 0)
		drawStart = 0;
    int drawEnd = HEIGHT / 2 + lineHeight / 2 - vertical_shift;
    if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
    // Set wall color (basic shading)
    int color = 0xFFFFFF; // White walls by default
    if (side == 1) color /= 2; // Darker if hit on y-side

    // Draw the vertical wall stripe
	/*printf("Casting ray at x = %d\n", x);
	printf("Player position: (%f, %f)\n", game->joueur.x, game->joueur.y);
	printf("Ray direction: (%f, %f)\n", rayDirX, rayDirY);
	printf("Map position: (%d, %d)\n", mapX, mapY);
*/
    int *pixels = (int *)mlx_get_data_addr(game->img.image, &game->bits_per_pixel, &game->line_length, &game->endian);
	int	y = drawStart;
    while (y < drawEnd)
	{
        pixels[y * (game->line_length / 4) + x] = color;
		y++;
	}
}

void	render_walls(t_data *game)
{
	int	x;

	x = 0;
	
	while (x < WIDTH)
	{
		cast_ray(game, x);
		x++;
	}
}

void	render_ceiling_floor(t_data *game)
{
	int	x;
	int	y;
	int	*pixels;

	pixels = (int *)mlx_get_data_addr(game->img.image, &game->bits_per_pixel, &game->line_length, &game->endian);
	if (!pixels)
		return (printf("Error: Failed to get the image address.\n"), exit(1));
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixels[y * (game->line_length / 4) + x] = game->map.c_col;
			x++;
		}
		y++;
	}
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixels[y * (game->line_length / 4) + x] = game->map.f_col;
			x++;
		}
		y++;
	}
}

int	render_game(t_data *game)
{
	t_ray		ray;
	t_dda		dda = {0};
	double		move_speed = 0.05;
	double		rot_speed = 0.05;

	if (game->mlx_ptr && game->img.image)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.image);
		game->img.image = NULL;
	}
	game->img.image = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->img.image)
		return (printf("Error: Failed to create image.\n"), 1);
	move_player(game, move_speed, rot_speed);
	render_ceiling_floor(game);
	render_walls(game);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->img.image, 0, 0);
	return (0);
}

int	init_mlx(t_data *game)
{
	game->window = mlx_new_window(game->mlx_ptr, 800, 600, "girls' cub3d");
	if (!game->window)
		return (printf("Error initializing mlx window.\n"), 1);
	mlx_key_hook(game->window, key_release, game);
	mlx_hook(game->window, 17, 0, close_win, game);
	mlx_hook(game->window, 2, 1L<<0, key_ex, game);
	mlx_hook(game->window, 3, 1L<<1, key_release, game);
	return (0);
}

void	init_player(t_data *game, t_map *map)
{
	game->joueur.dir_x = 1;
	game->joueur.dir_y = 1;
	game->joueur.plane_x = 0;
	game->joueur.plane_y = 0.50;
}

int	exec(char *map_file, t_data *game)
{
	game->img.image = NULL;
	init_mlx(game);
	init_player(game, &game->map);
	init_keys(game);	
	mlx_loop_hook(game->mlx_ptr, render_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
