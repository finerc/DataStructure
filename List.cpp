#include "iostream"
#include "cstdio"


template<class DataType>
class List{
private:
	class Node{
	public:
		DataType data;
		Node *next;
		
		Node()
		{
			next = NULL;
		}
	};
	
	Node *pHead;				//pHead�в��������
	
	int length;
	
public:
	List();						//Ĭ�Ϲ��캯��
	
	List(const List &_List);	//�������캯��
	
	~List();					//��������
	
	int getLength();			//����������
	
	void List_Append(const DataType _data);			//������������β
	
	void List_Insert(const int index, const DataType _data);	//��������
	
	void List_Delete(const int index);							//ɾ������
	
	void Display();				//��ʾ��������
	
	void List_Update(const int index,const DataType _data);		//��������
	
	void List_Locate(const DataType _data);						//����data����λ�ã� ���ж�����򷵻ص�һ��
	
};

template<class DataType> 
List<DataType>::List()
{
	Node *node = new Node();
	this->pHead = node;
	node->next = NULL;
	this->length = 0;
}

template<class DataType>
List<DataType>::~List()
{
	Node *pTempHead = pHead;
	
	while(NULL!=pTempHead->next)
	{
		pTempHead = pTeamHead->next;
	}
}

template<class DataType>
void List<DataType>::List_Append(const DataType _data)
{
	Node *pTempHead = pHead;
	
	Node *node = new Node();
	node->data = _data;
	
	while(NULL!=pTempHead->next)
	{
		pTempHead = pTempHead->next;
	}
	
	node->next = pTempHead->next;
	pTempHead->next = node;
	
	this->length++;	
}

template<class DataType>
void List<DataType>::Display()
{
	Node *pTempHead = pHead;
	while(NULL!=pTempHead->next)
	{
		std::cout<<pTempHead->next<<" ";
	}
	std::cout<<std::endl;
}

int main()
{
	List<int> mlist;
	for(int i=0;i<10;i++)
	{
		mlist.List_Append(i);
	}
	mlist.Display();
	return 0;
}

