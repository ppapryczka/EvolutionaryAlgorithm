import pandas as pd
import numpy as np
import matplotlib.pylab as plt


def read_data(file_name):
    """
    It reads data using pandas library.

    Args:
        :arg1 name of csv file

    Returns:
        DataFrame which contains read data.
    """

    data = pd.read_csv(file_name, delimiter=",", header = None)
    return data




def make_charts(file_name, limits):
    """
    It makes following charts:
        - min value
        - median
        - average
        - standard deviation

    Args:
        :arg1 name of csv file
        :arg2 limits for axis, it can be None

    Returns:
        DataFrame which contains read data.
    """


    data = read_data(file_name)
    x_axis = range(0, data[0].size)


    # min value
    plt.xlabel("Iteracja")
    plt.ylabel("Wartość")

    plt.plot(x_axis, data[0])
    plt.title('Wartość minimalna')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()

    if limits is not None:
        axes = plt.gca()
        axes.set_ylim(limits[0], limits[1])

    fig.savefig(file_name.split(".csv")[0]+"MinValue.png", dpi=300)
    plt.close(fig)


    # median
    plt.xlabel("Iteracja")
    plt.ylabel("Wartość")

    plt.plot(x_axis, data[1])
    plt.title('Mediana')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()

    if limits is not None:
        axes = plt.gca()
        axes.set_ylim(limits[2], limits[3])

    fig.savefig(file_name.split(".csv")[0] + "Median.png", dpi=300)
    plt.close(fig)


    # average
    plt.xlabel("Iteracja")
    plt.ylabel("Wartość")

    plt.plot(x_axis, data[2])
    plt.title('Średnia')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()

    if limits is not None:
        axes = plt.gca()
        axes.set_ylim(limits[4], limits[5])

    fig.savefig(file_name.split(".csv")[0] + "Average.png", dpi=300)
    plt.close(fig)


    # standard deviation
    plt.xlabel("Iteracja")
    plt.ylabel("Wartość")

    plt.plot(x_axis, data[3])
    plt.title('Odchylenie standardowe')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()

    if limits is not None:
        axes = plt.gca()
        axes.set_ylim(limits[6], limits[7])

    fig.savefig(file_name.split(".csv")[0] + "StandardDeviation.png", dpi=300)
    plt.close(fig)