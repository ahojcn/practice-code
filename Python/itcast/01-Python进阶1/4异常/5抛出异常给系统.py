try:
    print(1 / 0)
except Exception as e:
    print("%s".center(50, ".") % e)
    raise
