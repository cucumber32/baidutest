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
	void printList(SqList& L);						// ������Ա�
	bool ListInsert(SqList& L, int i, ElemType e);	// ����Ԫ��e
	bool ListDelete(SqList& L, int i, ElemType& e); // ɾ����i��Ԫ��
	ElemType GetElem(SqList L, int i);				// ��ѯ��i��Ԫ��
	int locateElem(SqList L, ElemType e);			// ����ֵΪe��Ԫ�ش���
	int getLength(SqList L);						// ��ȡ���Ա�ĳ���

	// ��ϰ
	bool deleteMinElem(SqList &L, ElemType& e);								// ɾ����Сֵ��Ԫ�أ�����Ψһ��
	void ListReverse(SqList& L);											// ����˳���
	bool deleteElem(SqList& L, ElemType e);									// ɾ������ֵΪe��Ԫ��
	bool deleteSeqElemFromMin2Max(SqList& L, ElemType min, ElemType max);	// ɾ�������min-max֮�������Ԫ��
	bool deleteElemFromMin2Max(SqList& L, ElemType min, ElemType max);		// ɾ��˳�����min-max֮�������Ԫ�أ�����min��max��
	void SingleList(SqList& L);												// ����˳���ȥ��
	SqList unionSqList(SqList L1, SqList L2);								// �ϲ���������˳���
};

/****** ���ߺ�����������Ա� ********/
template <typename ElemType>
void SqList<ElemType>::printList(SqList& L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << "\t";
	}
	cout << endl;
}

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
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

/****** ɾ����i��Ԫ�� ******/
template <typename ElemType>
bool SqList<ElemType>::ListDelete(SqList& L, int i, ElemType& e) {
	if (i < L.length || i < 1) {
		return false;
	}
	e = L.data[i];
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

/****** ���ҵ�i��Ԫ�� ******/
template <typename ElemType>
ElemType SqList<ElemType>::GetElem(SqList L, int i) {
	return L.data[i-1];
}

/****** ����ֵΪe��Ԫ�ش��� ******/
template <typename ElemType>
int SqList<ElemType>::locateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) { // ����ע�⣬�����������Ϊ�ṹ�壬��ô��Ҫ������ж��Ƿ���ȣ������ֱ��д��ֵ�����ж�
			return i + 1;
		}
	}
	return -1;
}

/****** ��ȡ���Ա�ĳ��� ******/
template <typename ElemType>
int SqList<ElemType>::getLength(SqList L) {
	return L.length;
}

/****************************************** ��������ϰ *******************************************/

// test1
/*
** Ҫ��ɾ����Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾԪ�ص�ֵ���ճ���λ�������һ��Ԫ�������˳���Ϊ������ʾ������Ϣ���˳����У�
*/
template <typename ElemType>
bool SqList<ElemType>::deleteMinElem(SqList &L, ElemType &e) {
	if (L.length <= 0) {
		cout << "˳���Ϊ�գ����ɽ��в�����" << endl;
		return false;
	}
	ElemType elem = L.data[0];
	int i = 0;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] < elem) {
			elem = L.data[i];
		}
	}
	e = elem;
	L.data[i] = L.data[length - 1];
	L.length--;
	return true;
}

// test2
/*
** Ҫ������˳��������Ԫ�أ�Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)
*/
template<typename ElemType>
void SqList<ElemType>::ListReverse(SqList& L) {
	for (int i = 0; i < L.length / 2; i++) {
		int temp = L.data[i];
		L.data[i] = L.data[length - i - 1];
		L.data[length - i - 1] = temp;
	}
}

// test3
/*
** Ҫ��ɾ�����Ա�������ֵΪe��Ԫ�ء�Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/
template<typename ElemType>
bool SqList<ElemType>::deleteElem(SqList& L, ElemType e) {
	if (L.length <= 0) {
		return false;
	}
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != e) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;

	return true;
}

// test4
/*
** Ҫ��ɾ���������ֵ��min-max֮���Ԫ�أ�min<max�������min��max�������˳���Ϊ�գ���ʾ������Ϣ���˳�����
*/
template<typename ElemType>
bool SqList<ElemType>::deleteSeqElemFromMin2Max(SqList& L, ElemType min, ElemType max) {
	if (min >= max || L.length == 0) {
		cout << "���ݲ��������޸Ĳ���" << endl;
		return false;
	}
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] > max || L.data[i] < min) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;

	return true;
}

// test5
/*
** Ҫ��ɾ�����Ա���ֵ��min-max֮���Ԫ�أ�min<max������min��max�������min��max�������˳���Ϊ�գ���ʾ������Ϣ���˳�����
*/
template<typename ElemType>
bool SqList<ElemType>::deleteElemFromMin2Max(SqList& L, ElemType min, ElemType max) {
	if (min >= max || L.length == 0) {
		cout << "���ݲ��������޸Ĳ���" << endl;
		return false;
	}
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] >= max || L.data[i] <= min) {
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;

	return true;
}

// test6
/*
** Ҫ�󣺴�����˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ��������Ԫ�ص�ֵ����ͬ��
*/
template<typename ElemType>
void SqList<ElemType>::SingleList(SqList& L) {
	int k = 0;	// �ظ��Ĵ���
	int j = 0;	// ���ظ���Ԫ���±�
	for (int i = 1; i < L.length; i++) {
		if (L.data[j] != L.data[i]) {
			j++;
			L.data[j] = L.data[i];
		}
		else {
			k++;
		}
	}
	L.length = L.length - k;
}

// test7
/*
** Ҫ�󣺺ϲ���������˳�������һ���µ�����˳���
*/
template<typename ElemType>
SqList<ElemType> SqList<ElemType>::unionSqList(SqList L1, SqList L2) {
	SqList<ElemType> L;
	L.InitList(L);
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length) {
		if (L1.data[i] <= L2.data[j]) {
			L.data[k] = L1.data[i];
			i++;
		}
		else {
			L.data[k] = L2.data[j];
			j++;
		}
		k++;
	}
	while (i < L1.length) {
		L.data[k] = L1.data[i];
		i++;
		k++;
	}
	while (j < L2.length) {
		L.data[k] = L2.data[j];
		j++;
		k++;
	}
	L.length = k;
	return L;
}