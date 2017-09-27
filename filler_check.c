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

int		filler_point_check(s_fil *f, s_piece *p)
{
	f->i3 = 0;
	if (f->i1 > 0 && f->i3 == 0)
	{
		if (f->map[f->i1 - 1][f->i2] == (char)f->p1 ||
			f->map[f->i1 - 1][f->i2] == ((char)(f->p1 + 32)))
			f->i3 = filler_piece_check(f, p, f->i1 - 1, f->i2);
	}
	if (f->i1 < (f->map_y - 1) && f->i3 == 0)
	{
		if (f->map[f->i1 + 1][f->i2] == (char)f->p1 ||
			f->map[f->i1 + 1][f->i2] == ((char)(f->p1 + 32)))
			f->i3 = filler_piece_check(f, p, f->i1 + 1, f->i2);
	}
	if (f->i2 > 0 && f->i3 == 0)
	{
		if (f->map[f->i1][f->i2 - 1] == (char)f->p1 ||
			f->map[f->i1][f->i2 - 1] == ((char)(f->p1 + 32)))
			f->i3 = filler_piece_check(f, p, f->i1, f->i2 - 1);
	}
	if (f->i2 < (f->map_x - 1) && f->i3 == 0)
	{
		if (f->map[f->i1][f->i2 + 1] == (char)f->p1 ||
			f->map[f->i1][f->i2 + 1] == ((char)(f->p1 + 32)))
			f->i3 = filler_piece_check(f, p, f->i1, f->i2 + 1);
	}
	return (f->i3);
}

int 	filler_piece_check(s_fil *f, s_piece *, int y, int x)
{
	f->ff = 0;
	f->i4 = -1;
	while (++f->i4 < p->s_y)
	{
		f->i5 = -1;
		while (++f->i5 < p->s_x)
		{
			if (p->p[f->i4][f->i5] == '*' && f->ff = 0 &&
				filler_piece_check ())
			{

			}
		}
	}
}
