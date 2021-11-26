/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:22:31 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/26 14:46:07 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_extension(int *i, va_list *args, t_flags *f_arg, const char *format)
{
	int	j;

	j = *i;
	(*i)++;
	if (format[j] == 'd' || format[j] == 'i' || format[j] == 'c'
		|| format[j] == '%' || format[j] == 's' || format[j] == 'u'
		|| format[j] == 'p' || format[j] == 'x' || format[j] == 'X')
		return (extension_two(args, f_arg, format[j]));
	else
	{
		free(f_arg->result);
		free(f_arg);
		return (-1);
	}
}

int	extension_two(va_list *args, t_flags *f_arg, char convers)
{
	if (get_arg(args, f_arg, convers))
		return (1);
	/*if (f_arg->precision)
	{
		if (put_precision(args, f_arg))// do it
			return (1);
	}
	else
		put_res();//do it
	if (f_arg->width)
		add_width();// do it*/
	if (convers != 'c' && convers != '%')
		f_arg->numb_simb = f_arg->tmp;
	return (0);
}
