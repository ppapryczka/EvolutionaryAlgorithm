from make_charts import make_charts, make_ECDF
import subprocess

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


if __name__ == "__main__":
    executable_name = "cmake-build-debug/EvolutionaryAlgorithm"

    list_name = []

    for x in range(1000):
        list_name.append(executable_name + " -1 5 -2 10 -r 1 -m 0.02 -v 2 -u -c 10 -s" + str(x) + " -a 10 -b 0.05 -i 20 -f test" + str(x))

        #list_name.append(executable_name + " -1 5 -2 10 -r 1 -m 0.02 -v 2 -u -c 5 -s"+ str(x) + " -a 10 -b 0.05 -i 20 -f test"+ str(x))
        #list_name.append(executable_name + " -1 5 -2 10 -r 1 -m 0.05 -v 2 -u -c 5 -s" + str(x) + " -a 10 -b 0.2 -i 20 -f test" + str(x))

    #list_name = [
    #    executable_name + " -1 100 -2 100 -r 1 -m 0.01 -v 2 -u -c 10 -a 30 -b 0.05 -s 1000 -i 1000 -f test1",
    #    executable_name + " -1 100 -2 100 -r 1 -m 0.05 -v 2 -u -c 10 -a 30 -b 0.15 -s 1000 -i 1000 -f test2"
    #]
    #output_file_names = run_and_make_charts(list_name)

    output_file_names = run(list_name)

    make_ECDF(output_file_names)
