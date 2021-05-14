/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:45:48 by hopark            #+#    #+#             */
/*   Updated: 2021/05/13 20:37:55 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action(t_inf *inf, char *com)
{
	if (ft_strncmp(com, "sa", 2) || ft_strncmp(com, "ss", 2))
		ft_swap_tool(&(inf->a_h));
	if (ft_strncmp(com, "sb", 2) || ft_strncmp(com, "ss", 2))
		ft_swap_tool(&(inf->b_h));
	if (ft_strncmp(com, "pa", 2))
		ft_push_tool(&(inf->a_h), &(inf->b_h));
	if (ft_strncmp(com, "pb", 2))
		ft_push_tool(&(inf->b_h), &(inf->a_h));
	if (ft_strncmp(com, "rra", 3) || ft_strncmp(com, "rrr", 3))
		ft_revrotate_tool(&inf->a_h, &inf->a_t);
	if (ft_strncmp(com, "rrb", 3) || ft_strncmp(com, "rrr", 3))
		ft_revrotate_tool(&inf->b_h, &inf->b_t);
	if (ft_strncmp(com, "ra", 2) || ft_strncmp(com, "rr", 2))
		ft_rotate_tool(&inf->a_h, &inf->a_t);
	if (ft_strncmp(com, "rb", 2) || ft_strncmp(com, "rr", 2))
		ft_rotate_tool(&inf->b_h, &inf->b_t);
	ft_htsetting(inf);
	g_cnt++;
	//if (inf->bonus)
	//	ft_show(inf, com);
	//else
	//{
		write(1, com, ft_strlen(com));
		write(1, "\n", 1);
	//}
}

int	ft_swap_tool(t_list **type)
{
	int			temp;

	if (*type == 0 || (*type)->next == 0)
		return (SUCCESS);
	temp = (*type)->num;
	(*type)->num = (*type)->next->num;
	(*type)->next->num = temp;
	return (SUCCESS);
}

int	ft_push_tool(t_list **dest, t_list **src)
{
	t_list		*temp;

	if ((*src) == 0)
		return (SUCCESS);
	temp = *src;
	ft_listexcpet(src);
	if ((*src) == (*src)->next)
		(*src) = 0;
	else
		(*src) = (*src)->next;
	ft_listadd_front(dest, &temp);
	return (SUCCESS);
}

int	ft_rotate_tool(t_list **head, t_list **tail)
{
	if (!head || !tail)
		return (SUCCESS);
	(*head) = (*head)->next;
	(*tail) = (*tail)->next;
	return (SUCCESS);
}

int	ft_revrotate_tool(t_list **head, t_list **tail)
{
	if (!head || !tail)
		return (SUCCESS);
	(*head) = (*head)->prev;
	(*tail) = (*tail)->prev;
	return (SUCCESS);
}
