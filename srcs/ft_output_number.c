/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:34:29 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/04/22 13:42:42 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr)
	{
		nbr = nbr / 10;
		++len;
	}
	return (len);
}

static int	ft_shrink(int *width)
{
	if (*width > 0)
	{
		--(*width);
		return (1);
	}
	return (0);
}

static void	ft_putnbr(int nbr, int *a)
{
	unsigned int	nb;

	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, a);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + '0', a);
}

static void	ft_sign(t_print *tab, int nbr, int *a)
{
	if (tab->space && (!tab->plus) && tab->width <= 0 && nbr >= 0)
		ft_putchar(' ', a);
	while (tab->width > tab->dot && !tab->zero
		&& !tab->minus && ft_shrink(&tab->width))
		ft_putchar(' ', a);
	if (tab->plus && nbr >= 0)
		ft_putchar('+', a);
	if (nbr < 0)
		ft_putchar('-', a);
}

void	ft_output_number(t_print *tab, int nbr, int *a)
{
	int	len;

	len = ft_nbrlen(nbr);
	if (tab->dot == 0 && nbr == 0)
		len = 0;
	if (nbr < 0 && tab->dot > 0)
		++tab->dot;
	tab->width -= len;
	tab->dot -= len;
	if (tab->plus && nbr >= 0)
		--tab->width;
	ft_sign(tab, nbr, a);
	while ((tab->zero && tab->width > 0) || tab->dot > 0)
	{
		ft_putchar('0', a);
		--tab->width;
		--tab->dot;
	}	
	if (len)
		ft_putnbr(nbr, a);
	while (tab->minus && (tab->dot <= 0) && ft_shrink(&tab->width))
		ft_putchar(' ', a);
}
