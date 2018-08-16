
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
//递归构建斐波那契数列
int ft(int i)
{
    if (i < 2)
    {
        return i == 0 ? 0 : 1;
    }

    return ft(i - 1) + ft(i - 2);
}

//斐波那契查找
int search(SqList *mylist, int f[] ,DataType e)
{
    int low,high,mid,k;

    low = 1;
    high = mylist->length;

    //high处于斐波那契数列的位置
    while(mylist->length > f[k] - 1) {
        k++;
    }

    //将不满的数值补全
    int i;
    for(i = mylist->length; i <= f[k] - 1; i++)
    {
        mylist->data[i] = mylist->data[mylist->length];
    }

    while(low <= high)
    {
        mid = low + f[k - 1] - 1; 

        if (e > mylist->data[mid]) {
            low = mid + 1;
            //斐波那契数列下标减2为
            k = k -2;
        
        }else if (e < mylist->data[mid]) {
            high = mid - 1;
            //斐波那契数列下标减1位
            k = k - 1;
            
        }else {
            //小于等于数组的长度 则是查找到的位置，否则补全数据
            if (mid <= mylist->length) {
                return mid;
            }else {
                return mylist->length;
            }
        }
    }
    return 0;

}

void main()
{


}
