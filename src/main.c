/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:58:18 by qmennen           #+#    #+#             */
/*   Updated: 2025/03/27 19:33:21 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	*game;
	
	game = game_create(window_create(WIDTH, HEIGHT, SCALE, "So Long", false));
	mlx_key_hook(game->window->mlx, keyboard_handle, (void *)game);
	mlx_loop(game->window->mlx);
	game_terminate(game);
	return (0);
}
