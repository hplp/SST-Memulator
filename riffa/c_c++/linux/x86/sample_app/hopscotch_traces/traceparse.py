import re

# File to write DRAMsim traces to
file0 = open('rw_scatter_gather.trace', 'w')

# File to read from using readline()
file1 = open('rw_scatter_gather.out', 'r')
count = 0

while True:
    count += 1

    # Get next line from file
    line = file1.readline()

    # if line is empty
    # end of file is reached
    if not line:
        break
    # if count > 100000:
    #     break

    if (": Write" in line) and ("size 64" in line):
        m = re.search('address (.+?) ', line)
        if m:
            address = m.group(1)
        else:
            address = ""
            print(count, " ERROR address not found in Write")
            break
        m = re.search('^(.+?):', line)
        if m:
            tick = int(int(m.group(1))/1000)
        L = "{} WRITE   {}\n".format(address, tick)
        file0.writelines((L))

    if ((": Read" in line) or (": IFetch" in line)) and ("size 64" in line):
        m = re.search('address (.+?) ', line)
        if m:
            address = m.group(1)
        else:
            address = ""
            print(count, " ERROR address not found in Read")
            break
        m = re.search('^(.+?):', line)
        if m:
            tick = int(int(m.group(1))/1000)
        L = "{} READ   {}\n".format(address, tick)
        file0.writelines((L))

print(tick+10000) # print last tick

file1.close()
file0.close()
