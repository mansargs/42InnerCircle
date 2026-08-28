/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:24 by mansargs          #+#    #+#             */
/*   Updated: 2025/02/02 21:17:32 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill(char *hex, int len, size_t nb)
{
	int	mod;

	hex[0] = '0';
	hex[1] = 'x';
	hex[len] = '\0';
	while (--len > 1)
	{
		mod = nb % 16;
		if (mod > 9)
			hex[len] = mod + 87;
		else
			hex[len] = mod + 48;
		nb /= 16;
	}
}

int	print_pointer(void *p)
{
	size_t	nb;
	int		len;
	char	*hex;
	int		count;

	nb = (size_t)p;
	len = count_hex_len(nb) + 2;
	hex = (char *)malloc((len + 1) * sizeof(char));
	if (!hex)
		return (-1);
	fill(hex, len, nb);
	count = print_string(hex);
	free(hex);
	return (count);
}

/*
int main ()
{
	int k;
	k = 12;
	int *p = &k;
	printf("my pointer address --------> %p", p);
	ft_putaddress(p);
	return (0);
}
*/
