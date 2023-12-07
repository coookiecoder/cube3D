/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 12:00:34 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

# include "get_next_line/get_next_line.h"

# define LEFT 1
# define RIGHT 2
# define BOTH 3

typedef struct s_rgb {
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_map {
	char	*north_texture_location;
	char	*south_texture_location;
	char	*west_texture_location;
	char	*east_texture_location;
	t_rgb	*floor;
	t_rgb	*celling;
	char	*map;
}	t_map;

t_map	*load_file(char *location);

int		is_texture(char *line, t_map *map);
void	set_texture(char *line, t_map *map);

int		is_floor(char *line, t_map *map);
void	set_floor(char *line, t_map *map);

int		is_celling(char *line, t_map *map);
void	set_celling(char *line, t_map *map);

int		is_map(t_map *map);
void	add_line_map(char *line, t_map *map);

void	map_error(t_map *map);
void	malloc_error(t_map *map);

int		ft_strlen(char *s);

char	*ft_strdup(char *s);

char	*ft_strjoin(char *string_a, char *string_b, int mode);

#endif
