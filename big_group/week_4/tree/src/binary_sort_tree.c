#include"C:/Users/AURORA/Desktop/QG/训练营第四周/QG训练营第四周大组/代码和头文件/inc/binary_sort_tree.h"
/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr L)
{
	int i;
	int test;/* test用于检测输入是否合法 */
	printf("请输入根结点的数据\n");
	i=input_detection(test);
	L->root=(NodePtr)malloc(sizeof(Node)); /* 初始化根节点 */
	L->root->left=NULL;
	L->root->right=NULL;
	L->root->value=i;
	return true;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr L, ElemType x)
{
	NodePtr bt = L->root;
	BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	if(bt->value==x) /* 输入的数据与树上已有数据相同 */
	{
		printf("二叉排序树无法插入两个相同的数据！\n");
		return false;
	}
	/* 如果要插入的数据比较小,那么就要插左边 */
	if (bt->value > x)
	{
		if (bt->left == NULL)
		{
			NodePtr s = (NodePtr)malloc(sizeof(Node));
			s->value = x;
			s->left = s->right = NULL;
			bt->left = s;
		}
		else
		{
			p->root = L->root->left;
			BST_insert(p, x);
		}
	}
	else /* 反之插右边 */
	{
		if (bt->right == NULL)
		{
			NodePtr s = (NodePtr)malloc(sizeof(Node));
			s->value = x;
			s->left = s->right = NULL;
			bt->right = s;
		}
		else
		{
			p->root = L->root->right;
			BST_insert(p, x);
		}
	}
	return true;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr L, ElemType key)
{
	Node *p,*f,*s,*q; /* 用于临时保存结点 */
	p=L->root;
	f=NULL;
	while(p)/* 查找为key的待删除结点 */
	{
		if(p->value==key)
			break;/* 找到则break */
		f=p;/* f指向p的双亲结点 */
		if(p->value>key)
			p=p->left;
		else
			p=p->right;
	}
	if(p==NULL)
		return false; /* 找不到则退出 */
	if(p->left==NULL) /* 若p无左子树 */
	{
		if(f==NULL)
			free(p); /* p为原树的根 */
		else if(f->left==p) /* p为f的左子树 */
			f->left=p->right; /* 把p的右子树链到f的左子树上 */
		else /* p为f的右子树 */
			f->right=p->right; /* 把p的右子树链到f的右子树上 */
		free(p);
	}
	else/* p有左子树 */
	{
		q=p;
		s=q->left;
		while(s->right)
		{
			q=s;
			s=s->right;/* 在p的左子树中查找最右下结点 */
		}
		if(q==p)
			q->left=s->left;
		else
			q->right=s->left;/* 把s的左子树链到s的双亲结点p的右子树 */
		p->value=s->value;
		free(s);
	}
}
/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
//查找指定值
Status BST_search(BinarySortTreePtr L, ElemType key)
{
	NodePtr T = L->root;
	while(T != NULL && key != T->value)
	{
		if(key < T->value) /* 小于，则在左子树上进行查找 */
			T = T->left;
		else
			T = T->right;
	}
	return !(T == NULL) ;

}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/* 先序遍历非递归 */
Status BST_preorderI(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	NodePtr stack[50], node;  /* stack用于充当栈，node作为临时结点 */
	int k = -1;
	k++;
	/* 仿照一个栈 */
	stack[k] = L->root; /* 将根节点入栈 */
	while (k > -1)
	{
		/* 出栈 */
		node = stack[k--];
		visit(node);
		/* 先把右子树放进去，栈是先进去后出，所以下面的左子树先出 */
		if (node->right != NULL)
		{
			stack[++k] = node->right;
		}
		if (node->left != NULL)
		{
			stack[++k] = node->left;
		}
	}
}
/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/* 先序遍历递归 */
Status BST_preorderR(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	if(L->root)
	{
		visit(L->root);
		BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree)); /* 新建一棵树用于递归 */
		p->root= L->root->left;
		BST_preorderR(p, visit);
		p->root= L->root->right;
		BST_preorderR(p, visit);
	}
	return true;
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/* 中序遍历非递归 */
Status BST_inorderI(BinarySortTreePtr L, void (*visit)(NodePtr))
{

	NodePtr stack[50], node; /* stack用于充当栈，node作为临时结点*/
	int top = 0;
	node = L->root;
	while (node != NULL || top > 0)
	{
		/* 将所有的左子树节点入栈 */
		while (node != NULL)
		{
			stack[++top] = node;
			node = node->left;
		}
		/*  如果右节点为空的话，执行下列语句 */
		node = stack[top--];
		visit(node);
		/* 扫描右节点 */
		node = node->right;
	}
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/* 中序遍历递归 */
Status BST_inorderR(BinarySortTreePtr L, void (*visit)(NodePtr))
{
//中序遍历
	if(L->root)
	{
		BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree)); /* 新建一棵树用于递归 */
		p->root= L->root->left;
		BST_inorderR(p,visit);
		visit(L->root);
		p->root = L->root->right;
		BST_inorderR(p,visit);
	}
	return true;
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/* 后序遍历非递归 */
Status BST_postorderI(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	Node *p = L->root;
	Node *stack[50]; /* stack用于充当栈，p，have_visited作为临时结点*/
	int num = 0;
	Node *have_visited = NULL;
	while (NULL != p || num>0)
	{
		while (NULL != p)
		{
			stack[num++] = p;
			p = p->left;
		}
		p = stack[num - 1];
		if (NULL == p->right || have_visited == p->right)
		{
			visit(p);
			num--;
			have_visited = p;
			p = NULL;
		}
		else
		{
			p = p->right;
		}
	}

}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/* 后序遍历递归 */
Status BST_postorderR(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	if(L->root)
	{
		BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree)); /* 新建一棵树用于递归 */
		p->root= L->root->left;
		BST_postorderR(p,visit);
		p->root = L->root->right;
		BST_postorderR(p,visit);
		visit(L->root);
	}
	return true;
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/* 层序遍历 */
Status BST_levelOrder(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	NodePtr stack[50], node;  /* stack用于充当队列，node作为临时结点 */
	node = L->root;
	int front = 0;  // 使用 front， rear模拟队列
	int rear = 0;

	stack[rear++] = node;

	while (front != rear)
	{

		node = stack[front++]; /* 模拟队列，先获取front当前元素，然后在指向 front++ 位元素  */
		visit(node);

		/* 左右子树入队列 */
		if (node->left != NULL)
		{
			stack[rear++] = node->left;
		}

		if (node->right != NULL)
		{
			stack[rear++] = node->right;
		}
	}
}

void printValue(NodePtr node) /* 用于打印函数 */
{
	printf("%d ",node->value);
}
