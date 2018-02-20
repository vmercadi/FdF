/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:46:46 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/25 19:06:37 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Write the pixel in the image
*/

void	px_img(t_base *base, int x, int y, int color)
{
	if (x > base->win_x || x < 0 || y > base->win_y || y < 0)
		return ;
	base->data[y * base->win_x + x] = color;
}

/*
** All the parsing & args errors
*/

void	error(int e)
{
	ft_putstr("Error: ");
	if (e == -1)
		ft_putendlcolor("Usage: ./fdf map.fdf", GREEN);
	else if (e == 1)
		ft_putstr_fd("Too much arguments.", 2);
	else if (e == 2)
		ft_putstr_fd("A map is needed as argument.", 2);
	else if (e == 3)
		ft_putstr_fd("File is empty or doesn't exist.", 2);
	else if (e == 4)
		ft_putstr_fd("Map contain some wrong char.", 2);
	else if (e == 5)
		ft_putstr_fd("Argument given is not a file.", 2);
	else if (e == 6)
		ft_putstr_fd("Map is not okay.", 2);
	exit(0);
}

/*
** Isometric conversion of the 3D points to 2D points
*/

void	conv_iso(t_base *base, int n, int i)
{
	base->x = base->xi - base->d.x / 2;
	base->y = base->yi - base->d.y / 2;
	base->xi = base->view.vx * (base->x - base->y) * base->view.zoom;
	base->yi = base->view.vy * (base->x + base->y) * base->view.zoom;
	base->yi -= base->d.z[i] * base->alt / 3;
	if (n)
	{
		base->xj = base->view.vx * ((base->x + 1) - base->y) * base->view.zoom;
		base->yj = base->view.vy * ((base->x + 1) + base->y) * base->view.zoom;
		base->yj -= base->d.z[i + 1] * base->alt / 3;
	}
	else
	{
		base->xj = base->view.vx * (base->x - (base->y + 1)) * base->view.zoom;
		base->yj = base->view.vy * (base->x + (base->y + 1)) * base->view.zoom;
		base->yj -= base->d.z[i + base->d.x] * base->alt / 3;
	}
	base->xi += base->win_x / 2 - base->d.x / 2;
	base->xj += base->win_x / 2 - base->d.x / 2;
	base->yi += base->win_y / 2 - base->d.y / 2;
	base->yj += base->win_y / 2 - base->d.y / 2;
}

/*
** Free all the tabs
*/

void	clean(t_base *base)
{
	mlx_destroy_window(base->mlx, base->win);
	mlx_destroy_image(base->mlx, base->img);
	free(base->d.z);
	ft_strdel(&base->av);
	exit(0);
}
