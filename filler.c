/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 20:02:56 by dverbyts          #+#    #+#             */
/*   Updated: 2017/09/21 20:02:58 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_fil	*f;
	t_piece	*p;

	f = (t_fil *)malloc(sizeof(t_fil));
	ft_bzero(f, sizeof(t_fil));
	p = (t_piece *)malloc(sizeof(t_piece));
	ft_bzero(p, sizeof(t_piece));
	filler_init(f);
	while (1)
	{
		if (filler_make(f, p) != 1)
			ft_printf("%d %d\n", -1, -1);
		ft_printf("%d %d\n", f->piece_y, f->piece_x);
		f->ff = 0;
		f->piece_y = 0;
		f->piece_x = 0;
	}
	return (1);
}

int		filler_make(t_fil *f, t_piece *p)
{
	if (filler_copy_map(f) == 0)
		return (-1);
	if (filler_copy_piece(p) == 0)
		return (-1);
	filler_koef_map(f, p);
	f->i3 = 0;
	filler_find_plase(f, p);
	if (f->ff == 0)
		return (-1);
	filler_free(f, p);
	return (1);
}

void	filler_koef_map(t_fil *f, t_piece *p)
{
	f->i1 = -1;
	while (++f->i1 < f->map_y)
	{
		f->i2 = -1;
		while (++f->i2 < f->map_x)
		{
			f->pam[f->i1][f->i2] = 0;
			f->i3 = 0;
			if (f->map[f->i1][f->i2] == '.' && filler_point_check(f, p) > 0)
				filler_koef(f);
		}
	}
}

void	filler_find_plase(t_fil *f, t_piece *p)
{
	f->i1 = -1;
	while (++f->i1 < f->map_y)
	{
		f->i2 = -1;
		while (++f->i2 < f->map_x)
		{
			if (f->pam[f->i1][f->i2] > 0)
			{
				if (f->i3 > f->pam[f->i1][f->i2] || f->i3 == 0)
				{
					f->i3 = f->pam[f->i1][f->i2];
					f->i4 = f->i1;
					f->i5 = f->i2;
				}
			}
		}
	}
	f->ff = f->i3;
	f->i3 = 0;
	f->i1 = f->i4;
	f->i2 = f->i5;
	if (filler_point_check(f, p) == 0)
		return ;
	f->piece_y = f->i6 - p->z_y;
	f->piece_x = f->i7 - p->z_x;
}

void	filler_free(t_fil *f, t_piece *p)
{
	f->i1 = -1;
	while (++f->i1 < f->map_y)
		ft_strdel(&f->map[f->i1]);
	f->i1 = -1;
	while (++f->i1 < p->s_y)
		ft_strdel(&p->p[f->i1]);
	ft_strdel(p->p);
	p->s_y = 0;
	p->s_x = 0;
	p->z_y = 0;
	p->z_x = 0;
	f->i1 = -1;
	f->i1 = 0;
	f->i2 = 0;
	f->i3 = 0;
	f->i4 = 0;
	f->i5 = 0;
	f->i6 = 0;
	f->i7 = 0;
	f->i8 = 0;
	f->i9 = 0;
}
