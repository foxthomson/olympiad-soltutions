def fib(a, b, n):
    if n == 0:
        return a
    return fib(b, a+b, n-1)

start = raw_input()
s, p = map(int, raw_input().split())

tots = [0, 0, 0, 0, 0]

for c in start:
    if c == "A":
        step = fib(1, 1, s)
        if step < p:
            tots[0] += fib(1, 0, s)
            tots[1] += fib(0, 1, s)
            p -= step
        else:
            currstr = "A"
            for i in range(p):
                newstr=""
                for cchange in currstr:
                    if cchange == "A":
                        newstr = newstr + "B"
                    else:
                        newstr = newstr + "AB"
                currstr = newstr

            for cadd in currstr[:p]:
                tots[int(cadd=="B")] += 1

            break
    elif c == "B":
        step = fib(1, 2, s)
        if step < p:
            tots[0] += fib(0, 1, s)
            tots[1] += fib(1, 1, s)
            p -= step
        else:
            currstr = "B"
            for i in range(p):
                newstr=""
                for cchange in currstr:
                    if cchange == "A":
                        newstr = newstr + "B"
                    else:
                        newstr = newstr + "AB"
                currstr = newstr

            for cadd in currstr[:p]:
                tots[int(cadd=="B")] += 1

            break
    elif c == "C":
        step = 2**s
        if step < p:
            tots[2] += 2**(s-1)
            tots[3] += 2**(s-1)
            p -= step
        else:
            currstr = "C"
            for i in range(p):
                newstr=""
                for cchange in currstr:
                    if cchange == "C":
                        newstr = newstr + "CD"
                    else:
                        newstr = newstr + "DC"
                currstr = newstr

            for cadd in currstr[:p]:
                tots[int(cadd=="D")+2] += 1

            break
    elif c == "D":
        step = 2**s
        if step < p:
            tots[2] += 2**(s-1)
            tots[3] += 2**(s-1)
            p -= step
        else:
            currstr = "D"
            for i in range(p):
                newstr=""
                for cchange in currstr:
                    if cchange == "C":
                        newstr = newstr + "CD"
                    else:
                        newstr = newstr + "DC"
                currstr = newstr

            for cadd in currstr[:p]:
                tots[int(cadd=="D")+2] += 1

            break
    else:
        step = 2**s
        if step < p:
            tots[4] += 2**s
            p -= step
        else:
            tots[4] += p

print ' '.join(map(str, tots))
