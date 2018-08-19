/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:05:12 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/19 16:31:08 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"
#include <stdio.h>

static int		ft_ch_check(t_lstc *a, t_lstc *b)
{
	t_lstc	*check1;
	t_lstc	*check2;

	check1 = a->next;
	check2 = a->next->next;
	if (b->next == b && check1 != a)
	{
		while (check2 != a)
		{
			if (check1->nbr > check2->nbr)
				return (0);
			check1 = check1->next;
			check2 = check2->next;
		}
		return (1);
	}
	return (0);
}

static int		ft_ch_mode(char **argv, int *mode)
{
	if (!ft_strcmp(*argv, "-littlev") || !ft_strcmp(*argv, "-game")
	|| !ft_strcmp(*argv, "-visual++"))
	{
		if (!ft_strcmp(*argv, "-littlev"))
			*mode = 1;
		else if (!ft_strcmp(*argv, "-game"))
			*mode = 2;
		else if (!ft_strcmp(*argv, "-visual++"))
			*mode = 3;
		return (1);
	}
	return (0);
}

static void		ft_ch_display_mode(t_lstc *a, t_lstc *b, int mode)
{
	static int	call = 0;

	if (mode == 2 && call == 0)
		ft_putstr("===== START =====\n");
	if (mode && call)
	{
		mode == 2 ? ft_putstr("\n==== ROUND ") : ft_putstr("\n==== STEP ");
		ft_putnbr(call);
		ft_putstr(" ====\n");
	}
	ft_ch_putlstc(a, b);
	if (mode == 2 && !ft_ch_check(a, b))
		ft_putstr("\nENTER AN ORDER : ");
	else if (mode == 2)
	{
		ft_putstr("YOU WIN WITH : ");
		ft_putnbr(call);
		ft_putstr(" ORDER");
		call > 1 ? ft_putstr("S !\n") : ft_putstr(" !\n");
	}
	call++;
}

static void		ft_ch_loop(t_lstc *stack_a, t_lstc *stack_b, int mode)
{
	char	*line;

	line = NULL;
	if (ft_ch_check(stack_a, stack_b))
		ft_ch_error(stack_a, stack_b, 4);
	if (mode == 1 || mode == 2)
			ft_ch_display_mode(stack_a, stack_b, mode);
	while (get_next_line(0, &line) != 0)
	{
		if (line)
			ft_ch_apply_op(stack_a, stack_b, line);
		if (mode == 1 || mode == 2)
			ft_ch_display_mode(stack_a, stack_b, mode);
		ft_strdel(&line);
	}
}

int				ft_key_hook(int keycode, t_visu *data)
{
	char	*line;

	line = NULL;
	if (keycode == 36 && get_next_line(0, &line) != 0)
	{
		if (line)
			ft_ch_apply_op(data->a, data->b, line);
		ft_ch_visual_plus(data->a, data->b, data);
		mlx_string_put(data->mlx, data->win, 590, 700, 0x00FFFFFF, line);
		ft_strdel(&line);
	}
	else if (keycode == 36 && get_next_line(0, &line) == 0 &&
	ft_ch_check(data->a, data->b))
		mlx_string_put(data->mlx, data->win, 1000, 600, 0x00FFFFFF, "OK");
	else if (keycode == 36 && get_next_line(0, &line) == 0 &&
	!ft_ch_check(data->a, data->b))
		mlx_string_put(data->mlx, data->win, 1000, 600, 0x00FFFFFF, "KO");
	return (1);
}

int				main(int argc, char **argv)
{
	int		mode;
	char		*line;
	t_visu	*data;
	t_lstc	*stack_a;
	t_lstc	*stack_b;

	mode = 0;
	line = NULL;
	stack_a = ft_ch_init_lstc();
	stack_b = ft_ch_init_lstc();
	if (!stack_a || !stack_b)
		ft_ch_error(stack_a, stack_b, 4);
	if ((argc <= 1 || (ft_ch_mode(++argv, &mode) && argc <= 2)))
		ft_ch_error(stack_a, stack_b, 0);
	if (argc > 1 && ft_ch_gen_a(stack_a, stack_b, argc, argv))
	{
		if (stack_a->next == stack_a)
			ft_ch_error(stack_a, stack_b, 0);
		if (mode != 3)
			ft_ch_loop(stack_a, stack_b, mode);
		else
		{
			if (!(data = (t_visu *)malloc(sizeof(t_visu))))
				ft_ch_error(stack_a, stack_b, 4);
			ft_ch_init_visual(data);
			data->nbrline = WINDOWY / stack_a->nbr;
			data->a = stack_a;
			data->b = stack_b;
			mlx_hook(data->win, 2, (1l<<0),
			ft_key_hook, data);
			mlx_loop(data->mlx);
		}
	}
	else
		ft_ch_error(stack_a, stack_b, 1);
	ft_ch_check(stack_a, stack_b) ? ft_putstr("OK\n") : ft_putstr("KO\n");
	ft_ch_del_lstc(stack_a, stack_b);
	return (1);
}
