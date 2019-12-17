/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:45:32 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/14 16:33:49 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libc.h>
# include <stdarg.h>

typedef struct s_struct
{
	char flag;
	int width;
	int precision;
	char type;
}				t_struct;

void		ft_verif_type(const char *str,t_struct *Struct,  int *i );
void	ft_verif_precision(const char *str, t_struct *Struct, int *i);
void	ft_verif_width(const char *str, t_struct *Struct, int *i);
void	ft_verif_flags(const char *str, t_struct *Struct, int *i);
//void	ft_print_char(char c);
void	ft_print_char(char c, t_struct *Struct);
//char	*ft_print_nb(int nb);
void	ft_print_nb(int nb, t_struct *Struct);
void	ft_print_string(char *str, t_struct *Struct);
//char	*ft_print_string(char *str);
//char	*ft_print_U(unsigned int n);
void	ft_print_U(unsigned int n, t_struct *Struct);
//char	*ft_print_x(unsigned long long int x);
void	ft_print_x(unsigned long long int nb, t_struct *Struct);

//char	*ft_print_add(long long int p);
void	ft_print_add(long long int p, t_struct *Struct);
void	select_type(t_struct *Struct, va_list arg);
void	ft_initial_struct(t_struct *Struct);
int		count_len(int nb);
void	ft_right_U(unsigned int nb, t_struct *Struct, int len, char c);
void	ft_parsing_all(t_struct *Struct, va_list arg);
void	ft_left_U(unsigned int nb, t_struct *Struct, int len);
int ft_printf(const char *str, ...);
int		count_len_U(unsigned int nb);
void	ft_right_x(unsigned long long int nb, t_struct *Struct, int len, char c);
void	ft_left_x(unsigned long long int nb, t_struct *Struct, int len);
int		count_len_x(unsigned long long int nb);
void	ft_right_add(char *str, t_struct *Struct, int len, char c);
void	ft_left_add(char *str, t_struct *Struct, int len);
int		count_len_add(long long int nb);
void	ft_right_string(char *str, t_struct *Struct, int len, char c);
void	ft_left_string(char *str, t_struct *Struct, int len);
void	ft_right_char(char a, t_struct *Struct, int len, char c);
void	ft_left_char(char a, t_struct *Struct, int len);

#endif
