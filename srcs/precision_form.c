/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:20:31 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/28 15:56:01 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision_form(t_flags *f_arg, char convers)
{
	int	j;
	int	i;
	int	sign;

	sign = 0;
	j = f_arg->precision;
	i = f_arg->tmp - f_arg->numb_simb;
	if (f_arg->result[f_arg->numb_simb] == '-' || f_arg->result[f_arg->numb_simb] == '+')
		sign += 1;
	j = f_arg->precision + sign;
	while(i < j && convers != 's')
	{
		if (add_pr(f_arg, sign))
			return (1);
		j--;
	}
	return 0;
}

int	add_pr(t_flags *f_arg, int sign)
{
	int	i;

	i = f_arg->tmp;
	if (f_arg->size <= (unsigned int)(f_arg->tmp + 1))
	{
		f_arg->result = my_realloc(f_arg, 0);
		if (!f_arg)
			return (1);
	}
	while(f_arg->numb_simb + sign <= i)
	{
		f_arg->result[i + 1] = f_arg->result[i];
		i--;
	}
	f_arg->result[++i] = '0';
	f_arg->result[++f_arg->tmp] = '\0';
	return (0);
}
