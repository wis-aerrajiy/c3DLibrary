/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:51:03 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 01:09:35 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/ft_printf.h"

int	ft_put_hex(int fd, char base, unsigned long c)
{
	char	*hex;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (base == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (c >= 16)
		count += ft_put_hex(fd, base, c / 16);
	count += ft_putchar(fd, hex[c % 16]);
	return (count);
}
