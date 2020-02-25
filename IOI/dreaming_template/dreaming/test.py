import glob, os
os.chdir("/home/contestant/practice/dreaming")
for file in sorted(glob.glob("*.in")):
    os.system("/home/contestant/practice/dreaming_template/dreaming/dreaming {} {}".format(file, file[:-2]+"out"))
