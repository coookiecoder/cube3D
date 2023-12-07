/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

static
void	parse_line(char *line, t_map *map)
{
	if (is_texture(line))
		set_texture(line, map);
	else if (is_floor(line))
		set_floor(line, map);
	else if (is_celling(line))
		set_celling(line, map);
	else if (is_map(map))
		add_line_map(line, map);
	else
		map_error(map);
}

t_map	*load(char *location)
{
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(location, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(map));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n')
			parse_line(line, map);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
