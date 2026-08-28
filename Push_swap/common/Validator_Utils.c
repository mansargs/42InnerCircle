/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validator_Utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:36:08 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/28 11:55:12 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare(char *itoa, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-')
	{
		if (itoa[j] == '-')
			++j;
		++i;
	}
	while (str[i] == '0')
		++i;
	while (itoa[j] == '0')
		j++;
	while (str[i] && itoa[j])
	{
		if (str[i] != itoa[j])
			return (0);
		++i;
		++j;
	}
	return (str[i] == '\0' && itoa[j] == '\0');
}

static int	no_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
	return (1);
}

static int	check(char *str, t_list **stack, char ***split)
{
	int		i;
	int		num;
	char	*itoa;

	i = 0;
	num = ft_atoi(str);
	itoa = ft_itoa(num);
	if (!itoa)
		error_handle (stack, split, ENOMEM);
	if (str[i] == '+')
		++i;
	while (str[i] == '0')
		++i;
	if (str[i] == '\0')
		--i;
	if (!compare(itoa, str + i))
	{
		free(itoa);
		error_handle (stack, split, EINVAL);
	}
	free(itoa);
	return (num);
}

static void	add(t_list **stack_a, char ***split, int num)
{
	t_list	*new_node;

	new_node = ft_lstnew(num);
	if (!new_node)
		error_handle (stack_a, split, ENOMEM);
	ft_lstadd_back(stack_a, new_node);
	indexation(stack_a, split, num);
}

void	check_and_add(int argc, char *argv[], t_list **stack_a)
{
	char	**split;
	int		i;
	int		j;
	int		num;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '\0' || no_digit(argv[i]))
			error_handle(stack_a, NULL, EINVAL);
		split = ft_split(argv[i], ' ');
		if (!split)
			error_handle(stack_a, NULL, ENOMEM);
		j = -1;
		while (split[++j])
		{
			num = check(split[j], stack_a, &split);
			add(stack_a, &split, num);
		}
		strclear(&split);
	}
}
