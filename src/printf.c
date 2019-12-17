/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:57:58 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/14 16:18:29 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void		ft_verif_type(const char *str,t_struct *Struct,  int *i )
{
	while (str[*i])
	{
		if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' ||
		str[*i] == 'd' || str[*i] == 'i' ||
		str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X' || str[*i] == '%')
		{
			Struct->type = str[*i];
			return ;
		}
		*i = *i + 1;
	}
}

void	ft_verif_precision(const char *str, t_struct *Struct, int *i)
{
	if (str[*i] == '.')
	{
		*i += 1;
		Struct->precision = ft_atoi(&str[*i]);
	}
	while (str[*i] && str[*i] >= '0' &&  str[*i] <= '9')
		*i += 1;
}

void	ft_verif_width(const char *str, t_struct *Struct, int *i)
{
	if (str[*i] >= '0' &&  str[*i] <= '9')
		Struct->width = ft_atoi(&str[*i]);
	while (str[*i] && str[*i] >= '0' &&  str[*i] <= '9')
		*i += 1;
}

void	ft_verif_flags(const char *str, t_struct *Struct, int *i)
{

		if (str[*i] == '-')
		{
			Struct->flag = '-';
			while (str[*i] == '-' || str[*i] == '0')
				*i += 1;
			return ;
		}
		if (str[*i] == '0')
		{
			Struct->flag = '0';
			while (str[*i] == '0' || str[*i] == '-')
			{
				if (str[*i] == '-')
					Struct->flag = '-';
				*i += 1;
			}
			return ;
		}
}

void	select_type(t_struct *Struct, va_list arg)
{
	if (Struct->type == 'c')
		ft_print_char(va_arg(arg, int), Struct);

	if (Struct->type == '%')
		ft_print_char('%', Struct);

	if (Struct->type == 'd' || Struct->type == 'i')
		ft_print_nb(va_arg(arg, int), Struct);

	if (Struct->type == 's')
		ft_print_string(va_arg(arg, char *), Struct);

	 if (Struct->type == 'p')
	 	ft_print_add(va_arg(arg, long long int), Struct);

	if (Struct->type == 'u')
		ft_print_U(va_arg(arg, unsigned int), Struct);


	if (Struct->type == 'x')
		ft_print_x(va_arg(arg,unsigned long long int), Struct);

	if (Struct->type == 'X')
		ft_print_x(va_arg(arg,unsigned long long int), Struct);

}

void	ft_initial_struct(t_struct *Struct)
{
	Struct->flag = 0;
	Struct->width = 0;
	Struct->precision = 0;
	Struct->flag = 0;
}

int ft_printf(const char *str, ...)
{
	int i;
	t_struct *Struct;
	va_list		arg;
	i = 0;

	va_start(arg, str);
	Struct = (t_struct *)malloc(sizeof(t_struct));
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_initial_struct(Struct);
			ft_verif_flags(str, Struct, &i);
			ft_verif_width(str, Struct, &i);
			ft_verif_precision(str, Struct, &i);
			ft_verif_type(str, Struct, &i);
			select_type(Struct, arg);

		}

		else
			ft_putchar_fd(str[i], 1);

		i++;
	}
	va_end(arg);
	return (0);
}
