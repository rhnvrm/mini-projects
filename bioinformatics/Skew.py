def Skew(Genome):
    skew = {} #initializing the dictionary
    # your code here
    skew[0] = 0
    for i in range(1,len(Genome)+1):
        last = Genome[i-1]
        if last == 'G':
            skew[i] = skew[i-1]+1
        elif last == 'C':
            skew[i] = skew[i-1]-1
        else:
            skew[i] = skew[i-1]
    return skew

