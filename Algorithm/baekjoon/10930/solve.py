import hashlib

data = input()
result = hashlib.sha256(data.encode())
print(result.hexdigest())
