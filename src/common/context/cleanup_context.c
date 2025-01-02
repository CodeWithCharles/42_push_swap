/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_context.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:21:56 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 17:32:00 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

// Static prototypes

static void	_do_nothing(
				void *_
				);

// Function implementation

void	cleanup_context(
	t_ps_context **context_ptr
)
{
	if (*context_ptr == NULL)
		return ;
	ft_lstclear(&(*context_ptr)->a, _do_nothing);
	ft_lstclear(&(*context_ptr)->b, _do_nothing);
	free((*context_ptr)->values);
	free(*context_ptr);
	*context_ptr = NULL;
}

// Static implementation

static void	_do_nothing(
	void *_
)
{
	(void)_;
}
