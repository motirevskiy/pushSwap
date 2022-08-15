/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   komand3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:39:20 by cgretche          #+#    #+#             */
/*   Updated: 2022/03/06 19:05:25 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack_a;
	*stack_a = tmp2;
	if (flag)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack_b;
	*stack_b = tmp2;
	if (flag)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
