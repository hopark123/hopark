/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:59:39 by hopark            #+#    #+#             */
/*   Updated: 2021/05/05 16:42:49 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			ft_two_a(t_inf *inf, float chunk)
{
	printf("two_a\n");

	if (inf->a_h->num > inf->a_h->next->num)
		ft_action(inf, "sa");
	inf->a_h->chunk = chunk;
	inf->a_h->next->chunk = chunk;

}
void			ft_two_b(t_inf *inf, float chunk)
{
	printf("two_b\n");
	if (inf->b_h->num < inf->b_h->next->num)
		ft_action(inf, "sb");
	ft_action(inf, "pa");
	ft_action(inf, "pa");
	inf->a_h->chunk = chunk;
	inf->a_h->next->chunk = chunk;
}