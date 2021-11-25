/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:08:21 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/25 19:26:58 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct a_flags
{
	char			flag_p;
	char			flag_m;
	char			flag_s;
	char			flag_n;
	char			flag_o;
	char			flag_prec;
	int				width;
	int				precision;
	char			*result;
	unsigned int	size;
	int				numb_simb;
	int				tmp;
}		t_flags;

int		ft_printf(const char *format, ...);
int		pars(int *i, va_list *args, t_flags *f_arg, const char *format);
void	check_flags(int *i, va_list *args, t_flags *f_arg, const char *format);
void	save_flag(char f, int *i, t_flags *f_arg);
void	save_width(const char *format, int *i, t_flags *f_arg, va_list *args);
void	save_precision(const char *format, int *i, t_flags *f_arg,
			va_list *args);
t_flags	*start_struct(void);
int		get_extension(int *i, va_list *args, t_flags *f_arg, const char *format);
int		extension_two(va_list *args, t_flags *f_arg, char convers);

void	check_size(long long number, size_t *discharge);
int		get_arg(va_list *args, t_flags *f_arg, char convers);
int		put_arg(t_flags *f_arg, char *line);
char	*my_realloc(t_flags *f_arg, char mod);
char	*my_realloc_two(t_flags *f_arg);
char	*ft_itoa_new(long long n, char *result);
void	ft_itoa_base(unsigned long numb, int base, char *line, int i);
char	*reverse(char *line);
void	change_case(char *line);
int		put_0x(t_flags *f_arg, char convers, char *num);
int		put_result(t_flags *f_arg);

#endif
