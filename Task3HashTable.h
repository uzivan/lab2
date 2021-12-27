#pragma once
#include "Functions_1.h"
#include "Dictionary.h"
#include "vector"
using namespace std;
void Task3()
{
    Sequence<string>* seq;
    string s;
    cout <<"Enter text"<<endl;
    getline(cin,s);
    seq = GetSeqFromString(s);
    Dictionary<string,int> dict = Dictionary<string,int>();
    for(int i = 0; i < seq->GetLength(); i++)
    {
        dict.Add(seq->Get(i),0);
    }
    dict.Print();
    dict.Remove("q");
    cout << endl;
    dict.Print();
}