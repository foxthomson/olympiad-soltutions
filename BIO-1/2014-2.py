size = int(raw_input())

grid = []

for _ in range(size):
    grid.append(map(int, raw_input().split()))

redgrid = [[False]*size]*size
redscore = 0

for y in range(size):
    for x in range(size):
        print
        print x, y
        if redgrid[y][x]:
            continue
        unjoined = True
        broken = False
        length = 1
        lx, ly = x, y
        redgrid[ly][lx] = True
        point = True
        if grid[ly][lx] == 1:
            if point:
                ly += 1
                if not (y < size):
                    brocken = True
                # print grid[ly][lx], grid[ly][lx] in (1, 3, 4)
                if grid[ly][lx] in (1, 3, 4):
                    if grid[ly][lx] == 3:
                        point = False
                    else:
                        point = True
                else:
                    brocken = True
            else:
                ly -= 1
                if not (y >= 0):
                    brocken = True
                if grid[ly][lx] in (1, 5, 6):
                    if grid[ly][lx] == 5:
                        point = False
                    else:
                        point = True
                else:
                    brocken = True
        elif grid[ly][lx] == 2:
            if point:
                lx += 1
                if not (x < size):
                    brocken = True
                if grid[ly][lx] in (2, 3, 6):
                    point = True
                else:
                    brocken = True
            else:
                lx -= 1
                if not (x >= 0):
                    brocken = True
                if grid[ly][lx] in (2, 4, 5):
                    point = False
                else:
                    brocken = True
        elif grid[ly][lx] == 3:
            if point:
                ly -= 1
                if not (y >= 0):
                    brocken = True
                if grid[ly][lx] in (1, 5, 6):
                    if grid[ly][lx] == 5:
                        point = False
                    else:
                        point = True
                else:
                    brocken = True
            else:
                lx -= 1
                if not (x >= 0):
                    brocken = True
                if grid[ly][lx] in (2, 4, 5):
                    point = False
                else:
                    brocken = True
        elif grid[ly][lx] == 4:
            if point:
                lx += 1
                if not (x < size):
                    brocken = True
                if grid[ly][lx] in (2, 3, 6):
                    point = True
                else:
                    brocken = True
            else:
                ly -= 1
                if not (y >= 0):
                    brocken = True
                if grid[ly][lx] in (1, 5, 6):
                    if grid[ly][lx] == 5:
                        point = False
                    else:
                        point = True
                else:
                    brocken = True
        elif grid[ly][lx] == 5:
            if point:
                lx += 1
                if not (x < size):
                    brocken = True
                if grid[ly][lx] in (2, 3, 6):
                    point = True
                else:
                    brocken = True
            else:
                ly += 1
                if not (y < size):
                    brocken = True
                if grid[ly][lx] in (1, 3, 4):
                    if grid[ly][lx] == 3:
                        point = False
                    else:
                        point = True
                else:
                    brocken = True
        elif grid[ly][lx] == 6:
            if point:
                ly += 1
                if not (y < size):
                    brocken = True
                if grid[ly][lx] in (1, 3, 4):
                    if grid[ly][lx] == 3:
                        point = False
                    else:
                        point = True
                else:
                    brocken = True
            else:
                lx -= 1
                if not (x >= 0):
                    brocken = True
                if grid[ly][lx] in (2, 4, 5):
                    point = False
                else:
                    brocken = True
        # print not brocken, ((lx, ly) != (x, y)) and (not broken)
        print brocken
        if not brocken:
            redgrid[ly][lx] = True
        while ( broken):
            # print brocken
            # print not broken, (lx, ly) != (x, y)
            print lx, ly
            length += 1
            if grid[ly][lx] == 1:
                if point:
                    ly += 1
                    if not (y < size):
                        brocken = True
                    if grid[ly][lx] in (1, 3, 4):
                        if grid[ly][lx] == 3:
                            point = False
                        else:
                            point = True
                    else:
                        brocken = True
                else:
                    ly -= 1
                    if not (y >= 0):
                        brocken = True
                    if grid[ly][lx] in (1, 5, 6):
                        if grid[ly][lx] == 5:
                            point = False
                        else:
                            point = True
                    else:
                        brocken = True
            elif grid[ly][lx] == 2:
                if point:
                    lx += 1
                    if not (x < size):
                        brocken = True
                    if grid[ly][lx] in (2, 3, 6):
                        point = True
                    else:
                        brocken = True
                else:
                    lx -= 1
                    if not (x >= 0):
                        brocken = True
                    if grid[ly][lx] in (2, 4, 5):
                        point = False
                    else:
                        brocken = True
            elif grid[ly][lx] == 3:
                if point:
                    ly -= 1
                    if not (y >= 0):
                        brocken = True
                    if grid[ly][lx] in (1, 5, 6):
                        if grid[ly][lx] == 5:
                            point = False
                        else:
                            point = True
                    else:
                        brocken = True
                else:
                    lx -= 1
                    if not (x >= 0):
                        brocken = True
                    if grid[ly][lx] in (2, 4, 5):
                        point = False
                    else:
                        brocken = True
            elif grid[ly][lx] == 4:
                if point:
                    lx += 1
                    if not (x < size):
                        brocken = True
                    if grid[ly][lx] in (2, 3, 6):
                        point = True
                    else:
                        brocken = True
                else:
                    ly -= 1
                    if not (y >= 0):
                        brocken = True
                    if grid[ly][lx] in (1, 5, 6):
                        if grid[ly][lx] == 5:
                            point = False
                        else:
                            point = True
                    else:
                        brocken = True
            elif grid[ly][lx] == 5:
                if point:
                    lx += 1
                    if not (x < size):
                        brocken = True
                    if grid[ly][lx] in (2, 3, 6):
                        point = True
                    else:
                        brocken = True
                else:
                    ly += 1
                    if not (y < size):
                        brocken = True
                    if grid[ly][lx] in (1, 3, 4):
                        if grid[ly][lx] == 3:
                            point = False
                        else:
                            point = True
                    else:
                        brocken = True
            elif grid[ly][lx] == 6:
                if point:
                    ly += 1
                    if not (y < size):
                        brocken = True
                    if grid[ly][lx] in (1, 3, 4):
                        if grid[ly][lx] == 3:
                            point = False
                        else:
                            point = True
                    else:
                        brocken = True
                else:
                    lx -= 1
                    if not (x >= 0):
                        brocken = True
                    if grid[ly][lx] in (2, 4, 5):
                        point = False
                    else:
                        brocken = True
            if not brocken:
                redgrid[ly][lx] = True
        if not broken:
            redscore += length
print redscore,
