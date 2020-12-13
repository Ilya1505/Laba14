// stl c++.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <iostream>
#include <string>

using namespace std;

class MyException : public exception// ����� ��������� exception
{
private:
	int CodeError;// ��� ������
public:
	MyException(char *msg, int CodeError) :exception(msg)
	{
		this->CodeError = CodeError;
	}
	int Code()
	{
		return CodeError;
	}
};
template<typename T> class Sizeof// ������ ������
{
private:
	T value;
public:
	Sizeof(T value)
	{
		this->value = value;
	}
	void SetValue(T value)
	{
		this->value = value;
	}
	T GetValue()
	{
		return value;
	}
	void DataTypeSize()
	{
		cout << "������ ��������: " << sizeof(value) << " ����" << endl;
	}
};





class avtoshop// ����������� �����
{
public:
	virtual void addTov() = 0;// ����� ����������� �����
};

class engine// ���������
{
private:
	int power;// �������� (�.�.)
	string name;// ����� ���������
	double weight;// ���
	int probeg;// ������
	int resurs;// ������ ���������
public:
	engine &operator=(const engine &other)// ���������� ���������� =
	{
		this->power = other.power;
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
		return *this;
	}
	engine(string init_name, double weight, int power, int probeg, int resurs)// ����������� � �����������
	{
		this->name = init_name;
		this->weight = weight;
		this->power = power;
		this->probeg = probeg;
		this->resurs = resurs;
	}
	engine(string name)
	{
		this->name = name;
		this->weight = 50;
		this->power = 100;
		this->probeg = 0;
		this->resurs = 100;
	}
	engine()// ����������� ��� ����������
	{
		name = "No_Name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
	}

	// ������� � �������
	void SetName(string name)
	{
		this->name = name;
	}
	void SetWeight(double weight)
	{
		this->weight = weight;
	}
	void SetPower(int power)
	{
		this->power = power;
	}
	void SetProbeg(int probeg)
	{
		this->probeg = probeg;
	}
	void SetResurs(int resurs)
	{
		this->resurs = resurs;
	}
	string GetName()
	{
		return name;
	}
	double GetwWight()
	{
		return weight;
	}
	int GetPower()
	{
		return power;
	}
	int GetProbeg()
	{
		return probeg;
	}
	int GetResurs()
	{
		return resurs;
	}
	void Remont()// ������ ���������
	{
		probeg = 0;
	}
	void Read()// ���� ������
	{
		fflush(stdin);
		cout << endl << "����� ���������: ";
		getline(cin, name);
		if (name == "") throw exception("������� ������ ������ ����� ���������!!!");
		cout << "��� ���������: ";
		cin >> weight;
		if (weight <10 || weight>5000) throw exception("������ ������������ ��� ���������!!!");
		cout << "�������� ���������: ";
		cin >> power;
		if (power <10 || power>1500) throw exception("������� ������������ �������� ���������!!!");
		cout << "������ ���������: ";
		cin >> probeg;
		if (probeg <0 || probeg>1000000) throw exception("������ ������������ ������!!!");
		cout << "������ ���������: ";
		cin >> resurs;
		if (resurs <100 || resurs>5000000) throw exception("������ ������������ ������ ���������!!!");
	}
	void Print()// ����� ������
	{
		cout << "����� ���������: " << name << endl;
		cout << "�������� ���������: " << power << endl;
		cout << "������ ���������: " << probeg << endl;
		cout << "������ ���������: " << resurs << endl;
		cout << "����� ���������: ";
		printf("%.4lf\n", weight);
	}
	~engine()// ����������
	{

	}
};
class technika :public avtoshop// ������������ ����� ���� �������, ��������� ������������ ������ avtoshop
{
protected:
	int year;// ��� �������
	string name;// ����� �������
	string color;// ���� �������
	double price;// ����
	int count;
	int petrol;// ���������� ������� (� ������)
public:
	technika(const technika &other)// ����������� �����������
	{
		this->year = other.year;
		this->name = other.name;
		this->color = other.color;
		this->price = other.price;
		this->count = other.count;
		this->petrol = other.petrol;
	}
	technika(int year, string name, string color, double price, int count)// ����������� � �����������
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->price = price;
		this->count = count;
		this->petrol = 0;
	}
	technika()// ����������� ��� ����������
	{
		name = "No_Name";
		color = "No_Color";
		year = 2020;
		price = 1000;
		count = 0;
		zapravka();// ����� ����������� ������� �� ������� �������� ������
	}
	// ������� � �������
	void SetName(string name)
	{
		this->name = name;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	void SetYear(int year)
	{
		this->year = year;
	}
	void SetPrice(double price)
	{
		this->price = price;
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	string GetName()
	{
		return name;
	}
	string GetColor()
	{
		return color;
	}
	int GetYear()
	{
		return year;
	}
	double GetPrice()
	{
		return price;
	}
	int GetCount()
	{
		return count;
	}
	int GetPetrol()
	{
		return petrol;
	}
	virtual void zapravka()// ����������� �������
	{
		if (petrol == 0)
		{
			petrol = 100;
			cout << "������ ���!(100�)" << endl;
		}
		else
		{
			cout << "������, ��� �� ������!" << endl;
		}
	}
	int Sell()
	{
		count--;
		cout << "������� �������!" << endl;
		cout << "������� ����������: " << count << endl;
		return count;
	}
	friend void operator<<(ostream &o, technika t);
	friend technika operator>>(istream &o, technika &t);
	void addTov() override
	{
		count++;
		cout << "��������� 1 ����� �������" << endl;
	}
	void Zapravit()// �������, ���������� ����������� ������� ��� ���������������� �������
	{
		zapravka();
	}
};
void operator<<(ostream &o, technika t)// �������� ������ ������
{
	cout << endl << "�����: " << t.name << endl;
	cout << "����: " << t.color << endl;
	cout << "��� �������: " << t.year << endl;
	cout << "����: ";
	printf("%.4lf\n", t.price);
	cout << "����������: " << t.count << endl;
}
technika operator >>(istream &o, technika &t)// ������� ����� ������
{
	fflush(stdin);
	cout << "�����: ";
	getline(cin, t.name);
	if (t.name == "") throw exception("������� ������ ������ �����!!!");
	fflush(stdin);
	cout << "����: ";
	getline(cin, t.color);
	if (t.color == "") throw exception("������� ������ ������ �����!!!");
	cout << "��� �������: ";
	cin >> t.year;
	if (t.year<2000 || t.year>2020) throw exception("������ ������������ ��� �������!!!");
	cout << "����: ";
	cin >> t.price;
	if (t.price <= 0) throw exception("������� ������������ ����!!!");
	cout << "����������: ";
	cin >> t.count;
	if (t.count <= 0) throw exception("������� ������������ ����������!!!");
	return t;
}
class cars :public technika// ����������� ����� "������" �� ������ "�������"
{
private:
	engine dvs;// ���������
	double timeToHundred;// ����� ������� �� �����

public:
	cars()
	{
		timeToHundred = 0;
	}
	cars(engine &dvs, double time, int year, string name, string color, double price, int count) :technika(year,
		name, color, price, count)
	{
		this->dvs = dvs;//��������� ���������
		this->timeToHundred = time;
	}
	void SetTime(double time)
	{
		this->timeToHundred = time;
	}
	double GetTime()
	{
		return timeToHundred;
	}
	void Modern(double NewWeight, int NewPower, int NewResurs)// ������������
	{
		if (NewWeight<10 || NewWeight>500) throw MyException("������, ������������ ������ ������������!", 3);
		if (NewPower<50 || NewPower>1500) throw MyException("������, ������������ ������ ������������!", 4);
		if (NewResurs<500 || NewResurs>500000) throw MyException("������, ������������ ������ ������������!", 5);
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
	int Sell(int count)// ���������� ������ �������� ������
	{
		if (this->count < count) throw exception("������������ ���������� ����������� �����!");
		this->count -= count;
		cout << "������� �������!" << endl;
		cout << "������� ����������: " << this->count << endl;
	}
	void operator=(technika other)
	{
		this->name = other.GetName();
		this->color = other.GetColor();
		this->year = other.GetYear();
		this->price = other.GetPrice();
		this->count = other.GetCount();
		this->petrol = other.GetPetrol();
		this->timeToHundred = 0;
	}
	void zapravka() override// ���������������� ������� �������� ������
	{
		if (petrol != 100)
		{
			petrol += 10;
			cout << "�������� �� 10 ������!" << endl;
		}
		else
		{
			cout << "�� ������� �����������, ��� ������" << endl;
		}
	}
	void addTov() override
	{
		count += 3;
		cout << "��������� 3 ����� ������" << endl;
	}
	int Drive(cars *avto, int km);
	friend void operator<<(ostream &o, cars c);// ���������� ��������� cout
	friend cars operator>>(istream &o, cars &c);// ���������� ��������� cin
};
void operator<<(ostream &o, cars c)
{
	cout << endl << "������:" << endl;
	cout << "�����: " << c.name << endl;
	cout << "����: " << c.color << endl;
	cout << "��� �������: " << c.year << endl;
	cout << "����: ";
	printf("%.4lf\n", c.price);
	cout << "����������: " << c.count << endl;
	cout << "����� ������� �� �����: " << c.timeToHundred << " ������" << endl;
	c.dvs.Print();
}
cars operator>>(istream &o, cars &c)// ���������� ��������� cin
{
	cout << "������:" << endl;
	fflush(stdin);
	cout << "�����: ";
	getline(cin, c.name);
	if (c.name == "") throw exception("������� ������ ������ �����!!!");
	fflush(stdin);
	cout << "����: ";
	getline(cin, c.color);
	if (c.color == "") throw exception("������� ������ ������ �����!!!");
	cout << "��� �������: ";
	cin >> c.year;
	if (c.year<2000 || c.year>2020) throw exception("������ ������������ ��� �������!!!");
	cout << "����: ";
	cin >> c.price;
	if (c.price <= 0) throw exception("������� ������������ ����!!!");
	cout << "����������: ";
	cin >> c.count;
	if (c.count <= 0) throw exception("������� ������������ ����������!!!");
	cout << "����� ������� �� �����: ";
	cin >> c.timeToHundred;
	if (c.timeToHundred<0 || c.timeToHundred>100000) throw exception("������� ������������ �����!!!");
	c.dvs.Read();
	return c;
}

int cars::Drive(cars *avto, int km)// ������� �������� ����� ���������
{
	if (km<1) throw MyException("������, ������������ ���������� ����-������!", 0);
	if (km>100)throw MyException("������, ������������ ���������� ����-������!", 1);
	int ProbegAfterDrive;
	ProbegAfterDrive = avto->dvs.GetProbeg() + km;
	avto->dvs.SetProbeg(ProbegAfterDrive);
	avto->petrol -= 10;
	return ProbegAfterDrive;
}

class plane :public technika// ����������� ����� "�������" �� ������ "�������"
{
private:
	double MaxHeight;// ������������ ������ ������ (� ������)
	double HourFly;// ����� � �����
public:
	plane()
	{
		MaxHeight = 10000;
		HourFly = 0;
	}
	plane(double maxheight, double hourfly, int year, string name, string color, double price, int count) :technika(year,
		name, color, price, count)
	{
		MaxHeight = maxheight;
		HourFly = hourfly;
	}
	void SetHeight(double height)
	{
		this->MaxHeight = height;
	}
	void SetHourFly(double hour)
	{
		this->HourFly = hour;
	}
	double GetHeight()
	{
		return MaxHeight;
	}
	double GetHour()
	{
		return HourFly;
	}
	double Fly(double hour)// ������� ������ �� ������������ ���������� �����
	{
		if (hour < 0) throw exception("������������ ����������������� ������!");
		HourFly += hour;
		return HourFly;
	}
	void addTov() override
	{
		count += 2;
		cout << "��������� 2 ����� ��������" << endl;
	}
	friend void operator<<(ostream &o, plane p);// ���������� ��������� cout
	friend plane operator>>(istream &o, plane &p);// ���������� ��������� cin
};
void operator<<(ostream &o, plane p)// ���������� ��������� cout
{
	cout << "�������:" << endl;
	cout << "�����: " << p.name << endl;
	cout << "����: " << p.color << endl;
	cout << "��� �������: " << p.year << endl;
	cout << "����: ";
	printf("%.4lf\n", p.price);
	cout << "����������: " << p.count << endl;
	cout << "������������ ������ ������: ";
	cin >> p.MaxHeight;
	cout << "����� ������ (� �����): ";
	cin >> p.HourFly;
}
plane operator>>(istream &o, plane &p)// ���������� ��������� cin
{
	cout << "�������:" << endl;
	fflush(stdin);
	cout << "�����: ";
	getline(cin, p.name);
	if (p.name == "") throw exception("������� ������ ������ �����!!!");
	fflush(stdin);
	cout << "����: ";
	getline(cin, p.color);
	if (p.color == "") throw exception("������� ������ ������ �����!!!");
	cout << "��� �������: ";
	cin >> p.year;
	if (p.year<2000 || p.year>2020) throw exception("������ ������������ ��� �������!!!");
	cout << "����: ";
	cin >> p.price;
	if (p.price <= 0) throw exception("������� ������������ ����!!!");
	cout << "����������: ";
	cin >> p.count;
	if (p.count <= 0) throw exception("������� ������������ ����������!!!");
	cout << "������������ ������ ������: " << p.MaxHeight << endl;
	cout << "����� ������: " << p.HourFly << "�����(�)" << endl;
	return p;
}

void addTov(avtoshop *ptr)
{
	ptr->addTov();
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// ����������� �������������� �����/������
	SetConsoleOutputCP(1251);
	//����� ������:
	engine dvs("��-01", 10, 100, 0, 400);
	technika *tk = new technika(2020, "No_Name", "No_Color", 15000, 5);
	cars *avto = new cars(dvs, 5, 2020, "No_Name", "No_Color", 1000, 8);
	int a = 4;
	Sizeof<int> size1(a);
	size1.DataTypeSize();
	tk->Zapravit();// ����� �������, ���������� ����������� ������� �������� ������
	*avto = *tk;// ���������� ��������� =
	cout << *avto;
	Sizeof<cars> size2(*avto);
	size2.DataTypeSize();
	bool f;
	do{
		f = false;
		try{ cin >> *avto; }
		catch (exception &ex)
		{
			cout << "������ �����: " << ex.what() << endl;
			cout << "��������� ������� �����!" << endl;
			f = true;
		}
	} while (f);
	printf("\n������ ����� �����:");
	cout << *avto;
	int probeg = 0;
	try{ probeg = avto->Drive(avto, 10); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "��� ������: " << ex.Code() << endl;
		cout << "���������� ������ ���������!";
		getch();
		exit(1);
	}
	avto->Zapravit();// �������, ���������� ������� ������������ ������
	printf("\n������ ����� ����-������: ");
	cout << probeg << endl;
	try{ avto->Modern(100, 200, 500); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "��� ������: " << ex.Code() << endl;
		cout << "���������� ������ ���������!";
		getch();
		exit(1);
	}
	printf("\n����� ������������:");
	cout << *avto;
	avto->technika::Sell();// ����� �������������� ������ �������� ������
	try{ avto->Sell(5); }
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		cout << "���������� ������ ���������!";
		getch();
		exit(1);
	}
	addTov(avto);
	//����� �������
	plane pl(20000, 0, 2020, "No_Name", "No_Color", 150000, 5);
	cout << pl;
	do{
		f = false;
		try{ cin >> pl; }
		catch (exception &ex)
		{
			cout << "������ �����: " << ex.what() << endl;
			cout << "��������� ������� �����!" << endl;
			f = true;
		}
	} while (f);
	printf("\n������ ����� �����:");
	cout << pl;
	try{ pl.Fly(1); }
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		cout << "���������� ������ ���������!";
		getch();
		exit(1);
	}
	cout << "����� (� �����) ����� ������: " << pl.GetHour() << endl;
	pl.Sell();
	getch();
	return 0;
}

