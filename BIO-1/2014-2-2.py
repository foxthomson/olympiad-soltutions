size = int(raw_input())

grid = []

for _ in range(size):
    grid.append(map(int, raw_input().split()))

# 0 up 1 right 2 down 3 right
redconvert = {1: (0, 2),
              2: (1, 3),
              3: (0, 3),
              4: (0, 1),
              5: (1, 2),
              6: (2, 3),}
redlinks = [[False for _ in range(size)] for _ in range(size)]

for y in range(size):
    for x in range(size):
        links = []
        for direction in redconvert[grid[y][x]]:
            if direction == 0:
                if y == 0:
                    break
                links.append((y - 1, x))
            if direction == 1:
                if x == size - 1:
                    break
                links.append((y, x + 1))
            if direction == 2:
                if y == size - 1:
                    break
                links.append((y + 1, x))
            if direction == 3:
                if x == 0:
                    break
                links.append((y, x - 1))
        else:
            # print x
            redlinks[y][x] = links
        # print x

# for i in range(size): print redlinks[i]

changed = True
while changed:
    score = 0
    changed = False
    for y in range(size):
        for x in range(size):
            if redlinks[y][x]:
                for ny, nx in redlinks[y][x]:
                    if not bool(redlinks[ny][nx]):
                        changed = True
                        redlinks[y][x] = False
                else:
                    score += 1

# print redlinks
print score,
# for i in range(size): print redlinks[i]

redconvert = {2: (0, 2),
              1: (1, 3),
              5: (0, 3),
              6: (0, 1),
              3: (1, 2),
              4: (2, 3),}
redlinks = [[False for _ in range(size)] for _ in range(size)]

for y in range(size):
    for x in range(size):
        links = []
        for direction in redconvert[grid[y][x]]:
            if direction == 0:
                if y == 0:
                    break
                links.append((y - 1, x))
            if direction == 1:
                if x == size - 1:
                    break
                links.append((y, x + 1))
            if direction == 2:
                if y == size - 1:
                    break
                links.append((y + 1, x))
            if direction == 3:
                if x == 0:
                    break
                links.append((y, x - 1))
        else:
            # print x
            redlinks[y][x] = links
        # print x

# for i in range(size): print redlinks[i]

changed = True
while changed:
    score = 0
    changed = False
    for y in range(size):
        for x in range(size):
            if redlinks[y][x]:
                for ny, nx in redlinks[y][x]:
                    if not bool(redlinks[ny][nx]):
                        changed = True
                        redlinks[y][x] = False
                else:
                    score += 1

print score
