/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:48:31 by hopark            #+#    #+#             */
/*   Updated: 2020/11/23 14:49:12 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar_fd.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
