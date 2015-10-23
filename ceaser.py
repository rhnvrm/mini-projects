ciphertext = raw_input()
ciphertext = ciphertext.lower()

def itoc(x):
	return chr(x+ ord('a'))

def decrypt(x,n):
	x = ord(x) - ord('a')
	return (x-n) % 26


for j in xrange(0, 26):
	print j , "-> ",
	for i in xrange(0, len(ciphertext)):
		if(ciphertext[i].isalpha()):
			print itoc(decrypt(ciphertext[i], j)),
		else:
			print '~',
	print ""