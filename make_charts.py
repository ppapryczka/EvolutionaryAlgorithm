import pandas as pd
import numpy as np
import matplotlib.pylab as plt


def read_data(fileName):
    data = pd.read_csv(fileName, delimiter=",", header = None)
    return data


def make_ECDF(fileName_List):
    minValues = np.arange(len(fileName_List))

    for x in range(len(fileName_List)):
        data = read_data(fileName_List[x])
        minElement = data[0].min()
        minValues[x] = minElement

    x = np.sort(minValues)
    y = np.arange(1, len(minValues) + 1) / len(minValues)

    plt.plot(x, y, marker='.', linestyle='none')
    plt.title('ECDF')
    plt.grid(True)
    fig = plt.gcf()
    fig.savefig("QualityECDF.png")
    plt.close(fig)

def make_charts(fileName):
    data = read_data(fileName)

    x_axis = range(0, data[0].size)

    plt.plot(x_axis, data[0])
    plt.title('Min value')
    plt.grid(True)
    fig = plt.gcf()
    fig.savefig(fileName.split(".csv")[0]+"MinValue.png")
    plt.close(fig)

    plt.plot(x_axis, data[1])
    plt.title('Median')
    plt.grid(True)
    fig = plt.gcf()
    fig.savefig(fileName.split(".csv")[0] + "Median.png")
    plt.close(fig)

    plt.plot(x_axis, data[2])
    plt.title('Average')
    plt.grid(True)
    fig = plt.gcf()
    fig.savefig(fileName.split(".csv")[0] + "Average.png")
    plt.close(fig)

    plt.plot(x_axis, data[3])
    plt.title('Standard deviation')
    plt.grid(True)
    fig = plt.gcf()
    fig.savefig(fileName.split(".csv")[0] + "StandardDeviation.png")
    plt.close(fig)

    x = np.sort(data[0])
    y = np.arange(1, len(x) + 1) / len(x)

    plt.plot(x, y, marker='.', linestyle='none')
    plt.title('ECDF')
    plt.grid(True)
    fig = plt.gcf()
    fig.savefig(fileName.split(".csv")[0] + "ECDF.png")
    plt.close(fig)

