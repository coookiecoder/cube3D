/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 11:01:29 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_texture(char *line)
{
	if (*(line + 3) == '\0')
		return (0);
	if (*(line + 0) == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (1);
	if (*(line + 0) == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (1);
	if (*(line + 0) == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		return (1);
	if (*(line + 0) == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		return (1);
	return (0);
}

void	set_texture(char *line, t_map *map)
{

}
