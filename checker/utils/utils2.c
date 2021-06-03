/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:52:35 by shenquin          #+#    #+#             */
/*   Updated: 2021/05/31 15:31:26 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	*ft_addbacktab(int *tab, int add, int len)
{
	int	i;
	int	*new_tab;

	printf("add : %i\n", add);
	new_tab = malloc(sizeof(int *) * (len + 1));
	i = 0;
	while (i < len)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = add;
	new_tab[i + 1] = 0;
	free(tab);
	return (new_tab);
}

int	*addfronttab(int *tab, int add, int len)
{
	int	i;
	int	*new_tab;

	new_tab = malloc(sizeof(int *) * (len + 1));
	i = 0;
	new_tab[0] = add;
	while (i < len)
	{
		new_tab[i + 1] = tab[i];
		i++;
	}
	new_tab[i + 1] = 0;
	free(tab);
	return (new_tab);
}

int	*ft_tabcpy(int *dest, int *src, int len)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
	dest = malloc(sizeof(int *) * len);
	if (!dest)
		return (0);
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
