#include <stdio.h>
#include "unit_test.h"
#include "../include/push_swap.h"

void		test_ft_parsing(void)
{
	setbuf(stdout, NULL); // disable buffering on STDOUT

	t_list	*ret = NULL;
	t_node	*tmp = NULL;
	char	*av[4];
	int		ac = 4;
	av[0] = "a.out";
	av[1] =	"56";
	av[2] = "-89";
	av[3] = "2";

	printf("Test normal:\t");
	ret = ft_parsing(ac, av);
	tmp = ret->head;
	while (tmp)
	{
		printf("%d|", tmp->v);
		tmp = tmp->next;
	}
	printf("ret->len == %d\n", ret->len);

	printf("Test int max:\t");
	av[0] = "a.out";
	av[1] =	"2147483647";
	av[2] = "1";
	av[3] = "2";
	ret = ft_parsing(ac, av);
	tmp = ret->head;
	while (tmp)
	{
		printf("%d|", tmp->v);
		tmp = tmp->next;
	}
	printf("ret->len == %d\n", ret->len);

	printf("Test int min:\t");
	av[0] = "a.out";
	av[1] =	"-2147483648";
	av[2] = "1";
	av[3] = "2";
	ret = ft_parsing(ac, av);
	tmp = ret->head;
	while (tmp)
	{
		printf("%d|", tmp->v);
		tmp = tmp->next;
	}
	printf("ret->len == %d\n", ret->len);

	// printf("Test int max plus:\t");
	// av[0] = "a.out";
	// av[1] =	"2147483789";
	// av[2] = "1";
	// av[3] = "2";
	// ret = ft_parsing(ac, av);
	// tmp = ret->head;
	// while (tmp)
	// {
	// 	printf("%d|", tmp->v);
	// 	tmp = tmp->next;
	// }
	// printf("ret->len == %d\n", ret->len);

	// printf("Test int min less:\t");
	// av[0] = "a.out";
	// av[1] =	"-2147483893";
	// av[2] = "1";
	// av[3] = "2";
	// ret = ft_parsing(ac, av);
	// tmp = ret->head;
	// while (tmp)
	// {
	// 	printf("%d|", tmp->v);
	// 	tmp = tmp->next;
	// }
	// printf("ret->len == %d\n", ret->len);

	// printf("Test double:\t");
	// av[0] = "a.out";
	// av[1] =	"2";
	// av[2] = "1";
	// av[3] = "2";
	// ret = ft_parsing(ac, av);
	// tmp = ret->head;
	// while (tmp)
	// {
	// 	printf("%d|", tmp->v);
	// 	tmp = tmp->next;
	// }
	// printf("ret->len == %d\n", ret->len);

	// printf("Not digit:\t");
	// av[0] = "a.out";
	// av[1] =	"56";
	// av[2] = "87";
	// av[3] = "pow";
	// ret = ft_parsing(ac, av);
	// tmp = ret->head;
	// while (tmp)
	// {
	// 	printf("%d|", tmp->v);
	// 	tmp = tmp->next;
	// }
	// printf("ret->len == %d\n", ret->len);
}

int			main()
{
	test_ft_parsing();
	return (0);
}
