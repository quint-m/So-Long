/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:27:47 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/10 15:51:29 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static int	level_get_height(char *path)
{
	int		fd;
	int		height;
	char	*line;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("open: failed opening map file");
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		height++;
	}
	close (fd);
	return (height);
}

static int	process_row(char **line)
{
	int	width;

	width = 0;
	while (line[width])
	{
		width++;
		free(line[width - 1]);
	}
	free(line);
	return (width);
}

static int	level_get_width(char *path)
{
	int		fd;
	int		p_width;
	int		width;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("open: failed opening map file");
	width = 0;
	p_width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		p_width = width;
		width = process_row(ft_split(line, ' '));
		if (p_width != 0 && p_width != width)
			ft_error("map size is inconsistent");
		free(line);
	}
	close (fd);
	return (width);
}

static void	map_read(char *path, t_level *level)
{
	int		fd;
	int		y;
	int		x;
	char	*line;
	char	**split;

	y = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("open: failed opening map file");
	while (1)
	{
		x = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		while (split[x])
		{
			level->map[x + y * level->width] = *split[x];
			x++;
			free(split[x - 1]);
		}
		y++;
		free(split);
		free(line);
	}
	close(fd);
}

t_level	*level_load(char *path)
{
	t_level	*level;

	level = malloc(sizeof(t_level));
	if (!level)
		ft_error("malloc level failed");
	ft_memset(level, 0, sizeof(t_level));
	level->height = level_get_height(path);
	printf("level height %i\n", level->height);
	level->width = level_get_width(path);
	printf("level width %i\n", level->width);
	level->map = malloc((level->width * level->height) + 1);
	if (! level->map)
		ft_error("malloc: level map failed");
	map_read(path, level);
	level->map[level->width * level->height] = 0;
	return (level);
}
