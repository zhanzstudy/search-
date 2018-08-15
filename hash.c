
#include <stdio.h>
#include <malloc.h>

#define HashSize 18 //Hash表长度
#define InitNum -1

typedef struct
{
    int count; //数据元素个数
    int *data; //动态分配数组
}HashTable;


//hash算法，取余法
int Hash(int k)
{
    return k % HashSize;
}

//初始化哈希表
int InitHashTable(HashTable *H)
{
    H->count = HashSize;
    //动态分配
    H->data = (int *) malloc(HashSize * sizeof(int));

    int i;
    //初始化赋值
    for (i = 0 ; i < HashSize; i++) {
        H->data[i] = InitNum;
    }
    return 1;
}

//插入
int InsertHashTable(HashTable H, int k, int *addr)
{
    //求散列地址
    *addr = Hash(k);
    //判断是否冲突
    while(H.data[*addr] != InitNum) {
        //开放定制法的线性探测
        *addr = (*addr + 1) % HashSize;
    }

    H.data[*addr] = k;
}

//查找算法
int Search(HashTable *H, int k, int *addr)
{
    //求散列地址
    *addr = Hash(k);
    //如果没找到
    while(H->data[*addr] != k)
    {
        //开方定址法的线性探测
        *addr = (*addr + 1) % HashSize;
        //如果没找到
        if (H->data[*addr] == InitNum || *addr == Hash(k)) {
            return 0;
        }
    }
    return *addr;
}

void main()
{
    HashTable H;
    int i;
    i = InitHashTable(&H);

    int addr;
    InsertHashTable(H, 8,  &addr);
    InsertHashTable(H, 18,  &addr);
    InsertHashTable(H, 7,  &addr);
    InsertHashTable(H, 5,  &addr);
    InsertHashTable(H, 4,  &addr);
    
    int a;
    a = Search(&H, 8, &addr);
    /*printf("%d\n", a);*/

}
