/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:08:16 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 17:32:18 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

// Static prototypes

static void	_push(
				t_list	**dst_list,
				t_list	**src_list
				);

// Function implementations

void	pa(
	t_ps_context	*context
)
{
	_push(&context->a, &context->b);
}

void	pb(
	t_ps_context	*context
)
{
	_push(&context->b, &context->a);
}

// Static implementation

static void	_push(
	t_list	**dst_list,
	t_list	**src_list
)
{
	t_list	*tmp;

	if (*src_list == NULL)
		return ;
	tmp = *src_list;
	*src_list = (*src_list)->next;
	tmp->next = *dst_list;
	*dst_list = tmp;
}
