#!/bin/sh

gcc test_main.c ../src/ft_parsing.c\
				../src/ft_error.c\
				../src/ft_operations.c\
				../src/ft_sortmin.c\
				../src/ft_optimization.c\
				../lib/*.c\
				../ft_printf/libftprintf.a
