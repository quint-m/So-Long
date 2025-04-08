/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:27:47 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/08 16:30:24 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	level_get_width(char *path)
{

}

void	level_load(char *path)
{
	t_level	*level;

	level = malloc(sizeof(t_level));
	if (!level)
		ft_error("malloc level failed");
}
