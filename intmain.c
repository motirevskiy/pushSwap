/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:14:29 by cgretche          #+#    #+#             */
/*   Updated: 2022/03/09 17:59:40 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stacks(t_list *a, t_list *b)
// {
// 	printf("Stack a:\n");
// 	while (a)
// 	{
// 		printf("%d ", a->content);
// 		a = a->next;
// 	}
// 	printf("\nStack b:\n");
// 	while (b)
// 	{
// 		printf("%d ", b->content);
// 		b = b->next;
// 	}
// 	printf("\n");
// }
//	print_stacks(s.stack_a, s.stack_b);

int	main(int argc, char **argv)
{
	t_stacks	s;
	int			i;

	i = 0;
	if (argc < 2)
		error();
	argv = join_split(argv);
	argc = 0;
	while (argv[argc])
		argc++;
	while (++i < argc)
		ft_validation(argv[i]);
	s.stack_a = argv_add_to_list(argv);
	if (sort_check(s.stack_a))
	{
		if (argc <= 6)
			ft_sort_five(&s);
		s.stack_b = 0;
		s.next = 0;
		if (argc > 6)
			sort_stack(&s);
	}
	list_delete(s.stack_a);
	return (0);
}
