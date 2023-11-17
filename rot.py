def rot(s):
    chars = "abcdefghijklmnopqrstuvwxyz"
    for i in range(1, 26):
	    trans = chars[i:]+chars[:i]
	    rot_char = lambda c: trans[chars.find(c)] if chars.find(c)>-1 else c
	    print( ''.join( rot_char(c) for c in s ) )
