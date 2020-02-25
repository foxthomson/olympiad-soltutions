letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

def length(n, lena):
    if n <= lena:
        return 1
    pairs = (n*n+n)
    if n <= (n*n+n):
        return 2
    

def nthpass(n, alphabet):
    if n <= len(alphabet):
        return alphabet[n-1]
    n -= len(alphabet)
    for letter in alphabet:

inp = int(raw_input)
