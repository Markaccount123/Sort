//#include"Stack.h"
////ʲôʱ���ʹ�õ�ջ�أ�����˵�����ȳ��ĳ���������һ���Թ���˵����ʱ���ҿ��ܻ��ߵ�����ͬ����ʱ��ϣ�����ܹ��˻ص�ԭ����λ�ã��ҾͿ����������ʵ��
////��ʼ��
//void StackInit(Stack* pst)
//{
//	assert(pst);
//	//���ַ�ʽ���в��õĵط��ģ���Ϊ��������Ҫ���ݵ�ʱ����ͻᷢ�֣�����capacity��ʼ����0����ô���2������0�����Խ���һ��ʼ�͸�һ���̶�ֵ
//	//pst->_a = NULL;
//	//pst->_top = 0;
//	//pst->_capacity = 0;
//	pst->_a = (STDateType*)malloc(sizeof(STDateType)*4);
//	pst->_top = 0;
//	pst->_capacity = 4;
//}
//
////����
//void StackDestory(Stack* pst)
//{
//	assert(pst);
//	free(pst->_a);
//	pst->_a = NULL;
//	pst->_top = pst->_capacity = 0;
//}
//
////��ջ
//void StackPush(Stack* pst, STDateType x)
//{
//	assert(pst);
//	//�ռ䲻��������
//	if (pst->_top == pst->_capacity)
//	{
//		pst->_capacity *= 2;
//		STDateType* tmp = (STDateType*)realloc(pst->_a, sizeof(STDateType)*pst->_capacity);
//		if (tmp == NULL)
//		{
//			printf("�ڴ治��\n");
//			exit(-1);
//		}
//		else
//		{
//			pst->_a = tmp;
//		}
//	}
//	pst->_a[pst->_top] = x;//���������ջ����������������ݵ���һ��λ��
//	pst->_top++;
//}
//
////��ջ
//void StackPop(Stack* pst)
//{
//	assert(pst);
//	assert(pst->_top > 0);
//	--pst->_top;
//}
//
////��ȡ���ݸ���
//int StackSize(Stack* pst)
//{
//	assert(pst);
//	return pst->_top;
//}
//
//
////����1�ǿգ�����0�Ƿǿ�
//int StackEmpty(Stack* pst)
//{
//	assert(pst);
//	return pst->_top == 0 ? 1 : 0;
//}
//
//
////��ȡջ��������
//STDateType StackTop(Stack* pst)
//{
//	assert(pst);
//	assert(pst->_top > 0);
//	return pst->_a[pst->_top - 1];//���������ջ����������������ݵ���һ��λ��
//}