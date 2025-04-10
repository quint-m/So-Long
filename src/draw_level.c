/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:15:01 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/10 15:42:21 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_level(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->level->height)
	{
		x = 0;
		while (x < game->level->width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}
