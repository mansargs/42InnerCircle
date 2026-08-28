/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:34:14 by mansargs          #+#    #+#             */
/*   Updated: 2025/03/31 00:54:38 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	if (dstsize == 0)
		return (srcsize);
	while (i < srcsize && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

static size_t	count_char(int num)
{
	size_t	len;

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

static int	minus_case(char *str, int *len, int *num)
{
	int	limit;

	limit = 0;
	if (*num < 0)
	{
		*str = '-';
		limit = 1;
		if (*num == -2147483648)
		{
			*num = (*num + 1) * -1;
			*(str + --(*len)) = '8';
			*num /= 10;
		}
		else
			*num *= -1;
	}
	return (limit);
}

char	*ft_itoa(int num)
{
	int		len;
	char	*str;
	int		limit;

	len = count_char(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*(str + len) = '\0';
	limit = minus_case(str, &len, &num);
	while (len > limit)
	{
		*(str + len - 1) = (num % 10) + '0';
		num = num / 10;
		--len;
	}
	return (str);
}
