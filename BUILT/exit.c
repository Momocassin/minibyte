/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:12:04 by edvicair          #+#    #+#             */
/*   Updated: 2023/01/20 15:39:01 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_env(t_env *env)
{
	t_env	*tmp;

	tmp = NULL;
	while (env)
	{
		if (env->name)
			free(env->name);
		env->name = NULL;
		if (env->value)
			free(env->value);
		env->value = NULL;
		if (env->next)
		{
			tmp = env;
			env = env->next;
			if (tmp)
				free(tmp);
			tmp = NULL;
		}
		else
			break ;
	}
	free(env);
	env = NULL;
}

void	ft_exit(t_msh *msh, int value)
{
	int	res;

	ft_free_env(msh->env);
	if (msh->token)
	{
		if (msh->token->cmd[1])
		{
			free(msh->line);
			res = ft_atoi(msh->token->cmd[1]);
			ft_free_token(msh, msh->token);
			exit(res);
		}
		close(msh->fd[0]);
		close(msh->fd[1]);
		dup2(msh->stin, 0);
		dup2(msh->stout, 1);
		close(msh->stin);
		close(msh->stout);
	}
	if (msh->token)
		ft_free_token(msh, msh->token);
	free(msh->line);
	exit(value);
}
