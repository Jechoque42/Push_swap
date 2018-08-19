/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_gen_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:04:37 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/19 16:14:42 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "../../include/checker.h"

static long int		ft_ch_getnbr(char **av)
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

static int			ft_ch_lstcadd(t_lstc *a, int value)
{
	t_lstc		*new;

	if (!(new = malloc(sizeof(t_lstc))))
		return (0);
	new->nbr = value;
	new->next = a;
	new->prev = a->prev;
	a->prev->next = new;
	a->prev = new;
	return (1);
}

static int			ft_ch_doublon(t_lstc *a, int nbr)
{
	t_lstc	*tmp;

	tmp = a->next;
	while (tmp != a)
	{
		if (tmp->nbr == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void			ft_ch_rank(t_lstc *a)
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

int					ft_ch_gen_a(t_lstc *a, t_lstc *b, int ac, char **av)
{
	long int	nbr;
	int			i;

	i = 0;
	if ((!ft_strcmp(*av, "-littlev") || !ft_strcmp(*av, "-game") ||
	!ft_strcmp(*av, "-visual++")) && ac--)
		av++;
	while (i++ < ac - 1)
	{
		while (**av)
		{
			nbr = ft_ch_getnbr(&(*av));
			if (!ft_ch_doublon(a, nbr))
				ft_ch_error(a, b, 3);
			if (nbr > 2147483647 || nbr < -2147483648 ||
			!ft_ch_lstcadd(a, nbr))
				return (0);
		}
		(*av)++;
	}
	a->nbr = i - 1;
	ft_ch_rank(a);
	return (1);
}
