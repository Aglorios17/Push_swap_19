/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:01:14 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/26 13:04:08 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_freetab(char **tabs)
{
	int	a;

	a = 0;
	while (tabs[a])
	{
		free(tabs[a]);
		tabs[a] = NULL;
		a++;
	}
	free(tabs);
	tabs = NULL;
}
