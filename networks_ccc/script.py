__author__ = 'rohan verma (rhnvrm) <hello@rohanverma.net>'

__desc__   = 'Converts dataset values of source and target into hashed strings to be read by a network graph visualizer like gephi'

fname = 'rfa_all.NL-SEPARATED.txt'

with open(fname) as f:
    content = f.read().splitlines()

for line in content:
	spl_line = line.split(':')
	cmd = spl_line[0]
	if(len(spl_line) == 2): 
		msg = spl_line[1]
		if(cmd == 'SRC'):
			print hash(msg), 
		if(cmd == 'TGT'):
			print hash(msg)