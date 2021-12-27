
#ifndef LAB2_TESTS_H
#define LAB2_TESTS_H
#include <cassert>
#include "Task1TextDistribution.h"
#include "Task2VectorMatrixDistribution.h"
#include "Task3HashTable.h"

void test_task1(){
    Sequence<string>* seq;
    string s = "qwer asd fgt ffx ff f vrfcfrc rvf rvrf r";
    int ar[10] = {1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
    seq = GetSeqFromString(s);
    int sizeOfPage = 3;
    SortedSequence<pair<int,string>>* sortedSeq = GetDistributionString(seq,sizeOfPage);
    for ( int i = 0; i < sortedSeq->GetLength(); i++)
    {
        assert(sortedSeq->Get(i).first == ar[i]);
    }
}

void test_task1_2(){
    Sequence<string>* seq;
    string s = "qwer asd fgt rc f";
    int ar[10] = {1, 1, 2, 2, 2,};
    seq = GetSeqFromString(s);
    int sizeOfPage = 5;
    SortedSequence<pair<int,string>>* sortedSeq = GetDistributionString(seq,sizeOfPage);
    for ( int i = 0; i < sortedSeq->GetLength(); i++)
    {
        assert(sortedSeq->Get(i).first == ar[i]);
    }
}

void test_task1_3(){
    Sequence<string>* seq;
    string s = "qwer asd fgt";
    int ar[10] = {1, 1, 1};
    seq = GetSeqFromString(s);
    int sizeOfPage = 7;
    SortedSequence<pair<int,string>>* sortedSeq = GetDistributionString(seq,sizeOfPage);
    for ( int i = 0; i < sortedSeq->GetLength(); i++)
    {
        assert(sortedSeq->Get(i).first == ar[i]);
    }
}

void test_task2(){
    int size = 10;
    int arr[10] = {1, 0,0,0,0, 2,3, 0,0, 4};
    int ar_i[4] = {1, 2, 3, 4};
    int ar_v[4] = {1, 6, 7, 10};
    SortedSequence<pair<int,int>>* res = GetDistributionVector(arr,size);
    for(int i = 0; i < res->GetLength();i++)
    {
        assert(res->Get(i).first == ar_v[i] && res->Get(i).second == ar_i[i]);
    }
}

void test_task2_2(){
    int size = 5;
    int arr[10] = {0, 0,10000,0,0};
    int ar_i[1] = {3};
    int ar_v[1] = {10000};
    SortedSequence<pair<int,int>>* res = GetDistributionVector(arr,size);
    for(int i = 0; i < res->GetLength();i++)
    {
        assert(res->Get(i).first == ar_i[i] && res->Get(i).second == ar_v[i]);
    }
}

void test_task2_2_1(){
    int ar[6] = {1, 0, 0, 2, 3, 0};
    int ar_c[3] = {1 ,1, 2};
    int ar_r[3] = {1, 2, 2};
    int ar_v[3] = {1, 2, 3};
    int count = 0;
    int rows = 2;
    int cols = 3;
    int** arr = new int* [rows];
    for(int i = 0; i < rows;i++)
    {
        arr[i] = new int[cols];
    }
    for(int i = 0; i < rows;i++)
    {
        for(int j = 0;j < cols;j++)
        {
            arr[i][j] = ar[count];
            count++;
        }
    }
    SortedSequence<Triple>* res = GetDistributionMatrix(arr,rows,cols);
    for(int i = 0; i < res->GetLength() ;i++)
    {
        assert(res->Get(i).row==ar_r[i] && res->Get(i).value==ar_v[i] && res->Get(i).col==ar_c[i]);
    }
}

void test_task2_2_2(){
    int ar[6] = {1, 0, 0, 2};
    int ar_c[3] = {1 ,2};
    int ar_r[3] = {1, 2};
    int ar_v[3] = {1, 2};
    int count = 0;
    int rows = 2;
    int cols = 2;
    int** arr = new int* [rows];
    for(int i = 0; i < rows;i++)
    {
        arr[i] = new int[cols];
    }
    for(int i = 0; i < rows;i++)
    {
        for(int j = 0;j < cols;j++)
        {
            arr[i][j] = ar[count];
            count++;
        }
    }
    SortedSequence<Triple>* res = GetDistributionMatrix(arr,rows,cols);
    for(int i = 0; i < res->GetLength() ;i++)
    {
        assert(res->Get(i).row==ar_r[i] && res->Get(i).value==ar_v[i] && res->Get(i).col==ar_c[i]);
    }
}

void test_task3(){
    Sequence<string>* seq;
    string s = "q qw qwe qwer qwert";
    int values[5] = {1, 2, 3, 4, 5};
    seq = GetSeqFromString(s);
    Dictionary<string,int> dict = Dictionary<string,int>();
    for(int i = 0; i < seq->GetLength(); i++)
    {
        dict.Add(seq->Get(i),values[i]);
    }
    for(int i = 0;i< 5;i++)
    {
        assert(dict.Get(seq->Get(i))==values[i]);
    }
}

void test_task3_2(){
    Sequence<string>* seq;
    string s = "q qw qwe qwer  qwert qwerty qwertyu";
    int values[8] = {1, 2, 3, 4, 5, 6, 7};
    seq = GetSeqFromString(s);
    Dictionary<string,int> dict = Dictionary<string,int>();
    for(int i = 0; i < seq->GetLength(); i++)
    {
        dict.Add(seq->Get(i),values[i]);
    }
    for(int i = 0;i< 7;i++)
    {
        assert(dict.Get(seq->Get(i))==values[i]);
    }
    assert(dict.GetSize() == 100);
}

void test_task3_3(){
    Sequence<string>* seq;
    string s = "q qw qwe qwer qwert qwerty qwertyu";
    double values[8] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    seq = GetSeqFromString(s);
    Dictionary<string,double> dict = Dictionary<string,double>();
    for(int i = 0; i < seq->GetLength(); i++)
    {
        dict.Add(seq->Get(i),values[i]);
    }
    for(int i = 0;i< 7;i++)
    {
        assert(dict.Get(seq->Get(i))==values[i]);
    }
    assert(dict.GetSize() == 100);
}

void test_task3_4(){
    Sequence<string>* seq;
    string s = "q qw qwe qwer qwert qwerty qwertyu";
    int values[7] = {1, 2, 3, 4, 5, 6, 7};
    seq = GetSeqFromString(s);
    Dictionary<string,int> dict = Dictionary<string,int>();
    for(int i = 0; i < seq->GetLength(); i++)
    {
        dict.Add(seq->Get(i),values[i]);
    }
    dict.Remove("q");
    for(int i = 0;i< 6;i++)
    {
        assert(dict.Get(seq->Get(i+1))==values[i+1]);
    }
    assert(!(dict.Get(seq->Get(0))==values[0]));
    assert(dict.GetSize() == 100);
}

void all_tests(){
    test_task1();
    test_task1_2();
    test_task1_3();
    test_task2();
    test_task2_2();
    test_task2_2_1();
    test_task2_2_2();
    test_task3();
    test_task3_2();
    test_task3_3();
    test_task3_4();
}
#endif //LAB2_TESTS_H
