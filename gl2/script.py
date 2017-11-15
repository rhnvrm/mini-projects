f = open('out.tr', 'r')

plot_file = open('graph', 'w')

drop = 0
packets = 0

for line in f:
	if(line[0] == 'd'):
		drop += 1
		
	if 'ack' not in line: 
		packets += 1

	line = line.split(' ')
	plot_file.write(line[1]+" "+str(packets*1.0/float(line[1]))+"\n")

print "no of packets dropped are: ", drop
print "throughput is", packets*1.0/5, "kpbs"

f.close()
plot_file.close()