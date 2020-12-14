import os 
import numpy as np

"""
    File to facilitate the calculation of the average of the tests sequence
"""

files = os.listdir('.')
means = []

for file in files:
    if  '.out' in file:
        with open(file) as f:
            meanLine = f.readlines()[-1]
            init = meanLine.find("Mean time:")
            end = meanLine.find("seconds")
            mean = float(meanLine[init+11:end].strip())
            means.append(mean)

print(np.mean(means))