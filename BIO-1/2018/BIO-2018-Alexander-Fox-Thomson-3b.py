
d = int(raw_input())
original = raw_input()

def partar(d, original, searched, longest):
    searched.append(original)

    switches = -1
    todo = [original]
    found = [original]

    if d in (1, 2):
        print 0
    # elif d == 3:
    #     print int(original not in ("123", "321"))
    else:
        while len(todo) > 0:
            switches += 1

            newtodo = []

            for s in todo:
                # First switch
                if min(s[0], s[1]) < s[2] < max(s[0], s[1]):
                    if s[1] + s[0] + s[2:] not in found:
                        newtodo.append(s[1] + s[0] + s[2:])
                        found.append(s[1] + s[0] + s[2:])
                        if s[1] + s[0] + s[2:] not in searched:
                            longest = partar(d, s[1] + s[0] + s[2:], searched, longest)

                for i in range(1, d-2):
                    # Middle switches
                    if min(s[i], s[i+1]) < s[i+2] < max(s[i], s[i+1]) or min(s[i], s[i+1]) < s[i-1] < max(s[i], s[i+1]):
                        if s[:i] + s[i+1] + s[i] + s[i+2:] not in found:
                            newtodo.append(s[:i] + s[i+1] + s[i] + s[i+2:])
                            found.append(s[:i] + s[i+1] + s[i] + s[i+2:])
                            if s[:i] + s[i+1] + s[i] + s[i+2:] not in searched:
                                longest = partar(d, s[:i] + s[i+1] + s[i] + s[i+2:], searched, longest)

                # last switch
                if min(s[-2], s[-1]) < s[-3] < max(s[-2], s[-1]):
                    if s[:-2] + s[-1] + s[-2] not in found:
                        newtodo.append(s[:-2] + s[-1] + s[-2])
                        found.append(s[:-2] + s[-1] + s[-2])
                        if s[:-2] + s[-1] + s[-2] not in searched:
                            longest = partar(d, s[:-2] + s[-1] + s[-2], searched, longest)

            todo = newtodo

        if switches == 16: print original
        return max(longest, switches)
print partar(d, original, [], 0)
