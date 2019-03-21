/*
 * 只在堆上创建对象的类
 */
class HeapOnly
{
  public:
    static HeapOnly *getHeapOnlyObj()
    {
        return new HeapOnly;
    }

  private:
    HeapOnly() {}   // 不允许外部在堆上 new 对象

    HeapOnly(HeapOnly const &) = delete;  // 不允许外部通过拷贝创建栈上的对象
};