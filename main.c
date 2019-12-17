/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:17:47 by rqouchic          #+#    #+#             */
/*   Updated: 2019/12/17 17:24:25 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int main (void)
{
	printf("|----	ft_printf	----|\n\n");

	int a;

	a = 59898;

	//ft_printf("%-5.5drayane%s%--25d\n",96225,"salut",25);
	//printf("%-5.5drayane%s%--25d\n",96225,"salut",25);

	//ft_printf("%-55dra|\n",925);
	//printf("%-55dra|\n\n",925);

	//ft_printf("%10.5xra|\n",96225);
	//printf("%10.5xra|\n\n",96225);

	//ft_printf("%-90.5dra|\n",96225);
	//printf("%-90.5dra|\n",96225);

	//ft_printf("%90sra|\n", "rayane");
	//printf("%90sra|\n", "rayane");

	//ft_printf("%50Xra|\n",506);
	//printf("%50Xra|\n\n",506);

	//ft_printf("%-100pra\n",&a);
    printf("%0*d", 10,1000);




	//printf("%p",&a);
	//printf("%--0-55.9d", 5);
    /*  printf("\n|----          Debut           ----|\n\n");
    printf("\n               *Mon Printf* \n");
    ft_printf("Ecriture              |Salut a tous bande de batard|\n");
    ft_printf("Avec tirait           |%-4c|\n", 'a');
    ft_printf("Sans tirait           |%4c|\n", 'a');
    ft_printf("Zero * 5 et 3         |%0*d|\n", 5, 3);
    ft_printf("Zero * -5 et 3        |%0*d|\n", -5, 3);
    ft_printf("Point  5 caractere    |%.5s|\n",  "Salut les gens");
    ft_printf("Point 3 67            |%.3d|\n",  67);
    ft_printf("Point 1 67            |%.1d|\n",  67);



	printf("\n-----------------------------------------------------\n");
    printf("\n                     *Vrais Printf* \n");
    printf("Ecriture              |Salut a tous bande de batard|\n");
    printf("Avec tirait           |%-4c|\n", 'a');
    printf("Sans tirait           |%4c|\n", 'a');
    printf("Zero * 5 et 3         |%0*d|\n", 5, 3);
    printf("Zero * -5 et 3        |%0*d|\n", 5, 3);
    printf("Point  5 caractere    |%.5s|\n",  "Salut les gens");
    printf("Point 3 67            |%.3d|\n",  67);
    printf("Point 1 67            |%.1d|\n",  67);
    printf("\n|----           Fin            ----|\n\n");
    //system("leaks a.out");*/
    return (0);
}

//
