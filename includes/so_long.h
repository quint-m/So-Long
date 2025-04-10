/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:58:21 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/10 15:44:23 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define WIDTH 720
#define HEIGHT 480
#define SCALE 1
#define TILE_COUNT 1
#define TILE_SIZE 16
#define EXIT_FAILURE 1

#include <MLX42/MLX42.h>
#include <fcntl.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_level {
  int width;
  int height;
  char *map;
} t_level;

typedef struct s_window {
  mlx_t *mlx;
  mlx_image_t *screen;
} t_window;

typedef struct s_tile {
  int id;
  mlx_image_t *image;
} t_tile;

typedef struct s_game {
  t_tile *tiles;
  t_level *level;
  t_window *window;
} t_game;

t_window	*window_create(int w, int h, int scale, char *title, bool resize);
t_game	*game_create(t_window *window);
void	window_clear_screen(t_game *game);
void	game_loop(void *param);
void	game_terminate(t_game *game);
void	ft_error(char *str);
void	keyboard_handle(mlx_key_data_t keydata, void *param);
t_level	*level_load(char *path);

void	resource_free_level(t_level *level);
void	load_tiles(t_game *game);
void	draw_level(t_game *game);
void	draw_tile(t_game *game, int x, int y);
void	resource_free_tiles(t_game *game);
#endif
