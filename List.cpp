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
	
	Node *pHead;				//pHead中不存放数据
	
	int length;
	
public:
	List();						//默认构造函数
	
	List(const List &_List);	//拷贝构造函数
	
	~List();					//析构函数
	
	int getLength();			//返回链表长度
	
	Node* getpHead()
	{
		return this->pHead;
	}
	
	void List_Append(const DataType _data);			//插入数据至表尾
	
	void List_Insert(const int index, const DataType _data);	//插入数据
	
	void List_Delete(const int index);							//删除数据
	
	void Display();				//显示链表数据
	
	void List_Update(const int index,const DataType _data);		//更新数据
	
	int List_Locate(const DataType _data);						//返回data所在位置， 若有多个，则返回第一个
	
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
		std::cout<<"error index!"<<std::endl;		//不允许隔空插数据
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

