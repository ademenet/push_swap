#include <stdio.h>
#include "unit_test.h"
#include "../include/push_swap.h"

void		print_la(t_list *l)
{
	t_node	*tmp;

	tmp = l->head;
	while (tmp)
	{
		fprintf(stdout, "%5d", tmp->v);
		tmp = tmp->next;
	}
}

void		print_lb(t_list *l)
{
	t_node	*tmp;

	tmp = l->head;
	while (tmp)
	{
		fprintf(stdout, "%5d", tmp->v);
		tmp = tmp->prev;
	}
}


// void		test_ft_parsing(void)
// {
// 	setbuf(stdout, NULL); // disable buffering on STDOUT
//
// 	t_list	*ret = NULL;
// 	char	*av[4];
// 	int		ac = 4;
// 	av[0] = "a.out";
// 	av[1] =	"56";
// 	av[2] = "-89";
// 	av[3] = "2";
//
// 	printf("Test normal:\t");
// 	ret = ft_parsing(ac, av);
// 	print_la(ret);
//
// 	printf("\nTest int max:\t");
// 	av[0] = "a.out";
// 	av[1] =	"2147483647";
// 	av[2] = "1";
// 	av[3] = "2";
// 	ret = ft_parsing(ac, av);
// 	print_la(ret);
//
// 	printf("\nTest int min:\t");
// 	av[0] = "a.out";
// 	av[1] =	"-2147483648";
// 	av[2] = "1";
// 	av[3] = "2";
// 	ret = ft_parsing(ac, av);
// 	print_la(ret);

// The following tests should return "Error" and exit program

	// printf("\nTest int max plus:\t");
	// av[0] = "a.out";
	// av[1] =	"2147483789";
	// av[2] = "1";
	// av[3] = "2";
	// ret = ft_parsing(ac, av);
	// print_la(ret);
	//
	// printf("\nTest int min less:\t");
	// av[0] = "a.out";
	// av[1] =	"-2147483893";
	// av[2] = "1";
	// av[3] = "2";
	// ret = ft_parsing(ac, av);
	// print_la(ret);
	//
	// printf("\nTest double:\t");
	// av[0] = "a.out";
	// av[1] =	"2";
	// av[2] = "1";
	// av[3] = "2";
	// ret = ft_parsing(ac, av);
	// print_la(ret);
	//
	// printf("\nNot digit:\t");
	// av[0] = "a.out";
	// av[1] =	"56";
	// av[2] = "87";
	// av[3] = "pow";
	// ret = ft_parsing(ac, av);
	// print_la(ret);
// }

void		test_ft_operations(void)
{
	t_list	*la = NULL;
	t_list	*lb = NULL;
	char	*av[6];
	int		ac = 6;

	av[0] = "a.out";
	av[1] = "56";
	av[2] = "15";
	av[3] = "78";
	av[4] = "-56";
	av[5] = "4";

	la = ft_parsing(ac, av);

	printf("Test avant swap:\t");
	print_la(la);

	printf("Test apres swap:\t");
	ret = ft_swap();
	print_la(la);
	print_lb(lb);
}

int			main()
{
	// test_ft_parsing();
	test_ft_operations();
	return (0);
}
