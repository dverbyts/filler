/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:53:37 by dverbyts          #+#    #+#             */
/*   Updated: 2017/09/26 20:53:39 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		filler_point_check(t_fil *f, t_piece *p)
{
	if (f->i1 > 0 && f->i3 == 0)
	{
		if (f->map[f->i1 - 1][f->i2] == (char)f->p1 ||
			f->map[f->i1 - 1][f->i2] == (char)(f->p1 + 32))
			f->i3 = filler_piece_check(f, p, f->i1 - 1, f->i2);
	}
	if (f->i1 < (f->map_y - 1) && f->i3 == 0)
	{
		if (f->map[f->i1 + 1][f->i2] == (char)f->p1 ||
			f->map[f->i1 + 1][f->i2] == (char)(f->p1 + 32))
			f->i3 = filler_piece_check(f, p, f->i1 + 1, f->i2);
	}
	if (f->i2 > 0 && f->i3 == 0)
	{
		if (f->map[f->i1][f->i2 - 1] == (char)f->p1 ||
			f->map[f->i1][f->i2 - 1] == (char)(f->p1 + 32))
			f->i3 = filler_piece_check(f, p, f->i1, f->i2 - 1);
	}
	if (f->i2 < (f->map_x - 1) && f->i3 == 0)
	{
		if (f->map[f->i1][f->i2 + 1] == (char)f->p1 ||
			f->map[f->i1][f->i2 + 1] == (char)(f->p1 + 32))
			f->i3 = filler_piece_check(f, p, f->i1, f->i2 + 1);
	}
	return (f->i3);
}

int		filler_piece_check(t_fil *f, t_piece *p, int y, int x)
{
	f->i4 = -1;
	f->i6 = y;
	f->i7 = x;
	while (++f->i4 < p->s_y)
	{
		f->i5 = -1;
		while (++f->i5 < p->s_x)
		{
			if (p->p[f->i4][f->i5] == '*' && filler_in_map(f) == 1)
			{
				p->z_y = f->i4;
				p->z_x = f->i5;
				if (filler_dots_stars(f, p) == 1)
					return (1);
				else
				{
					p->z_y = 0;
					p->z_x = 0;
				}
			}
		}
	}
	return (0);
}


int		filler_in_map(t_fil *f)
{
	int re;

	re = 0;
	if ((f->i6 - f->i4) >= 0 && (f->i7 - f->i5) >= 0)
		re++;
	if ((f->i6 + (f->piece_y - f->i4)) < f->map_y &&
		(f->i7 + (f->piece_x - f->i5)) < f->map_x)
		re++;
	if (re == 2)
		return (1);
	return (0);
}

int		filler_dots_stars(t_fil *f, t_piece *p)
{
	f->i8 = -1;
	while (++f->i8 < p->s_y)
	{
		f->i9 = 0;
		while (f->i9 < p->s_x)
		{
			if ((f->i8 == p->z_y && f->i9 == p->z_x) || p->p[f->i8][f->i9] == '.')
				f->i9++;
			else if (p->p[f->i8][f->i9] == '*')
			{
				if (f->map[f->i6 + (f->i8 - p->z_y)][f->i7 + (f->i9 - p->z_x)]
					== '.')
					f->i9++;
				else
					return (0);
			}
		}
	}
	return (1);
}

void	filler_koef(t_fil *f)
{
	f->i3 = -1;
	while (++f->i3 < f->map_y)
	{
		f->i4 = -1;
		while (++f->i4 < f->map_x)
		{
			if (f->map[f->i3][f->i4] == (char)f->p2 ||
				f->map[f->i3][f->i4] == (char)(f->p2 + 32))
			{	
				f->i5 = (f->i1 - f->i3) < 0 ? (f->i1 - f->i3) * -1 :
				f->i1 - f->i3;
				f->i6 = (f->i2 - f->i4) < 0 ? (f->i2 - f->i4) * -1 :
				f->i2 - f->i4;
//				f->i5 = 0;
//				f->i6 = 0;
//				filler_koef2(f);
				f->i7 = f->i5 > f->i6 ? f->i5 : f->i6;
				if (f->pam[f->i1][f->i2] == 0 || f->pam[f->i1][f->i2] > f->i7)
					f->pam[f->i1][f->i2] = f->i7;
			}
		}
	}
}

// void	filler_koef2(t_fil *f)
// {
// 	f->i5 = (f->i1 - f->i3) < 0 ? (f->i1 - f->i3) * -1 : f->i1 - f->i3;
// 	f->i6 = (f->i2 - f->i4) < 0 ? (f->i2 - f->i4) * -1 : f->i2 - f->i4;
// }
