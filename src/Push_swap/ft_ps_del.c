/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:47:12 by jechoque          #+#    #+#             */
/*   Updated: 2017/12/21 13:56:05 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/push_swap.h"

void			ft_ps_del_cmds(t_lcmd **todel)
{
	if (*todel && (*todel)->next)
		ft_ps_del_cmds(&(*todel)->next);
	ft_strdel(&(*todel)->cmd);
	free(*todel);
	*todel = NULL;
}

void			ft_ps_del_lstc(t_lstc *todel)
{
	t_lstc		*del;
	t_lstc		*cur;

	if (todel)
	{
		cur = todel->next;
		while (cur != todel && (del = cur))
		{
			cur = cur->next;
			free(del);
		}
		if (todel->cmds)
			ft_ps_del_cmds(&todel->cmds);
		free(todel);
		todel = NULL;
	}
}
