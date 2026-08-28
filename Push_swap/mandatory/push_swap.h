/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 03:34:20 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/31 00:54:15 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

// Stack operations
void	swap_stack(t_list **stack, char *operation);
void	push_pop(t_list **push, t_list **pop, char *operation);
void	rotate(t_list **stack, char *operation);
void	reverse_rotate(t_list **stack, char *operation);

// sorting
int		is_sorted(t_list *stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_three_number(t_list **stack);
void	four_and_five(t_list **stack_a, t_list **stack_b);
void	butterfly(t_list **stack_a, t_list **stack_b);

#endif
