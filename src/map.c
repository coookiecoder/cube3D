/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 12:42:07 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	is_map(t_map *map)
{
	if (map->north_texture_location < (char *) 2)
		return (0);
	if (map->south_texture_location < (char *) 2)
		return (0);
	if (map->west_texture_location < (char *) 2)
		return (0);
	if (map->east_texture_location < (char *) 2)
		return (0);
	if (map->floor < (t_rgb *) 2)
		return (0);
	if (map->celling < (t_rgb *) 2)
		return (0);
	return (1);
}

void	add_line_map(char *line, t_map *map)
{
	if (!map->map)
		map->map = ft_strdup(line);
	else
		map->map = ft_strjoin(map->map, line, LEFT);
	if (!map->map)
		malloc_error(map);
}
