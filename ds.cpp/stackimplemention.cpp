#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define yes cout<<"Yes"<<nl
#define no cout<<"No"<< nl 
#define r0 return 0 ;
#define cin_arr for(int i = 0 ; i < n ; i++) { cin >> arr[i] ; }
#define cout_arr for(int i = 0 ; i < n ; i++) { cout << arr[i] << nl ; }
using namespace std;

class stackk{
    int *arr;
    int top;
    int size;

    public:

    stackk(int size){
        this->size = size; 
        arr = new int[size];
        top = -1;
    }

    bool isempty(){
        return top == -1;
    }

    bool isfull(){
        return top == size - 1;
    }

    void push(int element){
        if(!isfull()){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<nl;
        }
    }

    void pop(){
        if(!isempty()){
            cout<<"Popped Element: "<<arr[top]<<nl;
            delete &arr[top];
            top--;
        }
        else{
            cout<<"Stack Underflow"<<nl;
        }
    }

    void display(){
        if(!isempty()){
            for(int i=top; i>=0; i--){
                cout<<arr[i]<<" ";
            }
            cout<<nl;
        }
        else{
            cout<<"Stack is empty"<<nl;
        }
    }

    void topElement(){
        if(!isempty()){
            cout<<"Top Element: "<<arr[top]<<nl;
        }
        else{
            cout<<"Stack is empty"<<nl;
        }
    }

};

void fastcode(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void) {
    fastcode();
	stackk st(5);
   st.push(10);
   st.push(20);
   st.isempty() ? cout<<"Stack is empty"<<nl : cout<<"Stack is not empty"<<nl;
   st.display();
   st.isfull() ? cout<<"Stack is full"<<nl : cout<<"Stack is not full"<<nl;
   st.push(30);
   st.push(40);
    st.push(50);
    st.isfull() ? cout<<"Stack is full"<<nl : cout<<"Stack is not full"<<nl;
    st.display();
    st.topElement();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.isempty() ? cout<<"Stack is empty"<<nl : cout<<"Stack is not empty"<<nl;
    st.isfull() ? cout<<"Stack is full"<<nl : cout<<"Stack is not full"<<nl;
    // yarab accepted
       // # future software engineer
       r0 ; 
    }