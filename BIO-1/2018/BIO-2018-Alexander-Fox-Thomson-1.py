from math import ceil

print "Alexander Fox Thomson, King Alfred's Accademy, Question 1"

topay = 10000.
payed = 0.

intrest, payment = map(int, raw_input().split())
# n = 0
topay += ceil(topay*(intrest*0.01))
while topay > 5000:
    # n+=1
    payed += max(5000., ceil(topay*(payment*0.01)))
    topay -= max(5000., ceil(topay*(payment*0.01)))
    topay += ceil(topay*(intrest*0.01))

# print n
print (payed + topay)/100.

raw_input()
