/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:07:08 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 17:05:50 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_color(t_env *env, int i)
{
	if (env->rc.render.tex_y > 0)
	{
		if (env->rc.sprite[i].get_data[env->rc.render.tex_x + \
		env->rc.render.tex_y * env->rc.sprite[i].width] != 0)
			env->rc.sprite[i].color = env->rc.sprite[i].get_data[env->\
			rc.render.tex_x + env->rc.render.tex_y * env->rc.sprite[i].width];
		else
			env->rc.sprite[i].color = 0xBFD195;
	}
}

static void	last_render_sprite(t_env *env, int x, int i)
{
	int	y;
	int	d;

	y = env->rc.render.start_y;
	while (y < env->rc.render.end_y)
	{
		d = (y * 256 - env->height_screen * 128 + env->rc.render.height * 128);
		env->rc.render.tex_y = (d * env->rc.sprite[i].height / \
		env->rc.render.height) / 256;
		get_color(env, i);
		if (env->rc.sprite[i].color != 0xBFD195 && env->rc.render.transform_y \
		< env->rc.render.dist_wall[x])
		{
			if (x >= 0 && x < env->width_screen && y >= 0 && y \
			< env->height_screen)
			{
				env->get_data[x + y * (env->size_line / 4)] = \
				env->rc.sprite[i].color;
			}
		}
		y++;
	}
}

static void	aux_render_sprite_2(t_env *env)
{
	if (env->rc.render.start_y < 0)
		env->rc.render.start_y = 0;
	env->rc.render.end_y = env->rc.render.height / 2 + env->height_screen / 2;
	if (env->rc.render.end_y >= env->height_screen)
		env->rc.render.end_y = env->height_screen - 1;
	env->rc.render.width = abs((int)(env->height_screen / \
	env->rc.render.transform_y));
	env->rc.render.start_x = -env->rc.render.width / 2 + \
	env->rc.render.screen_x;
	if (env->rc.render.start_x < 0)
		env->rc.render.start_x = 0;
	env->rc.render.end_x = env->rc.render.width / 2 + env->rc.render.screen_x;
	if (env->rc.render.end_x >= env->width_screen)
		env->rc.render.end_x = env->width_screen - 1;
}

static void	aux_render_sprite_1(t_env *env, int i)
{
	env->rc.render.x = env->rc.sprite[env->rc.sprite[i].order].coord_x \
	- env->rc.player.position_x;
	env->rc.render.y = env->rc.sprite[env->rc.sprite[i].order].coord_y \
	- env->rc.player.position_y;
	env->rc.render.inv_det = 1 / (env->rc.plan_x * env->rc.player.dir_y - \
	env->rc.player.dir_x * env->rc.plan_y);
	env->rc.render.transform_x = env->rc.render.inv_det * \
	(env->rc.player.dir_y * env->rc.render.x - env->rc.player.dir_x * \
	env->rc.render.y);
	env->rc.render.transform_y = env->rc.render.inv_det * (-env->rc.plan_y * \
	env->rc.render.x + env->rc.plan_x * env->rc.render.y);
	env->rc.render.screen_x = (int)((env->width_screen / 2) * \
	(1 + env->rc.render.transform_x / env->rc.render.transform_y));
	env->rc.render.height = abs((int)(env->height_screen / \
	env->rc.render.transform_y));
	env->rc.render.start_y = -env->rc.render.height / 2 + \
	env->height_screen / 2;
	aux_render_sprite_2(env);
}

void		ft_render_sprite(t_env *env)
{
	int	i;
	int	x;

	i = 0;
	while (i < env->rc.nbr_sprites)
	{
		aux_render_sprite_1(env, i);
		x = env->rc.render.start_x;
		while (x < env->rc.render.end_x && x < env->width_screen)
		{
			env->rc.render.tex_x = (int)(256 * (x - (-env->rc.render.width / \
			2 + env->rc.render.screen_x)) * env->rc.sprite[i].width / \
			env->rc.render.width) / 256;
			if (env->rc.render.transform_y > 0)
				last_render_sprite(env, x, i);
			x++;
		}
		i++;
	}
}
