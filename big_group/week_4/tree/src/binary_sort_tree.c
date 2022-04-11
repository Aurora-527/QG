#include"C:/Users/AURORA/Desktop/QG/ѵ��Ӫ������/QGѵ��Ӫ�����ܴ���/�����ͷ�ļ�/inc/binary_sort_tree.h"
/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr L)
{
	int i;
	int test;/* test���ڼ�������Ƿ�Ϸ� */
	printf("���������������\n");
	i=input_detection(test);
	L->root=(NodePtr)malloc(sizeof(Node)); /* ��ʼ�����ڵ� */
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
	if(bt->value==x) /* �������������������������ͬ */
	{
		printf("�����������޷�����������ͬ�����ݣ�\n");
		return false;
	}
	/* ���Ҫ��������ݱȽ�С,��ô��Ҫ����� */
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
	else /* ��֮���ұ� */
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
	Node *p,*f,*s,*q; /* ������ʱ������ */
	p=L->root;
	f=NULL;
	while(p)/* ����Ϊkey�Ĵ�ɾ����� */
	{
		if(p->value==key)
			break;/* �ҵ���break */
		f=p;/* fָ��p��˫�׽�� */
		if(p->value>key)
			p=p->left;
		else
			p=p->right;
	}
	if(p==NULL)
		return false; /* �Ҳ������˳� */
	if(p->left==NULL) /* ��p�������� */
	{
		if(f==NULL)
			free(p); /* pΪԭ���ĸ� */
		else if(f->left==p) /* pΪf�������� */
			f->left=p->right; /* ��p������������f���������� */
		else /* pΪf�������� */
			f->right=p->right; /* ��p������������f���������� */
		free(p);
	}
	else/* p�������� */
	{
		q=p;
		s=q->left;
		while(s->right)
		{
			q=s;
			s=s->right;/* ��p���������в��������½�� */
		}
		if(q==p)
			q->left=s->left;
		else
			q->right=s->left;/* ��s������������s��˫�׽��p�������� */
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
//����ָ��ֵ
Status BST_search(BinarySortTreePtr L, ElemType key)
{
	NodePtr T = L->root;
	while(T != NULL && key != T->value)
	{
		if(key < T->value) /* С�ڣ������������Ͻ��в��� */
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
/* ��������ǵݹ� */
Status BST_preorderI(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	NodePtr stack[50], node;  /* stack���ڳ䵱ջ��node��Ϊ��ʱ��� */
	int k = -1;
	k++;
	/* ����һ��ջ */
	stack[k] = L->root; /* �����ڵ���ջ */
	while (k > -1)
	{
		/* ��ջ */
		node = stack[k--];
		visit(node);
		/* �Ȱ��������Ž�ȥ��ջ���Ƚ�ȥ���������������������ȳ� */
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
/* ��������ݹ� */
Status BST_preorderR(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	if(L->root)
	{
		visit(L->root);
		BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree)); /* �½�һ�������ڵݹ� */
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
/* ��������ǵݹ� */
Status BST_inorderI(BinarySortTreePtr L, void (*visit)(NodePtr))
{

	NodePtr stack[50], node; /* stack���ڳ䵱ջ��node��Ϊ��ʱ���*/
	int top = 0;
	node = L->root;
	while (node != NULL || top > 0)
	{
		/* �����е��������ڵ���ջ */
		while (node != NULL)
		{
			stack[++top] = node;
			node = node->left;
		}
		/*  ����ҽڵ�Ϊ�յĻ���ִ��������� */
		node = stack[top--];
		visit(node);
		/* ɨ���ҽڵ� */
		node = node->right;
	}
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/* ��������ݹ� */
Status BST_inorderR(BinarySortTreePtr L, void (*visit)(NodePtr))
{
//�������
	if(L->root)
	{
		BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree)); /* �½�һ�������ڵݹ� */
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
/* ��������ǵݹ� */
Status BST_postorderI(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	Node *p = L->root;
	Node *stack[50]; /* stack���ڳ䵱ջ��p��have_visited��Ϊ��ʱ���*/
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
/* ��������ݹ� */
Status BST_postorderR(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	if(L->root)
	{
		BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree)); /* �½�һ�������ڵݹ� */
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
/* ������� */
Status BST_levelOrder(BinarySortTreePtr L, void (*visit)(NodePtr))
{
	NodePtr stack[50], node;  /* stack���ڳ䵱���У�node��Ϊ��ʱ��� */
	node = L->root;
	int front = 0;  // ʹ�� front�� rearģ�����
	int rear = 0;

	stack[rear++] = node;

	while (front != rear)
	{

		node = stack[front++]; /* ģ����У��Ȼ�ȡfront��ǰԪ�أ�Ȼ����ָ�� front++ λԪ��  */
		visit(node);

		/* ������������� */
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

void printValue(NodePtr node) /* ���ڴ�ӡ���� */
{
	printf("%d ",node->value);
}
