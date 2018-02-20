/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:36:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/15 15:19:42 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Start the computing and drawing of the fdf
*/

void	fdf(t_base *base)
{
	refresh(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
	ui(base);
	mlx_hook(base->win, 2, 0, event, base);
	mlx_loop(base->mlx);
}

/*
** Print the UI on the window
*/

void	ui(t_base *base)
{
	int w;

	w = 0xffffff;
	mlx_string_put(base->mlx, base->win, 50, 20, 0x00ff00, "    - KEYS -");
	mlx_string_put(base->mlx, base->win, 50, 50, w, "Move   =  Arrows");
	mlx_string_put(base->mlx, base->win, 50, 70, w, "Colors =  NumPad");
	mlx_string_put(base->mlx, base->win, 50, 90, w, "Quit   =  Esc");
	mlx_string_put(base->mlx, base->win, 50, 110, w, "Zoom   =  +  &  -");
	mlx_string_put(base->mlx, base->win, 50, 130, w, "Depth  =  <  &  >");
}

int		main(int ac, char **av)
{
	t_base	base;

	if (ac > 2)
		error(1);
	else if (ac < 2)
		error(2);
	if (!ft_strcmp(av[1], "usage"))
		error(-1);
	base.av = ft_strdup(av[1]);
	check_file(base.av);
	base = init_base(&base);
	base.updown = 0;
	base.leftright = 0;
	base.color = 0x00ff00;
	fdf(&base);
	return (0);
}
