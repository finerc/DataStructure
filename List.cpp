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
			next = nullptr;
		}
	};
	
	Node *pHead;				//pHead�в��������
	
	int length;
	
public:
	List();						//Ĭ�Ϲ��캯��
	
	List(const List &_List);	//�������캯��
	
	~List();					//��������
	
	int getLength();			//����������
	
	Node* getpHead()
	{
		return this->pHead;
	}
	
	void List_Append(const DataType _data);			//������������β
	
	void List_Insert(const int index, const DataType _data);	//��������
	
	void List_Delete(const int index);							//ɾ������
	
	void Display();				//��ʾ��������
	
	void List_Update(const int index,const DataType _data);		//��������
	
	int List_Locate(const DataType _data);						//����data����λ�ã� ���ж�����򷵻ص�һ��
	
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
List<DataType>::List(const List &_List)
{
	Node *node = new Node();
	this->pHead = node;
	
	Node *pTempHead = this->pHead;
	Node *qTempHead = _List.getpHead();
	while(nullptr!=pTempHead->next)
	{
		Node *cur_node = new Node();
		cur_node->data = pTempHead->next->data;
		cur_node->next = pTempHead->next;
		pTempHead->next = cur_node;
		
		pTempHead = pTempHead->next;
		qTempHead = qTempHead->next;
	}
}

template<class DataType>
List<DataType>::~List()
{
	Node *pTempHead = pHead;
	Node *qTempHead = pHead;
	
	while(nullptr!=pTempHead->next)
	{
		qTempHead = pTempHead->next;
		delete(pTempHead);
		pTempHead = qTempHead;
	}
	delete(pTempHead);
}

template<class DataType>
int List<DataType>::getLength()
{
	return this->length;
}

template<class DataType>
void List<DataType>::List_Append(const DataType _data)
{
	Node *pTempHead = pHead;
	
	Node *node = new Node();
	node->data = _data;
	
	while(nullptr!=pTempHead->next)
	{
		pTempHead = pTempHead->next;
	}
	
	node->next = pTempHead->next;
	pTempHead->next = node;
	
	this->length++;	
}

template<class DataType>
void List<DataType>::List_Insert(const int index,const DataType _data)	//index from 0 to length
{
	if(index>length)
	{
		std::cout<<"error index!"<<std::endl;		//��������ղ�����
		return;
	}
	Node *pTempHead = pHead;
	
	int i = 0;
	
	Node *node = new Node();
	node->data = _data;
	
	while(i!=index)
	{
		i++;
		pTempHead = pTempHead->next;
	}
	node->next = pTempHead->next;
	pTempHead->next = node;
	
	this->length++;
}

template<class DataType>
void List<DataType>::List_Delete(const int index)	//index from 0 to length-1
{
	if(index>length-1)
	{
		std::cout<<"error index!"<<std::endl;
		return;
	}
	Node *pTempHead = pHead;
	Node *qTempHead = pHead->next;

	int i = 0;
	
	while(i!=index)
	{
		pTempHead = qTempHead;
		qTempHead = qTempHead->next;
		i++;
	}
	pTempHead->next = qTempHead->next;
	delete(qTempHead);

	this->length--;
}

template<class DataType>
int List<DataType>::List_Locate(DataType _data)
{
	Node *pTempHead = pHead;
	int i = 0;
	while(nullptr!=pTempHead->next)
	{
		if(pTempHead->next->data==_data)
			return i;
		i++;
		pTempHead = pTempHead->next;
	}
	std::cout<<"no data match "<<_data<<"!"<<std::endl;
	return -1;
}

template<class DataType>
void List<DataType>::Display()
{
	Node *pTempHead = pHead;
	while(nullptr!=pTempHead->next)
	{
		std::cout<<pTempHead->next->data<<" ";
		pTempHead = pTempHead->next;
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
	std::cout<<"insert 21 to index 0"<<std::endl;
	mlist.List_Insert(0,21);
	mlist.Display();
	std::cout<<"delete from index 10"<<std::endl;
	mlist.List_Delete(10);
	mlist.Display();
	int x = mlist.List_Locate(22);
	if(x!=-1)
		std::cout<<"data 3 is in index " <<x<<std::endl;
	List <int> nlist(mlist);
	nlist.Display();
	return 0;
}

