from make_charts import make_charts, make_ECDF, read_data
import subprocess
import numpy
import sys

def run_and_make_charts(list_name):
    output_file_names = []
    for x in list_name:
        args = x.split()
        popen = subprocess.Popen(args, stdout=subprocess.PIPE)
        popen.wait()
        output = popen.stdout.read().decode('utf-8')
        file_name = output.split('\n')
        make_charts(file_name[1])
        output_file_names.append(file_name[1])
    return output_file_names

def run(list_name):
    output_file_names = []
    for x in list_name:
        args = x.split()
        popen = subprocess.Popen(args, stdout=subprocess.PIPE)
        popen.wait()
        output = popen.stdout.read().decode('utf-8')
        file_name = output.split('\n')
        print(file_name[1])
        output_file_names.append(file_name[1])
    return output_file_names

def make_all_charts(list_name, list):
    for x in list_name:
        make_charts(x, list)

def count_Y_min_max(file_names):
    aaa = []

    min_median = 10000000000000000
    max_median = -10000000000000000

    min_average = 10000000000000000
    max_average = -10000000000000000

    min_deviation = 10000000000000000
    max_deviation = -10000000000000000

    min_value = 10000000000000000
    max_value = -10000000000000000

    for x in file_names:
        data = read_data(x)
        min_value = min(min_value, min(data[0]))
        max_value = max(max_value, max(data[0]))

        min_median = min(min_median,min(data[1]))
        max_median = max(max_median, max(data[1]))

        min_average = min(min_average,min(data[2]))
        max_average = max(max_average, max(data[2]))

        min_deviation = min(min_deviation, min(data[3]))
        max_deviation = max(max_deviation, max(data[3]))

    aaa.append(min_value)
    aaa.append(max_value)
    aaa.append(min_median)
    aaa.append(max_median)
    aaa.append(min_average)
    aaa.append(max_average)
    aaa.append(min_deviation)
    aaa.append(max_deviation)

    return aaa


if __name__ == "__main__":
    executable_name = "cmake-build-debug/EvolutionaryAlgorithm"

    list_name = []

    for x in range(500):
        list_name.append(executable_name + " -1 220 -2 220 -t 10 -m 0.05 -v 2 -u -c 80 -s " + str(x) + " -a 100 -b 0.4 -i 100 -f test" + str(x))
        #list_name.append(executable_name + " -1 2 -2 3 -r 1  -m 0.05 -v 2 -u -c 100 -s" + str(x) + " -a 10 -b 0.3 -i 100 -f test" + str(x))
        #list_name.append(executable_name + " -1 2 -2 3 -h 20  -m 0.05 -v 2 -u -c 100 -s" + str(x) + " -a 10 -b 0.3 -i 100 -f test" + str(x))

        #list_name.append(executable_name + " -1 5 -2 10 -r 1 -m 0.02 -v 2 -u -c 5 -s"+ str(x) + " -a 10 -b 0.05 -i 20 -f test"+ str(x))
        #list_name.append(executable_name + " -1 5 -2 10 -r 1 -m 0.05 -v 2 -u -c 5 -s" + str(x) + " -a 10 -b 0.2 -i 20 -f test" + str(x))


    #list_name = [
    #    executable_name + " -1 275 -2 275 -r 0.5 -m 0.05 -v 2 -u -c 100 -a 100 -b 0.5 -s 2 -i 100 -f test1",
    #    executable_name + " -1 275 -2 275 -r 0.5 -m 0.05 -v 2 -u -c 100 -a 10000 -b 0.5 -s 2 -i 100 -f test2"
    #]

    output_file_names = run(list_name)

    #list = count_Y_min_max(output_file_names)

    #make_all_charts(output_file_names, list)

    make_ECDF(output_file_names)
