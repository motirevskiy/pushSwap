/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:08:22 by cgretche          #+#    #+#             */
/*   Updated: 2022/03/09 17:41:52 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_line(char **line)
{
	int		i;
	int		j;
	char	*buf;

	i = -1;
	buf = (char *)malloc(5);
	j = read(0, &buf[++i], 1);
	while (j > 0 && buf[i] != '\n' && buf[i] != '\0')
		j = read(0, &buf[++i], 1);
	buf[i] = '\0';
	*line = buf;
	return (j);
}

void	command(t_stacks *s, char *str)
{
	if (!ft_strncmp(str, "sa", 3))
		ft_sa(&s->stack_a, 0);
	else if (!ft_strncmp(str, "sb", 3))
		ft_sb(&s->stack_b, 0);
	else if (!ft_strncmp(str, "ss", 3))
		ft_ss(&s->stack_a, &s->stack_b, 0);
	else if (!(ft_strncmp(str, "pb", 3)))
		ft_pb(&s->stack_a, &s->stack_b, 0);
	else if (!(ft_strncmp(str, "pa", 3)))
		ft_pa(&s->stack_a, &s->stack_b, 0);
	else if (!(ft_strncmp(str, "ra", 3)))
		ft_ra(&s->stack_a, 0);
	else if (!(ft_strncmp(str, "rb", 3)))
		ft_rb(&s->stack_b, 0);
	else if (!(ft_strncmp(str, "rr", 3)))
		ft_rr(&s->stack_b, &s->stack_a, 0);
	else if (!(ft_strncmp(str, "rra", 4)))
		ft_rra(&s->stack_a, 0);
	else if (!(ft_strncmp(str, "rrb", 4)))
		ft_rrb(&s->stack_b, 0);
	else if (!(ft_strncmp(str, "rrr", 4)))
		ft_rrr(&s->stack_a, &s->stack_b, 0);
	else
		error();
}

void	read_commands(t_stacks *s)
{
	char	*str;

	while (get_next_line(&str))
	{
		command(s, str);
		free(str);
	}
	if (sort_check(s->stack_a))
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	free(str);
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	int			i;

	i = 1;
	if (argc < 2)
		error();
	argv = join_split(argv);
	argc = 0;
	while (argv[argc])
		argc++;
	while (i < argc)
	{	
		ft_validation(argv[i]);
		i++;
	}
	s.stack_a = argv_add_to_list(argv);
	s.stack_b = 0;
	s.next = 0;
	if (sort_check(s.stack_a))
		read_commands(&s);
	else
		write (1, "OK\n", 3);
	list_delete(s.stack_a);
	return (0);
}
