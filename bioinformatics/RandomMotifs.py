def RandomMotifs(Dna, k, t):
    # place your code here.
    n = len(Dna[0])
    random_motifs = []
    for each_string in Dna:
        random_start = random.randint(0,n-k)
        random_motifs.append(each_string[random_start:random_start+k])
    return random_motifs
