n = int(raw_input())

answers = filter(lambda x: sorted(str(x*n)) == sorted(str(n)), range(2, 10))

print ' '.join(map(str, answers)) if answers else "NO"
