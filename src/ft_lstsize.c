#include "libft.h"

int ft_lstsize(t_list *lst)
{

	t_list *tmp;
	int i;

	tmp = lst;
	i = 0;

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
