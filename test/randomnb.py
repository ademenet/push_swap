import random

my_list = list(range(0, 1999))
random.shuffle(my_list)
print ' '.join(map(str, my_list))
