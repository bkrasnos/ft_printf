/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hexadicimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:34:18 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/04/22 13:42:25 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr)
	{
		nbr = nbr / 16;
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

static void	ft_putnbr_unsigned(unsigned int nb, int *a)
{
	if (nb >= 16)
	{
		ft_putnbr_unsigned(nb / 16, a);
		nb = nb % 16;
	}
	if (nb < 10)
		ft_putchar(nb + '0', a);
	else
		ft_putchar(nb + 87, a);
}

void	ft_output_hexadicimal(t_print *tab, unsigned int nbr, int *a)
{
	int	len;

	len = ft_nbrlen(nbr);
	if (tab->dot == 0 && nbr == 0)
		len = 0;
	tab->dot -= len;
	tab->width -= len;
	if (tab->sharp && nbr)
		tab->width -= 2;
	while (tab->width > tab->dot && !tab->zero
		&& !tab->minus && ft_shrink(&tab->width))
		ft_putchar(' ', a);
	if (tab->sharp && nbr)
		ft_putstr("0x", a);
	while ((tab->zero && tab->width > 0) || tab->dot > 0)
	{
		ft_putchar('0', a);
		--tab->width;
		--tab->dot;
	}	
	if (len)
		ft_putnbr_unsigned(nbr, a);
	while (tab->minus && ft_shrink(&tab->width))
		ft_putchar(' ', a);
}
