# Input:  A DNA string Pattern
# Output: The reverse complement of Pattern
def ReverseComplement(Pattern):
    revComp = reverse([complement(p) for p in Pattern]) # output variable
    # your code here
    return ''.join(revComp)


# Copy your reverse function from the previous step here.
def reverse(string):
    return string[::-1]

# HINT:   Filling in the following function is optional, but it may come in handy when solving ReverseComplement
# Input:  A character Nucleotide
# Output: The complement of Nucleotide
def complement(Nucleotide):
    complement = {'A': 'T', 'C': 'G', 'G': 'C', 'T': 'A'} 
    return complement[Nucleotide]
    

### DO NOT MODIFY THE CODE BELOW THIS LINE ###
import sys
print(ReverseComplement(sys.stdin.read().strip()))
