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

double	t_float_to_float(t_float floating_number)
{
	double	result;

	result = (double) floating_number.value / 1000.0;
	return (result);
}

t_float float_to_t_float(double floating_number)
{
	t_float result;

	result.value = floating_number * 1000.0;
	return(result);
}