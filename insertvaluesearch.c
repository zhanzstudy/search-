#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 10
typedef int DataType;

typedef struct {
    DataType data[MAXSIZE];
    int length;
}SqList;

//初始化线性表

void initSqList(SqList *mylist)
{
    int i;
    for (i = 0; i <= MAXSIZE; i++)
    {
        mylist->data[i] = 0;
    }
    mylist->length = 0;
}

//线性表插入
int insertSqlList(SqList *mylist, int index, DataType e)
{
    if (mylist->length >= MAXSIZE) {
        return 0;
    }
    if (index < 0)
    {
        index = mylist->length - 1;    
    }

    int i;
    //根据插入位置，挪动元素
    for (i = mylist->length; i >= index; i-- )
    {
        mylist->data[i + 1] = mylist->data[i];
    }

    //插入元素
    mylist->data[index] = e;
    mylist->length++;
    return 1;
}

//插值查找
int search(SqList *mylist, DataType e)
{
    int low,high,mid;

    low = 1;
    high = mylist->length;
    
    
    while (low <= high)
    {
        //mid值算法
        mid = low + (high - low) * (e - mylist->data[low]) / (mylist->data[high] - mylist->data[low]);
        //如果查找的值比线性表的小 改变最高下标,如果大，改变最低下标，相等返回位置
        if(e < mylist->data[mid])
        {
            high = mid - 1;
        }else if (e > mylist->data[mid]) {
            low = mid + 1;
        }else {
            return mid;
        }
    }

    return 0;

}


void main()
{
    SqList mylist;
    initSqList(&mylist);

    insertSqlList(&mylist, 1, 3);
    insertSqlList(&mylist, 2, 7);
    insertSqlList(&mylist, 3, 8);
    insertSqlList(&mylist, 4, 10);
    insertSqlList(&mylist, 5, 15);
    insertSqlList(&mylist, 6, 17);
    insertSqlList(&mylist, 5, 12);
    
    printf("%d\n", mylist.data[7]);
    int a;
    a = search(&mylist, 12);
    printf("%d\n", a);
}
