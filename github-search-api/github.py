import requests
import json



#atom atom 27-02-2013

L = input().split()

org = L[0]
repo = L[1]
date = L[2].split('-')

date_str = '' + date[2] + '-' + date[1] + '-' + date[0]

#print(org, repo, date_str)

r = requests.get('https://api.github.com/search/issues?q=user:'+org+'+repo:'+repo+'+created:'+date_str+'&sort=created&order=asc').json()


for i in range(0, len(r['items'])):
	print(r['items'][i]['html_url'])