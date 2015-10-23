ciphertext = 'abc'
vignere = 'key'

def itoc(x):
	return chr(x+ ord('a'))

def ctoi(x):
	return ord(x) - ord('a')

print ctoi('a'), ctoi('z')