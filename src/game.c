/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:00:14 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/10 15:44:32 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*game_create(t_window	*window)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("malloc: game failed");
	game->window = window;
	game->level = NULL;
	mlx_loop_hook(game->window->mlx, game_loop, game);
	return (game);
}

void	game_loop(void	*param)
{
	t_game	*game;

	game = (t_game *)param;
	window_clear_screen(game);
	draw_level(game);
}

void	game_terminate(t_game *game)
{
	mlx_close_window(game->window->mlx);
	mlx_terminate(game->window->mlx);
	mlx_delete_image(game->window->mlx, game->window->screen);
	if (game->level)
		resource_free_level(game->level);
	if (game->tiles)
		resource_free_tiles(game);
	if (game->window)
		free(game->window);
	free(game);
	exit(0);
}
