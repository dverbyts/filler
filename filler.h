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
	int		u_y;
	int		u_x;
	int		d_y;
	int		d_x;
	char	**p;
}						t_piece;
