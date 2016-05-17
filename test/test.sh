#!/bin/sh

gcc test_main.c ../src/ft_parsing.c\
				../src/ft_error.c\
				../src/ft_operations.c\
				../lib/*.c
