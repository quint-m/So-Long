/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:58:18 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/10 15:53:46 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	*game;
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	game = game_create(window_create(WIDTH, HEIGHT, SCALE, "So Long", false));
	game->level = level_load("assets/maps/map.test");
	load_tiles(game);
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			printf("%c", game->level->map[x +y * 4]);
			x++;
		}
		printf("\n");
		y++;
	}
	mlx_key_hook(game->window->mlx, keyboard_handle, (void *)game);
	mlx_loop(game->window->mlx);
	game_terminate(game);
	return (0);
}
