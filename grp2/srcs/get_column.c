/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:45:55 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/21 17:38:37 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	get_column(t_column *c, int x_mur, int y_mur, float x_touch, float y_touch)
{
	float		w_r;
	float		w_l;
	float		w_d;
	float		w_u;

	w_u = TS * y_mur;
	w_d = TS * (y_mur + 1);
	w_l = TS * x_mur;
	w_r = TS * (x_mur + 1);
	c->face = -1;
	if(fabs(y_touch - w_u) <= 1)
		c->face = 0;
	if(fabs(y_touch - w_d) <= 1)
		c->face = (c->face == -1) ? 1 : c->old_face;
	if(fabs(x_touch - w_r) <= 1)
		c->face = (c->face == -1) ? 2 : c->old_face;
	if(fabs(x_touch - w_l) <= 1)
		c->face = (c->face == -1) ? 3 : c->old_face;
	if (c->face == 0 && !y_mur)
		c->face = 1;
	if (c->face == 3 && !x_mur)
		c->face = 2;
	c->old_face = c->face;
}
