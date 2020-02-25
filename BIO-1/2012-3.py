from collections import Counter as C

def num2C(n):
    ans = C()
    for i in str(n):
        ans += C(numbers[int(i)])
    return ans

numbers = "ZERO ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE".split()
cnumbers = map(C, numbers)

diff = lambda a, b: sum(((a-b) + (b-a)).values())

counted = []
# num2C(n) for n in range(1, 1000)
for a in range(1, 10):
    counted.append(cnumbers[a])
    for b in range(0, a+1):
        counted.append(cnumbers[a] + cnumbers[b])
        for c in range(0, b+1):
            counted.append(cnumbers[a] + cnumbers[b] + cnumbers[c])

tranformable = lambda a: filter(lambda b: diff(a, b) <= 5, counted)

def getans(inps):
    s, f = inps
    idf = counted.index(num2C(f))
    ids = counted.index(num2C(s))

    cantransform = [False]*len(counted)
    cantransform[ids] = True
    newtransforms = [ids]
    ts = 0
    while not cantransform[idf]:
        ts+=1
        newnewtransforms = []
        for i, c in enumerate(counted):
            if not cantransform[i]:
                for t in newtransforms:
                    if diff(counted[t], c) <= 5:
                        cantransform[i] = True
                        newnewtransforms.append(i)
                        break
        newtransforms = newnewtransforms
    return str(ts) if ts else str(int(s!=f))

print "\n".join(getans(map(int, raw_input().split())) for _ in range(3))
