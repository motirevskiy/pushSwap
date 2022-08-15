/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   komand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:20:46 by cgretche          #+#    #+#             */
/*   Updated: 2022/03/06 19:05:18 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **a, int flag)
{
	t_list	*tmp;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	tmp = *a;
	*a = (*a)->next;
	last->next = tmp;
	tmp->next = 0;
	if (flag)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **b, int flag)
{
	t_list	*tmp;
	t_list	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	tmp = *b;
	*b = (*b)->next;
	last->next = tmp;
	tmp->next = 0;
	if (flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_b, t_list **stack_a, int flag)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (flag)
		write(1, "rr\n", 3);
}
