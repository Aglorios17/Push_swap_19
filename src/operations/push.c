/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:33:56 by shenquin          #+#    #+#             */
/*   Updated: 2021/05/27 16:39:25 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	push_a(t_pile *pile)
{
	int	tmp;
	int	i;
	int	*tab_tmp;

	i = 0;
	tab_tmp = 0;
	if (pile->arg_nb_b != 0)
	{
		tmp = pile->b[0];
		i = 1;
		while (i < pile->arg_nb_b)
			tab_tmp = ft_addbacktab(tab_tmp, pile->b[i++]);
		pile->a = addfronttab(pile->a, tmp);
		pile->arg_nb_a += 1;
		pile->arg_nb_b -= 1;
		free(pile->b);
		pile->b = ft_tabcpy(pile->b, tab_tmp);
		free(tab_tmp);
	}
	return (0);
}

int	push_b(t_pile *pile)
{
	int	tmp;
	int	i;
	int	*tab_tmp;

	i = 0;
	tab_tmp = 0;
	if (pile->arg_nb_a != 0)
	{
		tmp = pile->a[0];
		i = 1;
		while (i < pile->arg_nb_a)
			tab_tmp = ft_addbacktab(tab_tmp, pile->a[i++]);
		pile->b = addfronttab(pile->b, tmp);
		pile->arg_nb_b += 1;
		pile->arg_nb_a -= 1;
		free(pile->a);
		pile->a = ft_tabcpy(pile->a, tab_tmp);
		free(tab_tmp);
	}
	return (0);
}
