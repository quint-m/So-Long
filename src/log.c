/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:14:50 by qmennen           #+#    #+#             */
/*   Updated: 2025/04/08 16:29:23 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	if (str)
		printf("%s\n", str);
	else
		printf("%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
