/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:10:07 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/21 17:45:44 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	point(int x, int y, t_map *m)
{
	int	x_m;
	int	y_m;

	x_m = x * m->img_x / (TS * m->t_x);
	y_m = y * m->img_y / (TS * m->t_y);
	if 	(m->data_map[x_m + y_m * m->img_x] != BLACK)
		m->data_map[x_m + y_m * m->img_x] = RED;
}

/*
int ft_fill(int num)
{

}*/
int	ft_color(int num, t_env *e)
{
	if (num == 0)
		return ((RED + e->p));
	else if (num == 1)
		return ((GREEN + e->p));
	else if (num == 2)
		return ((YELLOW + e->p));
	else if (num == 3)
		return ((CYAN + e->p) );
	else if (num == -1)
	//	ft_fill(num);
		return ((BLACK + e->p));
	return ((G3 + e->p));
}

void	ft_value_wall(t_column *c, t_env *e)
{
	if (c->face == 0)
		e->texture_x -= e->w_texture - 1;
	if (c->face == 1)
		e->texture_x -= e->w_texture - 1;
}

void	ft_texture_orientation(t_column *c, t_env *e)
{
	if (c->face == 0)
	{
		e->texture = e->tex_mur_nord;
		e->w_texture = e->w_tex_mur_nord;
		e->h_texture = e->h_tex_mur_nord;
	}
	else if (c->face == 1)
	{
		e->texture = e->tex_mur_sud;
		e->w_texture = e->w_tex_mur_sud;
		e->h_texture = e->h_tex_mur_sud;
	}
	else if (c->face == 2)
	{
		e->texture = e->tex_mur_ouest;
		e->w_texture = e->w_tex_mur_ouest;
		e->h_texture = e->h_tex_mur_ouest;
	}
	else
	{
		e->texture = e->tex_mur_est;
		e->w_texture = e->w_tex_mur_est;
		e->h_texture = e->h_tex_mur_est;
	}
}

void	make_co(int h, int i, t_env *e, t_column c)
{
	int a;
//	int color_g;
//	int color_b;
//	int texture_y;
	int color;


	a = 0;
	i = e->win_x - i;
	color = (WHITE + e->p) % CM;
	ft_value_wall(&c,e);
	ft_texture_orientation(&c,e);
	while (a < e->win_y + 1)
	{
		if (a >= (e->win_y + h) / 2)
			color = G1;
			if (a > (e->win_y - h) / 2 && a < (e->win_y + h) / 2)
					e->data[i + e->win_x * a] = ft_color(c.face, e);
			else
					e->data[i + e->win_x * a] = color;

		a++;
	}

		}

/*

		if (a >= (e->win_y + h) / 2)
			color = G1;
		e->data[i + e->win_x * a] = (a > (e->win_y - h) / 2 && a < (e->win_y + h) / 2) ?
									ft_color(c.face) : color;
		a++;*/


void	raycast(float d, t_perso *p, t_map *m, t_column *c)
{
	float	x_t;
	float	y_t;

	x_t = p->pos_x;
	y_t = p->pos_y;
	while (x_t >= 0 && x_t < m->t_x * TS && y_t >= 0 && y_t < m->t_y * TS
			&& (m->grid[(int)(y_t / TS)][(int)(x_t / TS)] != '1')
			&& (m->grid[(int)(y_t / TS)][(int)(x_t / TS)] != '2'))
	{
		x_t = x_t + sinf(d / 180 * PI);
		y_t = y_t + cosf(d / 180 * PI);
	}
	if (m->pal)
		get_column(c, (int)x_t / TS, (int)y_t / TS, x_t, y_t);
	c->d_mur = hypotf((float)(p->pos_x) - x_t, (float)(p->pos_y) - y_t);
}

void	get_view(t_env *e)
{
	int			i;
	t_column	c;
	float		d_ecr;
	float		h;
	float		d;

	i = 0;
	d_ecr = (float)e->win_x / (2 * tan(30 * PI / 180));
	while (i <= e->win_x)
	{
		d = (float)e->pe->angle - 30 + (float)i * 60 / (float)e->win_x;
		d = (d < 0) ? 360 + d : d;
		d = (d >= 360) ? d - 360 : d;
		raycast(d, e->pe, e->map, &c);
		d = (d > (float)e->pe->angle) ? d - (float)e->pe->angle : (float)e->pe->angle - d;
		c.d_mur = c.d_mur * cosf(d / 180 * PI);
		h = (d_ecr * TS) / c.d_mur;
		make_co((int)h, i, e, c);
		i++;
	}
}
/*void	mur(t_var *var, int x, t_raycasting *r)
{
	int y;
	int color_g;
	int color_b;
	int texture_y;
	int i;

	ft_texture_orientation(var, r);
	ft_value_wall(var, r);
	y = r->drawstart - 1;
	while (++y < r->drawend + 1)
	{
		i = y * 256 - WIN_Y * 128 + (r->lineheight) * 128;
		texture_y = (i * e->h_texture) / (r->lineheight) / 256;
		if (texture_y >= 0)
		{
			i = (texture_y * e->w_texture + e->texture_x) * 4;
			texture_y = e->texture[i + 2];
			color_g = e->texture[i + 1];
			color_b = e->texture[i];
			i = (y * WIN_Y + x) * 4;
			if (i > 0 && i < (WIN_Y * WIN_Y * 4))
				mlx_pixel_put_to_image(var->mlx, x, y, \
									rgb_to_hexa(texture_y, color_g, color_b));
		}
	}
}
*/
