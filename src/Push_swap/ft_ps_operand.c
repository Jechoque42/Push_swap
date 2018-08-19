/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_operand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:48:33 by jechoque          #+#    #+#             */
/*   Updated: 2018/01/03 17:08:34 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void			ft_ps_swap(t_lstc *toswap)
{
	t_lstc	*tmp1;
	t_lstc	*tmp2;

	tmp1 = toswap->next;
	tmp2 = toswap->next->next;
	tmp2->next->prev = tmp1;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp2->prev = toswap;
	toswap->next = tmp2;
}

void			ft_ps_rotate(t_lstc *torot)
{
	t_lstc	*tmp;

	tmp = torot->next;
	tmp->next->prev = torot;
	torot->next = tmp->next;
	tmp->next = torot;
	tmp->prev = torot->prev;
	torot->prev->next = tmp;
	torot->prev = tmp;
}

void			ft_ps_reverse(t_lstc *torev)
{
	t_lstc	*tmp;

	tmp = torev->prev;
	tmp->prev->next = torev;
	torev->prev = tmp->prev;
	tmp->prev = torev;
	tmp->next = torev->next;
	torev->next->prev = tmp;
	torev->next = tmp;
}

void			ft_ps_push(t_lstc *push, t_lstc *to)
{
	t_lstc	*tmp;

	tmp = push->next;
	if (tmp != push)
	{
		push->nbr--;
		to->nbr++;
		push->next = tmp->next;
		tmp->next->prev = push;
		tmp->next = to->next;
		tmp->prev = to;
		to->next->prev = tmp;
		to->next = tmp;
	}
}
