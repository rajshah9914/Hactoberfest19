def generate(a, c, m, seed,key_length):
	key=chr(seed%m + 48)
	for i in range(1,key_length):
		seed = (a * seed + c)
		key += chr(seed%m + 48)
	return key

def str2bin(str1):
	r = [bin(ord(i))[2:] for i in str1]
	for i in range(len(r)):
		r[i] = '0'*(8-len(r[i]))+r[i]
	binary = "".join(r)
	return binary

def bin2str(str1):
	str = ''
	for i in range(0, len(str1), 8):
		str += chr(int(str1[i:i+8],2))
	return str

def encrypt(key, plaintext):
	j = 0
	ciphertext = ''
	for i in plaintext:
		t = ord(i) - 48
		t1 = ord(key[j%len(key)]) - 48
		r = t ^ t1
		ciphertext += chr(r + 48)
		j += 1
	return ciphertext

def decrypt(key, ciphertext):
	j = 0
	plaintext = ''
	for i in ciphertext:
		t = ord(i) - 48
		t1 = ord(key[j%len(key)]) - 48
		r = t ^ t1
		plaintext += chr(r + 48)
		j += 1
	return plaintext

print("Vernam Cipher")
print("1. Encryption")
print("2. Decryption")
print("3. Exit")
ch = int(input("Enter your choice: "))
if ch == 1:
	print("Generate the key")
	key_length = int(input("Enter the length of key: "))
	a = int(input("Enter the value of a in the random number equation: "))
	c = int(input("Enter the value of c in the random number equation: "))
	seed = int(input("Enter the value of seed in the random number equation: "))
	key = generate(a, c, 2, seed, key_length)
	plaintext = input("Enter the plaintext: ")
	ciphertext = encrypt(key, str2bin(plaintext))
	print("Ciphertext is: " + ciphertext)
elif ch == 2:
	print("Generate the key")
	key_length = int(input("Enter the length of key: "))
	a = int(input("Enter the value of a in the random number equation: "))
	c = int(input("Enter the value of c in the random number equation: "))
	seed = int(input("Enter the value of seed in the random number equation: "))
	key = generate(a, c, 2, seed, key_length)
	ciphertext = input("Enter the ciphertext: ")
	plaintext = bin2str(decrypt(key, ciphertext))
	print("Plaintext is: " + plaintext)
else:
	exit(0)