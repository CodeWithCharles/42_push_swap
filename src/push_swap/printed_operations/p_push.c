/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:48:28 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 13:52:23 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function implementations

void	p_pa(
	t_ps_context *context
)
{
	ft_putstr_fd("pa\n", 1);
	pa(context);
}

void	p_pb(
	t_ps_context *context
)
{
	ft_putstr_fd("pb\n", 1);
	pb(context);
}
