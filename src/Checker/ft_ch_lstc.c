/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_lstc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:03:52 by jechoque          #+#    #+#             */
/*   Updated: 2017/12/21 14:54:00 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void			ft_ch_del_lstc(t_lstc *todel_a, t_lstc *todel_b)
{
	t_lstc		*del;
	t_lstc		*cur;

	cur = todel_a->next;
	while (cur != todel_a && (del = cur))
	{
		cur = cur->next;
		free(del);
	}
	free(todel_a);
	todel_a = NULL;
	cur = todel_b->next;
	while (cur != todel_b && (del = cur))
	{
		cur = cur->next;
		free(del);
	}
	free(todel_b);
	todel_b = NULL;
}

t_lstc			*ft_ch_init_lstc(void)
{
	t_lstc		*root;

	if (!(root = malloc(sizeof(t_lstc))))
		return (NULL);
	root->nbr = 0;
	root->next = root;
	root->prev = root;
	return (root);
}

void			ft_ch_putlstc(t_lstc *a, t_lstc *b)
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
