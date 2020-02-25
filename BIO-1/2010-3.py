j, n = map(int, raw_input().split())

jugs = map(int, raw_input().split())

if j == 1:
    print int(bool(n))
else:
    if j == 2:
        reachable = [[False]*(jugs[0]+1) for i in range(jugs[1]+1)]
        reachable[0][0] = True

        todo = [(0, 0)]

        moves = 0
        loopflag = n != 0
        while loopflag:
            moves += 1

            newtodo = []

            for a, b in todo:
                # Fill a
                if not reachable[b][jugs[0]]:
                    if n == jugs[0]:
                        loopflag = False
                        break
                    newtodo.append((jugs[0], b))
                    reachable[b][jugs[0]] = True

                # Fill b
                if not reachable[jugs[1]][a]:
                    if n == jugs[1]:
                        loopflag = False
                        break
                    newtodo.append((a, jugs[1]))
                    reachable[jugs[1]][a] = True

                # Fill b with a
                # Would overflow
                if a+b > jugs[1]:
                    if not reachable[jugs[1]][a+b-jugs[1]]:
                        if n == jugs[1]:
                            loopflag = False
                            break

                        if n == a+b-jugs[1]:
                            loopflag = False
                            break

                        newtodo.append((a+b-jugs[1], jugs[1]))
                        reachable[jugs[1]][a+b-jugs[1]] = True
                # wont overflaw
                else:
                    if not reachable[a+b][0]:
                        if n == a+b:
                            loopflag = False
                            break
                        newtodo.append((0, a+b))
                        reachable[a+b][0] = True

                # Fill a with b
                # Would overflow
                if a+b > jugs[0]:
                    if not reachable[a+b-jugs[0]][jugs[0]]:
                        if n == jugs[0]:
                            loopflag = False
                            break

                        if n == a+b-jugs[0]:
                            loopflag = False
                            break

                        newtodo.append((jugs[0], a+b-jugs[0]))
                        reachable[a+b-jugs[0]][jugs[0]] = True
                # wont overflow
                else:
                    if not reachable[0][a+b]:
                        if n == a+b:
                            loopflag = False
                            break
                        newtodo.append((a+b, 0))
                        reachable[0][a+b] = True

                # empty a
                if not reachable[b][0]:
                    newtodo.append((0, b))
                    reachable[b][0] = True

                # empty b
                if not reachable[0][a]:
                    newtodo.append((a, 0))
                    reachable[0][a] = True
            todo = newtodo
        print moves


    if j == 3:
        reachable = [[[False]*(jugs[0]+1) for i in range(jugs[1]+1)] for _ in range(jugs[2]+1)]
        reachable[0][0][0] = True

        todo = [(0, 0, 0)]

        moves = 0
        loopflag = n != 0
        while loopflag:
            moves += 1

            newtodo = []

            for a, b, c in todo:
                # Fill a
                if not reachable[c][b][jugs[0]]:
                    if n == jugs[0]:
                        loopflag = False
                        break
                    newtodo.append((jugs[0], b, c))
                    reachable[c][b][jugs[0]] = True

                # Fill b
                if not reachable[c][jugs[1]][a]:
                    if n == jugs[1]:
                        loopflag = False
                        break
                    newtodo.append((a, jugs[1], c))
                    reachable[c][jugs[1]][a] = True

                # Fill c
                if not reachable[jugs[2]][b][a]:
                    if n == jugs[2]:
                        loopflag = False
                        break
                    newtodo.append((a, b, jugs[2]))
                    reachable[jugs[2]][b][a] = True

                # Fill b with a
                # Would overflow
                if a+b > jugs[1]:
                    if not reachable[c][jugs[1]][a+b-jugs[1]]:
                        if n == jugs[1]:
                            loopflag = False
                            break

                        if n == a+b-jugs[1]:
                            loopflag = False
                            break

                        newtodo.append((a+b-jugs[1], jugs[1], c))
                        reachable[c][jugs[1]][a+b-jugs[1]] = True
                # wont overflaw
                else:
                    if not reachable[c][a+b][0]:
                        if n == a+b:
                            loopflag = False
                            break
                        newtodo.append((0, a+b, c))
                        reachable[c][a+b][0] = True

                # Fill a with b
                # Would overflow
                if a+b > jugs[0]:
                    if not reachable[c][a+b-jugs[0]][jugs[0]]:
                        if n == jugs[0]:
                            loopflag = False
                            break

                        if n == a+b-jugs[0]:
                            loopflag = False
                            break

                        newtodo.append((jugs[0], a+b-jugs[0], c))
                        reachable[c][a+b-jugs[0]][jugs[0]] = True
                # wont overflow
                else:
                    if not reachable[c][0][a+b]:
                        if n == a+b:
                            loopflag = False
                            break
                        newtodo.append((a+b, 0, c))
                        reachable[c][0][a+b] = True

                ###############################################################

                # Fill c with a
                # Would overflow
                if a+c > jugs[2]:
                    if not reachable[jugs[2]][b][a+c-jugs[2]]:
                        if n == jugs[2]:
                            loopflag = False
                            break

                        if n == a+c-jugs[2]:
                            loopflag = False
                            break

                        newtodo.append((a+c-jugs[2], b, jugs[2]))
                        reachable[jugs[2]][b][a+c-jugs[2]] = True
                # wont overflaw
                else:
                    if not reachable[a+c][b][0]:
                        if n == a+c:
                            loopflag = False
                            break
                        newtodo.append((0, b, a+c))
                        reachable[a+c][b][0] = True

                # Fill c with b
                # Would overflow
                if b+c > jugs[2]:
                    if not reachable[jugs[2]][b+c-jugs[2]][a]:
                        if n == jugs[2]:
                            loopflag = False
                            break

                        if n == b+c-jugs[2]:
                            loopflag = False
                            break

                        newtodo.append((a, b+c-jugs[2], jugs[2]))
                        reachable[jugs[2]][b+c-jugs[2]][a] = True
                # wont overflaw
                else:
                    if not reachable[b+c][0][a]:
                        if n == b+c:
                            loopflag = False
                            break
                        newtodo.append((a, 0, b+c))
                        reachable[b+c][0][a] = True


                # Fill b with c
                # Would overflow
                if c+b > jugs[1]:
                    if not reachable[c+b-jugs[1]][jugs[1]][a]:
                        if n == jugs[1]:
                            loopflag = False
                            break

                        if n == c+b-jugs[1]:
                            loopflag = False
                            break

                        newtodo.append((a, jugs[1], c+b-jugs[1]))
                        reachable[c+b-jugs[1]][jugs[1]][a] = True
                # wont overflaw
                else:
                    if not reachable[0][c+b][a]:
                        if n == c+b:
                            loopflag = False
                            break
                        newtodo.append((a, c+b, 0))
                        reachable[0][c+b][a] = True

                # Fill a with c
                # Would overflow
                if a+c > jugs[0]:
                    if not reachable[a+c-jugs[0]][b][jugs[0]]:
                        if n == jugs[0]:
                            loopflag = False
                            break

                        if n == a+c-jugs[0]:
                            loopflag = False
                            break

                        newtodo.append((jugs[0], b, a+c-jugs[0]))
                        reachable[a+c-jugs[0]][b][jugs[0]] = True
                # wont overflow
                else:
                    if not reachable[0][b][a+c]:
                        if n == a+b:
                            loopflag = False
                            break
                        newtodo.append((a+c, b, 0)) ####################
                        reachable[0][b][a+c] = True

                # empty a
                if not reachable[c][b][0]:
                    newtodo.append((0, b, c))
                    reachable[c][b][0] = True

                # empty b
                if not reachable[c][0][a]:
                    newtodo.append((a, 0, c))
                    reachable[c][0][a] = True

                # empty c
                if not reachable[0][b][a]:
                    newtodo.append((a, b, 0))
                    reachable[0][b][a] = True
            todo = newtodo
        print moves
