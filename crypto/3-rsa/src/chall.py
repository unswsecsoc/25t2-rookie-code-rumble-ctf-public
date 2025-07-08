from Crypto.Util.number import isPrime
from secrets import a, b, c, x, y, z, flag_part_1, flag_part_2, flag_part_3


n1 = a * x
n2 = b * y
n3 = c * z
e = 65537

assert z - y == y - x
assert c - b == b - a
assert all([isPrime(prime) for prime in (a, b, c, x, y, z)]) # checks all numbers are prime

flag1 = pow(int.from_bytes(flag_part_1, "big"), e, n1)
flag2 = pow(int.from_bytes(flag_part_2, "big"), e, n2)
flag3 = pow(int.from_bytes(flag_part_3, "big"), e, n3)

print("Encrypted flags:")
print(f"{flag1 = }")
print(f"{flag2 = }")
print(f"{flag3 = }")

print("Public keys:")
print(f"{n1 = }")
print(f"{n2 = }")
print(f"{n3 = }")


# Example decryption:
# phi = (a-1)*(x-1)
# d = pow(e, -1, phi)
# decrypted = pow(flag1, d, n1)
# print(decrypted.to_bytes(29, "big"))