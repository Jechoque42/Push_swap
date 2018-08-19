/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:13:11 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/18 14:36:03 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int				main(int argc, char **argv)
{
	t_lstc	*stack_a;
	t_lstc	*stack_b;

	stack_a = ft_ps_init_lstc();
	stack_b = ft_ps_init_lstc();
	if (!stack_a || !stack_b)
		ft_ps_error(stack_a, stack_b, 4);
	if (argc <= 1)
		ft_ps_error(stack_a, stack_b, 0);
	if (argc > 1 && ft_ps_gen_a(stack_a, stack_b, argc, ++argv))
		ft_ps_algo(stack_a, stack_b);
	else
		ft_ps_error(stack_a, stack_b, 1);
	ft_ps_del_lstc(stack_a);
	ft_ps_del_lstc(stack_b);
	return (1);
}
