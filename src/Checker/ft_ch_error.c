/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:02:59 by jechoque          #+#    #+#             */
/*   Updated: 2017/12/21 14:51:54 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void		ft_ch_error(t_lstc *a, t_lstc *b, int mod)
{
	if (mod == 1)
		ft_putstr_fd("Argument Error\n", 2);
	else if (mod == 2)
		ft_putstr_fd("Operand Error\n", 2);
	else if (mod == 3)
		ft_putstr_fd("Doublon Error\n", 2);
	else if (mod == 4)
		ft_putstr_fd("Already Sorted\n", 1);
	ft_ch_del_lstc(a, b);
	exit(1);
}
