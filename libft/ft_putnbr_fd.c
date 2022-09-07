/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namina <namina@student.21-school.ru>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:24:41 by namina            #+#    #+#             */
/*   Updated: 2021/08/09 22:24:43 by namina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmaxnbr(int n, int fd)
{
	unsigned int	nbr;
	char			c;

	nbr = n;
	if (nbr < 10)
	{
		ft_putchar_fd('-', fd);
		c = nbr + 48;
		ft_putchar_fd(c, fd);
		return ;
	}
	ft_putmaxnbr(nbr / 10, fd);
	c = nbr % 10 + 48;
	ft_putchar_fd(c, fd);
}

static void	ft_putnegnbr(int nbr, int fd)
{
	char	n;

	if (nbr > -10)
	{
		ft_putchar_fd('-', fd);
		n = -nbr + 48;
		ft_putchar_fd(n, fd);
		return ;
	}
	ft_putnegnbr(nbr / 10, fd);
	if (nbr == -2147483648)
	{
		ft_putchar_fd('8', fd);
		return ;
	}
	n = -nbr % 10 + 48;
	ft_putchar_fd(n, fd);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putmaxnbr(n, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putnegnbr(n, fd);
		return ;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
