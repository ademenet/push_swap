import random

my_list = list(range(1, 1000))
random.shuffle(my_list)
print ' '.join(map(str, my_list))