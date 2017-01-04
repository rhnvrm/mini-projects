def ProfileWithPseudocounts(Motifs):
    t = len(Motifs)
    k = len(Motifs[0])
    profile = {} # output variable
    # your code here
    count = CountWithPseudocounts(Motifs)
    for symbol in "ACGT":
	    profile[symbol]=[]
	    for i in range(k):
	        profile[symbol].append(float(float(count[symbol][i])/float(t+4))) #set value as zero
    return profile
