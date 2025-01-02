/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:27:57 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 17:29:40 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

// Function implementation

bool	is_string_integer(
	const char *str
)
{
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
		++str;
	if (!ft_isdigit(*str))
		return (false);
	++str;
	while (ft_isdigit(*str))
		++str;
	while (ft_isspace(*str))
		++str;
	return (*str == '\0');
}
