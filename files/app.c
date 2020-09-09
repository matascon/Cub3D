/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:04:05 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 17:03:28 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**static void adjust_screen(t_env *env)
**{
**	int	x;
**	int	y;
**
**	mlx_get_screen_size(env->mlx_ptr, &x, &y);
**	if (x < env->width_screen)
**		env->width_screen = x;
**	if (y < env->height_screen)
**		env->height_screen = y;
**}
*/

void	ft_app(t_env *env)
{
	if (!(env->mlx_ptr = mlx_init()))
		ft_exit(env, ERROR_15);
/*
**	adjust_screen(env);
*/
	if (!env->bmp.bmp)
	{
		if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, \
		env->width_screen, env->height_screen, "Cub3D")))
			ft_exit(env, ERROR_15);
	}
	ft_init_textures(env);
	ft_render_frame(env);
	mlx_hook(env->win_ptr, 2, 1, &ft_key_press, env);
	mlx_hook(env->win_ptr, 3, 2, &ft_key_release, env);
	mlx_hook(env->win_ptr, 17, 1 << 17, &ft_key_exit, env);
	mlx_loop_hook(env->mlx_ptr, &ft_movement, env);
	mlx_loop(env->mlx_ptr);
}
