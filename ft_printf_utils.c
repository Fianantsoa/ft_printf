/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <finoment@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:25:54 by finoment          #+#    #+#             */
/*   Updated: 2026/04/13 13:44:56 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexlen(unsigned long n)
{
	size_t	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_ltoh(unsigned long n)
{
	char			*str;
	char			*base;
	size_t			len;

	base = "0123456789abcdef";
	len = ft_hexlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[n % 16];
		n /= 16;
	}
	return (str);
}

int	ft_n_show_c(long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (base == 10 && n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((n % 10 + '0'), fd);
}

char	*ft_strupcase(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
