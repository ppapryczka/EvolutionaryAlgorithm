from make_charts import *
import subprocess
import numpy
import sys

def get_program_arguments(executable_path):
    """
    It create list of program to be execute.

    Args:
        :arg1 path to executable

    Returns:
        List which elements holds executable path and args

    """
    executable_path_with_args_list = []

    for x in range(50):
        executable_path_with_args_list.append(executable_path + " -1 90 -2 0 -t 10 -m 0.05 -v 2 -u -c 10 -s " + str(x) + " -a 5 -b 0.4 -i 100 -f test" + str(x))

    return executable_path_with_args_list



def run(executable_path_with_args_list):
    """
    Run all programs from list.

    Args:
        :arg1 list which elements holds executable path and args

    Returns:
        List of output csv files.
    """

    output_csv_file_names = []

    for x in executable_path_with_args_list:
        args = x.split()
        popen = subprocess.Popen(args, stdout=subprocess.PIPE)
        popen.wait()
        output = popen.stdout.read().decode('utf-8')
        file_name = output.split('\n')
        print(file_name[1])
        output_csv_file_names.append(file_name[1])

    return output_csv_file_names



def count_limits(output_csv_file_names):
    """
    It counts the min and max limit for y axis for each of charts, which are:
        - median chart
        - average chart
        - standard deviation chart
        - min value chart

    Args:
        :arg1 list of csv output files names

    Returns:
        List of each of chart. List contain fallowing elements:
            - min value
            - max value
            - min median
            - max median
            - min average
            - max average
            - min deviation
            - max deviation
    """

    limits = []

    min_median = None
    max_median = None
    min_average = None
    max_average = None
    min_deviation = None
    max_deviation = None
    min_value = None
    max_value = None

    for x in output_csv_file_names:
        data = read_data(x)

        if min_median is None:
            min_value = min(data[0])
            max_value = max(data[0])
            min_median = min(data[1])
            max_median = max(data[1])
            min_average = min(data[2])
            max_average = max(data[2])
            min_deviation = min(data[3])
            max_deviation = max(data[3])
        else:
            min_value = min(min_value, min(data[0]))
            max_value = max(max_value, max(data[0]))
            min_median = min(min_median, min(data[1]))
            max_median = max(max_median, max(data[1]))
            min_average = min(min_average, min(data[2]))
            max_average = max(max_average, max(data[2]))
            min_deviation = min(min_deviation, min(data[3]))
            max_deviation = max(max_deviation, max(data[3]))

    limits.append(0.8*min_value)
    limits.append(1.2*max_value)
    limits.append(0.8*min_median)
    limits.append(1.2*max_median)
    limits.append(0.8*min_average)
    limits.append(1.2*max_average)
    limits.append(0.8*min_deviation)
    limits.append(1.2*max_deviation)
    return limits


def make_all_charts(output_csv_file_names, limits=None):
    """
    It makes charts from given csv.
    Limits are the max and min value from each csv file
        - it can be None, then matplotlib make charts without that information.
    I create:
        -min value chart
        -median chart
        -average chart
        -standard deviation chart

    Args:
        :arg1 list of output csv files.
        :arg2 limits for charts

    Returns:
        None
    """
    for name in output_csv_file_names:
        make_charts(name, limits)


if __name__ == "__main__":

    # specified executable path
    executable_path = "cmake-build-debug/EvolutionaryAlgorithm"

    # get program args
    executable_path_with_args_list = get_program_arguments(executable_path)

    # run programs
    output_file_names = run(executable_path_with_args_list)

    # count limits
    limits = count_limits(output_file_names)

    # make charts
    make_all_charts(output_file_names)
