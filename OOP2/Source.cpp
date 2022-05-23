#include <iostream>
#include <cstring>
using namespace std;

class String {
public:
String()
	:data(nullptr), //Данный вариант быстрее отрабатывает
	size(0),
	capacity (0)
	{
		//data = nullptr; //nullptr - индустриальный стандарт, записывать нулевой указатель.
		//size = 0;
		//capacity = 0;
	cout << this << " Base object created\n";
}

explicit String(int length) : String() {
		capacity = length;
		data = new char[length] {};
		//size = 0; - необзяательно, так как находится в String() по умолчанию.
	};
//String(int i) : String() {}; //сначала вызывает конструктор по умолчанию

String(const String &other) { //Левостороняя ссылка (переменная) с одним амперсантом, копирует данные с указанного объекта.
	size = other.size;
	capacity = other.capacity;
	data = new char[other.size] {};
	::memcpy(data, other.data, size);
	cout << this << " Base object created by copy\n";
}
//explicit Base(int i); Запрещено вызывать компилятору автоматически
//F00(static_cast<Base>(8)); - при explicit вызывать конкретно, так как будет ругаться компилятор.

String(const char* str){ //Копирование данных из строки в новое место.
	size = ::strlen(str)+1; //Возвращает длину строки без нуль терминатора.
	capacity = size;
	data = new char[size] {};
	::memcpy(data, str, size);//Побитовое копирование данных из одного файла в другой (Куда, откуда, размер)
}

const String& operator  = (const String &other) {
	if (capacity >= other.size) {
		for (int i = 0; i < size; i++) {
			data[i] = '\0';
		}		
	}		//Процесс копирования 
	else
	{
		if (!data) {
			delete[]data;
		}
		data = new char[other.size + 1];
		capacity = other.size + 1;

	}
	::memcpy(data, other.data, other.size);
	return *this;
}

~String() {
	if (!data) {
		delete[]data;
	}
	cout << this << " Base object destroed\n"; //вызывается (уничтожается) в обратном создании порядке

}

//void setString(const char *str) {
//	(*this) = String(str);
//}

friend String operator +(String a, String b);

private:
	char *data;//Указатель на место где храниться 
	int size;//Размер строки
	int capacity;//Сколько памяти нам доступно

};
String operator+(String a, String b) { //Конкатинация строк.
	String result(a.size + b.size);
	::memcpy(result.data, a.data, a.size);
	::memcpy(result.data + a.size, b.data, b.size);
	result.size = a.size + b.size;
	return result;
}

//void F00(String obj) {
//
//}

int main() {
	String a;
	String b(5);
	a = b = static_cast<String>(8); //Можно применять оператор присваивания.
	//Оператор присваивания Перегружается как метод класса
	String(); //Анонимный объект структуры Base/ Существует одну строчку, потом уничтожаются
	auto point = new String(4);
	//Base *point1 = new Base(6);
	//F00(a);
	delete point;
	double r = (1 / double(6));
	double e;
	e = r = 5.6;





	return 0;
};