/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 12:48:47 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	validate_map(t_map *map)
{
	char	*buffer;

	buffer = ft_strdup(map->map);
	if (!buffer)
		malloc_error(map);
	if (flood(buffer))
		map_error(map);
}
