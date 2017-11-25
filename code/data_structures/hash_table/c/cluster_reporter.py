import fileinput
import statistics

cluster_list = []
operation_timing = []

for line in fileinput.input():

    if "Cluster allert" in line:
        cluster_list.append(int(float(line.split()[-1])))
    elif "Operation" in line:
        operation_timing.append(int(float(line.split()[-1])))
    else:
        print("Max cluster: {0:.2f}%, mean clustering ratio: {1:.2f}%, cluster count: {2}".format((max(cluster_list) / int(line.split()[-2]) * 100), (statistics.mean(cluster_list) / int(line.split()[-2]) * 100), len(cluster_list)-1))
        print("Timing - Best: {0}, avg: {1}, mean: {2:.2f}, worst: {3}".format(min(operation_timing), statistics.median(operation_timing), statistics.mean(operation_timing), max(operation_timing)))
        print(line)
        cluster_list = [0]
        operation_timing = []
