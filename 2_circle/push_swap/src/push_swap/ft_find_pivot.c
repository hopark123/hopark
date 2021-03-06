/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:53:56 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 20:36:17 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pivot	ft_find_pivot(t_list *list)
{
	int				i;
	int				cnt_chunk;
	int				*arr;
	t_pivot			res;

	res.first = 0;
	i = 0;
	if (!list)
		return (res);
	cnt_chunk = ft_cnt_chunk(list);
	if (!ft_malloc(&arr, sizeof(int) * cnt_chunk))
		return (res);
	while (i < cnt_chunk)
	{
		arr[i] = ft_n_next_list(list, i)->num;
		i++;
	}
	ft_bubblesort(arr, cnt_chunk);
	i = (int)(cnt_chunk / 3);
	res.first = arr[cnt_chunk / 3];
	i = (int)(cnt_chunk / 3 * 2);
	res.second = arr[cnt_chunk / 3 * 2];
	ft_free(arr);
	return (res);
}
