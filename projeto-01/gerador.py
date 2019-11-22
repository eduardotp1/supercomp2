import numpy as np
import math
import random



if __name__ == "__main__":
    print("100000 100000 0.1\n")

    N=int(input())
    print(N)

    for i in range(N):
        m = str(np.random.randint(1, 50))
        wr = str(np.random.randint(1, 50))
        hr = str(np.random.randint(1, 50))
        x = str(np.random.randint(0, 100000-50))
        y = str(np.random.randint(0, 100000-50))
        vx = str(np.random.randint(1, 50))
        vy = str(np.random.randint(1, 50))
        print(m + ' ' + wr + ' ' + hr + ' ' + x + ' ' + y + ' ' + vx + ' ' + vy + '\n')


    print("0.01 10000 10000")