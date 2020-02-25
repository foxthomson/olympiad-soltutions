# Setup grid
grid = [[1]*11 for _ in range(11)] # grid[x][y]

for y in range(3):
    for x, inp in enumerate(map(int, raw_input().split())):
        grid[4+x][4+y] = inp

# Setup die
dirx, diry = 0, -1 # -1 is up/left
posx, posy = 5, 5
upper = 1
topfacing = 2
leftfacing = 3 # not needed but helpful

n = int(raw_input())
while n:
    # Move die
    for _ in range(n):
        # Add top
        grid[posx][posy] = (grid[posx][posy] + upper) % 6
        grid[posx][posy] += 0 if grid[posx][posy] else 6

        # change dir
        if grid[posx][posy] in (3, 4):
            dirx *= -1
            diry *= -1
        elif grid[posx][posy] == 2:
            # Clockwise
            dirx, diry = -diry, dirx
        elif grid[posx][posy] == 5:
            # anticlockwise
            dirx, diry = diry, -dirx

        # MOVE!!
        posx += dirx
        posy += diry

        # Change sides
        if dirx == -1:
            # Left
            upper, leftfacing = 7-leftfacing, upper
        if dirx == 1:
            # right
            upper, leftfacing = leftfacing, 7-upper
        if diry == -1:
            # up
            upper, topfacing = 7-topfacing, upper
        if diry == 1:
            # Left
            upper, topfacing = topfacing, 7-upper

    # print board
    for y in range(-1, 2):
        for x in range(-1, 2):
            if -1 < y+posy < 11 or -1 < x+posx < 11:
                print grid[x+posx][y+posy],
            else:
                print "x",
        print

    n = int(raw_input())
