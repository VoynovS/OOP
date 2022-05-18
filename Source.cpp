#ifndef HUMAN_HPP

#endif HUMAN_HPP //Почитать

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
	string getName()const;//Методы класса

private:
	Human1 person_;
	double grades_;
	string group_;
	string direction_;
};
class Human1 {
public:
	Human1(); //Конструкторы класса
	Human1(string name, 
		string patronymic, 
		string surname, 
		tm birtdate);//Конструкторы класса
	Human1(string name, string surname); //Конструкторы
	//setters and getters
	void setName(string name);
	string getName()const;//Методы класса
	//predicate
	bool isAdoult(); //Пустой набор инструментов yes/no
	//operators and traits //операторы и признаки
	//Есть как минимум два оператора : Присваивание (=) и сравнение (==)
	bool operator == (Human1 other);
	friend bool operator == (Human1 a, Human1 b);
	//traits (Свойство для параметра, например есть ли такой человек по фамилии, по возврасту)
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
		cout << "\nДанные о человеке: \n";
	}
	void getHuman(string name, string surname, int age, float body_weight) {
		cout << "Имя: " << name << endl;
		cout << "Фамилия: " << surname << endl;
		cout << "Возраст: " << age << endl;
		cout << "Вес: " << body_weight << endl;
	}
	
private:
	string name_;
	string surname_;
	int age_;
	float body_weight_;

};

class student {
	void message() {
		cout << "Данные о студенте: ";
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
	cout << "1.Введите имя: "; 
	getline(cin, name);
	cout << "2.Введите фамилию: ";
	getline(cin, surname);	
	cout << "3.Введите возраст: "; 
	cin >> age;
	cout << "4.Введите вес: ";     
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

Human1::Human1(string name, string patronymic, string surname, tm birtdate) //Не более 80 символов, далее необходимо переносить.
	:name_(name),
	patronymic_(patronymic),
	surname_(surname),
	birtdate_(birtdate)
{

}

Human1::Human1(string name, string surname)

{
	name_ = name;
	patronymic_ = ""; //Вставляем пустое значение
	surname_ = surname;
	birtdate_ = tm();//Вставляем пустое значение, потому что в аргументах не определено значение и чтобы убрать возможные ошибки.
}

void Human1::setName(string name)
{
	name_ = name;
}

string Human1::getName() const//get только константный. Предоставляет данные о полях класса.
{
	return name_;
}


void Student::setName(string name)
{
	person_.setName(name);
}

string Student::getName() const
{
	return person_.getName(); //Выходят только константные значения
}
