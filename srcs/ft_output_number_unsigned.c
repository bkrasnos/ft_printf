/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_number_unsigned.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:34:33 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/04/22 13:42:32 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
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

static void	ft_putnbr_unsigned(unsigned int nb, int *a)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, a);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + '0', a);
}

void	ft_output_number_unsigned(t_print *tab, unsigned int nbr, int *a)
{
	int	len;

	len = ft_nbrlen(nbr);
	if (tab->dot == 0 && nbr == 0)
		len = 0;
	tab->width -= len;
	tab->dot -= len;
	if (tab->dot > 0)
		tab->width = tab->width - tab->dot;
	while (!tab->zero && !tab->minus && ft_shrink(&tab->width))
		ft_putchar(' ', a);
	while ((tab->zero && ft_shrink(&tab->width))
		|| ft_shrink(&tab->dot))
		ft_putchar('0', a);
	if (len)
		ft_putnbr_unsigned(nbr, a);
	while (tab->minus && (tab->dot <= 0) && ft_shrink(&tab->width))
		ft_putchar(' ', a);
}
