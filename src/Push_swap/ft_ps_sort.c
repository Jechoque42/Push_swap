/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:14:39 by jechoque          #+#    #+#             */
/*   Updated: 2017/12/21 14:16:56 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int		ft_ps_search_min(t_lstc *a)
{
	t_lstc	*tmp;
	int		i;

	tmp = a->next;
	i = 0;
	while (tmp->nbr != a->min && ++i)
		tmp = tmp->next;
	if (i <= a->nbr / 2)
		return (1);
	return (0);
}

void			ft_ps_sort(t_lstc *a, t_lstc *b)
{
	if (a->nbr < 19 && a->next->nbr > a->next->next->nbr &&
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("sa\n")))
		ft_ps_swap(a);
	else if (ft_ps_search_min(a) &&
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("ra\n")))
		ft_ps_rotate(a);
	else if (ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n")))
		ft_ps_reverse(a);
}

void			ft_ps_littlesort(t_lstc *a, t_lstc *b)
{
	if (a->next->nbr == a->min && a->next->next->nbr == a->max &&
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("sa\n")))
		ft_ps_swap(a);
	else if ((a->next->nbr == a->min || a->next->nbr == a->max) &&
	(a->next->next->nbr == a->max || a->next->next->nbr == a->min) &&
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("ra\n")))
		ft_ps_rotate(a);
	else if (a->next->nbr == a->min && a->prev->nbr < a->prev->prev->nbr &&
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n")))
		ft_ps_reverse(a);
	else if (a->next->nbr > a->next->next->nbr &&
	(a->next->next->nbr != a->min || a->next->nbr != a->max)
	&& ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("sa\n")))
		ft_ps_swap(a);
	else if ((a->next->nbr > a->prev->nbr && a->next->nbr != a->min) &&
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n")))
		ft_ps_reverse(a);
	else if ((a->next->nbr < a->prev->nbr && a->next->nbr != a->max) &&
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("ra\n")))
		ft_ps_rotate(a);
	if (!ft_ps_check(a, 0))
		ft_ps_littlesort(a, b);
}
