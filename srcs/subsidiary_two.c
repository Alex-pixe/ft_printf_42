/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsidiary_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:19:09 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/26 15:59:56 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*char	*ft_itoa_new(long long n, char *result)
{
	long long	number;
	size_t		discharge;
	size_t		i;

	number = n;
	discharge = 1;
	i = -1;
	check_size(number, &discharge);
	if (n < 0)
	{
		result[++i] = '-';
		number *= -1;
	}
	while (discharge > 0)
	{
		result[++i] = (number / discharge) + '0';
		number %= discharge;
		discharge /= 10;
	}
	result[++i] = '\0';
	return (result);
}

void	check_size(long long number, size_t *discharge)
{
	while (number > 9)
	{
		*discharge *= 10;
		number /= 10;
	}
}*/

void	ft_itoa_base(unsigned long numb, int base, char *line, int i)//check this
{
	if (numb % base > 9)
		line[i++] = numb % base - 10 + 'a';
	else
		line[i++] = numb % base + '0';
	if (numb / base)
		ft_itoa_base(numb / base, base, line, i);
	else
		line[i++] = '\0';
}

char	*reverse(char *s)
{
	char	letter;
	char	*line;
	char	*tmp;
	int		i;

	i = ft_strlen(s);
	tmp = s + i - 1;
	line = s;
	while (i / 2)
	{
		letter = *line;
		*line = *tmp;
		*tmp = letter;
		line++;
		tmp--;
		i -= 2;
	}
	return (s);
}

void	change_case(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line))
			*line = ft_toupper(*line);
		line++;
	}
}
