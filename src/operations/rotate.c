/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:43:48 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/27 16:39:30 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	rot_rot(int *tab, int len)
{
	int	i;
	int	j;
	int	len;
	int	*temp;

	i = 1;
	j = 0;
	len = 0;
	temp = ft_tabcpy(NULL, tab);
	if (!temp)
		return (0);
	while (i < len)
	{
		tab[i++] = temp[j++];
	}
	tab[0] = temp[len - 1];
	return (1);
}

int	rev_rot_rot(int *tab1, int *tab2)
{
	if (!rotate(tab1) || !rotate(tab2))
		return (0);
	return (1);
}

int	rotate(int *tab)
{
	int	i;
	int	j;
	int	len;
	int	*temp;

	i = 1;
	j = 0;
	len = 0;
	temp = ft_tabcpy(NULL, tab);
	if (!temp)
		return (0);
	while (tab[len])
		len++;
	while (temp[i])
	{
		tab[j++] = temp[i++];
	}
	tab[j] = temp[0];
	return (1);
}

int	rev_rot(int *tab1, int *tab2)
{
	if (!rot_rot(tab1) || !rot_rot(tab2))
		return (0);
	return (1);
}
