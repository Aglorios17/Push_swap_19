/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:24:14 by aglorios          #+#    #+#             */
/*   Updated: 2021/06/12 13:25:21 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	main(int ac, char **av)
{
	t_pile	*pile;

	pile = ft_calloc(1, sizeof(t_pile));
	pile->count_arg = 1;
	if (ac < 2)
		exit_error("Error\n");
	if (!arg_to_pile(ac, av, pile))
		return (0);
	while (pile->count_arg != 0)
		pile_doublons(pile->a[--pile->count_arg], pile);
	checker_algo(pile);
	free_struct(pile);
	return (0);
}
