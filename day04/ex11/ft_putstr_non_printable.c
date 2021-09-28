/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 08:48:45 by acoezard          #+#    #+#             */
/*   Updated: 2021/09/26 09:47:36 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*base;
	char	a;
	char	b;

	base = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] > 31 && str[i] < 127)
			write(1, &str[i], 1);
		else
		{
			a = base[str[i] / 16];
			b = base[str[i] % 16];
			write(1, "\\", 1);
			write(1, &a, 1);
			write(1, &b, 1);
		}
		i++;
	}
}
