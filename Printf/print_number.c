/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:41:19 by mansargs          #+#    #+#             */
/*   Updated: 2025/02/03 19:46:00 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_char(long num)
{
	int	len;

	len = 1;
	if (num < 0)
		++len;
	while (num / 10)
	{
		num /= 10;
		++len;
	}
	return (len);
}

static void	fill(char *str, long num, int len)
{
	int	limit;

	limit = 0;
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		limit = 1;
		num = -num;
	}
	while (--len >= limit)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
}

int	print_number(long num)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = count_char(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	fill(str, num, len);
	len = print_string(str);
	free (str);
	return (len);
}
/*
#include <stdio.h>

int main ()
{
	printf("len is ------>%d\n", print_number(-33423));
	system("leaks a.out");
	return (0);
}
*/
