/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_return.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:12:32 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/30 21:56:46 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_putchar_fd_return(char c, int fd)
{
	static int i;

	i = 0;
	write(fd, &c, 1);
	i++;
	return (i);
}
