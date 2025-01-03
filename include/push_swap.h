/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:33:46 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 15:26:52 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

# include <stdint.h>

// Function prototypes

void	p_sa(
			t_ps_context	*context
			);

void	p_sb(
			t_ps_context	*context
			);

void	p_ss(
			t_ps_context	*context
			);

void	p_pa(
			t_ps_context	*context
			);

void	p_pb(
			t_ps_context	*context
			);

void	p_ra(
			t_ps_context	*context
			);

void	p_rb(
			t_ps_context	*context
			);

void	p_rr(
			t_ps_context	*context
			);

void	p_rra(
			t_ps_context	*context
			);

void	p_rrb(
			t_ps_context	*context
			);

void	p_rrr(
			t_ps_context	*context
			);

void	initialize_operations(
			t_ps_context	*context
			);

void	process_code(
			uint64_t	code,
			t_ps_context	*context
			);

void	sort_for_2(
			t_ps_context	*context
			);

void	sort_for_3(
			t_ps_context	*context
			);

void	sort_for_4(
			t_ps_context	*context
			);

void	sort_for_5(
			t_ps_context	*context
			);

void	radix_sort(
			t_ps_context	*context
			);

#endif
