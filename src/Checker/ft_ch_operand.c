/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_operand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:04:51 by jechoque          #+#    #+#             */
/*   Updated: 2017/12/21 15:34:44 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void			ft_ch_swap(t_lstc *toswap)
{
	t_lstc	*tmp1;
	t_lstc	*tmp2;

	if (toswap->next != toswap->prev)
	{
		tmp1 = toswap->next;
		tmp2 = toswap->next->next;
		tmp2->next->prev = tmp1;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		tmp1->prev = tmp2;
		tmp2->prev = toswap;
		toswap->next = tmp2;
	}
}

void			ft_ch_rotate(t_lstc *torot)
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

void			ft_ch_reverse(t_lstc *torev)
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

void			ft_ch_push(t_lstc *push, t_lstc *to)
{
	t_lstc	*tmp;

	tmp = push->next;
	if (tmp != push)
	{
		push->next = tmp->next;
		tmp->next->prev = push;
		tmp->next = to->next;
		tmp->prev = to;
		to->next->prev = tmp;
		to->next = tmp;
	}
}
