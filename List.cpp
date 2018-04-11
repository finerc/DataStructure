#include "iostream"
#include "cstdio"


template<class DataType>
class List{
private:
	class Node{
	public:
		DataType data;
		Node *pNext;
		
		Node()
		{
			pNext = null;
		}
	};
	
	Node *pHead;
	
	int length;
	
public:
	List();						//Ĭ�Ϲ��캯��
	
	List(const List &_List);	//�������캯��
	
	~List();					//��������
	
	int getLength();			//������������
	
	void List_Insert(const int index, const DataType _data);	//��������
	
	void List_Delete(const int index);							//ɾ������
	
	void Display();				//��ʾ��������
	
	void List_Update(const int index,const DataType _data);		//��������
	
	void List_Locate(const DataType _data);						//����data����λ�ã� ���ж�����򷵻ص�һ��
	
};