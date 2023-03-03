#include<iostream>
using namespace std;

string reverseString(string str){
    if(str.length()==1)
       return str;
    
    int left = 0;
    int right = str.length()-1;
    
    while(left<right){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    return str;
}

// T.C.O(n)
// S.C.O(1)
