/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <nandonomentsoa@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:01:03 by finoment          #+#    #+#             */
/*   Updated: 2026/03/05 12:52:26 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	get_print_len(const char c, va_list args)
{
	char	*str;

	if (c == 'c')
		return (va_arg(args, int), 1);
	if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			return (6);
		return (ft_strlen(str));
	}
	if (c == 'd' || c == 'i')
		return (ft_n_show_c(va_arg(args, int), 10));
	if (c == 'u')
		return (ft_n_show_c(va_arg(args, unsigned int), 10));
	if (c == 'x' || c == 'X')
		return (ft_n_show_c(va_arg(args, unsigned int), 16));
	if (c == 'p')
		return (ft_n_show_c(va_arg(args, unsigned long), 16) + 2);
	if (c == '%')
		return (1);
	return (0);
}

static void	ft_print_arg(char type, va_list args, size_t *count)
{
	va_list	copy;

	va_copy(copy, args);
	if (ft_strchr("csdiu%%", type))
		*count += get_print_len(type, copy);
	va_end(copy);
	if (type == 'c')
		ft_putchar_fd((int) va_arg(args, int), 1);
	if (type == 'd' || type == 'i')
		ft_putnbr_fd((int) va_arg(args, int), 1);
	if (type == 's')
		ft_putstr_fd((char *) va_arg(args, char *), 1);
	if (type == '%')
		ft_putchar_fd('%', 1);
	if (type == 'u')
		ft_putunbr_fd(((unsigned int) va_arg(args, unsigned int)), 1);
}

static void	ft_print_hex(char type, va_list args, size_t *count)
{
	va_list	copy;
	char	*str;

	va_copy(copy, args);
	if (ft_strchr("pxX", type))
		*count += get_print_len(type, copy);
	va_end(copy);
	if (type == 'p')
	{
		ft_putstr_fd("0x", 1);
		str = ft_ltoh((unsigned long) va_arg(args, void *));
		ft_putstr_fd(str, 1);
		free(str);
	}
	str = ft_ltoh(va_arg(args, unsigned int));
	if (type == 'x')
		ft_putstr_fd(str, 1);
	if (type == 'X')
		ft_putstr_fd(ft_strupcase(str), 1);
	free(str);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		else
		{
			if (ft_strchr("csdiu%%", *format++))
				ft_print_arg(*format, args, &count);
			if (ft_strchr("pxX", *format))
				ft_print_hex(*format, args, &count);
		}
		format++;
	}
	va_end(args);
	return (count);
}
