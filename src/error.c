/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 12:07:37 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	map_error(t_map *map)
{
	if (map->north_texture_location > (char *) 1)
		free(map->north_texture_location);
	if (map->south_texture_location > (char *) 1)
		free(map->south_texture_location);
	if (map->west_texture_location > (char *) 1)
		free(map->west_texture_location);
	if (map->east_texture_location > (char *) 1)
		free(map->east_texture_location);
	if (map->floor > (t_rgb *) 1)
		free(map->floor);
	if (map->celling > (t_rgb *) 1)
		free(map->celling);
	if (map->map > (char *) 1)
		free(map->celling);
	write(1, "Error\n", 6);
	exit(1);
}

void	malloc_error(t_map *map)
{
	if (map)
	{
		free(map->north_texture_location);
		free(map->south_texture_location);
		free(map->west_texture_location);
		free(map->east_texture_location);
		free(map->floor);
		free(map->celling);
	}
	write(1, "Error\n", 6);
	write(1, "a malloc f*** up\n", 18);
	exit(1);
}
