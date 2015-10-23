ciphertext = 'commonsenseisnotsocommon'
key = 'pizza'

def itoc(x):
	return chr(x +  ord('a')) 

def ctoi(x):
	return (ord(x) - ord('a')) % 26

print ctoi('a'), ctoi('z')
print itoc(0), itoc(25)


while(len(key) < len(ciphertext)):
	key = key + key

print "+ve: "
for i in xrange(0, len(ciphertext)):
	print itoc((ctoi(ciphertext[i]) - ctoi(key[i]))%26) , 
print ""

print "-ve: "
for i in xrange(0, len(ciphertext)):
	print itoc((ctoi(ciphertext[i]) - ctoi(key[i]))%26) , 
print ""
