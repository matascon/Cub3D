/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:22 by matascon          #+#    #+#             */
/*   Updated: 2020/09/07 17:26:22 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_errors_resolution(t_env *env, char *ptr, int n_arg)
{
	if (!(*ptr) || n_arg < 2)
	{
		if (!(*ptr))
			ft_exit(env, ERROR_6);
		else
			ft_exit(env, ERROR_7);
	}
	else if (env->width_screen < 0 || env->height_screen < 0)
		ft_exit(env, ERROR_8);
}

static char	*pop_resolution(t_env *env, char *ptr, int n_arg)
{
	int	nbr;

	nbr = ft_atoi(ptr);
	if (!n_arg)
		env->width_screen = nbr;
	else
		env->height_screen = nbr;
	while ((*ptr >= '0' && *ptr <= '9') || \
	*ptr == '-' || *ptr == '+')
		ptr++;
	if (!(*ptr))
		ft_exit(env, ERROR_6);
	return (ptr);
}

char		*ft_get_resolution(t_env *env, char *ptr)
{
	int	n_arg;

	if (env->file.r)
		ft_exit(env, ERROR_5);
	env->file.r = 1;
	n_arg = 0;
	while (*ptr && n_arg < 2)
	{
		if (ft_isspace(*ptr))
			ptr++;
		else if (!(*ptr >= '0' && *ptr <= '9') && \
		*ptr != '-' && *ptr != '+')
			break ;
		else
			ptr = pop_resolution(env, ptr, n_arg++);
	}
	check_errors_resolution(env, ptr, n_arg);
	return (ptr);
}
