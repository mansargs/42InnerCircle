/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:13:08 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/31 00:54:26 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	int				index;
}					t_list;

// Helper functions
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

// Cleaning and program interrupt functions
void	strclear(char ***str);
void	ft_lstclear(t_list **lst);
void	error_handle(t_list **stack, char ***split, int exit_code);

// Validation, stack builder and indexing functions
void	check_and_add(int argc, char *argv[], t_list **stack_a);
void	indexation(t_list **stack, char ***split, int num);

// Functions for linked list managment
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
