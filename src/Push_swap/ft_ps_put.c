/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:21:21 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/15 14:12:23 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void			ft_ps_putcmds(t_lcmd *a)
{
	t_lcmd	*tmpa;

	tmpa = a;
	while (tmpa)
	{
		ft_putstr(tmpa->cmd);
		tmpa = tmpa->next;
	}
}

void			ft_ps_putlstc(t_lstc *a, t_lstc *b)
{
	t_lstc		*cur;

	cur = a->next;
	ft_putstr("Stack A : ");
	while (cur != a)
	{
		ft_putnbr(cur->nbr);
		ft_putchar(' ');
		cur = cur->next;
	}
	ft_putstr("\nStack B : ");
	cur = b->next;
	while (cur != b)
	{
		ft_putnbr(cur->nbr);
		ft_putchar(' ');
		cur = cur->next;
	}
	ft_putchar('\n');
}
