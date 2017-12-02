def f(x):
    result = 0
    
    for i in range(int(len(x)/2)):
        if x[i] == x[i + int(len(x)/2)]:
            result +=  int(x[i])

    
    return 2*result

x = input()

print(f(x))
