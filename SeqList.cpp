#include "iostream"
#include "cstdio"

const int MaxSize = 100;

template<class DataType>
class SeqList
{
private:
		DataType array[MaxSize];				//˳���������	
		int length;								//ʵ�����ݳ���
public:
    	SeqList();									//���캯��
		
		~SeqList();								//��������

		bool isEmpty();							//�ж�˳����Ƿ�Ϊ��
		
		bool isFull();							//�ж�˳����Ƿ�����
		
		void Append(DataType _data);			//����˳���ĩβ	
		
		void Insert(int index, DataType _data);		//����������˳����i��λ��
		
		void Update(int index, DataType _data);		//�޸ĵ�i��λ�õ�����	
		
		void Delete(int index);						//ɾ��˳����i��λ�õ�����
		
		void Display();							//��ʾ˳�������
				
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