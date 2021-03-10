/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:52:08 by aglorios          #+#    #+#             */
/*   Updated: 2021/03/10 18:32:55 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../../libft/libft.h"

typedef	struct	s_check
{
			int		*arr;
			char	*input;
			t_list	*stacka;
			t_list	*firsta;
			t_list	*stackb;
			t_list	*firstb;
}				t_check;

t_check			*global_struct(void);

#endif
