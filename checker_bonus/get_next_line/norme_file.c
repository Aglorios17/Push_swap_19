/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:19:01 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/31 15:56:18 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	norme_gnlc(char *reste, int i, int *j, char *new)
{
	while (reste[i + *j])
	{
		new[*j] = reste[i + *j];
		(*j)++;
	}
}
