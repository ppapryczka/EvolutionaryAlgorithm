import pandas as pd
import numpy as np
import matplotlib as mpl
import pylab

def read_data(fileName):
    data = pd.read_csv(fileName, delimiter=",", header = None)
    print(data)
    return data


if __name__ == "__main__":
    data = read_data("nowy.csv")

    x = range(0, data[0].size)  # lista argumentów x

    pylab.plot(x, data[0])
    pylab.title('Min value')
    pylab.grid(True)
    pylab.show()

    pylab.plot(x, data[1])
    pylab.title('Median')
    pylab.grid(True)
    pylab.show()

    pylab.plot(x, data[2])
    pylab.title('Average')
    pylab.grid(True)
    pylab.show()

    pylab.plot(x, data[3])
    pylab.title('Standard deviation')
    pylab.grid(True)
    pylab.show()

    print(" make charts ")
