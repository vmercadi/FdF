/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:36:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/25 19:00:12 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# define SIZE 42

typedef struct		s_view
{
	double			vx;
	double			vy;
	double			vz;
	double			zoom;
}					t_view;

typedef struct		s_d
{
	int				x;
	int				y;
	int				*z;
}					t_d;

typedef struct		s_base
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*av;
	int				*data;
	int				alt;
	int				size;
	int				win_x;
	int				win_y;
	int				zmax;
	int				zmin;
	int				win_size;
	int				updown;
	int				leftright;
	int				dx;
	int				dy;
	int				x;
	int				y;
	int				xi;
	int				yi;
	int				xj;
	int				yj;
	int				*x2;
	int				*y2;
	int				endian;
	int				sizeline;
	int				bpp;
	struct s_d		d;
	struct s_view	view;
	unsigned int	color;
}					t_base;

/*
** Init.c
*/

t_base				init_base(t_base *base);
void				init_d(t_base *base);

/*
** Check.c
*/

void				check_file(char *av);
void				get_xy(t_base *base, char *line);
int					get_z(t_base *base, char *line, int j);

/*
** Utils.c
*/

void				error(int e);
void				px_img(t_base *base, int x, int y, int color);
void				conv_iso(t_base *base, int n, int i);
void				clean(t_base *base);

/*
** Display.c
*/

void				start_line(t_base *base);
void				draw_hori(t_base *base);
void				draw_verti(t_base *base);
void				line1(t_base *base, int xx, int yy);
void				line2(t_base *base, int xx, int yy);

/*
** Event.c
*/

int					event(int keycode, void *param);
void				ev_move(int k, t_base *base);
void				ev_else(int k, t_base *base);
void				refresh(t_base *base);

/*
** FDF.c
*/

void				fdf(t_base *base);
void				ui(t_base *base);

#endif
