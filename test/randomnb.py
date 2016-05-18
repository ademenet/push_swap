from random import randint

print(' '.join([str(i) for i in sorted([random.sample(xrange(1, 5000), 2000) for _ in range(5000)])]))
