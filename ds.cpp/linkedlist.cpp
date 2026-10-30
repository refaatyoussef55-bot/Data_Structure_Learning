#include<bits/stdc++.h>
#include "linkedlist.h"
#define nl "\n"
#define ll long long
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<< nl 
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
     LinkedList l1 ;
     l1.addNode(1) ;
        l1.addNode(2) ;
        l1.addNode(3) ;
        l1.addNode(4) ;
        l1.displayForward() ;
        l1.insertAt(2, 5) ;
        l1.displayForward() ;
        l1.deleteNode(3) ;
        l1.displayForward() ;
        l1.deleteAt(1) ;
        l1.displayForward() ;
        l1.displayReverse() ;
        l1.clear() ;
       // yarab accepted
       // # future software engineer
       r0 ; 
    }