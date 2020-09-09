/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:25:51 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 17:01:35 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_main_values(t_env *env)
{
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->file.file = NULL;
	env->rc.sprite = NULL;
	env->bmp.bmp = 0;
}

/*
** Remember, errors are defined in cub3d.h
*/

int			main(int argc, char **argv)
{
	t_env	*env;

	if (!(env = (t_env *)ft_calloc(sizeof(t_env), 1)))
		return (0);
	init_main_values(env);
	if (argc == 2 || argc == 3)
	{
		ft_read_file(env, argv[1]);
		ft_parse_file(env);
		ft_init_missing_values(env);
		if (argc == 3)
		{
			if (!ft_strncmp("--save", argv[2], 7))
				env->bmp.bmp = 1;
			else
				ft_exit(env, ERROR_16);
		}
		ft_app(env);
	}
	else if (argc > 3)
		ft_putendl_fd(ERROR_1, 1);
	else
		ft_putendl_fd(ERROR_0, 1);
	ft_exit(env, NULL);
	return (0);
}
