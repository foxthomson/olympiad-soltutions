flipflops = raw_input()
pos = raw_input()
n = int(raw_input())

letters = "ABCDEFGHIJKLMNOPQRSTUVWXY"

direction = {}

for l in letters:
    direction[l] = 0

def options(pos):
    going = pos[1]
    gone = pos[0]

    i = letters.index(going)

    if going <= "D":
        if gone <= "D":
            return letters[i*2+4:i*2+6]
        else:
            return letters[3-i]
    elif going <= "L":
        if gone <= "D":
            if going == "L":
                return "TM"
            else:
                return letters[i+8:i+10]
        else:
            return letters[i/2-2]
    elif going <= "T":
        if gone <= "L":
            return letters[i/2+14]
        else:
            if going == "M":
                return "LE"
            else:
                return letters[i-9:i-7]
    else:
        if gone >= "U":
            return letters[i*2-28:i*2-26]
        else:
            return letters[i-1 if i%2 else i+1]
# print " ".join(["AD", "AF", "FA", "FO", "OF", "OG", "FN", "OV", "TL", "LM", "ML", "ME", "EM", "NU", "UM", "DL", "UV", "QW"])
# print "\n".join(map(str, zip(["UV", "VU", "WX", "XW", "AD", "AF", "FA", "FO", "OF", "OG", "FN", "OV", "TL", "LM", "ML", "ME", "EM", "NU", "UM", "DL", "UV", "QW"], map(options, ["UV", "VU", "WX", "XW", "AD", "AF", "FA", "FO", "OF", "OG", "FN", "OV", "TL", "LM", "ML", "ME", "EM", "NU", "UM", "DL", "UV", "QW"]))))

for i in range(n):
    opts = options(pos)
    if len(opts) == 1:
        if pos[1] not in flipflops:
            # Check what side entering from
            if pos[0] <= "L":
                if pos[1] <= "D":
                    if letters.index(pos[0]) % 2 == 0:
                        direction[pos[1]] = 0
                    else:
                        direction[pos[1]] = 1
                else:
                    if (letters.index(pos[1]) - letters.index(pos[0])) % 2 == 0:
                        direction[pos[1]] = 1
                    else:
                        direction[pos[1]] = 0
            else:
                if pos[1] <= "L":
                    if (letters.index(pos[1]) - letters.index(pos[0])) % 2 == 0:
                        direction[pos[1]] = 0
                    else:
                        direction[pos[1]] = 1
                else:
                    if letters.index(pos[0]) % 2 == 0:
                        direction[pos[1]] = 0
                    else:
                        direction[pos[1]] = 1
        pos = pos[1] + opts
    else:
        newpos = pos[1] + opts[direction[pos[1]]]
        if pos[1] in flipflops:
            direction[pos[1]] = 1-direction[pos[1]]
        pos = newpos
print pos
