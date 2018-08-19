/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 22:01:30 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/19 20:09:24 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void		ft_ch_init_visual(t_visu *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOWX, WINDOWY, "PUSH-SWAP");
	data->img = mlx_new_image(data->mlx, WINDOWX, WINDOWY);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, &data->line, &data->end);
}

void		ft_ch_visual_plus(t_lstc *a, t_lstc *b, t_visu *data)
{
	int	y;
	int	x;
	int	color;
	t_lstc *tmp;
	t_lstc *tmp2;

	y = 0;
	tmp = a->next;
	tmp2 = b->next;
	while (tmp != a || tmp2 != b)
	{
		x = 0;
		while (x < WINDOWX)
		{
			if (tmp != a && x < tmp->rnk * (WINDOWX / 2) / a->nbr)
				color = tmp->rnk * 100000 + tmp->nbr;
			else if (tmp2 != b && x > WINDOWX - (tmp2->rnk * (WINDOWX / 2) / a->nbr))
				color = tmp2->rnk * 100000 + tmp2->nbr;
			else
				color = 0x000000;
			ft_memcpy(data->img_ptr + 4 * WINDOWX * y + x * 4, &color, (sizeof(int)));
			x++;
		}
		y++;
		if (y % data->nbrline == 0)
		{
			if (tmp != a)
				tmp = tmp->next;
			if (tmp2 != b)
				tmp2 = tmp2->next;
		}
	}
	color = 0x000000;
	while (y < WINDOWY)
	{
		x = 0;
		while (x < WINDOWX)
		{
			ft_memcpy(data->img_ptr + 4 * WINDOWX * y + x * 4, &color,
			(sizeof(int)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
