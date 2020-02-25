print "Alexander Fox Thomson, King Alfred's Accademy, Question 2"

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

n, word = raw_input().split()

n = int(n)

remainingletters = letters
dial = {}
ringpoint = 0
for i, l in enumerate(letters):
    ringpoint += n -1
    ringpoint %= len(remainingletters)
    dial[l] = remainingletters[ringpoint]
    remainingletters = remainingletters[:ringpoint]+remainingletters[ringpoint+1:]

print "".join(map(lambda j: dial[j], "ABCDEF"))

print "".join(map(lambda x: dial[letters[(letters.index(x[1])+x[0])%26]], enumerate(word)))

raw_input()
