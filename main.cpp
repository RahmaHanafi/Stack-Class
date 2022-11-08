#include <iostream>

using namespace std;
class Stack{

private:
    int* arr;
    int siz;
    int top;

public:
    Stack(){
        cout<<"Empty constructor.\n";
        siz = 0;
        top = 0;
        arr = new int[5];
    }

    Stack(int s){
        cout<<"Parameterize constructor.\n";
        siz = s;
        top = 0;
        arr = new int[siz];
    }

    Stack(const Stack& old){
        cout<<"Copy Constructor.\n";
        this->top = old.top;
        siz = old.siz;
        arr = new int[siz];
        for(int i = 0 ; i<top ; i++){
            this->arr[i] = old.arr[i];
        }
    }

    int getTop(){
        return top;
    }

    void Push(int num){
        if(top<siz){
            arr[top]=num;
            top++;
        }
        else{
            cout<<"Full Stack\n";
        }
    }

    void Pop(){
        if(top>0){
            --top;
            //arr[top]=-99;
        }
        else{
            cout<<"Empty Stack\n";
        }
    }

    int IsFull(){
        return top=siz;
    }

    int IsEmpty(){
        return top=0;
    }

    Stack operator+(const Stack& right){

        Stack retVal(this->siz + right.siz);
        for(int i = 0 ; i < this->top ; i++){
            retVal.Push(this->arr[i]);
        }
        for(int i = 0 ; i< right.top ;i++){
            retVal.Push(right.arr[i]);
        }
        return retVal;
    }

    Stack& operator=(const Stack& right){

        delete [] arr;
        top = right.top;
        siz = right.siz;
        arr = new int[siz];
        for(int i=0;i<right.top;i++){
            arr[i]= right.arr[i];
        }
        return *this;
    }

    Stack reverseStack(){

        Stack retVal(this->siz);
        for(int i = this->top-1 ; i >= 0 ; i--){
            retVal.Push(this->arr[i]);
        }
        return retVal;
    }

    int operator==(Stack right){
        int coun = 0;
        for(int i=0;i<this->top;i++){
            for(int j=0;j<right.top;j++){
                if(arr[i]==right.arr[j]){
                    coun++;
                    break;
                }
            }
        }
        if(coun==this->top){
            return 1;
        }
        else return 0;

    }

    friend void printStack(Stack s);

    ~Stack(){
        cout<<"Destructor\n";
        for(int i=0;i<top;i++){
            arr[i]=-99;
        }
        delete [] arr;
    }
};

void printStack(Stack s){
    for(int i=0;i<s.top;i++){
        cout<<s.arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    Stack s(6);
    s.Push(7);
    s.Push(11);
    s.Push(4);
    s.Push(9);
    s.Push(17);
    s.Push(1);
    s.Push(3);
    printStack(s);
    s.Pop();
    s.Pop();
    s.Push(5);
    printStack(s);

    Stack s1(3);
    s1.Push(15);
    s1.Push(2);
    printStack(s1);

    Stack s2=s1+s;
    printStack(s2);

    Stack s3=s2.reverseStack();
    //s3.Push(50);
    printStack(s3);
    printStack(s2);


    if(s3==s2)cout<<"2 stacks are the same.\n";
    else cout<<"s3 != s2\n";


    //printStack(s2);


    return 0;
}
