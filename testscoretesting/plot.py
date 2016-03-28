import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab
import math

fname = "scores.txt"

scores = [int(line.rstrip('\n')) for line in open(fname)]

print(scores)

plt.hist(scores)
plt.title("Histogram Midsem Marks of OS")
plt.xlabel("Marks")
plt.ylabel("Frequency")

plt.show()