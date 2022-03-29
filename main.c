#include "path.h"

int main(void)
{
	t_tab	tab;
	
	ft_initialize_tab(&tab);
	ft_resolve(&tab);
	ft_free(tab.tab);
	return (0);
}