/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2024/02/01 13:30:40 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int get_rgba(t_rgb *rgb)
{
	int result;

	result = 0;
	result |= rgb->red;
	result |= rgb->green << 8;
	result |= rgb->blue << 16;
	result |= 255 << 24;
    return (result);
}

int	main(int argc, char **argv)
{
	t_map			*map;
	t_pov			*player;
	mlx_t			*mlx;
	mlx_image_t*	img;

	if (argc != 2 || check_extension(*(argv + 1)))
		return (write(1, "Error in the argument\n", 23), 1);
	map = load_file(*(argv + 1));
	validate_map(map);
	validate_data(map);
	player = load_player(map);
	printf("position x : %f\n", player->position_x);
	printf("position Y : %f\n", player->position_y);
	printf("angle pov : %d\n", player->angle);
	mlx = mlx_init(1920, 1080, "cub3D", true);
	img = mlx_new_image(mlx, 1920, 1080);
	ft_intset(img->pixels, get_rgba(map->celling), 1920 * 1080 / 2);
	ft_intset(img->pixels + (1920 * 1080 * 2), get_rgba(map->floor), 1920 * 1080 / 2);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
