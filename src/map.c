/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 10:59:39 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	is_map(t_map *map)
{
	if (!map->north_texture_location)
		return (0);
	if (!map->south_texture_location)
		return (0);
	if (!map->west_texture_location)
		return (0);
	if (!map->east_texture_location)
		return (0);
	if (!map->floor)
		return (0);
	if (!map->celling)
		return (0);
	return (1);
}
