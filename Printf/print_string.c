/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:58 by mansargs          #+#    #+#             */
/*   Updated: 2025/02/02 20:23:38 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(const char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = -1;
	while (s[++i])
		write(1, s + i, 1);
	return (i);
}
/*
#include <stdio.h>

int	main ()
{
	printf("len is %d\n", printf(" NULL %s NULL \n", NULL));
	ft_printf("len is %d\n", ft_printf(" NULL %s NULL \n", NULL));
	return (0);
}
*/