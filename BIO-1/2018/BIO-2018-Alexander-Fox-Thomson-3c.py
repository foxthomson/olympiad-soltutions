
d = int(raw_input())

def partar(d, original):
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

                for i in range(1, d-2):
                    # Middle switches
                    if min(s[i], s[i+1]) < s[i+2] < max(s[i], s[i+1]) or min(s[i], s[i+1]) < s[i-1] < max(s[i], s[i+1]):
                        if s[:i] + s[i+1] + s[i] + s[i+2:] not in found:
                            newtodo.append(s[:i] + s[i+1] + s[i] + s[i+2:])
                            found.append(s[:i] + s[i+1] + s[i] + s[i+2:])

                # last switch
                if min(s[-2], s[-1]) < s[-3] < max(s[-2], s[-1]):
                    if s[:-2] + s[-1] + s[-2] not in found:
                        newtodo.append(s[:-2] + s[-1] + s[-2])
                        found.append(s[:-2] + s[-1] + s[-2])

            todo = newtodo
        return found

tot = 0

def findall(l, curr, d, allfound):
    if len(l) == 0:
        if curr not in allfound:
            allfound.extend(partar(d, curr))
            return 1
        return 0

    groups = 0
    for i, c in enumerate(l):
        groups += findall(l[:i] + l[i+1:], curr+c, d, allfound)

    return groups


l = map(str, range(1, d+1))
print findall(l, "", d, [])

# allfound = []
# groups = 0
# l = map(str, [1, 2, 3, 4, 5])
# for a in l:
#     l.remove(a)
#     for b in l:
#         l.remove(b)
#         for c in l:
#             l.remove(c)
#             for d in l:
#                 l.remove(d)
#                 if a+b+c+d+l[0] not in allfound:
#                     groups += 1
#                     allfound.extend(partar(5, a+b+c+d+l[0]))
#                 l.append(d)
#             l.append(c)
#         l.append(b)
#     l.append(a)
#
# print len(allfound)
# print groups
