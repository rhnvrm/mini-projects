
def Motifs(Profile, Dna):
    # insert your code here
    motifs=[]
    k= len(Profile)
    for dna in Dna:
	    most_prob_kmer=ProfileMostProbablePattern(dna, k, Profile)
	    motifs.append(most_prob_kmer)
    return motifs    

