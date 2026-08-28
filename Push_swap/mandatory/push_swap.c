/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:09:52 by lenovo            #+#    #+#             */
/*   Updated: 2025/03/28 11:46:20 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (EINVAL);
	stack_a = NULL;
	stack_b = NULL;
	check_and_add(argc, argv, &stack_a);
	if (is_sorted(stack_a))
		return (ft_lstclear(&stack_a), EXIT_SUCCESS);
	else
		sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (EXIT_SUCCESS);
}
