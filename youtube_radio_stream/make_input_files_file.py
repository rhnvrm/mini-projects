import glob
files = glob.glob("audio/*")

list_f = open('list.txt', 'w')

for i in range(10):
    for f in files:
        list_f.write('file ' + '\'' + f + '\'\n')

list_f.close()
