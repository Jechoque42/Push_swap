/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:14:01 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/17 01:59:00 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_lcmd
{
	char			*cmd;
	struct s_lcmd	*next;
}					t_lcmd;

typedef struct		s_lstc
{
	int				*srt;
	int				nbr;
	t_lcmd			*cmds;
	int				max;
	int				min;
	int				rra;
	int				ra;
	int				rrb;
	int				rb;
	int				rnk;
	struct s_lstc	*next;
	struct s_lstc	*prev;
}					t_lstc;

void				ft_ps_swap(t_lstc *toswap);
void				ft_ps_rotate(t_lstc *torot);
void				ft_ps_reverse(t_lstc *torev);
void				ft_ps_push(t_lstc *push, t_lstc *to);

int					ft_ps_check(t_lstc *tocheck, int mod);
int					ft_ps_addcmd(t_lcmd **cmds, t_lstc *a, t_lstc *b,
					char *new_cmd);
void				ft_ps_putcmds(t_lcmd *a);
void				ft_ps_putlstc(t_lstc *a, t_lstc *b);
void				ft_ps_del_cmds(t_lcmd **todel);
void				ft_ps_del_lstc(t_lstc *todel);
void				ft_ps_error(t_lstc *a, t_lstc *b, int mod);
t_lstc				*ft_ps_init_lstc(void);
int					ft_ps_gen_a(t_lstc *a, t_lstc *b, int ac, char **av);
void				ft_ps_algo(t_lstc *a, t_lstc *b);
void				ft_ps_littlesort(t_lstc *a, t_lstc *b);
void				ft_ps_sort(t_lstc *a, t_lstc *b);

#endif
