import requests
from bs4 import BeautifulSoup




for i in range(0, 200):
    r = requests.post('http://howstat.com/cricket/Quiz/Quiz.asp',data = {'cboCategory': 'J', 'txtAction': 'Start'})
    s = BeautifulSoup(r.text, 'lxml')
    x = s.find_all('td', {'class': 'TextCrimsonBold10'})
    question = x[0].text.strip()
    answers = [x[1].text.strip(), x[2].text.strip(), x[3].text.strip()]
    print(question)
    for i in answers:
        print(i)
    print('\n')
