/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:47:44 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/04/22 15:15:28 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_print
{
	int		plus;
	int		space;
	int		zero;
	int		dot;
	int		type;
	int		sharp;
	int		width;
	int		minus;
}	t_print;

int		ft_printf(const char *format, ...);
void	ft_output_char(t_print *tab, char c, int *a);
void	ft_output_hexadicimal_capital(t_print *tab, unsigned int nbr, int *a);
void	ft_output_hexadicimal(t_print *tab, unsigned int nbr, int *a);
void	ft_output_number_unsigned(t_print *tab, unsigned int nbr, int *a);
void	ft_output_number(t_print *tab, int nbr, int *a);
void	ft_output_pointer(t_print *tab, unsigned long long nbr, int *a);
void	ft_output_string(t_print *tab, char *str, int *a);
void	ft_putchar(char c, int *a);
void	ft_putstr(char *str, int *a);

#endif
