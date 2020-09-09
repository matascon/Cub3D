/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:25:38 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:58:42 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	texture_wall(t_env *env)
{
	if (env->rc.side == 0 && env->rc.ray_x > 0)
		return (env->rc.east);
	else if (env->rc.side == 0 && env->rc.ray_x < 0)
		return (env->rc.west);
	else if (env->rc.side == 1 && env->rc.ray_y > 0)
		return (env->rc.south);
	else
		return (env->rc.north);
}

static void			set_texture(t_env *env, int x)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			y;
	t_texture	tex_wall;

	tex_wall = texture_wall(env);
	if (env->rc.side == 0)
		wall_x = env->rc.player.position_y + env->rc.perp_wall_dist * \
		env->rc.ray_y;
	else
		wall_x = env->rc.player.position_x + env->rc.perp_wall_dist * \
		env->rc.ray_x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)tex_wall.width;
	y = env->rc.draw_start;
	while (y++ < env->rc.draw_end)
	{
		tex_y = (y - env->height_screen / 2 + env->rc.line_height / 2) * \
		tex_wall.height / env->rc.line_height;
		if (tex_y < 0)
			return ;
		env->get_data[x + y * (env->size_line / 4)] = tex_wall.get_data\
		[tex_x + tex_y * tex_wall.width];
	}
}

void				ft_raycast_columns(t_env *env, int x, int y)
{
	env->rc.line_height = (env->height_screen / env->rc.perp_wall_dist);
	env->rc.draw_start = -env->rc.line_height / 2 + env->height_screen / 2;
	env->rc.draw_end = env->rc.line_height / 2 + env->height_screen / 2;
	if (env->rc.draw_start < 0)
		env->rc.draw_start = 0;
	if (env->rc.draw_end >= env->height_screen)
		env->rc.draw_end = env->height_screen - 1;
	set_texture(env, x);
	y = 0;
	if (env->rc.draw_end < 0)
		env->rc.draw_end = env->height_screen;
	y = env->rc.draw_end;
	while (y < env->height_screen)
	{
		env->get_data[x + y * (env->size_line / 4)] = env->rc.color.floor;
		env->get_data[x + (env->height_screen - y - 1) * \
		(env->size_line / 4)] = env->rc.color.roof;
		y++;
	}
}
