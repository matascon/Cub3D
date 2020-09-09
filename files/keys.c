/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:57:36 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:58:19 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_exit(t_env *env)
{
	ft_exit(env, "¡PROGRAM EXECUTED SUCCESSFULLY!");
	return (0);
}

int	ft_key_release(int keycode, t_env *env)
{
	if (keycode == W_KEY)
		env->mv.up = 0;
	if (keycode == S_KEY)
		env->mv.down = 0;
	if (keycode == D_KEY)
		env->mv.right = 0;
	if (keycode == A_KEY)
		env->mv.left = 0;
	if (keycode == RIGHT)
		env->mv.rot_right = 0;
	if (keycode == LEFT)
		env->mv.rot_left = 0;
	if (keycode == ESC)
		ft_key_exit(env);
	return (0);
}

int	ft_key_press(int keycode, t_env *env)
{
	if (keycode == W_KEY)
		env->mv.up = 1;
	if (keycode == S_KEY)
		env->mv.down = 1;
	if (keycode == D_KEY)
		env->mv.right = 1;
	if (keycode == A_KEY)
		env->mv.left = 1;
	if (keycode == RIGHT)
		env->mv.rot_right = 1;
	if (keycode == LEFT)
		env->mv.rot_left = 1;
	return (0);
}
