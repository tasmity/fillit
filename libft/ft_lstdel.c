/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:02:38 by orubin            #+#    #+#             */
/*   Updated: 2019/12/03 22:32:55 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	if (alst == NULL || !del)
		return ;
	while ((list = (*alst)->next))
	{
		ft_lstdelone(&*alst, del);
		free(*alst);
		*alst = list;
	}
	ft_lstdelone(&*alst, del);
	free(*alst);
	*alst = NULL;
}
