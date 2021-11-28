/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:43:02 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/28 16:36:28 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_width(t_flags *f_arg, char convers)
{
	//if (convers == 's')
	//{
	//	if (f_arg->tmp - f_arg->numb_simb > f_arg->width)
	//		f_arg->tmp = f_arg->numb_simb +f_arg->width;
	//}
	if (f_arg->flag_n && convers != 's')
	{
		if (f_arg->result[f_arg->numb_simb] == '-' || f_arg->result[f_arg->numb_simb] == '+')
			f_arg->width--;
		f_arg->precision = f_arg->width;
		if (precision_form(f_arg, convers))
			return (1);
	}
	else
	{
		if (f_arg->flag_m)
		{
			if (width_end(f_arg))
				return (1);
		}
		else
		{
			if (width_start(f_arg))
				return (1);
		}
	}
	return (0);
}

int	width_start(t_flags *f_arg)
{
	int	j;
	int	i;
	int	d;

	j = f_arg->width;
	i = f_arg->tmp - f_arg->numb_simb;
	d = f_arg->tmp;
	while(i < j)
	{
		if (f_arg->size <= (unsigned int)(f_arg->tmp + 1))
		{
			f_arg->result = my_realloc(f_arg, 0);
			if (!f_arg)
				return (1);
		}
		while(f_arg->numb_simb <= d)
		{
			f_arg->result[d + 1] = f_arg->result[d];
			d--;
		}
		f_arg->result[++d] = ' ';
		f_arg->result[++f_arg->tmp] = '\0';
		d = f_arg->tmp;
		i++;
	}
	return (0);
}

int	width_end(t_flags *f_arg)
{
	int	j;
	int	i;

	j = f_arg->width;
	i = f_arg->tmp - f_arg->numb_simb;
	while(i < j)
	{
		if (f_arg->size <= (unsigned int)(f_arg->tmp + 1))
		{
			f_arg->result = my_realloc(f_arg, 0);
			if (!f_arg)
				return (1);
		}
		f_arg->result[f_arg->tmp++] = ' ';
		i++;
	}
	f_arg->result[f_arg->tmp] = '\0';
	return (0);
}