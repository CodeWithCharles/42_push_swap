/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:55:32 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/03 13:56:52 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function implementations

void	p_sa(
	t_ps_context *context
)
{
	ft_putstr_fd("sa\n", 1);
	sa(context);
}

void	p_sb(
	t_ps_context *context
)
{
	ft_putstr_fd("sb\n", 1);
	sb(context);
}

void	p_ss(
	t_ps_context *context
)
{
	ft_putstr_fd("ss\n", 1);
	ss(context);
}
