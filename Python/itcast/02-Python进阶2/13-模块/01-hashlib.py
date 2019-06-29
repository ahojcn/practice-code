import hashlib
t = hashlib.md5()
t.update(b"ahojcn")
print(t.hexdigest())
