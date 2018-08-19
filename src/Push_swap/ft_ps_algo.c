/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:05:29 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/18 14:34:57 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/push_swap.h"

static void		ft_ps_extrem(t_lstc *a)
{
	t_lstc	*tmp;

	tmp = a->next;
	a->min = tmp->nbr;
	a->max = tmp->nbr;
	while (tmp != a)
	{
		if (tmp->nbr > a->max)
			a->max = tmp->nbr;
		if (tmp->nbr < a->min)
			a->min = tmp->nbr;
		tmp = tmp->next;
	}
}

static void		ft_ps_algo_a(t_lstc *a, t_lstc *b)
{
	if (!ft_ps_check(a, 0) && a->next->nbr == a->min &&
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("pb\n")))
	{
		ft_ps_push(a, b);
		ft_ps_extrem(a);
	}
	else if (!ft_ps_check(a, 0))
	{
		ft_ps_extrem(a);
		if (a->nbr <= 4)
			ft_ps_littlesort(a, b);
		else
			ft_ps_sort(a, b);
	}
	ft_ps_putcmds(a->cmds);
	ft_ps_del_cmds(&a->cmds);
}

static void		ft_ps_algo_b(t_lstc *a, t_lstc *b)
{
	if (b->next->nbr > a->next->nbr &&
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("ra\n")))
		ft_ps_rotate(a);
	else if (b->next->nbr < a->next->nbr &&
	(b->next->nbr > a->prev->nbr || a->prev->nbr == a->max)
	&& ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("pa\n")))
		ft_ps_push(b, a);
	else if (ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n")))
		ft_ps_reverse(a);
	ft_ps_putcmds(a->cmds);
	ft_ps_del_cmds(&a->cmds);
}

void				ft_ps_optirotatea(t_lstc *a, t_lstc *calc)
{
	t_lstc	*tmp;
	int		counter;

	tmp = a->next;
	counter = 0;
	while (tmp->rnk != calc->rnk)
	{
		counter++;
		tmp = tmp->next;
	}
	calc->ra = counter;
	calc->rra = a->nbr - counter;
}

void				ft_ps_optirotateb(t_lstc *b, t_lstc *calc)
{
	t_lstc	*tmp;
	int		counter;
	int		delta;

	tmp = b->next;
	counter = 0;
	delta = 2147483647;
	while (tmp->next != b)
	{
		if (tmp->rnk > calc->rnk && tmp->next->rnk < calc->rnk)
		{
			if (tmp->rnk - tmp->next->rnk < delta
			&& (delta = tmp->rnk - tmp->next->rnk))
			{
				calc->rb = counter + 1;
				calc->rrb = b->nbr - counter - 1;
			}
		}
		counter++;
		tmp = tmp->next;
	}
	if ((b->next->rnk < calc->rnk && b->prev->rnk > calc->rnk)
	&& ABS(b->next->rnk - b->prev->rnk) < delta)
	{
			calc->rb = 0;
			calc->rrb = b->nbr;
	}
	counter = 0;
	tmp = b->next;
	if (b->min > calc->nbr)
	{
		while (tmp->nbr != b->min)
		{
			counter++;
			tmp = tmp->next;
		}
		calc->rb = counter + 1;
		calc->rrb = b->nbr - counter - 1;
	}
	if (b->max < calc->nbr)
	{
		while (tmp->nbr != b->max)
		{
			counter++;
			tmp = tmp->next;
		}
		calc->rb = counter;
		calc->rrb = b->nbr - counter;
	}
}

void			ft_ps_pushtwob(t_lstc *a, t_lstc *b)
{
	ft_ps_push(a, b);
	ft_ps_push(a, b);
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("pb\n"));
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("pb\n"));
	if (b->next->nbr < b->next->next->nbr)
	{
		ft_ps_swap(b);
		ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("sb\n"));
	}
}

void			ft_ps_calcopti(t_lstc *a, t_lstc *b)
{
	t_lstc	*tmp;

	tmp = a->next;
	while (tmp != a)
	{
		ft_ps_optirotatea(a, tmp);
		ft_ps_optirotateb(b, tmp);
		tmp = tmp->next;
	}
}

int			ft_ps_cmprr(t_lstc *min, int mod)
{
	int		rr;
	int		r;

	rr = min->rra >= min->rrb ? min->rra : min->rrb;
	r = min->ra >= min->rb ? min->ra : min->rb;
	if (mod == 1)
	{
		if (min->rra + min->rb < rr && min->rra + min->rb < r
		&& min->rra + min->rb < min->rrb + min->ra)
			return (min->rra + min->rb);
		if (min->rrb + min->ra < rr && min->rrb + min->ra < r
		&& min->rrb + min->ra < min->rra + min->rb)
			return (min->rrb + min->ra);
		if (rr < r)
			return (rr);
		return (r);
	}
	if (min->rra + min->rb < rr && min->rra + min->rb < r
	&& min->rra + min->rb < min->rrb + min->ra)
		return (2);
	if (min->rrb + min->ra < rr && min->rrb + min->ra < r
	&& min->rrb + min->ra < min->rra + min->rb)
		return (3);
	if (rr < r)
		return (0);
	return (1);
}

void			ft_ps_applyopti(t_lstc *a, t_lstc *b, t_lstc *choose)
{
	if (ft_ps_cmprr(choose, 2) == 0)
	{
		while (choose->rra && choose->rrb)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rrr\n"));
			ft_ps_reverse(a);
			ft_ps_reverse(b);
			choose->rra--;
			choose->rrb--;
		}
		while (choose->rra && choose->rra--)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n"));
			ft_ps_reverse(a);
		}
		while (choose->rrb && choose->rrb--)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rrb\n"));
			ft_ps_reverse(b);
		}
	}
	else if (ft_ps_cmprr(choose, 2) == 1)
	{
		while (choose->ra && choose->rb)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rr\n"));
			ft_ps_rotate(a);
			ft_ps_rotate(b);
			choose->ra--;
			choose->rb--;
		}
		while (choose->ra && choose->ra--)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("ra\n"));
			ft_ps_rotate(a);
		}
		while (choose->rb && choose->rb--)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rb\n"));
			ft_ps_rotate(b);
		}
	}
	else if (ft_ps_cmprr(choose, 2) == 2)
	{
		while (choose->rra && choose->rra--)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n"));
			ft_ps_reverse(a);
		}
		while (choose->rb && choose->rb--)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rb\n"));
			ft_ps_rotate(b);
		}
	}
	else if (ft_ps_cmprr(choose, 2) == 3)
	{
		while (choose->rrb && choose->rrb--)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rrb\n"));
			ft_ps_reverse(b);
		}
		while (choose->ra && choose->ra--)
		{
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("ra\n"));
			ft_ps_rotate(a);
		}
	}
}

void			ft_ps_selectopti(t_lstc *a, t_lstc *b)
{
	t_lstc		*tmp;
	t_lstc		*choose;
	int		min1;
	int		min2;

	tmp = a->next->next;
	choose = a->next;
	while (tmp != a)
	{
		min1 = ft_ps_cmprr(choose, 1);
		min2 = ft_ps_cmprr(tmp, 1);
		if (min2 < min1)
			choose = tmp;
		tmp = tmp->next;
	}
	ft_ps_applyopti(a, b, choose);
	ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("pb\n"));
	ft_ps_push(a, b);
}

void			ft_ps_orderb(t_lstc *a, t_lstc *b)
{
	t_lstc *tmp;
	int	counter;
	int	rotate;

	tmp = b->next;
	ft_ps_extrem(b);
	counter = 0;
	rotate = 0;
	while (tmp->nbr != b->max)
	{
		counter++;
		tmp = tmp->next;
	}
	if (counter <= b->nbr / 2)
		rotate = 1;
	while (b->next->nbr != b->max)
	{
		if (rotate && ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rb\n")))
			ft_ps_rotate(b);
		else if (ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rrb\n")))
			ft_ps_reverse(b);
	}
}

void			ft_ps_algo(t_lstc *a, t_lstc *b)
{
	int		i;

	i = 0;
	if (a->nbr > 9 && !ft_ps_check(a, 0))
	{
		ft_ps_pushtwob(a, b);
		while (!ft_ps_check(a, 0))
		{
			ft_ps_extrem(b);
			ft_ps_calcopti(a, b);
			ft_ps_selectopti(a, b);
		}
		ft_ps_orderb(a, b);
		while (a->prev->rnk > b->next->rnk && a->next->rnk != b->next->rnk +1)
		{
			ft_ps_reverse(a);
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n"));
		}
		while (b->next != b)
		{
			while (a->next->rnk == a->prev->rnk + 1)
			{
				ft_ps_reverse(a);
				ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n"));
			}
			ft_ps_push(b, a);
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("pa\n"));
		}
		while (a->next->rnk != 1)
		{
			ft_ps_reverse(a);
			ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n"));
		}
		ft_ps_putcmds(a->cmds);
	}
	else
	{
		while (!ft_ps_check(a, 0))
			ft_ps_algo_a(a, b);
		while (b->next != b)
			ft_ps_algo_b(a, b);
		while (!ft_ps_check(a, 0))
		{
			ft_putstr("rra\n");
			ft_ps_reverse(a);
		}
	}
}
