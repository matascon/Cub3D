/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:13 by matascon          #+#    #+#             */
/*   Updated: 2020/09/07 17:26:14 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_color_floor(t_env *env, char *ptr_file)
{
	if (env->file.f)
		ft_exit(env, ERROR_5);
	env->file.f = 1;
	ptr_file = ft_aux_colors(env, ptr_file, F);
	return (ptr_file);
}

char	*ft_get_color_roof(t_env *env, char *ptr_file)
{
	if (env->file.c)
		ft_exit(env, ERROR_5);
	env->file.c = 1;
	ptr_file = ft_aux_colors(env, ptr_file, C);
	return (ptr_file);
}
