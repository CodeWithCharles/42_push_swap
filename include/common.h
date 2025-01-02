/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:26:58 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 17:33:43 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

// Operations define

# define OP_NOP	0x0
# define OP_SA	0x1
# define OP_SB	0x2
# define OP_SS	0x3
# define OP_PA	0x4
# define OP_PB	0x5
# define OP_RA	0x6
# define OP_RB	0x7
# define OP_RR	0x8
# define OP_RRA	0x9
# define OP_RRB	0xA
# define OP_RRR	0xB

// Structures

typedef struct s_ps_context
{
	t_list	*a;
	t_list	*b;
	int		*values;
	size_t	count;
}	t_ps_context;

// Types

typedef void	(*t_operator)(t_ps_context *);

// Functions prototypes

// Swap

void			sa(
					t_ps_context	*context
					);

void			sb(
					t_ps_context	*context
					);

void			ss(
					t_ps_context	*context
					);

// Push

void			pa(
					t_ps_context	*context
					);

void			pb(
					t_ps_context	*context
					);

// Rotate

void			ra(
					t_ps_context	*context
					);

void			rb(
					t_ps_context	*context
					);

void			rr(
					t_ps_context	*context
					);

// Reverse rotate

void			rra(
					t_ps_context	*context
					);

void			rrb(
					t_ps_context	*context
					);

void			rrr(
					t_ps_context	*context
					);

// Utils

t_ps_context	*initialize_context(
					const char	**values
					);

void			cleanup_context(
					t_ps_context	**context_ptr
					);

#endif
