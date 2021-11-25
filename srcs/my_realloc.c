/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:55:56 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/25 17:45:33 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_realloc(t_flags *f_arg, char mod)
{
	char			*tmp;

	if (mod)
	{
		tmp = (char *)malloc(sizeof(char) * f_arg->size);
		if (!tmp)
			return ((void *)0);
		tmp[0] = '\0';
	}
	else
		tmp = my_realloc_two(f_arg);
	return (tmp);
}

char	*my_realloc_two(t_flags *f_arg)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (f_arg->size * 2));
	if (!tmp)
	{
		free(f_arg->result);
		free(f_arg);
		return ((void *)0);
	}
	while (i < f_arg->size)
	{
		tmp[i] = f_arg->result[i];
		i++;
	}
	f_arg->size *= 2;
	free(f_arg->result);
	return (tmp);
}
