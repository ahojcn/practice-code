a = filter(lambda x:x%2, [1,2,3,4])
for i in a:
    print(i, end=' ')
print()


b = filter(None, "she")
for i in b:
    print(i, end=' ')
print()