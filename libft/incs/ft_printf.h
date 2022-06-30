/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:22:25 by mbarutel          #+#    #+#             */
/*   Updated: 2022/06/28 11:15:05 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/incs/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		mod;
	int		dot;
	int		hash;
	int		zero;
	int		plus;
	int		minus;
	int		width;
	int		space;
	int		precision;
}				t_flags;

typedef struct s_arg
{
	va_list	arg;
	char	specifier;
}				t_arg;

typedef struct s_colours
{
	char	*code;
	char	*name;
}				t_colours;

void	print_date(size_t date, int *ret);
void	non_printa_print(char val, int *ret);
void	ft_bin_print(size_t nbr, int *ret);
char	*coloring(char *format, int *char_count);
int		ft_printf(const char *restrict format, ...);
int		ft_str_convert(char *str, t_flags *flags);
int		ft_char_convert(unsigned int c, t_flags *flags);
int		ft_arg_filter(t_arg *arg, t_flags *flags);
int		ft_diouxf_convert(t_arg *arg, t_flags *flags);
int		ft_printer(char *str, t_flags *flags);
int		ft_diouxf_printer(char *str, t_flags *flags, char specifier);
void	flags_correction(t_flags *flags, char specifier);
int		speci_correction(char specifier);
char	*width_calculator(char *format, t_flags *flags, t_arg *arg);
char	*precision_calculator(char *format, t_flags *flags, t_arg *arg);

#endif