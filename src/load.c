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

static
void	parse_line(char *line, t_map *map)
{
	if (is_texture(line, map))
		set_texture(line, map);
	else if (is_floor(line, map))
		set_floor(line, map);
	else if (is_celling(line, map))
		set_celling(line, map);
	else if (is_map(map))
		add_line_map(line, map);
	else
		map_error(map);
}

static
void	init_map(t_map *map)
{
	map->north_texture_location = NULL;
	map->south_texture_location = NULL;
	map->west_texture_location = NULL;
	map->east_texture_location = NULL;
	map->floor = NULL;
	map->celling = NULL;
	map->map = NULL;
}


t_map	*load_file(char *location)
{
	int		fd;
	char	*line;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		malloc_error(map);
	init_map(map);
	fd = open(location, O_RDONLY);
	if (fd == -1)
		map_error(map);
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n')
			parse_line(line, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
