import hashlib
import sys


data = input()
result = hashlib.sha256(data.encode())
print(result.hexdigest())
