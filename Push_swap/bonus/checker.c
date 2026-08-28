/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:09:52 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/31 00:57:37 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	compare_strings(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (EXIT_FAILURE);
		++s1;
		++s2;
	}
	if (*s1 == *s2)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (EXIT_FAILURE);
		stack = stack->next;
	}
	return (EXIT_SUCCESS);
}

static int	realize(char	*str, t_list **stack_a, t_list **stack_b)
{
	if (!compare_strings(str, "sa\n"))
		swap_stack(stack_a);
	else if (!compare_strings(str, "sb\n"))
		swap_stack(stack_b);
	else if (!compare_strings(str, "pa\n"))
		push_pop(stack_a, stack_b);
	else if (!compare_strings(str, "pb\n"))
		push_pop(stack_b, stack_a);
	else if (!compare_strings(str, "ra\n"))
		rotate(stack_a);
	else if (!compare_strings(str, "rb\n"))
		rotate(stack_b);
	else if (!compare_strings(str, "rra\n"))
		reverse_rotate(stack_a);
	else if (!compare_strings(str, "rrb\n"))
		reverse_rotate(stack_b);
	else
	{
		ft_lstclear(stack_b);
		free(str);
		error_handle(stack_a, NULL, 127);
	}
	return (EXIT_SUCCESS);
}

static void	result(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a && !is_sorted(*stack_a) && !*stack_b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*operation;

	if (argc == 1)
		return (EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	check_and_add(argc, argv, &stack_a);
	while (1)
	{
		operation = get_next_line(STDIN_FILENO);
		if (!operation)
			break ;
		if (*operation == '\n')
		{
			free(operation);
			continue ;
		}
		realize(operation, &stack_a, &stack_b);
		free(operation);
	}
	result(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
