/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:38:58 by shenquin          #+#    #+#             */
/*   Updated: 2021/06/03 12:40:28 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sort(int *pile, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (pile[i] > pile[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	pile_doublons(int arg, t_pile *pile)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < pile->arg_nb_a)
	{
		if (arg == pile->a[i])
			count++;
		i++;
	}
	if (count > 1)
		exit_error("Error\n");
}

void	pile_arg(char *arg, t_pile *pile)
{
//	int	j; ////////////////////////////////////////////// why ?

//	j = 0;
//	while (arg[j])
//	{
//		if (!ft_isdigit(arg[j]))
//			exit_error("Error\n");
//		j++;
//	} //////////////////////////////////////////////////////
	pile->a[pile->arg_nb_a] = ft_atoi(arg);
	if (pile->a[pile->arg_nb_a] < -2147483648 && pile->a[pile->arg_nb_a] > 2147483647)
		exit_error("Error5\n");
	pile->arg_nb_a++;
}

int	algo_main(t_pile *pile)
{
	if (!is_sort(pile->a, pile->arg_nb_a))
		return (0);
	if (pile->arg_nb_a <= 3)
		algo_3nba(pile->a, pile->arg_nb_a);
	else if (pile->arg_nb_a <= 5 && pile->arg_nb_a >= 4)
		algo_5nb(pile);
	else
		algo(pile);
	return (0);
}
