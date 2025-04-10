/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:17:08 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/10 15:58:12 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_png_path(int id)
{
	char	*iid;
	char	*file_name;
	char	*path;
	iid = ft_itoa(id);
	file_name = ft_strjoin(iid, ".png");
	path = ft_strjoin("./assets/tiles/", file_name);
	free(iid);
	free(file_name);
	return (path);
}

void	load_tiles(t_game *game)
{
	int				id;
	char			*path;
	mlx_texture_t	*texture;
	t_tile			*tiles;

	id = 0;
	tiles = malloc(sizeof(t_tile) * TILE_COUNT);
	if (!tiles)
		ft_error("tile: failed allocating tiles");
	while (id < TILE_COUNT)
	{
		path = get_png_path(id);
		texture = mlx_load_png(path);
		if (!texture)
			ft_error("tile: failed loading tile texture");
		tiles[id].id = id;
		tiles[id].image = mlx_texture_to_image(game->window->mlx, texture);
		mlx_delete_texture(texture);
		free(path);
		id++;
	}
	game->tiles = tiles;
}

void	draw_tile(t_game *game, int x, int y)
{
	int	tid;

	tid = game->level->map[x + y * game->level->width];
	tid = 0;
	if (tid < 0 || tid > TILE_COUNT)
		ft_error("draw tile: unrecognized tile id");
	if (mlx_image_to_window(game->window->mlx, game->tiles[(int) tid].image, x * TILE_SIZE + 1, y * TILE_SIZE + 1) < 0)
		ft_error("draw tile: mlx image to window failed");
}

