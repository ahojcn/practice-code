info = [
    {"name": "xiaoming", "age": 20},
    {"name": "laowang", "age": 25},
    {"name": "ahojcn", "age": 21}
]

print(info)

"""匿名函数"""
info.sort(key=lambda x:x["name"])

print(info)

info.sort(key=lambda x:x["age"])

print(info)