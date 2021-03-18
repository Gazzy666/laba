/*****************************************************
* Project type:       Win32 Console Application      *
* Project name:       Laboratory work				 *
* File name:          main.cpp  				     *
* Language:           C++; Visual Studio 2019        *
* Programmer(s):      Anisimov �.�., Artamonov D.D.  *
* Modified by:        Artamonov D.D.                 *
* Created:            07.03.2021                     *
* Last revision:      17.03.2021                     *
* Comment:            ���������� �������             *
******************************************************/

//
// Created by Daniil Artamonov on 25.02.2021.
//

//���������� ����� �����
#include <fstream>
#include <iostream>

using namespace std;

const int N = 9;
const char* INAME = "/Users/dacoder/development/untitled/input.txt";
const char* ONAME = "/Users/dacoder/development/untitled/output.txt";

///���������� �������
void closeStreams(ifstream& in, ofstream& out);

int main() {
    //�������� ������� ��� ������ �� �����
    ifstream in(INAME);
    ofstream out(ONAME);

    //���������� ����������
    float array[N]; //������ ������������� �����
    float negSum; //����� ���������� ���������
    int minI; //������ ����������� ��������
    float min; //����������� �������
    float max; //������������ �������
    int maxI; //������ ����������� ��������
    float mulBetween; //������������ ��������� ����� ������������ � �����������
    int i; //������ ��� �����
    int start;
    int end;
    i = 0;

    //�������� ��� ���� ������
    if (!in) {
        cout << "���� �� ������." << endl;
        //�������� ������
        closeStreams(in, out);
        return 1;
    }//if(!in)

    //�������� �� ��, ��� ���� �� ������
    if (in.peek() == EOF) {
        cout << "������ ������ ����." << endl;
        //�������� ������
        closeStreams(in, out);
        //����� � ����� 2
        return 2;
    }//if(in.peek() == EOF)

    //�������� �� ������������ �����.
    if (in.fail()) {
        cout << "������ ��� ������ �����." << endl;
        //�������� ������
        closeStreams(in, out);
        //����� � ����� 3
        return 3;
    }//if(in.fail())

    //���������� ������� ������� �� �����(���� �� ���������� ����)
    while (!in.eof()) {
        //�������� ������������ �������
        if (i >= N) {
            cout << "������ ������ ��������� " << N << " ���������. ������� ������ " << N << " ���������." << endl;
            //�������� ������
            closeStreams(in, out);
            //����� � ����� 4
            return 4;
        }//if

        in >> array[i];
        cout << "array [" << i << "] = " << array[i] << endl;
        i++;
    }//while

    //�������� �������������� �������
    if (i < N) {
        cout << "������ ������ ��������� " << N << " ���������." << endl << "�� ����� " << i << " ���������." << endl;
        //�������� ������
        closeStreams(in, out);
        //����� � ����� 5
        return 5;
    }//if

    //������������� ����������
    negSum = 0;
    start = 0;
    end = 0;
    mulBetween = 1;
    min = array[0];
    minI = 0;
    maxI = 0;
    max = array[0];

    //��������� �������
    //����� ����� �������������
    //����� ����������� � �����������
    for (i = 0; i < N; i++) {
        //���� ������� ������ ����, ��� ���������� ��� � ����������� �����
        if (array[i] < 0) {
            negSum += array[i];
        }//if (array[i] < 0)

        if (array[i] > max) {
            max = array[i];
            maxI = i;
        }//if (array[i] > max)
        else if (array[i] < min) {
            min = array[i];
            minI = i;
        }//else if (array[i] < min)
    }

    //���������� ������� ��������� ������� ������������ ����� ���������� � ����������.
    if (minI < maxI) {
        start = minI + 1;
        end = maxI;
    }
    else {
        start = maxI + 1;
        end = minI;
    }

    //������ ������������ ��������� ����� ���������� � ���������� ���������� �������
    for (i = start; i < end; i++) {
        mulBetween *= array[i];
    }

    cout << "����������� �������: " << min << " ������: " << minI << endl;
    cout << "������������ �������: " << max << " ������: " << maxI << endl;
    cout << "����� ������������� ���������: " << negSum << endl;
    cout << "������������ ��������� ����� ���������� � ����������: " << mulBetween << endl;

    out << "����������� �������: " << min << " ������: " << minI << endl;
    out << "������������ �������: " << max << " ������: " << maxI << endl;
    out << "����� ������������� ���������: " << negSum << endl;
    out << "������������ ��������� ����� ���������� � ����������: " << mulBetween << endl;


    //��������� �����
    closeStreams(in, out);
}// main()


///���������� �������
void closeStreams(ifstream& in, ofstream& out) {
    in.close();
    out.close();
}