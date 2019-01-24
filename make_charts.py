import pandas as pd
import numpy as np
import matplotlib.pylab as plt


def read_data(fileName):
    data = pd.read_csv(fileName, delimiter=",", header = None)
    return data


def make_value_graph(filename):
    data = read_data(filename)

    plt.xlabel("Wartość funkcji oceny")
    plt.ylabel("Ilość wystąpień")
    plt.plot(data[0], data[1], "ro")
    plt.title('Wartości')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()
    plt.show()
    axes = plt.gca()
    fig.savefig(filename.split(".csv")[0]+"Values.png", dpi=300)
    #plt.close(fig)



def make_ECDF(fileName_List):
    minValues = np.arange(len(fileName_List))

    for x in range(len(fileName_List)):
        data = read_data(fileName_List[x])
        minElement = data[0].min()
        minValues[x] = minElement

    x = np.sort(minValues)
    y = np.arange(1, len(minValues) + 1) / len(minValues)

 #   plt.plot(x, y, marker='.', linestyle='none')
    plt.plot(x, y, marker='.')
    plt.title('ECDF')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()
    fig.savefig("QualityECDF.png", dpi=300)
    plt.close(fig)

def make_charts(fileName, list):
    data = read_data(fileName)
    print(data[0])

    x_axis = range(0, data[0].size)

    plt.xlabel("Iteracja")
    plt.ylabel("Wartość")

    plt.plot(x_axis, data[0])
    plt.title('Wartość minimalna')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()

    axes = plt.gca()
    axes.set_ylim(list[0], list[1])

    fig.savefig(fileName.split(".csv")[0]+"MinValue.png", dpi=300)
    plt.close(fig)

    plt.xlabel("Iteracja")
    plt.ylabel("Wartość")

    plt.plot(x_axis, data[1])
    plt.title('Mediana')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()

    axes = plt.gca()
    axes.set_ylim(list[2], list[3])

    fig.savefig(fileName.split(".csv")[0] + "Median.png", dpi=300)
    plt.close(fig)

    plt.xlabel("Iteracja")
    plt.ylabel("Wartość")

    plt.plot(x_axis, data[2])
    plt.title('Średnia')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()

    axes = plt.gca()
    axes.set_ylim(list[4], list[5])

    fig.savefig(fileName.split(".csv")[0] + "Average.png", dpi=300)
    plt.close(fig)

    plt.xlabel("Iteracja")
    plt.ylabel("Wartość")

    plt.plot(x_axis, data[3])
    plt.title('Odchylenie standardowe')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()

    axes = plt.gca()
    axes.set_ylim(list[6], list[7])

    fig.savefig(fileName.split(".csv")[0] + "StandardDeviation.png", dpi=300)
    plt.close(fig)

    x = np.sort(data[0])
    y = np.arange(1, len(x) + 1) / len(x)

    plt.xlabel("Iteracja")
    plt.ylabel("Wartość")

    plt.plot(x, y, marker='.', linestyle='none')
    plt.title('Dystrybuanta empiryczna')
    plt.grid(True)
    fig = plt.gcf()
    plt.tight_layout()
    fig.savefig(fileName.split(".csv")[0] + "ECDF.png", dpi=300)
    plt.close(fig)

