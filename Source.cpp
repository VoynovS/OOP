#ifndef HUMAN_HPP

#endif HUMAN_HPP //��������

#include <iostream>		
#include <string>
#include <ctime>//chrono

using namespace std;
class Student {
public:
	Student();
	Student(Human1 person, double grates, string group, string direction);
	//getters and setters
	void setName(string name);
	string getName()const;//������ ������

private:
	Human1 person_;
	double grades_;
	string group_;
	string direction_;
};
class Human1 {
public:
	Human1(); //������������ ������
	Human1(string name, 
		string patronymic, 
		string surname, 
		tm birtdate);//������������ ������
	Human1(string name, string surname); //������������
	//setters and getters
	void setName(string name);
	string getName()const;//������ ������
	//predicate
	bool isAdoult(); //������ ����� ������������ yes/no
	//operators and traits //��������� � ��������
	//���� ��� ������� ��� ��������� : ������������ (=) � ��������� (==)
	bool operator == (Human1 other);
	friend bool operator == (Human1 a, Human1 b);
	//traits (�������� ��� ���������, �������� ���� �� ����� ������� �� �������, �� ���������)
	bool olderThen(int age);

private:
	string name_;
	string patronymic_;
	string surname_;
	tm birtdate_;
};

/*
class Human {
public: 
	void message() {
		cout << "\n������ � ��������: \n";
	}
	void getHuman(string name, string surname, int age, float body_weight) {
		cout << "���: " << name << endl;
		cout << "�������: " << surname << endl;
		cout << "�������: " << age << endl;
		cout << "���: " << body_weight << endl;
	}
	
private:
	string name_;
	string surname_;
	int age_;
	float body_weight_;

};

class student {
	void message() {
		cout << "������ � ��������: ";
	}
};
*/
int main()
{
	setlocale(LC_ALL, "ru"); 
	system("chcp 1251>nul");

	Human1 vasya("Vasilii", "Pupkin");
	vasya.getName();

	/*const int SIZE = 100;
	string name;
	string surname;
	int age;
	float body_weight;
	cout << "1.������� ���: "; 
	getline(cin, name);
	cout << "2.������� �������: ";
	getline(cin, surname);	
	cout << "3.������� �������: "; 
	cin >> age;
	cout << "4.������� ���: ";     
	cin >> body_weight;

	Human obj_Human; 
	obj_Human.message(); 
	obj_Human.getHuman(name, surname, age, body_weight);*/

	

	return 0;
}

Human1::Human1()
	:name_("Jane"),
	patronymic_(""),
	surname_("Doe"),
	birtdate_({})
{
	//to-do data insrtion
}

Human1::Human1(string name, string patronymic, string surname, tm birtdate) //�� ����� 80 ��������, ����� ���������� ����������.
	:name_(name),
	patronymic_(patronymic),
	surname_(surname),
	birtdate_(birtdate)
{

}

Human1::Human1(string name, string surname)

{
	name_ = name;
	patronymic_ = ""; //��������� ������ ��������
	surname_ = surname;
	birtdate_ = tm();//��������� ������ ��������, ������ ��� � ���������� �� ���������� �������� � ����� ������ ��������� ������.
}

void Human1::setName(string name)
{
	name_ = name;
}

string Human1::getName() const//get ������ �����������. ������������� ������ � ����� ������.
{
	return name_;
}


void Student::setName(string name)
{
	person_.setName(name);
}

string Student::getName() const
{
	return person_.getName(); //������� ������ ����������� ��������
}
