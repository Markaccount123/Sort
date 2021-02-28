//#include"Stack.h"
////什么时候回使用到栈呢？比如说后入先出的场景，对于一个迷宫来说，有时候我可能会走到死胡同，此时我希望它能够退回到原来的位置，我就可以用这个来实现
////初始化
//void StackInit(Stack* pst)
//{
//	assert(pst);
//	//这种方式是有不好的地方的，因为但当你需要增容的时候，你就会发现，他的capacity初始化是0，那么你乘2依旧是0，所以建议一开始就给一个固定值
//	//pst->_a = NULL;
//	//pst->_top = 0;
//	//pst->_capacity = 0;
//	pst->_a = (STDateType*)malloc(sizeof(STDateType)*4);
//	pst->_top = 0;
//	pst->_capacity = 4;
//}
//
////销毁
//void StackDestory(Stack* pst)
//{
//	assert(pst);
//	free(pst->_a);
//	pst->_a = NULL;
//	pst->_top = pst->_capacity = 0;
//}
//
////入栈
//void StackPush(Stack* pst, STDateType x)
//{
//	assert(pst);
//	//空间不够则增容
//	if (pst->_top == pst->_capacity)
//	{
//		pst->_capacity *= 2;
//		STDateType* tmp = (STDateType*)realloc(pst->_a, sizeof(STDateType)*pst->_capacity);
//		if (tmp == NULL)
//		{
//			printf("内存不足\n");
//			exit(-1);
//		}
//		else
//		{
//			pst->_a = tmp;
//		}
//	}
//	pst->_a[pst->_top] = x;//你所定义的栈顶总是在你放入数据的下一个位置
//	pst->_top++;
//}
//
////出栈
//void StackPop(Stack* pst)
//{
//	assert(pst);
//	assert(pst->_top > 0);
//	--pst->_top;
//}
//
////获取数据个数
//int StackSize(Stack* pst)
//{
//	assert(pst);
//	return pst->_top;
//}
//
//
////返回1是空，返回0是非空
//int StackEmpty(Stack* pst)
//{
//	assert(pst);
//	return pst->_top == 0 ? 1 : 0;
//}
//
//
////获取栈顶的数据
//STDateType StackTop(Stack* pst)
//{
//	assert(pst);
//	assert(pst->_top > 0);
//	return pst->_a[pst->_top - 1];//你所定义的栈顶总是在你放入数据的下一个位置
//}