/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:26:28 by qmennen           #+#    #+#             */
/*   Updated: 2025/03/27 19:32:08 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyboard_handle(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)game;
	if (keydata.key == MLX_KEY_ESCAPE)
		game_terminate(game);
}
