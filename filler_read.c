/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:06:08 by dverbyts          #+#    #+#             */
/*   Updated: 2017/09/25 15:06:10 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler_init(t_fil *f)
{
	char	*line;

	get_next_line(0, &line);
	while (line[0] != '$')
	{
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	f->ff++;
	if (ft_atoi(&line[10]) == 1)
		f->p1 = (int)'O';
	else
		f->p1 = (int)'X';
	f->p2 = f->p1 == (int)'O' ? (int)'X' : (int)'O';
	ft_strdel(&line);
	get_next_line(0, &line);
	f->ff++;
	f->map_y = ft_atoi(&line[8]);
	f->i1 = 8;
	while (ft_isdigit(line[f->i1]))
		f->i1++;
	while (!(ft_isdigit(line[f->i1])))
		f->i1++;
	f->map_x = ft_atoi(&line[f->i1]);
	ft_strdel(&line);
	f->i1 = 0;
	f->map = (char **)malloc(sizeof(char *) * (f->map_y));
	ft_bzero(f->map, sizeof(char *) * (f->map_y));
	filler_init_pam(f);
}

void	filler_init_pam(t_fil *f)
{
	f->i1 = 0;
	f->pam = (int **)malloc(sizeof(int *) * (f->map_y));
	while (f->i1 < f->map_y)
		f->pam[f->i1++] = (int *)malloc(sizeof(int) * (f->map_x));
}

int		filler_copy_map(t_fil *f)
{
	char	*line;

	while(f->ff++ <= 1)
	{
		if (get_next_line(0, &line) != 1)
			return (0);
		ft_strdel(&line);
	}
	f->i1 = 0;
	while(f->i1 < f->map_y)
	{
		if (get_next_line(0, &line) != 1)
			return (0);
		f->map[f->i1++] = ft_strdup(line);
		ft_strdel(&line);
	}
	f->i1 = 0;
	f->ff = 0;
	return (1);
}

int		filler_copy_piece(t_piece *p)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) != 1)
		return (0);
	p->s_y = ft_atoi(&line[6]);
	p->s_x = ft_atoi(&line[8]);
	ft_strdel(&line);
	p->p = (char **)malloc(sizeof(char *) * (p->s_y));
	ft_bzero(p->p, sizeof(char *) * (p->s_y));
	i = 0;
	while(i < p->s_y)
	{
		if (get_next_line(0, &line) != 1)
			return (0);
		p->p[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	return (1);
//	filler_cords_piece(p);
}

// void	filler_cords_piece(t_piece *p)
// {
// 	p->u_y = -1;
// 	while (++p->u_y < p->s_y)
// 	{
// 		p->u_x = -1;
// 		while (++p->u_x < p->s_x)
// 		{
// 			if (p->p[p->u_y][p->u_x] == '*')
// 				break ;
// 		}
// 		if (p->p[p->u_y][p->u_x] == '*')
// 			break ;
// 	}
// 	p->d_y = p->s_y;
// 	while (--p->d_y > -1)
// 	{
// 		p->d_x = p->s_x;
// 		while (--p->d_x > -1)
// 		{
// 			if (p->p[p->d_y][p->d_x] == '*')
// 				break ;
// 		}
// 		if (p->p[p->d_y][p->d_x] == '*')
// 			break ;
// 	}
// }
