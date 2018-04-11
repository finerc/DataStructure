#include "iostream"
#include "cstdio"

const int MaxSize = 100;

template<class DataType>
class SeqList
{
private:
		DataType array[MaxSize];				//顺序表用数组	
		int length;								//实际数据长度
public:
    	SeqList();									//构造函数
		
		~SeqList();								//析构函数

		bool isEmpty();							//判断顺序表是否为空
		
		bool isFull();							//判断顺序表是否已满
		
		void Append(DataType _data);			//插入顺序表末尾	
		
		void Insert(int index, DataType _data);		//插入数据至顺序表第i个位置
		
		void Update(int index, DataType _data);		//修改第i个位置的数据	
		
		void Delete(int index);						//删除顺序表第i个位置的数据
		
		void Display();							//显示顺序表数据
				
};

	template<class DataType>
	SeqList<DataType>::SeqList()
	{
	    length = 0;
	}

	template<class DataType>
	SeqList<DataType>::~SeqList()
	{
	  	length = 0;
	}

	template<class DataType>
	void SeqList<DataType>::Display()						
	{
	    for(int i=0; i<length; i++)
		{
			std::cout<<array[i]<<" ";
		}
		std::cout<<std::endl;
	}
			
	template<class DataType>
	bool SeqList<DataType>::isEmpty()
	{
	    return length==0;
	}

	template<class DataType>
	bool SeqList<DataType>::isFull()
	{
	    return length==MaxSize-1;    
	}

	template<class DataType>
	void SeqList<DataType>::Append(DataType _data)
	{
	    if(isFull())
	    {
		    std::cout<<"The sequence list is full!"<<std::endl;
		    return;
	    }
	    else
	    {
	    	array[length] = _data;
	    	length++;
	    }
		
	}

	template<class DataType>
	void SeqList<DataType>::Insert(int index, DataType _data)
	{
		if(index>length)
		{
			std::cout<<"error index"<<std::endl;
			return;
		}
		else if(isFull())
		{
			std::cout<<"The sequence list is full!"<<std::endl;
		    return;
		}
		else
		{
			length++;
			for(int i=length-1;i>index;i--)
			{
				array[i] = array[i-1]; 
			}
			array[index] = _data;
		}
	}

	template<class DataType>
	void SeqList<DataType>::Delete(int index)
	{
		if(index>length)
		{
			std::cout<<"error index"<<std::endl;
			return;
		}
		else
		{
			for(int i=index;i<length-1;i++)
			{
				array[i] = array[i+1];
			}
			length--;
		}
	}

	template<class DataType>
	void SeqList<DataType>::Update(int index, DataType _data)
	{
		if(index>length)
		{
			std::cout<<"error index"<<std::endl;
		}
		else
		{
			Update[index] = _data;
		}
	}
	
	int main()
	{
		SeqList<int> sqlist;
		for(int i=0;i<10;i++)
		{
			sqlist.Append(i);
		}
		std::cout << "after append 10 integers: " << std::endl;
		sqlist.Display();
		std::cout<<"insert 12 into index 5"<<std::endl;
		sqlist.Insert(5,12);
		sqlist.Display();
		std::cout<<"delete from index 2"<<std::endl;
		sqlist.Delete(2);
		sqlist.Display();
		return 0;
	}