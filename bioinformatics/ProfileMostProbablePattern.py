def ProfileMostProbablePattern(Text, k, Profile):
    # insert your code here. Make sure to use Pr(Text, Profile) as a subroutine!
    max_p = -1
    s = 
    for i in range(len(Text)-k+1):
        p = Pr(Text[i:i+k],Profile)
        if(p > max_p):
            s = str(Text[i:i+k])
            max_p = p
    return s
