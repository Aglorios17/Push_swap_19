/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:52:35 by shenquin          #+#    #+#             */
/*   Updated: 2021/06/01 16:02:21 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*ft_addbacktab(int *tab, int add)
{
	int	i;
	int	*new_tab;

	i = 0;
	while (tab && tab[i])
		i++;
	new_tab = malloc(sizeof(int *) * (i + 1));
	i = 0;
	while (tab && tab[i])
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = add;
	new_tab[i + 1] = 0;
	free(tab);
	return (new_tab);
}

int	*addfronttab(int *tab, int add)
{
	int	i;
	int	*new_tab;

	i = 0;
	while (tab && tab[i])
		i++;
	new_tab = malloc(sizeof(int *) * (i + 1));
	i = 0;
	new_tab[0] = add;
	while (tab && tab[i])
	{
		new_tab[i + 1] = tab[i];
		i++;
	}
	new_tab[i + 1] = 0;
	free(tab);
	return (new_tab);
}

int	*ft_tabcpy(int *dest, int *src)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!src)
		return (0);
	while (src[len])
		len++;
	dest = malloc(sizeof(int *) * len);
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_min(int *pile)
{
	int	i;
	int	min;

	i = 0;
	min = pile[0];
	while (pile[i])
	{
		if (min > pile[i])
			min = pile[i];
		i++;
	}
	return (min);
}

int	ft_max(int *pile)
{
	int	i;
	int	max;

	i = 0;
	max = pile[0];
	while (pile[i])
	{
		if (max < pile[i])
			max = pile[i];
		i++;
	}
	return (max);
}


