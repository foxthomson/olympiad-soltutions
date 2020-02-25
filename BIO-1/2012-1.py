n = int(raw_input())

ans = 1
nprime = True
for i in range(2, max(2, n)):
    if n%i == 0:
        nprime = False
        for j in range(2, int(i**.5)+1):
            if i % j == 0:
                break
        else:
            ans *= i

print n if nprime else ans
