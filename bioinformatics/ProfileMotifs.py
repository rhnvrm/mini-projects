def Profile(Motifs):
    t = len(Motifs)
    k = len(Motifs[0])
    profile = Count(Motifs)
    # insert your code here
    profile['A'] = [i/k for i in profile['A']]
    profile['C'] = [i/k for i in profile['C']]
    profile['T'] = [i/k for i in profile['T']]
    profile['G'] = [i/k for i in profile['G']]
    return profile
