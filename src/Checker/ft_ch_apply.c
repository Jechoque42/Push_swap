/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:04:29 by jechoque          #+#    #+#             */
/*   Updated: 2017/12/21 15:30:57 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static void		ft_ch_apply_swap(t_lstc *a, t_lstc *b, char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		ft_ch_swap(a);
	else if (!ft_strncmp(line, "sb", 3))
		ft_ch_swap(b);
	else if (!ft_strncmp(line, "ss", 3))
	{
		ft_ch_swap(a);
		ft_ch_swap(b);
	}
	else
		ft_ch_error(a, b, 2);
}

static void		ft_ch_apply_rot_rev(t_lstc *a, t_lstc *b, char *line)
{
	if (!ft_strncmp(line, "rra", 4))
		ft_ch_reverse(a);
	else if (!ft_strncmp(line, "rrb", 4))
		ft_ch_reverse(b);
	else if (!ft_strncmp(line, "rrr", 4))
	{
		ft_ch_reverse(a);
		ft_ch_reverse(b);
	}
	else if (!ft_strncmp(line, "ra", 3))
		ft_ch_rotate(a);
	else if (!ft_strncmp(line, "rb", 3))
		ft_ch_rotate(b);
	else if (!ft_strncmp(line, "rr", 3))
	{
		ft_ch_rotate(a);
		ft_ch_rotate(b);
	}
	else
		ft_ch_error(a, b, 2);
}

void			ft_ch_apply_op(t_lstc *a, t_lstc *b, char *line)
{
	if (!ft_strncmp(line, "s", 1))
		ft_ch_apply_swap(a, b, line);
	else if (!ft_strncmp(line, "r", 1))
		ft_ch_apply_rot_rev(a, b, line);
	else if (!ft_strncmp(line, "pa", 3))
		ft_ch_push(b, a);
	else if (!ft_strncmp(line, "pb", 3))
		ft_ch_push(a, b);
	else
		ft_ch_error(a, b, 2);
}
