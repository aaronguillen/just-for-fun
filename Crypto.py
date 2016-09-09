#Crypto Tools
#Aaron Guillen

import re

nums = [1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25]
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
alphabetU = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

#Supporting Methods
def numToChar (i):
    i = i % 26
    return alphabet[i]

def charToNum (i):
    x = 0
    for y in alphabet:
        if y == i:
            return x
        x += 1
    x = 0
    for y in alphabetU:
        if y == i:
            return x
        x += 1

def mulInv(a):
    return pow(a, 23)

#Affine Cipher ------------------------------------------------------
def encryptAffine (plainText, alpha, beta):                         #
    a = alpha                                                       #
    b = beta                                                        #
    s = plainText                                                   #
    c = ""                                                          #
    if a not in nums:                                               #
        return "Invalid Alpha"                                      #
    for i in s:                                                     #
        if i in alphabet or i in alphabetU:                         #
            c += numToChar((a * charToNum(i) + b))                  #
        else:                                                       #
            c += i                                                  #
    return c                                                        #
                                                                    #
def decryptAffine (cipherText, alpha, beta):                        #
    a = alpha                                                       #
    b = beta                                                        #
    c = cipherText                                                  #
    p = ""                                                          #
    for i in c:                                                     #
        if i in alphabet or i in alphabetU:                         #
            p += numToChar((mulInv(a) * (charToNum(i) - b)) % 26)   #
        else:                                                       #
            p += i                                                  #
    return p                                                        #
#Affine Cipher ------------------------------------------------------

#Caesar Cipher-------------------------------------------------------
def encryptCaesar(plainText, rot):                                  #
    cipherText = ""                                                 #
    for i in plainText:                                             #
        if i in alphabet or i in alphabetU:                         #
            cipherText += numToChar((charToNum(i) + rot) % 26)      #           #
        else:                                                       #
            cipherText += i                                         #
    return cipherText                                               #
                                                                    #
def decryptCaesar(cipherText, rot):                                 #
    plainText = ""                                                  # 
    for i in cipherText:                                            #
        if i in alphabet or i in alphabetU:                         #
            plainText += numToChar((charToNum(i) + rot) % 26)       #
        else:                                                       #
            plainText += i                                          #
    return plainText                                                #
                                                                    #
def caesarBruteForce(cipherText):                                   #
    for i in range(0, 26):                                          #
        print 'ROT ' + str(i)                                       #
        print decryptCaesar(cipherText, i)                          #
        print                                                       #
#Caesar Cipher-------------------------------------------------------

#Substitution Cipher Analysis----------------------------------------
def subMain(cipherText):
    key = []
    dText = []
    print "For each letter, type the letter you'd like it to be",
    print "translated to. For example, if you'd like 'a' to become",
    print "'f', type 'f' when you see 'a -> '. If you don't want it",
    print "to be translated, leave it blank or type the same letter."
    for i in range(0, len(alphabet)):
        temp = raw_input(alphabet[i] + "-> ")
        if temp == "":
            key.append(alphabet[i])
        else:
            key.append(temp)
    for i in range(0, len(alphabetU)):
        if key[i].upper() != alphabetU[i]:
            key.append(key[i].upper())
        else:
            key.append(alphabetU[i])
    for i in cipherText:
        for j in i:
            if j in alphabet:
                dText.append(key[alphabet.index(j)])
            elif j in alphabetU:
                dText.append(key[alphabetU.index(j)])
            else:
                dText.append(j)
    r = ""
    for i in dText:
        r += i
    return r

def info():
    print "At anytime you can type Crypto.info() to see this message."
    print "Currently our supported crypto algorithms are:"
    print "Caesar Cipher:\n\tencyptCaesar(plaintText, rotation)"
    print "\tdecryptCaesar(cipherText, rotation)"
    print "\tcaesarBruteForce(cipherText)"
    print "Affine Cipher:\n\tencryptAffine(plainText, alpha, beta)"
    print "\tdecryptAffine(cipherText, alpha, beta)"

print "Welcome to Aaron Guillen's wonderful Crypto program!"
info()

fin = open("ciphert.txt")
stri = ""
for i in fin:
    stri += i
print subMain(stri)
#print subMain("a")
fin.close()

#EXAMPLE USAGES
#numsss = [21, 6, 7, 11, 8, 5, 1, 1, 23, 1, 17, 0, 22, 6, 0, 23, 12, 6, 24, 18, 1, 14, 25, 23, 2, 6, 21, 24, 1, 6, 16, 6, 21, 12, 21, 13, 25, 23, 17, 7, 24, 12, 23, 11]
#string = ""
#for i in numsss:
#    string += numToChar(i)
#string += "  |  vghlifb bxbraw gaxmgysbozxcgv ybgqgvmvnzxrhymxl"
#file_object = open("CIPHERS4DAZE.txt","w")
#for i in nums:
#    for j in range(0, 26):
#        file_object.write("a = " + str(i) + "  b = " + str(j) + "\n") 
#        dt = decrypt(string, i, j)
#        file_object.write(dt + "\n\n")
#file_object.close()

#Affine Cipher Brute Forcer
#Put your cipher text below.
#string = "Cipher Text here"
#file_object = open("CIPHERS4DAZE.txt","w")
#for i in nums:
#    for j in range(0, 26):
#        file_object.write("a = " + str(i) + "  b = " + str(j) + "\n") 
#        dt = decrypt(string, i, j)
#        file_object.write(dt + "\n\n")
#file_object.close()
