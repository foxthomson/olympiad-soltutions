from math import ceil

# intrest, payment = map(int, raw_input().split())

def parta(intrest, payment):
    topay = 10000.
    payed = 0.

    n = 0
    topay += ceil(topay*(intrest*0.01))
    while topay > 5000 and n < 100:
        n+=1
        payed += max(5000, ceil(topay*(payment*0.01)))
        topay -= max(5000, ceil(topay*(payment*0.01)))
        topay += ceil(topay*(intrest*0.01))

    # print n
    return (payed + topay)/100. if n<100 else False

best = 0
ba, bb = 0, 0
for a in range(100):
    for b in range(100):
        amount = parta(a, b)
        if amount:
            if amount > best:
                best = amount
                ba, bb = a , b

print best, ba, bb
