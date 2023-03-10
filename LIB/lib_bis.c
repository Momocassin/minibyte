/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:38:31 by edvicair          #+#    #+#             */
/*   Updated: 2023/01/20 11:39:49 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || (s1[i] == '\0' && s2[i] == '\0'))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i] || (s1[i] == '\0' && s2[i] == '\0'))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*s_cpy;

	i = -1;
	s_cpy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s_cpy)
		return (NULL);
	while (s[++i])
		s_cpy[i] = s[i];
	s_cpy[i] = '\0';
	return (s_cpy);
}

char	*ft_strjoin(t_msh *msh, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dest;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		while (s1[j])
			dest[i++] = s1[j++];
		j = 0;
		while (s2[j])
			dest[i++] = s2[j++];
	}
	dest[i] = '\0';
	return (dest);
}

bool	ft_strshr(const char *s, int c)
{
	size_t	i;
	char	*s_cpy;

	i = 0;
	s_cpy = (char *)s;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}
