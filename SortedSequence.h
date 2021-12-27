#pragma once
#include "Sequence.h"
#include "ArraySequence.h"
#include "SortedSequence.h"
class Exception2{};
class Node
{
public:
    string value;
    int count;
    Node()
    {
        this->value = "";
        this->count = 0;
    }
    Node(string value)
    {
        this->value = value;
        this->count = 0;
    }
};
class Triple
{
public:
    Triple()
    {
        this->row = 0;
        this->col = 0;
        this->value = 0;
    }
    Triple(int row, int col, int value)
    {
        this->row = row;
        this->col = col;
        this->value = value;
    }
    int row;
    int col;
    int value;
};

bool operator ==(const pair<int,string>& p1,const pair<int,string>& p2)
{
    bool result = false;
    if((p1.first==p2.first) && (p1.second == p2.second))
        result = true;
    return result;
}
bool operator >(const pair<int,string>& p1,const pair<int,string>& p2)
{
    bool result = false;
    if(p1.first > p2.first)
        result = true;
    return result;
}
bool operator >=(const pair<int,string>& p1,const pair<int,string>& p2)
{
    bool result = false;
    if(p1.first >= p2.first)
        result = true;
    return result;
}
bool operator <(const pair<int,string>& p1,const pair<int,string>& p2)
{
    bool result = false;
    if(p1.first < p2.first)
        result = true;
    return result;
}

bool operator ==(const Triple& p1,const Triple& p2)
{
    if(p1.row == p2.row && p1.col == p2.col)
        return true;
    else return false;
}
bool operator >=(const Triple& p1,const Triple& p2)
{
    if(p1.row >= p2.row && p1.col >= p2.col)
        return true;
    else return false;
}
bool operator >(const Triple& p1,const Triple& p2)
{
    if(p1.row == p2.row && p1.col > p2.col)
        return true;
    else if(p1.row > p2.row)
        return true;
    else return false;
}
bool operator <(const Triple& p1,const Triple& p2)
{
    if(p1.row == p2.row && p1.col < p2.col)
        return true;
    else if(p1.row < p2.row)
        return true;
    else return false;
}
bool operator ==(const Node& p1,const Node& p2)
{
    if(p1.value == p2.value)
        return true;
    else return false;
}
bool operator >=(const Node& p1,const Node& p2)
{
    if(p1.value >= p2.value)
        return true;
    else return false;
}
bool operator >(const Node& p1,const Node& p2)
{
    if(p1.value > p2.value)
        return true;
    else return false;
}
bool operator <(const Node& p1,const Node& p2)
{
    if(p1.value < p2.value)
        return true;
    else return false;
}
template<class T>
class SortedSequence
{
private:
    int size;
    Sequence<T>* items;
public:
    SortedSequence()
    {
        this->size = 0;
        this->items = new ArraySequence<T>();
    }
    SortedSequence(Sequence<T>* items)
    {
        this->size = items->GetLength();
        this->items = items;
    }
    SortedSequence(int size)
    {
        this->size = size;
        this->items = new ArraySequence<T>(size);
    }
    int GetLength()
    {
        return this->size;
    }
    bool GetIsEmpty()
    {
        return this->size == 0;
    }
    T Get(int index)
    {
        return this->items->Get(index);
    }
    T GetFirst()
    {
        return this->items->GetFirst();
    }
    T GetLast()
    {
        return this->items->GetLast();
    }
    int IndexOf(T item)
    {
        return this->items->BinSearch(item);
    }
    SortedSequence GetSubSequence(int startIndex, int endIndex)
    {
        if(this->GetIsEmpty())
            throw new Exception2;
        T* arr = new T[endIndex - startIndex + 1];
        for (int i = 0; i <= endIndex - startIndex + 1; i++)
        {
            arr[i] = this->items->Get(i+ startIndex);
        }
        Sequence<T>* newSeq = new ArraySequence<T>(arr, endIndex - startIndex + 1);
        SortedSequence<T> sortSeq = SortedSequence<T>(newSeq);
        return sortSeq;
    }
    void Add(T item) {
        if (this->GetLength() == 0) {
            this->items->Append(item);
            this->size = this->items->GetLength();
            return;
        } else if (item < this->GetFirst()) {
            this->items->Append(item);
            this->size = this->items->GetLength();
            return;
        } else if (item > this->GetLast()) {
            this->items->Prepend(item);
            this->size = this->items->GetLength();
            return;
        }
        int i = 0;
        while(item >= this->Get(i) && i < this->GetLength())
        {
            i++;
            if(i == this->GetLength())
                break;
        }
        ArraySequence<T>* arr = new ArraySequence<T>();
        for(int j = 0; j < i;j++)
        {
            arr->Prepend(this->Get(j));
        }
        arr->Prepend(item);
        for(int j = i; j < this->GetLength();j++)
        {
            arr->Prepend(this->Get(j));
        }
        this->items = arr;
        this->size = this->items->GetLength();
    }
};