/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:40:31 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/27 04:03:13 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int x)
{
	int	left;
	int	right;
	int	result;
	int	mid;

	if (x < 0)
		return (-1);
	if (x == 0 || x == 1)
		return (x);
	left = 1;
	right = x;
	result = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid <= x / mid)
		{
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return (result);
}

static int	ft_log(int base, int num)
{
	int	count;

	if (base <= 1)
		return (-1);
	if (!num)
		return (1);
	count = 0;
	while (base <= num / base)
	{
		++count;
		num /= base;
	}
	return (count);
}

static void	max_in_top(t_list **stack, int max)
{
	int		i;
	int		length;
	t_list	*max_index;

	i = 0;
	length = ft_lstsize(*stack);
	max_index = *stack;
	while (max_index)
	{
		if (max_index->index == max)
			break ;
		++i;
		max_index = max_index->next;
	}
	if (i <= length / 2)
		while (i--)
			rotate(stack, "rb\n");
	else
		while (length-- > i)
			reverse_rotate(stack, "rrb\n");
}

static int	fill_to_b(t_list **stack_a, t_list **stack_b, int size, int n)
{
	t_list	*last;
	int		counter;

	counter = 0;
	while (size != 0)
	{
		last = *stack_a;
		if (last->index <= counter)
		{
			push_pop(stack_b, stack_a, "pb\n");
			rotate(stack_b, "rb\n");
			++counter;
			--size;
		}
		else if (last->index <= counter + n)
		{
			push_pop(stack_b, stack_a, "pb\n");
			++counter;
			--size;
		}
		else
			rotate(stack_a, "ra\n");
	}
	return (counter);
}

void	butterfly(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		n;
	int		counter;
	int		max;

	size = ft_lstsize(*stack_a);
	n = ft_sqrt(size) + ft_log(2, size);
	counter = fill_to_b(stack_a, stack_b, size, n);
	max = size - 1;
	while (counter)
	{
		max_in_top(stack_b, max);
		push_pop(stack_a, stack_b, "pa\n");
		--max;
		--counter;
	}
}
