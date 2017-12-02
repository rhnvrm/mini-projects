t = 16
chksum = 0
for i in range(t):
    row = list(map(int, input().split()))
    
    for i in range(len(row)):
        for j in range(len(row)):
            if i == j:
                pass
            else:
                if row[i] % row[j] == 0:
                    chksum += int(row[i]/row[j])

print(chksum)
