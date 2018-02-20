/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:42:37 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/25 19:06:12 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Give the points to draw the horizontals lines
*/

void	draw_hori(t_base *base)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < base->d.y - 1)
	{
		x = 0;
		while (x < base->d.x)
		{
			base->xi = x - base->leftright + base->updown;
			base->yi = y + base->updown + base->leftright;
			base->xj = x - base->leftright + base->updown + 1;
			base->yj = y + base->updown + base->leftright + 1;
			conv_iso(base, 0, i);
			if (x + 1 <= base->d.x)
				start_line(base);
			i++;
			x++;
		}
		y++;
	}
}

/*
** Give the points to draw the verticals lines
*/

void	draw_verti(t_base *base)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < base->d.y)
	{
		x = 0;
		while (x < base->d.x)
		{
			base->xi = x - base->leftright + base->updown;
			base->yi = y + base->updown + base->leftright;
			base->xj = x - base->leftright + base->updown + 1;
			base->yj = y + base->updown + base->leftright + 1;
			conv_iso(base, 1, i);
			if (x + 1 < base->d.x)
				start_line(base);
			i++;
			x++;
		}
		y++;
	}
	draw_hori(base);
}

/*
** Init the lines values and start the line() needed
*/

void	start_line(t_base *base)
{
	int	xx;
	int	yy;

	base->x = base->xi;
	base->y = base->yi;
	base->dx = base->xj - base->xi;
	base->dy = base->yj - base->yi;
	xx = (base->dx > 0) ? 1 : -1;
	yy = (base->dy > 0) ? 1 : -1;
	base->dx = abs(base->dx);
	base->dy = abs(base->dy);
	px_img(base, base->x, base->y, base->color);
	if (base->xi >= base->win_x || base->yi >= base->win_y ||
		base->xj >= base->win_x || base->yj >= base->win_y ||
		base->xi < 0 || base->yi < 0 || base->xj < 0 || base->yj < 0)
		return ;
	if (base->dx > base->dy)
		line1(base, xx, yy);
	else
		line2(base, xx, yy);
}

/*
** Draw the lines between
*/

void	line1(t_base *base, int xx, int yy)
{
	int	i;
	int cumul;

	i = 1;
	cumul = base->dx / 2;
	while (i <= base->dx)
	{
		base->x += xx;
		cumul += base->dy;
		if (cumul >= base->dx)
		{
			cumul -= base->dx;
			base->y += yy;
		}
		px_img(base, base->x, base->y, base->color);
		i++;
	}
}

void	line2(t_base *base, int xx, int yy)
{
	int	i;
	int cumul;

	i = 1;
	cumul = base->dy / 2;
	while (i <= base->dy)
	{
		base->y += yy;
		cumul += base->dx;
		if (cumul >= base->dy)
		{
			cumul -= base->dy;
			base->x += xx;
		}
		px_img(base, base->x, base->y, base->color);
		i++;
	}
}
