#include "Sequence.h"
#include "ArraySequence.h"
using namespace std;
template <class T,class V>
struct TableElement
{
    T key;
    V value;
};
template<class T,class V>
class Dictionary
{
private:
    Sequence<ArraySequence<TableElement<T,V>>>* data;
    int size;
    int count;
    int HashFunction(T key)
    {
        int h = hash<T>()(key);
        if(h < 0)
            h*=-1;
        h = h%this->size;
        return h;
    }
    void AddInside(TableElement<T,V> element, int index)
    {
        count++;
        if(!this->IsEmpty(index))
        {
            //ArraySequence<TableElement<T,V>> arreyelement = new ArraySequence<TableElement<T,V>>;
            ArraySequence<TableElement<T,V>> arreyelement;
            arreyelement.Prepend(element);
            this->data->Set(arreyelement,index);
            return;
        }
        else
            for(int i =0;i < data->Get(index).GetLength();i++)
            {
                if(data->Get(index).Get(i).key == element.key) return;
            }
            this->data->Get(index).Prepend(element);
        return;
    }
    void Resize()
    {
        this->count = 0;
        int newSize;
        if(this->size == 0)
            newSize = 10;
        else newSize = this->size * 10;
        Sequence<ArraySequence<TableElement<T,V>>>* oldSequence = this->data;
        Sequence<ArraySequence<TableElement<T,V>>>* newSequence = new ArraySequence<ArraySequence<TableElement<T,V>>>(newSize);
        this->size = newSize;
        this->data = newSequence;
        for(int i = 0; i < oldSequence->GetLength(); i++)
        {
            if(oldSequence->Get(i).GetLength())
            {
                for(int j=0;j<oldSequence->Get(i).GetLength();j++)
                {
                    //cout << oldSequence->Get(i).Get(j).key <<" "<< oldSequence->Get(i).Get(j).value;
                    this->Add(oldSequence->Get(i).Get(j).key, oldSequence->Get(i).Get(j).value);
                }
            }
        }
    }
public:
    V Get(T key)
    {
        V value;
        int index = HashFunction(key);
        for(int i = 0;i < data->Get(index).GetLength();i++)
        {
            if(data->Get(index).Get(i).key == key) value = data->Get(index).Get(i).value;
        }
        return value;
    }
    Dictionary()
    {
        this->count = 0;
        this->size = 0;
        this->data = new ArraySequence<ArraySequence<TableElement<T,V>>>(0);
    }
    const int& GetSize()
    {
        return this->size;
    }
    /*int GetValuesCount()
    {
        int count = 0;
        for(int i = 0; i < this->GetSize(); i++)
        {
            if(!IsEmpty(i))
                count++;
        }
        return count;
    }*/
    bool IsEmpty(int index)
    {
        if(this->data->Get(index).GetLength())
            return true;
        return false;
    }

    void Remove(T key)
    {
        V index = HashFunction(key);
        ArraySequence<TableElement<T,V>> arreyelement;
        for(int i = 0 ;i< this->data->Get(index).GetLength();i++)
        {
            if(!(this->data->Get(index).Get(i).key == key))
            {
                arreyelement.Prepend(this->data->Get(index).Get(i));
            }
        }
        this->data->Set(arreyelement, index);
    }

    void Add(T key,V value)
    {
        TableElement<T,V> element;
        element.key = key;
        element.value = value;
        if(this->size == 0)
            this->Resize();
        if((this->GetSize()*0.5) <= (this->count)) {this->Resize();}
        this->AddInside(element,this->HashFunction(key));
    }
    void Print()
    {
        for(int i = 0; i < this->size;i++)
        {
            if(this->data->Get(i).GetLength())
            {
                for(int j = 0;j<data->Get(i).GetLength();j++)
                {
                    cout << i << " key = " << this->data->Get(i).Get(j).key << "   value = "<< this->data->Get(i).Get(j).value;
                    cout << endl;
                }
            }
        }
    }

};