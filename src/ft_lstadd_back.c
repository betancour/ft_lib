#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if (!alst || !new)
		return;
	if (!*alst)
	{
		*alst = new;
		return;
	}
	last = ft_lstlast(*alst);
	if (last)
		last->next = new;
}
