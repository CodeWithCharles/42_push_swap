/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:03:16 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 15:45:13 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

// Function implementations

void	initialize_operations(
	t_ps_context *context
)
{
	context->operations[OP_NOP] = do_nothing;
	context->operations[OP_SA] = p_sa;
	context->operations[OP_SB] = p_sb;
	context->operations[OP_SS] = p_ss;
	context->operations[OP_PA] = p_pa;
	context->operations[OP_PB] = p_pb;
	context->operations[OP_RA] = p_ra;
	context->operations[OP_RB] = p_rb;
	context->operations[OP_RR] = p_rr;
	context->operations[OP_RRA] = p_rra;
	context->operations[OP_RRB] = p_rrb;
	context->operations[OP_RRR] = p_rrr;
}
