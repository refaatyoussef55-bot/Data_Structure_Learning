#include<bits/stdc++.h>
#include "doublelinkedlist.h"
#define nl "\n"
#define ll long long
#define yes cout<<"Yes"<<nl
#define no cout<<"No"<< nl 
#define r0 return 0 ;
#define cin_arr for(int i = 0 ; i < n ; i++) { cin >> arr[i] ; }
#define cout_arr for(int i = 0 ; i < n ; i++) { cout << arr[i] << nl ; }
using namespace std;
void fastcode(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(void) {
    fastcode();
	DoubleLinkedList list;
    list.addNode(10);
    list.addNode(20);
    list.addNode(30);
    list.addNode(40);
    list.addNode(50);

    list.displayForward(); // Output: 10 20 30 40 50
    list.displayBackward(); // Output: 50 40 30 20 10

    list.deleteNode(10);
    list.displayForward(); // Output: 20 30 40 50

    list.deleteNode(30);
    list.displayForward(); // Output: 20 40 50

    list.deleteNode(50);
    list.displayForward(); // Output: 20 40

    list.deleteNode(30); // Node with value 30 not found.

    list.deleteNode(20);
    list.displayForward(); // Output: 40

    list.deleteNode(40);
    list.displayForward(); // Output: (empty)

    list.deleteNode(100); // Node with value 100 not found.

    list.addNode(60);
    list.addNode(70);
    list.addNode(80);
    list.addNode(90);
    list.addNode(100);

    list.displayForward(); // Output: 60 70 80 90 100
    cout << "Number of nodes: " << list.countNodes() << endl; // Output: 5
    cout << "Value at index 2: " << list.getbyindex(2) << endl; // Output: 80
    // yarab accepted
       // # future software engineer
       r0 ; 
    }