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
	List();						//默认构造函数
	
	List(const List &_List);	//拷贝构造函数
	
	~List();					//析构函数
	
	int getLength();			//返回链表长度
	
	void List_Insert(const int index, const DataType _data);	//插入数据
	
	void List_Delete(const int index);							//删除数据
	
	void Display();				//显示链表数据
	
	void List_Update(const int index,const DataType _data);		//更新数据
	
	void List_Locate(const DataType _data);						//返回data所在位置， 若有多个，则返回第一个
	
};