/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:45:32 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/31 01:04:07 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libc.h>
# include <stdarg.h>

typedef	struct	s_struct
{
	char		flag;
	int			width;
	int			precision;
	char		type;
}				t_struct;

void			ft_verif_type(const char *str, t_struct *data, int **i);
void			ft_verif_precision(const char *str, t_struct *data, int **i,
va_list arg);
void			ft_verif_width(const char *str, t_struct *data, int **i,
va_list arg);
void			ft_verif_flags(const char *str, t_struct *data, int **i);
int				ft_print_char(char c, t_struct *data);
int				ft_print_nb(int nb, t_struct *data);
int				ft_left(int nb, t_struct *data, int len);
int				ft_print_string(char *str, t_struct *data);
int				ft_right(int nb, t_struct *data, int len, char c);
int				ft_print_u(unsigned int nb, t_struct *data);
int				ft_print_x(unsigned long long int nb, t_struct *data);
int				count_len_u(unsigned int nb);
int				ft_print_add(long long int p, t_struct *data);
int				select_type(t_struct *data, va_list arg);
void			ft_initial_data(t_struct *data);
int				count_len(int nb);
int				ft_right_u(unsigned int nb, t_struct *data, int len, char c);
int				ft_left_u(unsigned int nb, t_struct *data, int len);
int				ft_printf(const char *str, ...);
int				ft_right_x(unsigned long long int nb, t_struct *data,
int l, char c);
int				ft_left_x(unsigned long long int nb, t_struct *data, int len);
int				count_len_x(unsigned long long int nb);
int				ft_right_add(char *str, t_struct *data, int len, char c);
int				ft_left_add(char *str, t_struct *data, int len);
int				count_len_add(long long int nb);
int				ft_right_string(char *str, t_struct *data, int len, char c);
int				ft_left_string(char *str, t_struct *data, int len);
int				ft_right_char(char a, t_struct *data, int len, char c);
int				ft_left_char(char a, t_struct *data, int len);
void			ft_width_precision_arg(int nextarg, t_struct *data);
void			ft_initial_data(t_struct *data);
void			ft_error_type(void);
char			*ft_str_raccou_add(long long int nb);
char			ft_raccou_string(t_struct *data);
void			ft_raccou_nb(t_struct *data, int nb, int *len);

#endif
