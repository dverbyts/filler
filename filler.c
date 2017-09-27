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
	s_fil	*f;
	s_piece	*p;

	f = (s_fil *)malloc(sizeof(s_fil));
	ft_bzero(f, sizeof(s_fil));
	p = (s_piece *)malloc(sizeof(s_piece));
	ft_bzero(p, sizeof(s_piece));
	filler_init(f);
	while (1)
	{
		if (filler_make(f, p) != 1)
			return (filler_free_all(f, p));
		ft_printf("%i %i\n", f->piece_y, f->piece_x);
		f->ff = 0;
		f->piece_y = 0;
		f->piece_x = 0;
	}
	return (1);
}

int		filler_make(s_fil *f, s_piece *p)
{
	filler_copy_map(f);
	filler_copy_piece(p);
	filler_koef_map(f, p);
	if (filler_find_plase(f, p) != 1)
		return (-1);
	filler_free_map(f);
	filler_free_piece(p);
	filler_free_koef_map(f);
	return (1);
}

int		filler_free_all(s_fil *f, s_piece *p)
{
	filler_free_map(f);
	filler_free_piece(f);
	filler_free_koef_map(f);
	filler_free_struct(f);
	return (-1);
}

void	filler_koef_map(s_fil *f, s_piece *p);
{
	if (!f->pam)
	{
		f->i1 = 0;
		f->pam = (int **)malloc(sizeof(int *) * (f->map_y));
		while (f->i1 < f->map_y)
			f->pam[f->i1++] = (int *)malloc(sizeof(int) * (f->map_x));
	}
	f->i1 = 0;
	ft_bzero(f->pam, f->map_y);
	while (f->i1 < f->map_y)
		ft_bzero(f->pam[f->i1++], f->map_x);
	f->i1 = 0;
	while (f->i1 < f->map_y)
	{
		f->i2 = 0;
		while (f->i2 < f->map_x)
		{
			if (f->map[f->i1][f->i2] == '.' && filler_point_check(f) > 0 )
				filler_koef(f);
			f->i2++;
		}
		f->i1++;
	}
}
