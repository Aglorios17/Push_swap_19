/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:25:01 by aglorios          #+#    #+#             */
/*   Updated: 2021/06/03 12:25:04 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	swap_ss(int *tab1, int *tab2, int len1, int len2)
{
	if (!swap(tab1, len1) || !swap(tab2, len2))
		return (0);
	return (1);
}

int	swap(int *tab, int len)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	if (len < 1)
		return (0);
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	return (1);
}
