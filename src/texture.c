/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 11:25:01 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	is_texture(char *line, t_map *map)
{
	if (ft_strlen(line) < 4)
		return (0);
	if (*(line + 0) == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (!map->north_texture_location);
	if (*(line + 0) == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (!map->south_texture_location);
	if (*(line + 0) == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		return (!map->west_texture_location);
	if (*(line + 0) == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		return (!map->east_texture_location);
	return (0);
}

void	set_texture(char *line, t_map *map)
{
	if (*(line + 0) == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		map->north_texture_location = ft_strdup(line + 3);
	if (*(line + 0) == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		map->south_texture_location = ft_strdup(line + 3);
	if (*(line + 0) == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		map->west_texture_location = ft_strdup(line + 3);
	if (*(line + 0) == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		map->east_texture_location = ft_strdup(line + 3);
}
