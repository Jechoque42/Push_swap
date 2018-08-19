/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_addcmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:24:00 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/15 14:13:24 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/push_swap.h"

int	ft_ps_addcmd(t_lcmd **cmds, t_lstc *a, t_lstc *b, char *new_cmd)
{
	t_lcmd	*new;

	if (*cmds)
		ft_ps_addcmd(&(*cmds)->next, a, b, new_cmd);
	else
	{
		if (!(new = malloc(sizeof(t_lcmd))))
			ft_ps_error(a, b, 4);
		new->cmd = new_cmd;
		new->next = NULL;
		*cmds = new;
	}
	return (1);
}
