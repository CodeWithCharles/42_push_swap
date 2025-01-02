/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:26:05 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 17:27:45 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	is_sorted(
	t_list *list
)
{
	int	v;

	if (list == NULL)
		return (true);
	v = *(int *)list->content;
	list = list->next;
	while (list)
	{
		if (v > *(int *)list->content)
			return (false);
		v = *(int *)list->content;
		list = list->next;
	}
	return (true);
}
