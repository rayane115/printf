/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:57:58 by rqouchic          #+#    #+#             */
/*   Updated: 2020/01/04 17:04:15 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int				select_type(t_struct *data, va_list arg)
{
	int			i;

	i = 0;
	if (data->type == 'c')
		i = ft_print_char(va_arg(arg, int), data);
	else if (data->type == '%')
		i = ft_print_char('%', data);
	else if (data->type == 'd' || data->type == 'i')
		i = ft_print_nb(va_arg(arg, int), data);
	else if (data->type == 's')
		i = ft_print_string(va_arg(arg, char *), data);
	else if (data->type == 'p')
		i = ft_print_add(va_arg(arg, long long int), data);
	else if (data->type == 'u')
		i = ft_print_u(va_arg(arg, unsigned int), data);
	else if (data->type == 'x' || data->type == 'X')
		i = ft_print_x(va_arg(arg, unsigned long long int), data);
	else
		return (0);

	return (i);
}

void			ft_struct(const char *str, va_list arg, int *i, t_struct *data)
{
	ft_initial_data(data);
	ft_verif_flags(str, data, &i);
	ft_verif_width(str, data, &i, arg);
	ft_verif_precision(str, data, &i, arg);
	ft_verif_type(str, data, &i);
}

int				ft_printf(const char *str, ...)
{
	int			i;
	t_struct	*data;
	va_list		arg;
	int			a;

	a = 0;
	i = 0;
	va_start(arg, str);
	data = (t_struct *)malloc(sizeof(t_struct));
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_struct(str, arg, &i, data);
		//	printf("%d = ma precisionbis\n",data->prec_s);
			a += select_type(data, arg);
			if (data->type == 'z')
				break;
		}
		else
			a += ft_putchar_fd_return(str[i], 1);
		i++;
	}
	printf("ret = %d\n",a);
	free (data);
	va_end(arg);
	return (a);
}
