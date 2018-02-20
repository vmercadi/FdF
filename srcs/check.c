/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 21:33:33 by vmercadi          #+#    #+#             */
/*   Updated: 2017/09/25 19:03:42 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Check if file is okay
*/

void	check_file(char *av)
{
	int		i;
	int		fd;
	char	*s;

	if (!ft_strcmp(av, "usage"))
		error(-1);
	if ((fd = open(av, O_RDONLY)) < 0)
		error(3);
	s = NULL;
	while (get_next_line(fd, &s) > 0)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == ',' && s[i + 1] == '0' && s[i + 2 == 'x'])
				;
			else if ((!ft_isdigit(s[i]) && !ft_isalpha(s[i])
				&& s[i] != ' ' && s[i] != '-' && s[i] != 9))
				error(4);
			i++;
		}
		free(s);
	}
	close(fd);
}

/*
** Get the x & y values
*/

void	get_xy(t_base *base, char *line)
{
	base->xi = 0;
	base->xj = 0;
	while (line[base->xi])
	{
		while (line[base->xi] && !ft_isdigit(line[base->xi]))
			base->xi++;
		while (line[base->xi] && line[base->xi] != ' ')
			base->xi++;
		if (ft_isdigit(line[base->xi - 1]))
			base->xj++;
	}
	base->xi = 0;
	while (line[base->xi])
	{
		if (ft_isdigit(line[base->xi++]))
		{
			base->d.y++;
			break ;
		}
	}
	base->d.x = (base->xj > base->d.x) ? base->xj : base->d.x;
	if (base->xj != base->d.x && base->d.x > 0 && base->xj != 0)
		error(6);
}

/*
** Fill the z tab
*/

int		get_z(t_base *base, char *line, int j)
{
	int		i;
	int		k;
	char	**c;
	char	*a;

	i = 0;
	k = 0;
	c = ft_strsplit(line, ' ');
	while (c[i])
	{
		a = NULL;
		if ((a = ft_strchr(c[i], ',')))
			*a = '\0';
		base->d.z[j] = ft_atoi(c[i]);
		if (base->d.z[j] > base->zmax)
			base->zmax = base->d.z[j];
		else if (base->d.z[j] < base->zmin)
			base->zmin = base->d.z[j];
		j++;
		i++;
		if (a == '\0')
			free(a++);
	}
	free_tab((void **)c);
	return (j);
}
