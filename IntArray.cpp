#include <iostream>
#include "IntArray.h"

IntArray::IntArray(int length) : m_length(length) {    //создание контейнера
    if (length <= 0) {
        throw bad_length();
    }
    else {
        m_data = new int[length] {};
    }
}

IntArray::~IntArray() {
    delete[] m_data;
}

void IntArray::erase() {                        //очищение контейнера
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int& IntArray::operator[](const int& index) {   //доступ к любому элементу контейнера по индексу
    if (index <= 0 && index > m_length) {
        throw bad_range();
    }
    return m_data[index];
}

void IntArray::reallocate(int newLength) {      // изменение размера контейнера с очищением существующих элементов
    if (newLength <= 0) {
        throw bad_length();
    }
    else {
        erase();
        if (newLength <= 0)
            return;
        m_data = new int[newLength];
        m_length = newLength;
        cout << "–азмер массива изменен на: " << newLength << endl;
    }
}

void IntArray::resize(int newLength) {          // изменение размера контейнера с сохранением существующих элементов
    if (newLength <= 0) {
        throw bad_length();
    }
    if (newLength == m_length)
        return;

    if (newLength <= 0) {
        erase();
        return;
    }

    int* data{ new int[newLength] };
    if (m_length > 0) {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        for (int index = 0; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    delete[] m_data;
    m_data = data;
    m_length = newLength;
    cout << "–азмер массива изменен на: " << newLength << endl;
}

void IntArray::insertBefore(int value, int index) {      //вставка числа по индексу
    if (index < 0 && index > m_length) {
        throw bad_range();
    }

    int* data { new int[m_length + 1] };

    for (int before{ 0 }; before < index; ++before)      //  опирование элементов до индекса
        data[before] = m_data[before];   
    data[index] = value;

    for (int after = index; after < m_length; ++after)  //  опирование элементов после индекса
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;
    cout << "¬ставл€ем число " << value << " по индексу " << index << endl;
}

void IntArray::remove(int index) {                        //удаление элемента из контейнера по индексу
    if (index < 0 && index > m_length) {
        throw bad_range();
    }
    else {
        if (m_length == 1) {
            erase();
            return;
        }
        int* data{ new int[m_length - 1] };

        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];

        for (int after{ index + 1 }; after < m_length; ++after)
            data[after - 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        --m_length;
        cout << "”дал€ем число с индексом " << index << endl;
    }
}

void IntArray::insertAtBegin(int value) {      //вставка элемента в начало
    insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value) {        //вставка элемента в конец
    insertBefore(value, m_length);
}

void IntArray::search(int value) {             //поиск элемента в контейнере
    int h = 0;
    for (int before = 0; before < m_length; ++before) {
        if (m_data[before] == value) {
            h += 1;
            cout << "„исло " << value << " находитс€ под индексом " << before << endl;
        }
    }
    if (h == 0) cout << "„исло " << value << " нет в контейнере" << endl;
}

int IntArray::getLength() const {
    return m_length;
}

void IntArray::printArray() {                   //выводим содержимое контейнера на консоль
    cout << "Ёлементы массива: ";
    for (int i{ 0 }; i < m_length; ++i)
        cout << m_data[i] << " ";
    cout << "\n\n";
}
