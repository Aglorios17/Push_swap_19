/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:52:08 by aglorios          #+#    #+#             */
/*   Updated: 2021/03/09 14:39:46 by aglorios         ###   ########.fr       */
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
}				t_check;

t_check			*global_struct(void);
#endif
