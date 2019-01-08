import pandas as pd
import numpy as np
import matplotlib.pylab as plt


def read_data(fileName):
    data = pd.read_csv(fileName, delimiter=",", header = None)
    print(data)
    return data


def make_charts(fileName):
    data = read_data(fileName)

    x_axis = range(0, data[0].size)

    plt.plot(x_axis, data[0])
    plt.title('Min value')
    plt.grid(True)
    plt.show()

    plt.plot(x_axis, data[1])
    plt.title('Median')
    plt.grid(True)
    plt.show()

    plt.plot(x_axis, data[2])
    plt.title('Average')
    plt.grid(True)
    plt.show()

    plt.plot(x_axis, data[3])
    plt.title('Standard deviation')
    plt.grid(True)
    plt.show()

    x = np.sort(data[0])

    y = np.arange(1, len(x) + 1) / len(x)

    plt.plot(x, y, marker='.', linestyle='none')

    plt.show()


