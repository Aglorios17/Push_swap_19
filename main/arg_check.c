/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:15:10 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/10 17:50:27 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	arg_is_str2(t_pile *pile, int b, char **str)
{
	int	j;
	int	i;

	pile->a = malloc(sizeof (int *) * b);
	if (!pile->a)
		exit_error("Error\n");
	j = 0;
	i = 0;
	pile->arg_nb_a = b;
	while (b--)
	{
		pile->a[j] = ft_atoi(str[i++]);
		if (pile->a[j] < -2147483648 || pile->a[j++] > 2147483647)
			exit_error("Error\n");
	}
	pile->a[j] = 0;
	ft_freetab(str);
}

void	arg_is_str(char *av, t_pile *pile)
{
	int		i;
	int		j;
	int		b;
	char	**str;

	i = 0;
	j = 0;
	b = 0;
	str = ft_split(av, ' ');
	while (str[b] != NULL && str[b])
		b++;
	while (i < b)
	{
		j = 0;
		while (str[i][j])
		{	
			if (!ft_isdigit(str[i][j]) && (str[i][j] != '-'
			&& str[i][j] != '+'))
				exit_error("Error\n");
			j++;
		}
		i++;
	}
	arg_is_str2(pile, b, str);
}
