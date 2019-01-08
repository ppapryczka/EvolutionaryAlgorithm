from make_charts import make_charts
import subprocess

def run_and_make_charts(list_name):
    for x in list_name:
        args = x.split()
        popen = subprocess.Popen(args, stdout=subprocess.PIPE)
        popen.wait()
        output = popen.stdout.read().decode('utf-8')
        file_name = output.split('\n')
        make_charts(file_name[1])





if __name__ == "__main__":
    executable_name = "cmake-build-debug/EvolutionaryAlgorithm"
    list_name = [
        executable_name + " -1 100 -2 100 -r 1 -m 0.09 -v 2 -u -c 10 -a 30 -b 0.10 -i 200 -f nowy"
    ]


    run_and_make_charts(list_name)