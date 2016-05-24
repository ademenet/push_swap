#include <stdio.h>
#include "unit_test.h"
#include "../include/push_swap.h"

void		print_la(t_list *l)
{
	t_node	*tmp;

	tmp = l->head;
	fprintf(stdout, "la |");
	while (tmp)
	{
		fprintf(stdout, "%5d", tmp->v);
		tmp = tmp->next;
	}
	fprintf(stdout, "|\n");
}

void		print_lb(t_list *l)
{
	t_node	*tmp;

	tmp = l->head;
	fprintf(stdout, "lb |");
	while (tmp)
	{
		fprintf(stdout, "%5d", tmp->v);
		tmp = tmp->next;
	}
	fprintf(stdout, "|\n");
}


// void		test_fpf_parsing(void)
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
// 	ret = fpf_parsing(ac, av);
// 	print_la(ret);
//
// 	printf("\nTest int max:\t");
// 	av[0] = "a.out";
// 	av[1] =	"2147483647";
// 	av[2] = "1";
// 	av[3] = "2";
// 	ret = fpf_parsing(ac, av);
// 	print_la(ret);
//
// 	printf("\nTest int min:\t");
// 	av[0] = "a.out";
// 	av[1] =	"-2147483648";
// 	av[2] = "1";
// 	av[3] = "2";
// 	ret = fpf_parsing(ac, av);
// 	print_la(ret);

// The following tests should return "Error" and exit program

	// printf("\nTest int max plus:\t");
	// av[0] = "a.out";
	// av[1] =	"2147483789";
	// av[2] = "1";
	// av[3] = "2";
	// ret = fpf_parsing(ac, av);
	// print_la(ret);
	//
	// printf("\nTest int min less:\t");
	// av[0] = "a.out";
	// av[1] =	"-2147483893";
	// av[2] = "1";
	// av[3] = "2";
	// ret = fpf_parsing(ac, av);
	// print_la(ret);
	//
	// printf("\nTest double:\t");
	// av[0] = "a.out";
	// av[1] =	"2";
	// av[2] = "1";
	// av[3] = "2";
	// ret = fpf_parsing(ac, av);
	// print_la(ret);
	//
	// printf("\nNot digit:\t");
	// av[0] = "a.out";
	// av[1] =	"56";
	// av[2] = "87";
	// av[3] = "pow";
	// ret = fpf_parsing(ac, av);
	// print_la(ret);
// }

// void		test_fpf_operations(void)
// {
// 	setbuf(stdout, NULL);
// 	t_list	*la = NULL;
// 	t_list	*lb;
// 	char	*av[6];
// 	int		ac = 6;
//
// 	av[0] = "a.out";
// 	av[1] = "1";
// 	av[2] = "2";
// 	av[3] = "3";
// 	av[4] = "6";
// 	av[5] = "5";
// // Initializing lists
// 	la = fpf_parsing(ac, av);
// 	lb = fpf_lstnew();
//
// 	printf("%-30s\n", "Liste initiale:");
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Test apres swap a:");
// 	fpf_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
//
// 	printf("%-30s\n", "Push b:");
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Push b:");
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "3*push b:");
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "2*push a:");
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap a:");
// 	fpf_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "3*push b:");
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Push b:");
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap a:");
// 	fpf_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Push a:");
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap a:");
// 	fpf_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap b:");
// 	fpf_swap(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "Swap b:");
// 	fpf_swap(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "3*push a:");
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate a:");
// 	fpf_rotate(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate a:");
// 	fpf_rotate(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate b:");
// 	fpf_rotate(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s\n", "3*push b:");
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate b:");
// 	fpf_rotate(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "RevRotate a:");
// 	fpf_revrotate(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "6*Push b:");
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "RevRotate b:");
// 	fpf_revrotate(lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Rotate b:");
// 	fpf_rotate(lb);
// 	print_la(la);
// 	print_lb(lb);
// }

// void		test_fpf_list_len(void)
// {
// 	setbuf(stdout, NULL);
// 	t_list	*la = NULL;
// 	t_list	lb;
// 	char	*av[6];
// 	int		ac = 6;
//
// 	av[0] = "a.out";
// 	av[1] = "56";
// 	av[2] = "15";
// 	av[3] = "78";
// 	av[4] = "-56";
// 	av[5] = "4";
// // Initializing my first list
// 	la = fpf_parsing(ac, av);
// // Initializing my second list
// 	lb.head = NULL;
// 	lb.tail = NULL;
// 	lb.len = 0;
//
// 	printf("%-30s", "Liste initiale:");
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
//
// 	printf("%-30s", "Apres deux push b");
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
//
// 	printf("%-30s", "Apres un push a");
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
//
// 	printf("%-30s", "Apres un push a");
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
//
// 	printf("%-30s", "Apres un push a inutile");
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	printf("la->len == %d\n", la->len);
// 	print_lb(lb);
// 	printf("lb->len == %d\n", lb.len);
// }

// void		test_fpf_example(void)
// {
// 	setbuf(stdout, NULL);
// 	t_list	*la = NULL;
// 	t_list	lb;
// 	char	*av[7];
// 	int		ac = 7;
//
// 	av[0] = "a.out";
// 	av[1] = "2";
// 	av[2] = "1";
// 	av[3] = "3";
// 	av[4] = "6";
// 	av[5] = "5";
// 	av[6] = "8";
// // Initializing my first list
// 	la = fpf_parsing(ac, av);
// // Initializing my second list
// 	lb.head = NULL;
// 	lb.tail = NULL;
// 	lb.len = 0;
//
// 	printf("%-30s", "Liste initiale:");
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Swap a:");
// 	fpf_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "3*push b:");
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	fpf_push_b(la, lb);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "Swap a:");
// 	fpf_swap(la);
// 	print_la(la);
// 	print_lb(lb);
//
// 	printf("%-30s", "3*push a:");
// 	fpf_push_a(la, lb);
// 	fpf_push_a(la, lb);
// 	fpf_push_a(la, lb);
// 	print_la(la);
// 	print_lb(lb);
// }

// void		test_fpf_sorts()
// {
// 	setbuf(stdout, NULL);
// 	t_list	*la = NULL;
// 	t_list	lb;
// 	char	*av[7];
// 	int		ac = 7;
//
// 	av[0] = "a.out";
// 	av[1] = "1";
// 	av[2] = "2";
// 	av[3] = "3";
// 	av[4] = "4";
// 	av[5] = "5";
// 	av[6] = "8";
// // Initializing my first list
// 	la = fpf_parsing(ac, av);
// // Initializing my second list
// 	lb.head = NULL;
// 	lb.tail = NULL;
// 	lb.len = 0;
//
// 	printf("Liste est-elle trie ascending/croissant ? (renvoie 0 si oui et 1 sinon) [%d]\n", fpf_issortasc(la));
//
// 	av[0] = "a.out";
// 	av[1] = "1";
// 	av[2] = "3";
// 	av[3] = "2";
// 	av[4] = "4";
// 	av[5] = "5";
// 	av[6] = "8";
// // Initializing my first list
// 	la = fpf_parsing(ac, av);
// // Initializing my second list
// 	lb.head = NULL;
// 	lb.tail = NULL;
// 	lb.len = 0;
//
// 	printf("Liste est-elle trie ascending/croissant ? (renvoie 0 si oui et 1 sinon) [%d]\n", fpf_issortasc(la));
//
//
// 	av[0] = "a.out";
// 	av[1] = "1";
// 	av[2] = "2";
// 	av[3] = "3";
// 	av[4] = "4";
// 	av[5] = "5";
// 	av[6] = "6";
// // Initializing my first list
// 	la = fpf_parsing(ac, av);
// 	t_node *tmp = la->head;
// 	la->head = la->tail;
// 	la->tail = tmp;
//
// 	printf("Liste est-elle trie descending/decroissant ? (renvoie 0 si oui et 1 sinon) [%d]\n", fpf_issortdes(la));
//
// 	ac = 2;
// 	av[0] = "a.out";
// 	av[1] = "0";
// // Initializing my first list
// 	la = fpf_parsing(ac, av);
// 	tmp = la->head;
// 	la->head = la->tail;
// 	la->tail = tmp;
//
// 	printf("Liste est-elle trie descending/decroissant ? (renvoie 0 si oui et 1 sinon) [%d]\n", fpf_issortdes(la));
//
// }

void		test_fpf_sortmin(void)
{
	setbuf(stdout, NULL);
	t_list	*la = NULL;
	t_list	*lb;
	char	*av[7];
	int		ac = 7;
	int		min;

	av[0] = "a.out";
	av[1] = "9";
	av[2] = "2";
	av[3] = "53";
	av[4] = "49";
	av[5] = "22";
	av[6] = "7";
// Initializing my first list
	la = fpf_parsing(ac, av);
	lb = fpf_lstnew();

	fpf_sortmin(la, lb);
	print_la(la);
	print_lb(lb);
}

int			main()
{
	// test_fpf_parsing();
	// test_fpf_operations();
	// test_fpf_list_len();
	// test_fpf_example();
	// test_fpf_sorts();
	test_fpf_sortmin();
	return (0);
}
