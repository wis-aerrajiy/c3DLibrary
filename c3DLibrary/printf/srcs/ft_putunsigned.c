/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrajiy <aerrajiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:51:21 by aerrajiy          #+#    #+#             */
/*   Updated: 2023/04/18 01:09:49 by aerrajiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/ft_printf.h"

int	count_digits(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putunsigned(int fd, unsigned int n)
{
	int	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr(fd, (n * -1));
	}
	else if (n > 9)
	{
		ft_putnbr(fd, (n / 10));
		ft_putnbr(fd, (n % 10));
	}
	else
	{
		c = n + 48;
		write(fd, &c, 1);
	}
	return (count_digits(n));
}
