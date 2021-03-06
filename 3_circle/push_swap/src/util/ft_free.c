/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:22:29 by hopark            #+#    #+#             */
/*   Updated: 2021/05/13 13:58:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free(void *memory)
{
	if (memory)
		free(memory);
	memory = 0;
}

void	ft_free2(char **s, int i)
{
	while (i--)
	{
		if (s[i])
			ft_free(s[i]);
	}
	ft_free(s);
}
