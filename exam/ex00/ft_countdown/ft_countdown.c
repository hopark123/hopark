/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:26:44 by hopark            #+#    #+#             */
/*   Updated: 2020/07/23 16:40:07 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

	int main()
	{
	char c;

	c = '9';
	while ( c >= '0')
	{
		write(1, &c, 1);
		c--;
	}
	write(1, "\n", 1);
	}
