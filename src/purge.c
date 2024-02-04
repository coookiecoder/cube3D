/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:09:25 by abareux           #+#    #+#             */
/*   Updated: 2024/02/04 20:17:38 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	purge_map(t_map *map)
{
	free(map->north_texture_location);
	free(map->south_texture_location);
	free(map->east_texture_location);
	free(map->west_texture_location);
	free(map->celling);
	free(map->floor);
	free(map->map);
	free(map);
}
