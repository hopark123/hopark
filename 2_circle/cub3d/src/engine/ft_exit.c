/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:18:49 by hopark            #+#    #+#             */
/*   Updated: 2021/03/31 16:17:51 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_free(void *memory)
{
	if (memory)
		free(memory);
}

void				ft_free2(char **s, int i)
{
	while (i--)
	{
		if (s[i])
			ft_free(s[i]);
	}
	ft_free(s);
}

void				ft_exit_msg(t_game *g, char *msg, int code)
{
	if (code == 0)
		write(1, "ERROR\n", 6);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	ft_exit(g);
}

int					mlx_destroy_display(void *mlx_ptr)
{
	return (mlx_ptr ? 0 : 1);
}

void				ft_exit(t_game *g)
{
	int		i;

	i = -1;
	while (i++ < 4)
		(g->tex[i].ptr ? mlx_destroy_image(g->mlx, g->tex[i].ptr) : 0);
	i = -1;
	ft_free2(g->map.m, g->map.size.y);
	ft_free(g->map.no);
	ft_free(g->map.so);
	ft_free(g->map.we);
	ft_free(g->map.ea);
	ft_free(g->map.s);
	(g->img.ptr ? mlx_destroy_image(g->mlx, g->img.ptr) : 0);
	(g->win ? mlx_destroy_window(g->mlx, g->win) : 0);
	(g->mlx ? mlx_destroy_display(g->mlx) : 0);
	exit(0);
}
