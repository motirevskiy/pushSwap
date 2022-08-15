/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:34:14 by cgretche          #+#    #+#             */
/*   Updated: 2022/03/09 17:52:20 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*argv_add_to_list(char **str)
{
	t_list	*tmp2;
	t_list	*a;
	int		j;

	a = NULL;
	j = 0;
	while (str[j])
	{
		tmp2 = ft_lstnew(ft_atoi(str[j]));
		if (!tmp2 || !ft_lstadd_back(&a, tmp2))
			exit(1);
		free(str[j]);
		j++;
	}
	free(str);
	return (a);
}
