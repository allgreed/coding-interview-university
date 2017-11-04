import fileinput
import statistics

cluster_list = []

for line in fileinput.input():

    if "Cluster allert" in line:
        cluster_list.append(int(line.split()[-1]))
    else:
        print("Max cluster: {0:.2f}%, mean clustering ratio: {1:.2f}%".format((max(cluster_list) / int(line.split()[-2]) * 100), (statistics.mean(cluster_list) / int(line.split()[-2]) * 100)))
        print(line)