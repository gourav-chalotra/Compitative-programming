#include<bits/stdc++.h>
using namespace std;
// queue implementation using array
class Queue{
    private:
        vector<int>q;
        int start;
        int Size;
    public:
    Queue(){
        start = -1;
        Size = 0;
    }
    void push(int num){
        q.push_back(num);
        start++;
        Size++;
    }
    void pop()
    {
        if(start < q.size())
        {
            start++;
            Size--;
        }
        else
            cout << "there is no element remain in the queue." << endl;
    }
    void size(){
        cout << "size is : "<< this->Size << endl;
    }
    void display(){
        for(int i = 0; i < q.size(); i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }

};
int main()
{
    Queue q;
    q.push(12);
    q.push(12);
    q.push(10);
    q.display();
    q.size();
    q.pop();
    q.size();
}