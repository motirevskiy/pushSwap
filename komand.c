/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   komand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:04:35 by cgretche          #+#    #+#             */
/*   Updated: 2022/03/09 17:51:22 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a, int flag)
{
	t_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = (tmp)->next;
	(tmp)->next = *stack_a;
	*stack_a = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b, int flag)
{
	t_list	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = (tmp)->next;
	(tmp)->next = *stack_b;
	*stack_b = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	ft_ss(t_list **a, t_list **b, int flag)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	if (flag)
		write(1, "ss\n", 3);
}

void	ft_pa(t_list **a, t_list **b, int flag)
{
	t_list	*tmp;

	if (!b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (flag)
		write(1, "pa\n", 3);
}

void	ft_pb(t_list **a, t_list **b, int flag)
{
	t_list	*tmp;

	if (!a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (flag)
		write(1, "pb\n", 3);
}
