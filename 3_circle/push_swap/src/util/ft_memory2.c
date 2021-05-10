/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:20:34 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 20:52:45 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strlen2(char **s)
{
	int				i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
