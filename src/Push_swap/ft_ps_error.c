/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:45:42 by jechoque          #+#    #+#             */
/*   Updated: 2017/12/21 13:58:27 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/push_swap.h"

void			ft_ps_error(t_lstc *a, t_lstc *b, int mod)
{
	if (mod == 1)
		ft_putstr_fd("Argument Error\n", 2);
	if (mod == 3)
		ft_putstr_fd("Doublon Error\n", 2);
	if (mod == 4)
		ft_putstr_fd("Malloc Error\n", 2);
	ft_ps_del_lstc(a);
	ft_ps_del_lstc(b);
	exit(1);
}
