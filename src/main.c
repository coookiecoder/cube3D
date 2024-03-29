/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2024/02/08 12:15:55 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"
#include <stdio.h>

#define WIDTH 1080
#define HEIGHT 1920

const static int	g_pixel = WIDTH * HEIGHT;

int	get_rgba(t_rgb *rgb)
{
	int	result;

	result = 0;
	result |= rgb->red;
	result |= rgb->green << 8;
	result |= rgb->blue << 16;
	result |= 255 << 24;
	return (result);
}

void	loop_hook(void *arg)
{
	(void) arg;
	return ;
}

void	key_hook(mlx_key_data_t keydata, void *arg)
{
	t_pov	*player;

	if (!arg)
		return ;
	player = arg;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(player->mlx);
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_RIGHT)
		player->angle += 1;
	else if (keydata.key == MLX_KEY_E || keydata.key == MLX_KEY_LEFT)
		player->angle -= 1;
	if (player->angle >= 360)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 360;
	return ;
}

t_data	*pack_data(t_map *map, t_pov *player, mlx_t *mlx, mlx_image_t *img)
{
	t_data	*packed_data;

	packed_data = malloc(sizeof(t_data));
	if (!packed_data)
		return (NULL);
	packed_data->map = map;
	packed_data->player = player;
	packed_data->mlx = mlx;
	packed_data->img = img;
	return (packed_data);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_pov		*player;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		*data;

	if (argc != 2 || check_extension(*(argv + 1)))
		return (write(1, "Error in the argument\n", 23), 1);
	map = load_file(*(argv + 1));
	validate_map(map);
	validate_data(map);
	player = load_player(map);
	mlx = mlx_init(HEIGHT, WIDTH, "cub3D", false);
	player->mlx = mlx;
	img = mlx_new_image(mlx, HEIGHT, WIDTH);
	ft_intset(img->pixels, get_rgba(map->celling), g_pixel / 2);
	ft_intset(img->pixels + (g_pixel * 2), get_rgba(map->floor), g_pixel / 2);
	mlx_image_to_window(mlx, img, 0, 0);
	data = pack_data(map, player, mlx, img);
	mlx_loop_hook(mlx, loop_hook, data);
	mlx_key_hook(mlx, key_hook, player);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (free(player), free(data), purge_map(map), 0);
}
