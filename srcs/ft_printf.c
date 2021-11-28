/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:36:04 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/28 16:36:51 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> //fix
#include <limits.h>

int		ft_printf(const char *format, ...)
{
	t_flags	*f_arg;
	va_list	args;
	int		i;

	i = 0;
	f_arg = start_struct();
	if (!f_arg)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			
			if (pars(&i, &args, f_arg, format))
				return (-1);
			continue ;
		}
		if ((unsigned int)f_arg->numb_simb == f_arg->size)
			f_arg->result = my_realloc(f_arg, 0);
		if (!f_arg)
			return (-1);
		f_arg->result[f_arg->numb_simb++] = format[i++];
	}
	f_arg->result[f_arg->numb_simb] = '\0';
	return (put_result(f_arg));
}

t_flags	*start_struct(void)
{
	t_flags *f_arg;
	
	f_arg = (t_flags *)malloc(sizeof(t_flags) * 1);
	if (!f_arg)
		return ((void *)0);
	f_arg->flag_m = 0;
	f_arg->flag_n = 0;
	f_arg->flag_o = 0;
	f_arg->flag_p = 0;
	f_arg->flag_s = 0;
	f_arg->flag_prec = 0;
	f_arg->width = 0;
	f_arg->precision = 0;
	f_arg->size = 20;
	f_arg->numb_simb = 0;
	//f_arg->tmp = 0; ???
	f_arg->result = my_realloc(f_arg, 1);
	if (!f_arg->result)
	{
		free(f_arg);
		return ((void *)0);
	}
	return (f_arg);
}

int	put_result(t_flags *f_arg)
{
	int	length;

	length = f_arg->numb_simb;
	write(1, f_arg->result, length);
	free(f_arg->result);
	free(f_arg);
	return (length);
}

/*int main()
{
	int i, j;

	i = ft_printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	j = printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d\n", INT_MAX, INT_MIN, (int)LONG_MAX, (int)LONG_MIN, (int)ULONG_MAX, 0, -42);
	printf("my=%d, libc=%d\n\n", i, j);
	return 0;
}*/
