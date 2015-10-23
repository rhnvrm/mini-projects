s=raw_input()
f=s[:1]
l=s[1:]
if f in list('aeiou'):
    print "%s-yay" % s
else:
    print "%s-%say" % (l, f)