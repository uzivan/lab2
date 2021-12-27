#include <iostream>
using namespace std;
void Task2()
{
    cout<<"Enter size"<<endl;
    int size;
    cin>> size;
    int* arr = new int[size];
    for(int i = 0; i < size;i++)
    {
        cin >> arr[i];
    }
    SortedSequence<pair<int,int>>* res = GetDistributionVector(arr,size);
    for(int i = 0; i < res->GetLength();i++)
    {
        cout <<"index="<< res->Get(i).first<< " " <<"value"<< res->Get(i).second<<"   ";
    }
}
void Task2_2()
{
    cout<<"Enter value of rows"<<endl;
    int rows;
    cin >> rows;
    cout<<"Enter value of cols"<<endl;
    int cols;
    cin >> cols;
    int** arr = new int* [rows];
    for(int i = 0; i < rows;i++)
    {
        arr[i] = new int[cols];
    }
    for(int i = 0; i < rows;i++)
    {
        for(int j = 0;j < cols;j++)
        {
            cin >> arr[i][j];
        }
    }
    SortedSequence<Triple>* res = GetDistributionMatrix(arr,rows,cols);
    for(int i = 0; i < res->GetLength() ;i++)
    {
        cout << "row="<<res->Get(i).row<<" "<<"col="<<res->Get(i).col<<" "<<res->Get(i).value<<"   ";
    }
}