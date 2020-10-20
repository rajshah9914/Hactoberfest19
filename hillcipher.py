import numpy as np
import math
def encryption(key, plaintext):
	'''
	Encrypts the plaintext using hill cipher.

	@param key:		  The key matrix to be used.
	@param plaintext: The plaintext to be encrypted.

	@return ciphertext: The encrypted ciphertext.
	'''
    while len(plaintext)%key.shape[0] != 0:
        plaintext += 'a'
    plaintext_matrix = np.zeros((key.shape[0],len(plaintext)//key.shape[0]),dtype = 'int64')
    for i in range(len(plaintext)):
        if ord(plaintext[i]) >=97 and ord(plaintext[i]) <=122:
            plaintext_matrix[i//key.shape[0]][i%key.shape[0]] = ord(plaintext[i]) - 97
        else:
            print("Only lowercase allowed")
            exit(1)
    ciphertext_matrix = np.matmul(key, plaintext_matrix)
    ciphertext = ''
    for i in ciphertext_matrix:
        for j in i:
            ciphertext += chr(j%26 + 97)
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

def decryption(key, ciphertext):
	'''
	Decrypts the ciphertext using hill cipher.

	@param key:		   The key matrix to be used.
	@param ciphertext: The ciphertext to be decrypted.

	@return plaintext: The decrypted plaintext.
	'''
    key_inv = np.linalg.inv(key)
    det = int(np.round(np.linalg.det(key)))
    key_inv = key_inv * det
    for i in range(key_inv.shape[0]):
    	for j in range(key_inv.shape[1]):
    		key_inv[i][j] = int(np.round(key_inv[i][j]))
    det_inv = pow_mod(det, 11, 26)
    if len(ciphertext)%key.shape[0] != 0:
        print("Invalid ciphertext")
        exit(1)
    else:
        ciphertext_matrix = np.zeros((key.shape[0],len(ciphertext)//key.shape[0]),dtype = 'int64')
        for i in range(len(ciphertext)):
            if ord(ciphertext[i]) >=97 and ord(ciphertext[i]) <=122:
                ciphertext_matrix[i//key.shape[0]][i%key.shape[0]] = ord(ciphertext[i]) - 97
            else:
                print("Only lowercase allowed")
                exit(1)
        plaintext_matrix = np.matmul(key_inv, ciphertext_matrix)
        plaintext = ''
        plaintext_matrix = plaintext_matrix * det_inv
        for i in plaintext_matrix:
            for j in i:
                j1 = j
                while j1 < 0:
                    j1 += 26
                plaintext += chr(int(j1)%26 + 97)
        return(plaintext)

print("Hill Cipher")
key_matrix_length = int(input("Enter the length of key_matrix: "))
key = np.zeros((key_matrix_length,key_matrix_length), dtype = 'int64')
print("Enter the key elements")
for i in range(key_matrix_length):
    for j in range(key_matrix_length):
        key[i][j] = int(input())
det = np.linalg.det(key)
while det == 0 or math.gcd(int(np.round(det)),26) != 1:
    print("Enter a invertible matrix!!!")
    for i in range(key_matrix_length):
        for j in range(key_matrix_length):
            key[i][j] = int(input())
    det = np.linalg.det(key)
print("1. Encryption")
print("2. Decryption")
print("3. Exit")
ch = input("Enter your choice: ")
if ch == '1':
    plaintext = input("Enter the plaintext: ")
    ciphertext = encryption(key, plaintext)
    print("The Encrypted Ciphertext is: " + ciphertext)
elif ch == '2':
    ciphertext = input("Enter the ciphertext: ")
    plaintext = decryption(key, ciphertext)
    print("The Decrypted Plaintext is: " + plaintext)
else:
    exit(0)