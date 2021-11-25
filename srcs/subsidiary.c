/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsidiary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:37:50 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/25 19:43:38 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_arg(va_list *args, t_flags *f_arg, char convers)
{
	char	numb[18];
	char	*line;

	//f_arg->tmp = f_arg->numb_simb; ???
	if (convers == 'i' || convers == 'd')
		line = ft_itoa_new(va_arg(*args, int), numb);
	else if (convers == 'p' || convers == 'x' || convers == 'X')
	{
		if (convers == 'p')
			ft_itoa_base(va_arg(*args, unsigned long), 16, numb + 2, 0);
		else
			ft_itoa_base(va_arg(*args, unsigned int), 16, numb + 2, 0);
		if (convers == 'X')
			change_case(numb + 2);
		
		line = reverse(numb + put_0x(f_arg, convers, numb));
	}
	else if (convers == 'u')
		line = ft_itoa_new(va_arg(*args, unsigned int), numb);
	else
	{
		if (f_arg->flag_p)
			f_arg->flag_p = 0;
		line = va_arg(*args, char *);
	}
	return (put_arg(f_arg, line));
}

int	put_arg(t_flags *f_arg, char *line)
{
	int	length;

	length = ft_strlen(line);
	while ((unsigned int)(length + f_arg->numb_simb) >= f_arg->size)
	{
		f_arg->result = my_realloc(f_arg, 0);
		if (!f_arg->result)
			return (1);
	}
	f_arg->tmp = f_arg->numb_simb;
	while (*line)
	{
		f_arg->result[f_arg->tmp++] = *line;
		line++;
	}
	f_arg->result[f_arg->tmp] = '\0';
	return (0);
}

int	put_0x(t_flags *f_arg, char convers, char *num)
{
	if (convers == 'p' || ((convers == 'x' || convers == 'X') && f_arg->flag_o))
	{
		num[0] = '0';
		if (convers == 'X' && *(num + 2) != '0')
		{
			num[1] = 'X';
			return (0);
		}
		else if (convers == 'x' && (*(num + 2) != '0' || convers == 'p'))
		{
			num[1] = 'x';
			return (0);
		}
	}
	return (2);
}
