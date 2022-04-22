/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:34:39 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/04/22 13:42:52 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nbrlen(unsigned long long nbr)
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

static void	ft_putnbr_unsigned(unsigned long long nb, int *a)
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

void	ft_output_pointer(t_print *tab, unsigned long long nbr, int *a)
{
	tab->width = tab->width - ft_nbrlen(nbr) - 2;
	while ((tab->dot <= 0) && !tab->zero && !tab->minus
		&& ft_shrink(&tab->width))
		ft_putchar(' ', a);
	ft_putstr("0x", a);
	while (tab->zero && ft_shrink(&tab->width))
		ft_putchar('0', a);
	tab->dot -= ft_nbrlen(nbr);
	while (tab->dot >= 0 && ft_shrink(&tab->dot))
		ft_putchar('0', a);
	ft_putnbr_unsigned(nbr, a);
	while (tab->minus && (tab->dot < 0) && ft_shrink(&tab->width))
		ft_putchar(' ', a);
}
