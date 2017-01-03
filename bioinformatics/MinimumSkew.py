def MinimumSkew(Genome):
    positions = [] # output variable
    # your code here
    skew = Skew(Genome)
    minimum = min(skew.values())
    
    for i in range(0,len(skew)):
        if skew[i] == minimum:
            positions += [i]
    return positions

