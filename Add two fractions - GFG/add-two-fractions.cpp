//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void addFraction(int num1, int den1, int num2,
                 int den2);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c,d,resultNum,resultDen;
        cin>>a>>b>>c>>d;
        addFraction(a,b,c,d);

    }
}

// } Driver Code Ends


/*You are required to complete this function*/

int GCD(int A,int B){
    if(A==0) return B;
    else if(B==0) return A;
    else if(A==B) return A;
    else if(A>B) return GCD(A-B,B);
    else return GCD(A,B-A);
}

int LCM(int A,int B){
    return (A/GCD(A,B))*B;
}

void addFraction(int num1, int den1, int num2,int den2)
{
  int denominator = LCM(den1,den2);
  int numerator = (denominator/den1)*num1 + (denominator/den2)*num2;
  
  int hcf = GCD(numerator,denominator);
  numerator = numerator/hcf;
  denominator = denominator/hcf;
  
  cout<<numerator<<"/"<<denominator<<endl;
  return ;
}