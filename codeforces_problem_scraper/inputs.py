import requests
from bs4 import BeautifulSoup


GROUP_SIZE = 10

#create input file
s = BeautifulSoup(open('saved_source.html'), 'lxml')
x = s.find_all('div', {'class': 'input-view'})

count = 0
real_count = 0
for i in x:
    if count == 0:
        real_count += 1
        f = open('input'+str(real_count).zfill(3)+'.txt', 'w+')
        print('10', file = f)
        
        
    count += 1
    print(i.find_all('pre')[0].text.strip(), file = f)
    if count == GROUP_SIZE:
        f.close()
        count = 0

#create output files
x = s.find_all('div', {'class': 'answer-view'})

count = 0
real_count = 0

for i in x:
    if count == 0:
        real_count += 1
        f = open('output'+str(real_count).zfill(3)+'.txt', 'w+')
    
    count += 1
    print(i.find_all('pre')[0].text.strip(), file = f)
    if count == GROUP_SIZE:
        f.close()
        count = 0

