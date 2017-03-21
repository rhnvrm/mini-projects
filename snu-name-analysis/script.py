import nltk
from nltk import FreqDist
import numpy as np
import matplotlib.pyplot as plt

i = open('emails.txt')
#o = open('out.txt', 'r+')

email_memo = []
names = []

for line in i:
	x = line.split('<')
	if len(x) >= 2:
		#print x[1]
		if x[1] not in email_memo:
			#o.write(x[0] + '\n')
			names.append(x[0].lower())
			email_memo.append(x[1])

i.close()

#print names

first_names = [n.split()[0] for n in names]
print "Sample Size: " + repr(len(first_names))
fdist = FreqDist(first_names)
top300 = fdist.most_common(300)
data = fdist.most_common(25)
print "\nTOP 25:"
print data
print "\nTOP 300:"
print top300

data = dict(data)


#plt.show()