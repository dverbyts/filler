/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:14:07 by dverbyts          #+#    #+#             */
/*   Updated: 2017/09/22 15:14:08 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
#include "libft/libft.h"

typedef	struct			s_fil
{
	int		p1;
	int		p2;
	int		l;
	int		map_y;
	int		map_x;
	int		piece_y;
	int		piece_x;
	int		i1;
	int		i2;
	int		i3;
	int		i4;
	int		i5;
	int		i6;
	int		i7;
	int		i8;
	int		i9;
	char	**map;
	int		**pam;
	int		ff;
}						t_fil;

/*
** p - player nmbr
** l - player letter
** i - some iterators
** map - filler map
** pam - koef map
** ff - flag - iterator, reading 2 lines;
*/

typedef	struct			s_piece
{
	int		s_y;
	int		s_x;
	int		z_y;
	int		z_x;
	// int		u_y;
	// int		u_x;
	// int		d_y;
	// int		d_x;
	char	**p;
}						t_piece;

//int		main(void);
int		filler_make(t_fil *f, t_piece *p);
void	filler_koef_map(t_fil *f, t_piece *p);
void	filler_find_plase(t_fil *f, t_piece *p);
void	filler_free(t_fil *f, t_piece *p);
void	filler_init(t_fil *f);
void	filler_init_pam(t_fil *f);
int		filler_copy_map(t_fil *f);
int		filler_copy_piece(t_piece *p);
int		filler_point_check(t_fil *f, t_piece *p);
int		filler_piece_check(t_fil *f, t_piece *p, int y, int x);
int		filler_in_map(t_fil *f);
int		filler_dots_stars(t_fil *f, t_piece *p);
void	filler_koef(t_fil *f);

#endif
