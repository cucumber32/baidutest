#include<iostream>
using namespace std;

#define INITSIZE 100 // ˳���ĳ�ʼ��С

template <typename ElemType>
class SqList {
	// ˳��������
	ElemType* data;	// ˳���̬�洢�ռ���׵�ַ
	int listSize;	// ˳���Ŀǰ�ѷ���Ĵ洢�ռ��С
	int length;		// ˳���ǰ����

public:
	// ˳���ķ���
	void InitList(SqList& L);						// ��ʼ�����Ա�
	//Elemtype getLength(SqList L);					// ��ȡ���Ա�ĳ���
	//Elemtype locateElem(SqList L, int e);			// ���Ҿ���ֵ��Ԫ��
	//Elemtype GetElem();
	bool ListInsert(SqList& L, int i, ElemType e);	// ����Ԫ��e
};

/****** ��ʼ�����Ա� ****/
template <typename ElemType>
void SqList<ElemType>::InitList(SqList& L) {
	L.length = 0;
	L.data = new ElemType[INITSIZE]; // ��̬����洢�ռ䡾�����Ҫ���ӳ��ȣ������¿��ٿռ䣬�����ݸ��ƽ��¿ռ䣬�ͷžɿռ�
	L.listSize = INITSIZE;
}

/****** ����Ԫ��e ******/
template <typename ElemType>
bool SqList<ElemType>::ListInsert(SqList& L, int i, ElemType e) {
	if (i > L.length + 1 || i < 1) {
		return false;
	}
	if (L.listSize == L.length) {
		return false;
	}
	for (int j = L.length; j-1 > i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}