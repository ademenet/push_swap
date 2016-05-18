#!/bin/sh

printf "Should return 0 (or nothing)\n"
./push_swap 4 5 12 25 89

printf "Should be done in 2 operations (okay for 3)\n"
./push_swap 3 2 1

printf "Should be done in only one swap\n"
./push_swap 2 1 3

printf "Should be done in less than 8 operations (5 is good)\n"
./push_swap 4 6 10 12 19 25 36 29

printf "Should be done between 5 and 20 operations\n"
./push_swap 100 1000 10 100000 10000

printf "Should be done between 5 and 20 operations too\n"
./push_swap 12 25 5 154 89

printf "Should return nothing (or empty line, it's okay)\n"
./push_swap

printf "Should return Error (non digit arguments)\n"
./push_swap 56 76 sig 67 62
./push_swap 56 76 sig 67 62
./push_swap sig 56 121 45 5
./push_swap s

printf "Should return Error (double)\n"
./push_swap 15 15
./push_swap 45 12 57 52 33 33
./push_swap 45 12 57 52 33 45

printf "Should return Error (bigger than integer)\n"
./push_swap 2147483648
./push_swap 29999999999
./push_swap -2147483649
./push_swap -29999999999

printf "Should return no operations\n"
./push_swap 2

printf "Check by yourself if the operations solve this : 5 6 2 9 1 3\n"
./push_swap 5 6 2 9 1 3

printf "Tests with negatives and positives\n"
./push_swap 2 -5 26 -7888 -998 564 12

printf "Tests with only negatives\n"
./push_swap -2 -5 -26 -7888 -998 -564 -12

printf "What happen's with a lot of parameters?\n"
./push_swap `ruby -e "puts (-1000..1000).to_a.shuffle.join(' ')"`

printf "What happen's with even more parameters?\n"
./push_swap `ruby -e "puts (-5000..5000).to_a.reverse.insert(rand(8000) + 1000, 10001).join(' ')"`
