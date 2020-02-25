otherplayer = {"O":"X", "X":"O"}

def getmoves(board, player):
    emptyloc = board.index("E")

    moves = []

    if emptyloc == 0:
        for i in range(2, 8):
            if board[i] == player and (board[i-1] != player or board[i+1] != player):
                moves.append(i)
        if board[1] == player and (board[2] != player or board[8] != player):
            moves.append(1)
        if board[8] == player and (board[1] != player or board[7] != player):
            moves.append(8)
    elif emptyloc == 1:
        if board[8] == player: moves.append(8)
        if board[2] == player: moves.append(2)
        if board[0] == player: moves.append(0)
    elif emptyloc == 8:
        if board[7] == player: moves.append(7)
        if board[1] == player: moves.append(1)
        if board[0] == player: moves.append(0)
    else:
        if board[emptyloc + 1] == player: moves.append(emptyloc + 1)
        if board[emptyloc - 1] == player: moves.append(emptyloc - 1)
        if board[0] == player: moves.append(0)

    return moves

def canmove(board, player):
    return len(getmoves(board, player)) != 0

def winningmove(board, player):
    moves = getmoves(board, player)
    emptyloc = board.index("E")
    for m in sorted(moves):
        newboard = board[:]
        newboard[emptyloc] = player
        newboard[m] = "E"
        if not canmove(newboard, otherplayer[player]): return newboard
    return False

def avoidlosing(board, player):
    moves = getmoves(board, player)
    emptyloc = board.index("E")
    for m in sorted(moves):
        newboard = board[:]
        newboard[emptyloc] = player
        newboard[m] = "E"
        if not winningmove(newboard, otherplayer[player]): return newboard
    return False

def findmove(board, player):
    win = winningmove(board, player)
    if win: return win, True
    avoid = avoidlosing(board, player)
    if avoid: return avoid, False
    m = sorted(getmoves(board, player))[0]
    emptyloc = board.index("E")
    newboard = board[:]
    newboard[emptyloc] = player
    newboard[m] = "E"
    return newboard, False

board = [c for c in raw_input()]
prevboards = []
player = "O"

run = True
if not canmove(board, player):
    print "".join(board)
    print "Player 2 wins"
    run = False

while run:
    mode = raw_input()

    if mode == "n":
        prevboards.append(("".join(board), player))
        board, win = findmove(board, player)
        print "".join(board)
        if win:
            print "Player {} wins".format(int(player=="X") + 1)
            break
        player = otherplayer[player]
    else:
        while 1:
            prevboards.append(("".join(board), player))
            board, win = findmove(board, player)
            if win:
                print "".join(board)
                print "Player {} wins".format(int(player=="X") + 1)
                break
            if ("".join(board), otherplayer[player]) in prevboards:
                print "Draw"
                break
            player = otherplayer[player]
        break
