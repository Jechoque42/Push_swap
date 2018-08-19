/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_gen_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:00:08 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/14 20:05:14 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/push_swap.h"

t_lstc				*ft_ps_init_lstc(void)
{
	t_lstc		*root;

	if (!(root = malloc(sizeof(t_lstc))))
		return (NULL);
	root->cmds = NULL;
	root->nbr = 0;
	root->min = 0;
	root->max = 0;
	root->next = root;
	root->prev = root;
	return (root);
}

static long int		ft_ps_getnbr(char **av)
{
	int			sign;
	long int	nbr;

	sign = 1;
	nbr = 0;
	while (**av == ' ')
		(*av)++;
	if ((**av == '-' || **av == '+'))
	{
		if (**av == '-')
			sign = -1;
		(*av)++;
	}
	if (!ft_isdigit(**av))
		return (2147483648);
	while (ft_isdigit(**av))
	{
		nbr *= 10;
		nbr += -'0' + *(*av)++;
	}
	if (**av != '\0' && **av != ' ')
		return (2147483648);
	else
		return (nbr *= sign);
}

static int			ft_ps_lstcadd(t_lstc *a, t_lstc *b, int value)
{
	t_lstc		*new;

	if (!(new = malloc(sizeof(t_lstc))))
		ft_ps_error(a, b, 4);
	new->cmds = NULL;
	new->nbr = value;
	new->next = a;
	new->prev = a->prev;
	a->prev->next = new;
	a->prev = new;
	return (1);
}

static int			ft_ps_doublon(t_lstc *a, int nbr)
{
	t_lstc		*tmp;

	tmp = a->next;
	while (tmp != a)
	{
		if (tmp->nbr == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void				ft_ps_rank(t_lstc *a)
{
	t_lstc		*tmp;
	t_lstc		*counter;

	tmp = a->next;
	while (tmp != a)
	{
		tmp->rnk = 1;
		counter = a->next;
		while (counter != a)
		{
			if (counter->nbr < tmp->nbr)
				tmp->rnk++;
			counter = counter->next;
		}
		tmp = tmp->next;
	}
}

int					ft_ps_gen_a(t_lstc *a, t_lstc *b, int ac, char **av)
{
	long int	nbr;
	int			i;

	i = 0;
	while (i++ < ac - 1)
	{
		while (**av)
		{
			nbr = ft_ps_getnbr(&(*av));
			if (!ft_ps_doublon(a, nbr))
				ft_ps_error(a, b, 3);
			if (nbr > 2147483647 || nbr < -2147483648 ||
			!ft_ps_lstcadd(a, b, nbr))
				return (0);
			a->nbr++;
		}
		(*av)++;
	}
	ft_ps_rank(a);
	return (1);
}
