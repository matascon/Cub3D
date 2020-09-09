/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:59:03 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:58:50 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_frame(t_env *env)
{
	env->new_image = mlx_new_image(env->mlx_ptr, env->width_screen, \
	env->height_screen);
	env->get_data = (int *)mlx_get_data_addr(env->new_image, \
	&env->bits_per_pixel, &env->size_line, &env->endian);
	if (!(env->rc.render.dist_wall = ft_calloc(sizeof(double), \
	env->width_screen)))
		ft_exit(env, ERROR_13);
	ft_raycast_wall(env);
	ft_raycast_sprite(env);
	if (env->bmp.bmp)
		ft_bmp(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->new_image, 0, 0);
	mlx_do_sync(env->mlx_ptr);
	mlx_destroy_image(env->mlx_ptr, env->new_image);
}
