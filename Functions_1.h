#pragma once
#include "SortedSequence.h"
#include "Sequence.h"
using namespace std;
Sequence<string>* GetSeqFromString(string s)
{
    Sequence<string>* result = new ArraySequence<string>();
    int i = 0;
    string tWord;
    while (i < s.size())
    {
        if(s[i] == ' ')
        {
            i++;
            continue;
        } else
        {
            while ((s[i] != ' ') && (i<s.size()))
            {
                tWord+=s[i];
                i++;
            }
            result->Prepend(tWord);
            tWord = "";
        }
    }
    return result;
}
SortedSequence<pair<int,string>>* GetDistributionString(Sequence<string>* seq,int sizeOfPage)
{
    int page = 1;
    int i = 0;
    int j = 0;
    bool flag = true;
    SortedSequence<pair<int,string>>* res = new SortedSequence<pair<int,string>>();
    while(flag)
    {
        if(j >= seq->GetLength())
        {
            flag = false;
            continue;
        }
        if(page == 1)
        {
            i = 0;
            while(j < seq->GetLength() && i < sizeOfPage/2)
            {
                res->Add(pair<int,string>(page,seq->Get(j)));
                i++;
                j++;
            }
            page++;
            continue;
        }
        if(page % 10 == 0)
        {
            i = 0;
            while(j < seq->GetLength() && i < sizeOfPage*3/4)
            {
                res->Add(pair<int,string>(page,seq->Get(j)));
                i++;
                j++;
            }
            page++;
            continue;
        }
        i = 0;
        while(j < seq->GetLength() && i < sizeOfPage)
        {
            res->Add(pair<int,string>(page,seq->Get(j)));
            i++;
            j++;
        }
        page++;
    }
    return res;
}

SortedSequence<pair<int,int>>* GetDistributionVector(int* arr,int size)
{
    SortedSequence<pair<int,int>>* res = new SortedSequence<pair<int,int>>();
    for(int i = 0; i < size;i++)
    {
        if(arr[i] != 0)
        {
            res->Add(pair<int,int>(i+1,arr[i]));
        }
    }
    return res;
}
SortedSequence<Triple>* GetDistributionMatrix(int** arr,int rows,int cols)
{
    SortedSequence<Triple>* res = new SortedSequence<Triple>();
    for(int i = 0; i < rows;i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(arr[i][j] != 0)
                res->Add(Triple(i+1,j+1,arr[i][j]));
        }
    }
    return res;
}