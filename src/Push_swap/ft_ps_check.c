/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:27:47 by jechoque          #+#    #+#             */
/*   Updated: 2017/12/21 14:28:18 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int				ft_ps_check(t_lstc *tocheck, int mod)
{
	t_lstc	*check;

	check = tocheck->next;
	if (mod == 0)
	{
		while (check->next != tocheck)
		{
			if (check->nbr > check->next->nbr)
				return (0);
			check = check->next;
		}
	}
	else if (mod == 1)
	{
		while (check->next != tocheck)
		{
			if (check->nbr < check->next->nbr)
				return (0);
			check = check->next;
		}
	}
	return (1);
}
