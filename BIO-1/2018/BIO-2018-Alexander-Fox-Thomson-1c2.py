from math import ceil, isnan


topay = 10000
payed = 0

intrest, payment = map(int, raw_input().split())
n = 0
topay += int(ceil(topay*(intrest*0.01)))
while topay > 5000:
    n+=1
    payed += int(max(5000, ceil(topay*(payment*0.01))))
    topay -= int(max(5000, ceil(topay*(payment*0.01))))
    topay += int(ceil(topay*(intrest*0.01)))
    # if n > 40000:print topay


print (payed + topay)/100. if not isnan(n) else "no"
