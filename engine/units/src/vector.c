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

#include "units.h"

void	init_vector(t_vector *vector)
{
	vector->pos.x = float_to_t_float(0);
	vector->pos.y = float_to_t_float(0);
	vector->pos.z = float_to_t_float(0);
	vector->dir.x = float_to_t_float(0);
	vector->dir.y = float_to_t_float(0);
	vector->dir.z = float_to_t_float(0);
}