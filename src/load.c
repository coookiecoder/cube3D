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
int	is_player(char map)
{
	if (map == 'N' || map == 'S' || map == 'E' || map == 'O')
		return (1);
	return (0);
}

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

t_pov	*load_player(t_map *map)
{
	int		iteration;
	int		position_x;
	int		position_y;
	t_pov	*player;

	iteration = 0;
	position_y = 0;
	position_x = 0;
	while (!is_player(map->map[iteration]) && map->map[iteration])
	{
		iteration++;
		if (map->map[iteration++] == '\n')
		{
			position_x = 0;
			position_y++;
		}
		position_x++;
	}
	if (!is_player(map->map[iteration]))
		map_error(map);
	player = malloc(sizeof(player));
	player->position_x = position_x;
	player->position_y = position_y;
	set_angle(player, map->map[iteration]);
	return (player);
}
