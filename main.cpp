//
// Created by Daniil Artamonov on 25.02.2021.
//

//Реализация через векто
#include <fstream>
#include <iostream>

using namespace std;

const int N = 10;
const char *INAME = "input.txt";
const char *ONAME = "outputs.txt";

int main(){
    //Создание потоков для чтения из файла
    ifstream in (INAME);
    ofstream out (ONAME);

    //Объявление переменных
    float array[N]; //массив вещеественных чисел
    float negSum; //Сумма негативных элементов
    int minI; //Индекс наименьшего элемента
    float min; //Минимальный элемент
    float max; //Максимвльный элемент
    int maxI; //Индекс наибольшего элемента
    float mulBetween; //Произведение элементов между максимальным и минимальным
    int i; //индекс для цикла
    int start;
    int end;
    i=0;
    //Заполнение массива числами из файла(пока не закончится файл)
    while (!in.eof()){
        in >> array[i];
        cout << "array [" << i<<"] = "<<array[i] << endl;
        i++;
    }


    //Инициализация переменных
    negSum = 0;
    start = 0;
    end = 0;
    mulBetween = 1;
    min = array[0];
    minI = 0;
    maxI = 0;
    max = array[0];

    //обработка массива
    //поиск суммы отрицательных
    //поиск наибольшего и наименьшего
    for(i = 0; i<N; i++){
        //Если элемент меньше нуля, тот прибавляем его к накопленной сумме
        if(array[i]<0){
            negSum += array[i];
        }//if (array[i] < 0)

        if(array[i] > max){
            max = array[i];
            maxI= i;
        }//if (array[i] > max)
        else if(array[i] < min){
            min = array[i];
            minI = i;
        }//else if (array[i] < min)
    }

    //Определяем границы интервала расчета произведения между наибольшим и наименьшим.
    if(minI < maxI){
        start = minI+1;
        end = maxI;
    }else{
        start = maxI+1;
        end = minI;
    }

    //расчет произведения элементов между наибольшим и наименьшим элементами массива
    for(i = start; i<end; i++){
        mulBetween *= array[i];
    }

    cout << "Минимальный элемент: " << min << " индекс: " << minI <<endl;
    cout << "Максимальный элемент: " << max << " индекс: " << maxI <<endl;
    cout << "Сумма отрицательных элементов: " << negSum << endl;
    cout << "Произведение между наименьшим и наибольшим: " << mulBetween << endl;


    //Закрываем файлы
    in.close();
    out.close();
}// main()