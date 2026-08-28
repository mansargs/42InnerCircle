/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 03:34:20 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/31 00:36:54 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"
# include "get_next_line.h"

// Stack operations
void	swap_stack(t_list **stack);
void	push_pop(t_list **push, t_list **pop);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

#endif
