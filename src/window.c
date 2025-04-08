/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:11:16 by qmennen           #+#    #+#             */
/*   Updated: 2025/03/27 19:33:48 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_window	*window_create(int w, int h, int scale, char *title, bool resize)
{
	t_window	*window;
	mlx_t		*mlx;
	mlx_image_t	*screen;

	window = malloc(sizeof(t_window));
	if (! window)
		ft_error("malloc: window failed");
	mlx = mlx_init(w * scale, h * scale, title, resize);
	if (!mlx)
		ft_error(NULL);
	window->mlx = mlx;
	screen = mlx_new_image(window->mlx, w, h);
	if (!screen)
		ft_error(NULL);
	window->screen = screen;
	if (mlx_image_to_window(window->mlx, window->screen, 0, 0) < 0)
		ft_error("image to window: failed");
	return (window);
}
void	window_clear_screen(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx_put_pixel(game->window->screen, i, j, 0x212121FF);
			j++;
		}
		i++;
	}
}