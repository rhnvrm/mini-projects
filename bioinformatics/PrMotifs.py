for i in range(0,len(Text) - len(Pattern)+1):
        if HammingDistance(Pattern, Text[i:i+len(Pattern)]) <= d:
            positions += [i]

