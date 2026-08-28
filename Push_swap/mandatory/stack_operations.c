/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:09:32 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/30 23:14:31 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (write (1, str + i, 1) == -1)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	swap_stack(t_list **stack, char *operation)
{
	t_list	*temp;
	t_list	*swap;

	temp = *stack;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next->next;
	swap = *stack;
	*stack = (*stack)->next;
	(*stack)->next = swap;
	(*stack)->next->next = temp;
	if (ft_putstr(operation))
		ft_lstclear(stack);
}

void	push_pop(t_list **push, t_list **pop, char *operation)
{
	t_list	*top;

	if (!pop || !*pop)
		return ;
	top = *pop;
	*pop = (*pop)->next;
	ft_lstadd_front(push, top);
	if (ft_putstr(operation))
	{
		ft_lstclear(push);
		ft_lstclear(pop);
	}
}

void	rotate(t_list **stack, char *operation)
{
	t_list	*temp;
	t_list	*first_to_last;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	first_to_last = *stack;
	if (!temp->next)
		return ;
	temp = temp->next;
	*stack = NULL;
	*stack = temp;
	while (temp->next)
		temp = temp->next;
	temp->next = first_to_last;
	temp->next->next = NULL;
	if (ft_putstr(operation))
		ft_lstclear(stack);
}

void	reverse_rotate(t_list **stack, char *operation)
{
	t_list	*temp;
	t_list	*pre_last;

	if (!stack || !*stack)
		return ;
	pre_last = *stack;
	if (!pre_last->next)
		return ;
	while (pre_last->next && pre_last->next->next)
		pre_last = pre_last->next;
	temp = pre_last;
	pre_last->next->next = *stack;
	*stack = pre_last->next;
	temp->next = NULL;
	if (ft_putstr(operation))
		ft_lstclear(stack);
}
