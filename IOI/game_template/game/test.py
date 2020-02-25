import glob, os, time
os.chdir("/home/contestant/practice/game")
for file in sorted(glob.glob("*.in")):
    # print file
    os.system("/home/contestant/practice/game_template/game/game {} {}".format(file, file[:-2]+"out"))
    time.sleep(13)
