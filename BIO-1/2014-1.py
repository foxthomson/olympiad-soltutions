inp = int(raw_input())

searching = True
test = inp
while searching:
    test -= 1
    if test % 2 == 0:
        continue
    for fact in range(3, int(test**.5)+1, 2):
        if (test/2 + 1) % fact == 0:
            break
    else:
        print test,
        break

searching = True
test = inp
while searching:
    test += 1
    if test % 2 == 0:
        continue
    for fact in range(3, int(test**.5)+1, 2):
        if (test/2 + 1) % fact == 0:
            break
    else:
        print test
        break
