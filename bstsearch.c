#include <stdio.h>
#include <malloc.h>

typedef int DataType;
//定义结构体
typedef struct BiTNode
{
    DataType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//二叉排序树查找
int BstSearch(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T) {
        *p = f;
        return 0;
    } else if (key == T->data) {
        *p = T;
        return 1;
    }else if (key < T->data) {
        //左孩子递归查找
        return BstSearch(T->lchild, key, T, p);
    }else {
        //右孩子递归查找
        return BstSearch(T->rchild, key, T, p);
    }

}

//二叉排序数插入
int BstInsert(BiTree T, int key)
{
    BiTree p,s;
    //查询节点是否存在
    if (!BstSearch(T, key, NULL, &p)) {
        s = (BiTree) malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        //新根节点
        if (!p) {
            T = s;
        }
        //比较插入节点和父节点大小
        if (p->data < key) {
            p->rchild = s;
        }else if (p->data > key) {
        
            p->lchild = s;
        }
        return 1;
    }else {
        return 0;
    }

}

void main()
{

    int n[5] = {3,5,10,9,11};
    int i;
    BiTree T;
    for(i = 0; i <= 4; i++) {
        BstInsert(T, n[i]);
    }
}
