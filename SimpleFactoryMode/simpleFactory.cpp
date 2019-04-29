#include <iostream>
using namespace std;


//book type
enum BOOKTYPE{CHINESE,MATH,ENGLISH};


//abstract product
class baseBook
{
	public:
	virtual ~baseBook(){};
	virtual void show()=0;
};

//child product
class ChineseBook: public baseBook
{
	public:
	void show()
	{
		cout<<"This is chinese book!"<<endl;
	}
};


class MathBook: public baseBook
{
	public:
	void show()
	{
		cout<<"This is math book!"<<endl;
	}
};

class EnglishBook: public baseBook
{
	public:
	void show()
	{
		cout<<"This is English book!"<<endl;
	}
};


//Factory
class SimpleFactory
{
	public:
	baseBook* CreateBook(BOOKTYPE enBookType)
	{
		switch(enBookType)
		{
			case CHINESE:
				return new ChineseBook();
			case MATH:
				return new MathBook();
			case ENGLISH:
				return new EnglishBook();
			default:
				cout<<"not suport"<<endl;
		}
	}
};



int main()
{
	SimpleFactory bookFactory;
	baseBook* math = bookFactory.CreateBook(MATH);
	math->show();
	baseBook* chinese = bookFactory.CreateBook(CHINESE);
	chinese->show();
	baseBook* English = bookFactory.CreateBook(ENGLISH);
	English->show();

	delete math;
	math =NULL;
	delete chinese;
	chinese = NULL;
	delete English;
	English = NULL;
	return 0;
}
