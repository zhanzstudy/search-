#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 10
typedef int DataType;
typedef struct
{
    //整形数组
    DataType data[MAXSIZE];
    //数组的长度
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
int InsertList(SqList *mylist, int index, DataType e)
{
    //判断插入位置
    if (index < 0 || index > MAXSIZE)
    {
        index = mylist->length - 1;
    }

    int i;
    
    //插入位置后的数据往后挪
    for (i = mylist->length - 1; i >= index; i--)
    {
        mylist->data[i + 1] = mylist->data[i];
    }
    //插入数据
    mylist->data[index] = e;
    //长度加1
    mylist->length++;
}

int binary_search(SqList *mylist, DataType e)
{
    int low,high,mid;
    //最低下标位置
    low = 1;
    //最高小标位置
    high = mylist->length;

    while(low <= high)
    {
        //折半（二分）
        mid = (low + high) / 2;

        if (e < mylist->data[mid]) {
            high = mid - 1;
        }else if (e >mylist->data[mid]) {
            low = mid + 1;
        }else {
            return mid;
        }
    }
    return 0;
}
