import math
from random import randint
def pow_mod(x, power, mod):
	'''
		Computes (x^power) % mod.
		
		@param x:     The base.
		@param power: The exponent.
		@param mod:   The modulus used.
		
		@return res: The computed result.
	'''
	if power == 0:
		return 1
	elif power%2 == 0:
		return pow_mod((x * x) % mod, power//2, mod) % mod
	else:
		return (x * pow_mod((x * x) % mod, power//2, mod) % mod) % mod

def encryption(plaintext, n, e):
	'''
	Encrypts plaintext using public key.

	@param plaintext: The text to be encrypted.
	@param n:		  The modulus.
	@param e:		  The public key.

	@return ciphertext: The corresponding ciphertext.
	'''
	ciphertext = []
	for i in plaintext:
		t = ord(i) - 96
		t1 = pow_mod(t, e, n)
		ciphertext.append(t1)
	return ciphertext

def decryption(ciphertext, n, d):
	'''
	Decrypts ciphertext using private key.

	@param ciphertext: The text to be decrypted.
	@param n:		   The modulus.
	@param d:		   The private key.

	@return plaintext: The corresponding plaintext.
	'''
	plaintext = ''
	for i in ciphertext:
		t = pow_mod(i, d, n)
		plaintext += chr(t + 96)
	return plaintext

def mod_inv(a, b):
	'''
	Returns a^-1 mod b
	@param a: The value to find inverse
	@param b: The modulus
	
	@return i: The value of inverse
	'''
	i = 1
	while (a * i) % b != 1:
		i += 1
	return i

print('RSA Encryption')
a = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
p = a[randint(0, len(a))]
q = a[randint(0, len(a))]
while p == q:
	q = a[randint(0, len(a))]
phi = (p-1) * (q-1)
n = p * q
print('Using p as ' + str(p) + ' and q as ' + str(q))
e = int(input('Enter the value of e: '))
while math.gcd(e, phi) != 1:
	e = int(input('Enter the value of e again(e is not coprime with phi): '))
d = mod_inv(e, phi)
plaintext = input('Enter the plaintext: ')
ciphertext = encryption(plaintext, n, e)
print('Ciphertext is: ' + str(ciphertext))
plaintext = decryption(ciphertext, n, d)
print('Plaintext is: ' + plaintext)

