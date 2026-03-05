/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finoment <nandonomentsoa@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:12:24 by finoment          #+#    #+#             */
/*   Updated: 2026/03/05 12:57:26 by finoment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_ltoh(unsigned long n)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	div;
	long	temp;

	len = ft_intlen(n);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp = n;
		div = len - i - 1;
		while (div--)
			temp /= 16;
		if (temp % 16 >= 0 && temp % 16 <= 10)
			str[i] = (temp % 16) + '0';
		if (temp % 16 >= 10 && temp % 16 <= 15)
			str[i] = 'a' + ((temp % 16) - 10);
		i++;
	}
	str[len] = '\0';
	return (str);
}
