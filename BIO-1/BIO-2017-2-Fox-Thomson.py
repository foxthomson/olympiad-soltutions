p1, m1, p2, m2, t = map(int, raw_input().split())

p1 -= 1
p2 -= 1

s1 = 0
s2 = 0

connections = [] # smallest first
boxes = [["*" for _ in range(5)] for _ in range(5)] # boxes[y][x]

turn = 1

for _ in range(t):
    if turn == 1:
        # player 1
        # print p1
        p1 = (p1 + m1) % 36
        # print p1
        turn = 2
        # notDrawn = False
        while True:
            if (p1 - 6, p1) not in connections and p1 > 5:
                connections.append((p1 - 6, p1))
                # print 1, (p1 - 6, p1)
                if (p1 - 7, p1 - 6) in connections and (p1 - 7, p1 - 1) in connections and (p1 - 1, p1) in connections:
                    boxes[p1/6 - 1][(p1%6) - 1] = "X"
                    turn = 1
                    s1 += 1
                if (p1 - 6, p1 - 5) in connections and (p1 - 5, p1 + 1) in connections and (p1, p1 + 1) in connections:
                    boxes[p1/6 - 1][p1%6] = "X"
                    turn = 1
                    s1 += 1
                break
            elif (p1, p1 + 1) not in connections and p1%6 != 5:
                connections.append((p1, p1 + 1))
                # print 2, (p1, p1 + 1)
                if (p1, p1 + 6) in connections and (p1 + 6, p1 + 7) in connections and (p1 + 1, p1 + 7) in connections:
                    boxes[p1/6][p1%6] = "X"
                    turn = 1
                    s1 += 1
                if (p1 - 6, p1 - 5) in connections and (p1 - 5, p1 + 1) in connections and (p1 - 6, p1) in connections:
                    boxes[p1/6 - 1][p1%6] = "X"
                    turn = 1
                    s1 += 1
                break
            elif (p1, p1 + 6) not in connections and p1 < 30:
                connections.append((p1, p1 + 6))
                # print 3, (p1, p1 + 6)
                if (p1, p1 + 1) in connections and (p1 + 6, p1 + 7) in connections and (p1 + 1, p1 + 7) in connections:
                    boxes[p1/6][p1%6] = "X"
                    turn = 1
                    s1 += 1
                if (p1 - 1, p1) in connections and (p1 - 1, p1 + 5) in connections and (p1 + 5, p1 + 6) in connections:
                    boxes[p1/6][(p1%6) - 1] = "X"
                    turn = 1
                    s1 += 1
                break
            elif (p1 - 1, p1) not in connections and p1%6 != 0:
                connections.append((p1 - 1, p1))
                # print 4, (p1 - 1, p1)
                if (p1 - 7, p1 - 6) in connections and (p1 - 7, p1 - 1) in connections and (p1 - 6, p1) in connections:
                    boxes[p1/6 - 1][(p1%6) - 1] = "X"
                    turn = 1
                    s1 += 1
                if (p1, p1 + 6) in connections and (p1 - 1, p1 + 5) in connections and (p1 + 5, p1 + 6) in connections:
                    boxes[p1/6][(p1%6) - 1] = "X"
                    turn = 1
                    s1 += 1
                break
            p1 = (p1 + 1) % 36
    else:
        # player 2
        p2 = (p2 + m2) % 36
        turn = 1
        # notDrawn = False
        while True:
            if (p2 - 6, p2) not in connections and p2 > 5:
                connections.append((p2 - 6, p2))
                if (p2 - 7, p2 - 6) in connections and (p2 - 7, p2 - 1) in connections and (p2 - 1, p2) in connections:
                    boxes[p2/6 - 1][(p2%6) - 1] = "O"
                    turn = 2
                    s2 += 1
                if (p2 - 6, p2 - 5) in connections and (p2 - 5, p2 + 1) in connections and (p2, p2 + 1) in connections:
                    boxes[p2/6 - 1][p2%6] = "O"
                    turn = 2
                    s2 += 1
                break
            elif (p2 - 1, p2) not in connections and p2%6 != 0:
                connections.append((p2 - 1, p2))
                if (p2 - 7, p2 - 6) in connections and (p2 - 7, p2 - 1) in connections and (p2 - 6, p2) in connections:
                    boxes[p2/6 - 1][(p2%6) - 1] = "O"
                    turn = 2
                    s2 += 1
                if (p2, p2 + 6) in connections and (p2 - 1, p2 + 5) in connections and (p2 + 5, p2 + 6) in connections:
                    boxes[p2/6][(p2%6) - 1] = "O"
                    turn = 2
                    s2 += 1
                break
            elif (p2, p2 + 6) not in connections and p2 < 30:
                connections.append((p2, p2 + 6))
                if (p2, p2 + 1) in connections and (p2 + 6, p2 + 7) in connections and (p2 + 1, p2 + 7) in connections:
                    boxes[p2/6][p2%6] = "O"
                    turn = 2
                    s2 += 1
                if (p2 - 1, p2) in connections and (p2 - 1, p2 + 5) in connections and (p2 + 5, p2 + 6) in connections:
                    boxes[p2/6][(p2%6) - 1] = "O"
                    turn = 2
                    s2 += 1
                break
            elif (p2, p2 + 1) not in connections and p2%6 != 5:
                connections.append((p2, p2 + 1))
                if (p2, p2 + 6) in connections and (p2 + 6, p2 + 7) in connections and (p2 + 1, p2 + 7) in connections:
                    boxes[p2/6][p2%6] = "O"
                    turn = 2
                    s2 += 1
                if (p2 - 6, p2 - 5) in connections and (p2 - 5, p2 + 1) in connections and (p2 - 6, p2) in connections:
                    boxes[p2/6 - 1][p2%6] = "O"
                    turn = 2
                    s2 += 1
                break
            p2 = (p2 + 1) % 36

# print connections
for row in boxes:
    for box in row: print box,
    print
print s1, s2
