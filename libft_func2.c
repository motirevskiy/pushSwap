/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:55:21 by cgretche          #+#    #+#             */
/*   Updated: 2022/03/09 17:58:07 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ss = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ss)
		return (0);
	i = 0;
	while (*s1)
		ss[i++] = *s1++;
	while (*s2)
		ss[i++] = *s2++;
	ss[i] = '\0';
	return (ss);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (0);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**join_split(char **argv)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (argv[++i])
	{
		if (!str)
			str = ft_strdup(argv[i]);
		else
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, argv[i]);
		}
	}
	return (ft_split(str, ' '));
}
