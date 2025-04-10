/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:58:18 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/10 14:59:05 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	*game;
	int		x;
	int		y;
	
	game = game_create(window_create(WIDTH, HEIGHT, SCALE, "So Long", false));
	game->level = level_load("assets/maps/map.test");
	mlx_key_hook(game->window->mlx, keyboard_handle, (void *)game);
	mlx_loop(game->window->mlx);
	game_terminate(game);
	return (0);
}
