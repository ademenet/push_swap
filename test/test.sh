#!/bin/sh

gcc test_main.c ../src/fpf_parsing.c\
				../src/fpf_error.c\
				../src/fpf_operations.c\
				../src/fpf_sortmin.c\
				../src/fpf_optimization.c\
				../lib/*.c\
				../fpf_printf/libftprintf.a
