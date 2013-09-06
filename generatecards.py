writefile = open('cards2.txt', 'w')
writefile.write("red 0")
colors = {1:'red', 2:'blue', 3:'green', 4:'yellow'}
actions = {1:' draw2 ', 2: ' skip ', 3: ' reverse '}

for i in range(1, 10):
   writefile.write(" red ")
   writefile.write(unichr(i+48))
   writefile.write(" red ")
   writefile.write(unichr(i+48))

writefile.write('\n')

writefile.write("blue 0")

for i in range(1, 10):
   writefile.write(" blue ")
   writefile.write(unichr(i+48))
   writefile.write(" blue ")
   writefile.write(unichr(i+48))

writefile.write('\n')

writefile.write("green 0")

for i in range(1, 10):
   writefile.write(" green ")
   writefile.write(unichr(i+48))
   writefile.write(" green ")
   writefile.write(unichr(i+48))

writefile.write('\n')

writefile.write("yellow 0")

for i in range(1, 10):
   writefile.write(" yellow ")
   writefile.write(unichr(i+48))
   writefile.write(" yellow ")
   writefile.write(unichr(i+48))

writefile.write('\n')

for i in range(1,5):
   for j in range(1,4):
      writefile.write(colors[i])
      writefile.write(actions[j])
      writefile.write(colors[i])
      writefile.write(actions[j])

writefile.write('\n')
for i in range(1,5):
   writefile.write('wild ')

for i in range(1,5):
   writefile.write('wilddraw4 ')
