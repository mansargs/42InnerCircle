/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:06 by mansargs          #+#    #+#             */
/*   Updated: 2025/02/02 19:47:14 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		print_symbol(const char c);
int		print_string(const char *s);
int		count_hex_len(size_t num);
int		print_pointer(void *p);
int		print_hex(unsigned int num, char c);
int		print_number(long num);
int		ft_printf(const char *s, ...);

#endif
