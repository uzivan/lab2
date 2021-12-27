#pragma once
#include "Sequence.h"
#include "SortedSequence.h"
#include "Functions_1.h"
void Task1()
{
    Sequence<string>* seq;
    string s;
    int sizeOfPage;
    cout <<"Enter text"<<endl;
    getline(cin,s);
    cout <<"Enter size of page"<<endl;
    cin >> sizeOfPage;
    seq = GetSeqFromString(s);
    SortedSequence<pair<int,string>>* sortedSeq = GetDistributionString(seq,sizeOfPage);
    for ( int i = 0; i < sortedSeq->GetLength(); i++)
    {
        /*if(i%5 == 0)
            cout<<endl;*/
        cout << sortedSeq->Get(i).second<<" " << sortedSeq->Get(i).first<<endl;
    }
    cout<<endl;
}