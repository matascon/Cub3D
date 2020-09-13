/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:25:09 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:58:16 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			set_sprite(t_env *env)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < env->map.h_map)
	{
		x = 0;
		while (x < env->map.w_map)
		{
			if (env->map.map[y][x] == '2')
			{
				env->rc.sprite[i].coord_x = x + 0.5;
				env->rc.sprite[i].coord_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void			pop_sprite(char *root_sprite, t_env *env, int i)
{
	if (!(env->rc.sprite[i].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, \
	root_sprite, &env->rc.sprite[i].width, &env->rc.sprite[i].height)))
		ft_exit(env, "Error\nSomething wrong in sprite texture");
	if (!(env->rc.sprite[i].get_data = (int *)mlx_get_data_addr(\
	env->rc.sprite[i].img_ptr, &env->rc.sprite[i].bits_per_pixel, \
	&env->rc.sprite[i].size_line, &env->rc.sprite[i].endian)))
		ft_exit(env, "Error\nSomething wrong in sprite texture");
}

static t_texture	pop_texture(char *root_texture, t_env *env)
{
	t_texture	texture;

	if (!(texture.img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, root_texture, \
	&texture.width, &texture.height)))
		ft_exit(env, "Error\nSomething wrong in wall texture");
	if (!(texture.get_data = (int *)mlx_get_data_addr(texture.img_ptr, \
	&texture.bits_per_pixel, &texture.size_line, &texture.endian)))
		ft_exit(env, "Error\nSomething wrong in wall texture");
	return (texture);
}

void				ft_init_textures(t_env *env)
{
	int	i;

	env->rc.north = pop_texture(env->dir_tex_north, env);
	env->rc.south = pop_texture(env->dir_tex_south, env);
	env->rc.east = pop_texture(env->dir_tex_east, env);
	env->rc.west = pop_texture(env->dir_tex_west, env);
	i = -1;
	while (++i < env->rc.nbr_sprites)
		pop_sprite(env->dir_tex_sprite, env, i);
	set_sprite(env);
}
