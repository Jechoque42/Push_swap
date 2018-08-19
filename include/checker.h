/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:04:21 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/19 19:58:04 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# define WINDOWX 1200
# define WINDOWY 1000

typedef struct		s_lstc
{
	int				nbr;
	int				rnk;
	struct s_lstc	*next;
	struct s_lstc	*prev;
}
					t_lstc;
typedef struct		s_visu
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int		bpp;
	int		line;
	int		end;
	t_lstc		*a;
	t_lstc		*b;
	int		nbrline;
}				t_visu;

void				ft_ch_swap(t_lstc *toswap);
void				ft_ch_rotate(t_lstc *torot);
void				ft_ch_reverse(t_lstc *torev);
void				ft_ch_push(t_lstc *push, t_lstc *to);

void				ft_ch_error(t_lstc *a, t_lstc *b, int mod);

void				ft_ch_del_lstc(t_lstc *todel_a, t_lstc *todel_b);
t_lstc				*ft_ch_init_lstc(void);
void				ft_ch_putlstc(t_lstc *a, t_lstc *b);
int					ft_ch_gen_a(t_lstc *a, t_lstc *b, int ac, char **av);
void				ft_ch_apply_op(t_lstc *a, t_lstc *b, char *line);
void				ft_ch_init_visual(t_visu *data);
void				ft_ch_visual_plus(t_lstc *a, t_lstc *b, t_visu *data);

#endif
