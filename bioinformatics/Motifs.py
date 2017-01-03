#! /usr/bin/python3.4
# -*-coding:utf-8 -*

def Count(Motifs):
    """
	Returns the count matrix of a list of sequences.
	The count matrix is the number of times a nucleotid appears at a position in the pool of sequences (Motifs).

	:param Motifs: The sequences to make the count matrix of.
	:type Motifs: list of string

	:return: the count matrix
	:rtype: dict of list of int with nucleotids as keys.

	..seealso:: Count()
    """
    count = {}
    k = len(Motifs[0])
    for symbol in "ACGT":
        count[symbol] = []
        for j in range(k):
             count[symbol].append(0)
    t = len(Motifs)
    for i in range(t):
        for j in range(k):
            symbol = Motifs[i][j]
            count[symbol][j] += 1
    return count

def Profile(Motifs):
    """
	Returns the profile matrix of a list of sequences.
	The profile matrix is the frequency of a nucleotid at a position in the pool of sequences (Motifs).

	:param Motifs: The sequences to make the profile matrix of.
	:type Motifs: list of string

	:return: the profile matrix
	:rtype: dict of list of float with nucleotids as keys.

	..seealso:: Count()
    """
    t = len(Motifs)
    k = len(Motifs[0])
    profile = {}
    count= Count(Motifs)
    for symbol in "ACGT":
        profile[symbol] = []
        for j in range(k):
             profile[symbol].append(0)
    for symbol in "ACGT":
        for j in range(k):
            if t >0:
               profile[symbol][j]= count[symbol][j]/t
    return profile

def Consensus(Motifs):
    """
	Returns the consensus sequence of several sequences.

	:param Motifs: the sequences to produce a consensus of.
	:type Motifs: list of string
	:return: the consensus sequence
	:rtype: string

	..warnings:: the strings in Motifs must only be composed on the letters A,C,G,T.
	..seealso:: Count()
    """
    consensus = ""
    k = len(Motifs[0])
    count=Count(Motifs)
    for j in range(k):
        m = 0
        frequentSymbol = ""
        for symbol in "ACGT":
            if count[symbol][j] > m:
                m = count[symbol][j]
                frequentSymbol = symbol
        consensus += frequentSymbol
    return consensus

def Score(Motifs):
    """
	returns the number of unpopular letter in the motif matrix (Motifs).

	:param Motifs: the motif matrix.
	:type Motifs: a list of string
	:return: the number of unpopular letters in the motif matrix.
	:rtype: int

	..seealso:: Count(), Consensus()
    """
    t = len(Motifs)
    k = len(Motifs[0])
    score=0
    count=Count(Motifs)
    consensus = Consensus(Motifs)
    for symbol in "ACGT":
        for j in range(k):
            if symbol != consensus[j]:
                score += count[symbol][j]
    return score


# Input:  String Text and profile matrix Profile
# Output: Pr(Text, Profile)
def Pr(Text, Profile):
    # insert your code here
    compteur=0
    Pr=1
    for letter in Text:
        Pr=Pr*Profile[letter][compteur]
        compteur+=1
    return Pr


# Input:  String Text, an integer k, and profile matrix Profile
# Output: ProfileMostProbablePattern(Text, k, Profile)
def ProfileMostProbablePattern(Text, k, Profile):
    prm=-1
    s=""
    for i in range(len(Text)-k+1):
        pr=Pr(Text[i:i+k],Profile)
        if pr>prm:
            prm=pr
            s=str(Text[i:i+k])
    return str(s)
