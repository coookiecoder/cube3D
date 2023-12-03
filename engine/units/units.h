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

#ifndef UNITS_H
# define UNITS_H

typedef struct s_int {
	long long	value;
}	t_int;

typedef struct s_float {
	long long	value;
}	t_float;

typedef struct s_pos {
	t_float	x;
	t_float	y;
	t_float	z;
}	t_pos;

typedef struct s_dir {
	t_float	x;
	t_float	y;
	t_float	z;
}	t_dir;

typedef struct s_vector {
	t_pos	pos;
	t_dir	dir;
}	t_vector;

// vector.c

void	init_vector(t_vector *vector);

// pos.c

void	init_pos(t_pos *pos);

// dir.c

void	init_dir(t_dir *dir);

// int.c

t_int	int_to_t_int(int integer);
int		t_int_to_int(t_int integer);

// float.c

t_float float_to_t_float(double floating_number);
double	t_float_to_float(t_float floating_number);

#endif
