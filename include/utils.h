/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:03:15 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 17:05:30 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"
# include "libft.h"

# include <stdbool.h>

// Function prototypes

bool	is_string_integer(
			const char *str
			);

bool	is_sorted(
			t_list *list
			);

void	do_nothing(
			t_ps_context *context
			);

#endif
