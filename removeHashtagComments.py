#This script removes all hashtag comments from a given file

from sys import argv
from sys import stdout

try:
    inputFile = open(argv[1])
except IndexError:
    stdout.write("No input file?")
    exit(0)
except FileNotFoundError:
    stdout.write("File not found:\n")
    stdout.write(argv[1])
    exit(0)

file = "" #We're going to collect all the information from the file
for i in inputFile:
    file += i

#DON'T FORGET TO CLOSE THE FILE
inputFile.close()

#Move from a string to a list
items = []
for i in file:
    items.append(i)

#Delete every hashtag and every character after it on whatever line its on
for i in items:
    if i == "#":
        index = items.index("#")
        while items[index] != "\n":
            del items[index]

#We're going to walk backwards from the end of our file name
count = len(argv[1]) - 1
#We're going to assume no change will be made
change = False

while count >= 0:
    if argv[1][count] == '.':
        change = True
        break
    count -= 1

if change:
    argv[1] = argv[1][:count] + "_clean" + argv[1][count:]
else:
    argv[1] = argv[1] + "_clean"

#By this time, argv[1] will have been changed one way or the other,
#So we're not editting the original file
outputFile = open(argv[1], 'w+')

for i in items:
    outputFile.write(i)

#DON'T FORGET TO CLOSE THE FILE
outputFile.close()

print("Your comment-free file has been written to " + argv[1])
