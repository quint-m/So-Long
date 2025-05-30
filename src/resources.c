/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:55:49 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/10 15:36:19 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resource_free_level(t_level *level)
{
	if (level->map)
		free(level->map);
	free(level);
}

void	resource_free_tiles(t_game *game)
{
	int	i;

	i = 0;
	while (i < TILE_COUNT)
	{
		if (game->tiles[i].image)
			mlx_delete_image(game->window->mlx, game->tiles[i].image);
		i++;
	}
	free(game->tiles);
}
