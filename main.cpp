// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "IntArray.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	try
	{
		IntArray s_array(10);				//создаем контейнер из 10 элементов
		for (int i{ 0 }; i < 10; ++i)
			s_array[i] = i + 1;

		s_array.reallocate(15);				//изменяем размер контейнера с очищением элементов
		for (int i{ 0 }; i < 15; ++i)		        //заполняем очищенный контейнер
			s_array[i] = i + 1;
		s_array.printArray();

		s_array.resize(7);				//изменяем размер контейнера с сохранением элементов
		s_array.printArray();

		s_array.insertBefore(20, 5);		        //вставляем число 20 по индексу 5
		s_array.remove(2);				//удаляем элемент с индексом 2
		s_array.insertAtEnd(35);			//вставляем число 35 в конец контейнера
		s_array.insertAtBegin(50);			//вставляем число 50 в начало контейнера		
		cout << "Размер массива: " << s_array.getLength() << endl;
		s_array.printArray();

		s_array.search(20);				//поиск элемента в контейнере
		s_array.search(150);
	}

	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}
