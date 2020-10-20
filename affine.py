import math
def encryption(plaintext,key1,key2):
	'''
		Encrypt the plaintext using Affine cipher.
		
		@param plaintext: The message to be encrypted.
		@param key1:	  The multiplicative key.
		@param key2: 	  The additive key.
		
		@return ciphertext: The encrypted ciphertext.
	'''
	ciphertext = ''
	for i in plaintext:
		if ord(i)>=97 and ord(i)<=122:
			ciphertext += chr(((ord(i)-97)*key1+key2)%26+97)
		else:
			print('Only lowercase characters allowed.Exiting....')
			exit()
	return ciphertext
	
def pow_mod(x,power,mod):
	'''
		Computes (x^power) % mod.
		
		@param x:     The base.
		@param power: The exponent.
		@param mod:   The modulus used.
		
		@return res: The computed result.
	'''
	res=1
	for i in range(power):
		res = (res * x)%mod
	return res

def decryption(ciphertext, key1, key2):
	'''
		Decrypt the ciphertext using Affine cipher.
		
		@param ciphertext: The message to be decrypted.
		@param key1:	   The multiplicative key.
		@param key2: 	   The additive key.
		
		@return plaintext: The decrypted plaintext.
	'''
	key1 = pow_mod(key1,11,26)
	plaintext= ''
	for i in ciphertext:
		if ord(i)>=97 and ord(i)<=122:
			plaintext += chr(((ord(i)-97-key2+26)%26*key1)%26+97)
		else:
			print('Only lowercase characters allowed.Exiting....')
			exit()
	return plaintext
	
print('Affine Cipher')
print('1. Encyption')
print('2. Decryption')
print('3. Exit')
choice = int(input('Enter your choice: '))
if choice == 1:
	key1 = int(input('Enter the multiplicative key: '))
	while(math.gcd(key1,26) !=1):
		print('Key must have multiplicative inverse')
		key1 = int(input('Enter the multiplicative key: '))
	key2 = int(input('Enter the additive key: '))
	plaintext = input('Enter the plaintext: ')
	ciphertext = encryption(plaintext, key1, key2)
	print('The Encrypted text is ' + ciphertext)
elif choice == 2:
	key1 = int(input('Enter the multiplicative key: '))
	while(math.gcd(key1,26) !=1):
		print('Key must have multiplicative inverse')
		key1 = int(input('Enter the multiplicative key: '))
	key2 = int(input('Enter the additive key: '))
	ciphertext = input('Enter the ciphertext: ')
	plaintext = decryption(ciphertext, key1, key2)
	print('The Decrypted text is ' + plaintext)
elif choice == 3:
	exit()
else:
	print('Wrong Choice')
	exit()
