def sum15(tot, ls):
    if len(ls) == 0:
        return int(tot == 15)
    else:
        return sum15(tot, ls[1:]) + sum15(tot + ls[0], ls[1:])

cards = map(int, raw_input().split())

score = sum15(0, cards)
for i, card in enumerate(cards):
    for card2 in cards[i+1:]:
        score += int(card == card2)

def all15(tot, left, prev):
    if left == 0:
        return int(tot == 15)
    num = 0
    for i in range(1, prev + 1):
        num += all15(tot+i, left-1, i)
    return num

print score
