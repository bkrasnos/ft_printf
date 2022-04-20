/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:34:12 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/04/20 13:34:14 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_shrink(int *width)
{
	if (*width > 0)
	{
		--(*width);
		return (1);
	}
	return (0);
}

void	ft_output_char(t_print *tab, char c, int *a)
{
	if (tab->width > 0)
		(*a) += tab->width;
	else
		++(*a);
	--tab->width;
	while (!tab->minus && !tab->zero && ft_shrink(&tab->width))
		write(1, " ", 1);
	while (tab->zero && ft_shrink(&tab->width))
		write(1, "0", 1);
	write(1, &c, 1);
	while (tab->minus && ft_shrink(&tab->width))
		write(1, " ", 1);
}
