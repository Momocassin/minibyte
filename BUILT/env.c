/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:28:00 by edvicair          #+#    #+#             */
/*   Updated: 2023/01/20 15:49:25 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv(t_msh *msh, char *namee)
{
	t_env	*cpy;

	cpy = msh->env;
	while (cpy->next)
	{
		if (!ft_strncmp(cpy->name, namee, ft_strlen(namee)))
			return (cpy->value);
		cpy = cpy->next;
	}
}

void	ft_env_red(t_msh *msh, t_env *cpy, int fd)
{
	while (cpy->next != NULL)
	{
		if (!cpy->egal && cpy->value)
		{
			write(fd, cpy->name, ft_strlen(cpy->name));
			write(fd, cpy->value, ft_strlen(cpy->value));
			write(fd, "\n", 1);
		}
		else if (!cpy->egal && !cpy->value)
		{
			write(fd, cpy->name, ft_strlen(cpy->name));
			write(fd, "=\n", 2);
		}
		cpy = cpy->next;
	}
	if (cpy->next == NULL && !cpy->egal && cpy->value)
	{
		write(fd, cpy->name, ft_strlen(cpy->name));
		write(fd, cpy->value, ft_strlen(cpy->value));
		write(fd, "\n", 1);
	}
	else if (cpy->next == NULL && !cpy->egal && !cpy->value)
	{	
		write(fd, cpy->name, ft_strlen(cpy->name));
		write(fd, "=\n", 2);
	}
}

void	ft_env(t_msh *msh)
{
	t_env	*cpy;

	cpy = msh->env;
	if (msh->token->cmd[1])
		return ;
	if (msh->pip)
	{
		if(msh->out != 1)
			ft_env_red(msh, cpy, msh->out);
		else
			ft_env_red(msh, cpy, msh->fd[1]);
		return ;
	}
	while (cpy->next != NULL)
	{
		if (!cpy->egal && cpy->value)
			printf("%s=%s\n", cpy->name, cpy->value);
		else if (!cpy->egal && !cpy->value)
			printf("%s=\n", cpy->name);
		cpy = cpy->next;
	}
	if (cpy->next == NULL && !cpy->egal && cpy->value)
		printf("%s=%s\n", cpy->name, cpy->value);
	else if (cpy->next == NULL && !cpy->egal && !cpy->value)
		printf("%s=\n", cpy->name);
}
