/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   celling.c                                          :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 12:45:13 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	is_celling(char *line, t_map *map)
{
	if (*(line + 0) == 'C' && *(line + 1) == ' ' && *(line + 2) != '\0')
		return (!map->celling);
	return (0);
}

void	set_celling(char *line, t_map *map)
{
	t_rgb	*result;

	result = malloc(sizeof(t_rgb));
	if (!result)
	{
		map->floor = (void *) 1;
		return ;
	}
	result->red = atoi(line + 2);
	while (*line != ',' && *line)
		line++;
	result->green = atoi(++line);
	while (*line != ',' && *line)
		line++;
	result->blue = atoi(++line);
	map->celling = result;
}
