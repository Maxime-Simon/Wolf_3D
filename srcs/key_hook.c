/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:46 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/28 16:10:48 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int	key_press(int k, t_env *e)
{
	e->pe->mv_y = (k == W) ? 1 : e->pe->mv_y;
	e->pe->mv_y = (k == S) ? -1 : e->pe->mv_y;
	e->pe->mv_x = (k == D) ? -1 : e->pe->mv_x;
	e->pe->mv_x = (k == A) ? 1 : e->pe->mv_x;
	e->pe->mv_r = (k == RIGHT) ? -1 : e->pe->mv_r;
	e->pe->mv_r = (k == LEFT) ? 1 : e->pe->mv_r;
	if (k == M)
		e->pm = (e->pm) ? 0 : 1;
	if (k == R)
		ft_clean(e);
	if (k == P)
	{
		e->p = 0;
		e->psi = (e->psi) ? 0 : 1;
	}
	if (k == UP && e->pe->pos_z > -740)
		e->pe->pos_z -= 10;
	if (k == DOWN && e->pe->pos_z < 740)
		e->pe->pos_z += 10;
	expose_hook(e);
	return (0);
}

int	key_release(int k, t_env *e)
{
	if (k == ESC)
		ft_exit(3);
	if (k == W || k == S)
		e->pe->mv_y = 0;
	if (k == D || k == A)
		e->pe->mv_x = 0;
	if (k == LEFT || k == RIGHT)
		e->pe->mv_r = 0;
	expose_hook(e);
	return (0);
}
