#include <iostream>

//Инкапсуляция. Агрегация. Композиция


class NameOfClass //объявление класса
{
	//Свойства и поведение объектов класса - тело

//элементы доступны всем клиентам класса, наследникам класса и клиентам наследника. 
public: 
	//здесь оставляют только методы класса
	NameOfClass() //конструктор класса
	{
		SetEven(2);
		even_ = 2;
	}
	NameOfClass(int newNum):even_(newNum) //после конструктора : - для автоматической записи (делегирование записи)
	{
		if (even_ % 2 == 1)
		{
			throw 1;
		}
	}
	void SomeWork()
	{
		std::cout << "Hello world!\n";
	}
	int GetEven() //геттер
	{
		return even_; //метод который возвращает копию метода класса, предоставляя защищенный доступ
	}
	void SetEven(int newNum) //сеттер
	{
		if (newNum % 2 == 0)
		{
			even_ = newNum;
		}
		else
		{
			throw 1;
		}
	}
//элементы доступны членам класса. дружественным классам. функциям и членам классов наследников
protected: 
	

//элементы доступны только членам класса дружественным классам и функциям
private: 
	int even_; //если оставить без значения, то выведется мусорное значение;
}; // - определение класса

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	NameOfClass obj; //создали экзампляр класса с именем obj;
	obj.SomeWork(); //
	obj.SetEven(6);
	std::cout << obj.GetEven() << '\n';

	NameOfClass obj2{ 10 }; //скобки для конструктора
	std::cout << obj2.GetEven() << '\n'; //мусорное значение
	obj2.SetEven(4); // сет решил проблему, но можно лучше
	std::cout << obj2.GetEven() << '\n';

	//Task1
	Ex();

	return 0;
}

//Task1 Календарь
class Day
{
public:
	Day():units_(0){}
	Day(int days) :units_(days)
	{
		if (units_ < 0)
		{
			throw 1;
		}
	}
	int Days()
	{
		return units_;
	}
	void Days(const Day& obj) //константная ссылка, которая может работать с чем угодно
	{
		this->units_ = obj.units_;
	}
	void AddDays(const Day& obj)
	{
		this->units_ += obj.units_;
	}
private: 
	int units_;
};

class Month
{
public:
	Month():units_(0){}
	Month(int month) : units_(month) //
	{
		if (units_ < 0)
		{
			throw 1;
		}
	}
	Month(Day& days) //месяц умеет работать с днями
	{
		units_ = days.Days()/30; 
	}
	int Months() //сколько месяцев
	{
		return units_;
	}
	void Months(const Month& obj)
	{
		units_ = obj.units_;
	}
	void Months(const Month& obj)
	{
		units_ += obj.units_;
	}

private:
	int units_;
};

class Year
{
public:
	Year() :units_(0) {}
	Year(int year) : units_(year) //
	{
		if (units_ < 0)
		{
			throw 1;
		}
	}
	Year(Day days) //год умеет работать с днями
	{
		units_ = days.Days() / 365;
	}
	Year(Month months) //год умеет работать с месцами
	{
		units_ = month.Months() / 12;
	}
	int Years() //сколько месяцев
	{
		return units_;
	}
	void Years(const Year& obj)
	{
		units_ = obj.units_;
	}
	void AddYears(const Year& obj)
	{
		units_ += obj.units_;
	}

private:
	int units_;
};

class Date //данный класс собирает внутри себя объекты других классов на правах композиции
{
public: //тут будут правила класса даты

private:
	Day day_ ;
	Month month_;
	Year year_;
};



void Ex()
{
	Day day;
	day.Days(6); //значение дней в объект дня
}