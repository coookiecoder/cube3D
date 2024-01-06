/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2024/01/06 10:24:36 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_pov	*player;

	if (argc != 2)
		return (write(1, "Error in the argument\n", 23), 1);
	map = load_file(*(argv + 1));
	validate_map(map);
	player = load_player(map);
	printf("position x : %f\n", player->position_x);
	printf("position Y : %f\n", player->position_y);
	printf("angle pov : %d\n", player->angle);
}
