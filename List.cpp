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
	
	Node *pHead;				//pHead中不存放数据
	
	int length;
	
public:
	List();						//默认构造函数
	
	List(const List &_List);	//拷贝构造函数
	
	~List();					//析构函数
	
	int getLength();			//返回链表长度
	
	void List_Append(const DataType _data);			//插入数据至表尾
	
	void List_Insert(const int index, const DataType _data);	//插入数据
	
	void List_Delete(const int index);							//删除数据
	
	void Display();				//显示链表数据
	
	void List_Update(const int index,const DataType _data);		//更新数据
	
	void List_Locate(const DataType _data);						//返回data所在位置， 若有多个，则返回第一个
	
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

