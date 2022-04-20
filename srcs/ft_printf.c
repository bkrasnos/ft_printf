/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:47:23 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/04/20 13:34:53 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_set_tab(t_print *tab)
{
	tab->zero = 0;
	tab->minus = 0;
	tab->dot = -1;
	tab->space = 0;
	tab->plus = 0;
	tab->sharp = 0;
	tab->width = 0;
	tab->type = 0;
}

static void	ft_check_tab(const char **format, t_print *tab)
{
	while (**format == '-' || **format == '+' || **format == ' '
		|| **format == '#' || **format == '0')
	{
		if (**format == '0' && !tab->minus)
			tab->zero = 1;
		else if (**format == '-')
		{
			tab->minus = 1;
			tab->zero = 0;
		}
		else if (**format == ' ')
			tab->space = 1;
		else if (**format == '+')
		{
			tab->space = 0;
			tab->plus = 1;
		}
		else if (**format == '#')
			tab->sharp = 1;
		++(*format);
	}
}

static void	ft_check_check_tab(const char **format, t_print *tab)
{	
	while (ft_isdigit(**format))
	{
		tab->width = tab->width * 10 + **format - '0';
		++(*format);
	}	
	if (**format == '.')
	{
		tab->zero = 0;
		tab->dot = 0;
		++(*format);
		while (ft_isdigit(**format))
		{
			tab->dot = tab->dot * 10 + **format - '0';
			++(*format);
		}	
	}
	if (**format == 'x' || **format == 'X' || **format == 's' || **format == 'p'
		|| **format == 'd' || **format == 'i' || **format == 'u'
		|| **format == 'c' || **format == '%')
	{
		tab->type = **format;
		++(*format);
	}
}

static void	ft_output(va_list arg, t_print *tab, int *a)
{
	if (tab->type == 'c')
		ft_output_char(tab, va_arg(arg, unsigned int), a);
	else if (tab->type == 'd' || tab->type == 'i')
		ft_output_number(tab, va_arg(arg, int), a);
	else if (tab->type == 's')
		ft_output_string(tab, va_arg(arg, char *), a);
	else if (tab->type == 'u')
		ft_output_number_unsigned(tab, va_arg(arg, unsigned int), a);
	else if (tab->type == 'x')
		ft_output_hexadicimal(tab, va_arg(arg, unsigned int), a);
	else if (tab->type == 'X')
		ft_output_hexadicimal_capital(tab, va_arg(arg, unsigned int), a);
	else if (tab->type == 'p')
		ft_output_pointer(tab, va_arg(arg, unsigned long long), a);
	else if (tab->type == '%')
		ft_output_char(tab, '%', a);
}

int	ft_printf(const char *format)
{
	va_list	arg;
	t_print	tab;
	int		a;

	va_start(arg, format);
	r = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			ft_set_tab(&tab);
			ft_check_tab(&format, &tab);
			ft_check_check_tab(&format, &tab);
			ft_output(arg, &tab, &a);
		}
		else
		{
			ft_putchar(*format, &a);
			++format;
		}
	}
	va_end(arg);
	return (a);
}
