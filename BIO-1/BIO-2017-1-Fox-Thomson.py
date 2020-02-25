row = raw_input().upper()

while len(row) > 1:
    newrow = ""
    for i in range(len(row) - 1):
        symbols = row[i:i+2]
        if symbols[0] == symbols[1]:
            newsym = symbols[0]
        else:
            for sym in "RGB":
                if sym not in symbols:
                    newsym = sym
        newrow = newrow + newsym
    row = newrow

print row
