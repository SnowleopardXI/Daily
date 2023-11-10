import numpy as np
from math import *
import matplotlib.pyplot as plt
x = np.linspace(0.01, 0.99, 1000)
y = []

for p in x:
    y_1 = -1 * p * log(p, 2) - (1 - p) * log(1 - p, 2)
    y.append(y_1)

plt.plot(x, y, label='H(p)')
plt.legend()
plt.show()
