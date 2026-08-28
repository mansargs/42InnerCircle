/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:41:56 by mansargs          #+#    #+#             */
/*   Updated: 2025/02/02 19:46:24 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int num, char c)
{
	int		len;
	char	*hex;
	int		mod;

	if (c == 'x')
		c = 87;
	else
		c = 55;
	len = count_hex_len(num);
	hex = (char *)malloc((len + 1) * sizeof(char));
	if (!hex)
		return (-1);
	hex[len] = '\0';
	while (--len >= 0)
	{
		mod = num % 16;
		if (mod > 9)
			hex[len] = mod + c;
		else
			hex[len] = mod + 48;
		num /= 16;
	}
	len = print_string(hex);
	free(hex);
	return (len);
}
/*
int main ()
{
	printf("our hex is ----->%d\n", ft_print_hex(1223242,'x'));
	return (0);
}
*/
