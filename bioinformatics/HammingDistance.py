def HammingDistance(p, q):
    # your code here
    distance = 0
    for i in range(0,len(p)):
        if p[i] != q[i]:
            distance+=1
    return distance
