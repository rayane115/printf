/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:17:47 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/11 15:17:55 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int main (void)
{
	printf("|----	ft_printf	----|\n\n");

	int a;

	a = 5;

	ft_printf("%-5dra\n",65);
	printf("%-5dra\n",65);
//	printf("%p",&a);
	//printf("%--0-55.9d", 5);
   return 0;
}

