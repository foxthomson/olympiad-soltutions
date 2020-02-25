def pack(i, n, w, m=1):
    # print i, n, w, m
    if n == 1:
        # if m <= w <= i:
        #     print w
        # else:
        #     print "//"
        return 1 if m <= w <= i else 0
    else:
        ans = 0
        for weight in range(m, i + 1):
            if weight < w:
                # print weight
                ans += pack(i, n - 1, w - weight, weight)
            # else:
            #     print "///"
        return ans

def pack2(i, n, w):
    ans = 0
    for num in range(1, n):
        ans += pack(i, num, w) * pack(i, n - num, w)
    return ans

def packn(i, n, w, p):
    if p == 2:
        return pack2(i, n, w)
    else:
        ans = 0
        for num in range(1, n - p + 2):
            ans += pack(i, num, w) * packn(i, n - num, w, p-1)
        return ans

p, i, n, w = map(int, raw_input().split())

if p == 1:
    print pack(i, n, w)
elif p == 2:
    print pack2(i, n, w)
elif p ==3:
    print packn(i, n, w, p)


# for n1 in range(1, n):
    # if n1 <= w <= n1 * i and (n - n1) <= w <= (n - n1) * i:
