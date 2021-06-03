/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:23:31 by aglorios          #+#    #+#             */
/*   Updated: 2021/05/31 15:24:45 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	swap_ss(int *tab1, int *tab2)
{
	if (!swap(tab1) || !swap(tab2))
		return (0);
	return (1);
}

int	swap(int *tab)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	if (!tab)
		return (0);
	if (!tab[1])
		return (0);
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	return (1);
}
