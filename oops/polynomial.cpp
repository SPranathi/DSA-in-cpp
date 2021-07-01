/*
Implement a polynomial class, with following properties and functions.
Properties :
1. An integer (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases
Input Format :
Line 1 : N, total number of terms in polynomial P1
Line 2 : N integers representing degree of P1 (separated by space)
Line 3 : N integers representing coefficients of P1 (separated by space)
Line 4 : M, total number of terms in polynomial P2
Line 5 : M integers representing degree of P2 (separated by space)
Line 6 : M integers representing coefficients of P2 (separated by space)
Line 7 : Integer C, choice representing the function to be called (See main for more details)
Sample Input 1 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
1
Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5
Sample Input 2 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
2
Sample Output 2 :
-4x0 -1x1 3x2 1x3 -4x5
Sample Input 3 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
3
Sample Output 3 :
4x1 2x2 5x3 5x4 -22x5 -6x6 12x7 -4x8
*/
#include<iostream>
#include<math.h>
using namespace std;

class polynomial{
    public:
    int *degcoeff;    //Name of the array
    int capacity;
    //default constructor
    polynomial(){
        this->degcoeff=new int[6];
        this->capacity=5;
    }
    //paramaterized constructor
    polynomial(int capacity){
        this->degcoeff=new int[capacity+1];
        this->capacity=capacity;
    }
    //copy constructor
    polynomial(polynomial const &p){
        int *newdeg=new int[p.capacity+1];

        for(int i=0;i<=p.capacity;i++)
            newdeg[i]=p.degcoeff[i];

        this->degcoeff=newdeg;
        this->capacity=p.capacity;
    }
    void setcoeffient(int degree,int coeffient){

        if(degree>capacity){
            int newcapacity=degree;
            int *newdeg=new int[newcapacity+1];

            //copy the contents from original to new
            for(int i=0;i<=capacity;i++)
                newdeg[i]=degcoeff[i];
            this->degcoeff=newdeg;
            this->capacity=newcapacity;

            //set the new coeffient
            degcoeff[degree]=coeffient;

        }
        else{
            degcoeff[degree]=coeffient;
        }
    }

    polynomial operator+(polynomial const &P2){
        int newcap=max(this->capacity,P2.capacity);

        polynomial P3(newcap);
        for(int i=0;i<=newcap;i++){
            if(i<=capacity && P2.capacity)
                P3.degcoeff[i]=this->degcoeff[i]+P2.degcoeff[i];
            else if(i<=capacity)
                P3.degcoeff[i]=this->degcoeff[i];
            else
            {
                P3.degcoeff[i]=P2.degcoeff[i];
            }
            
        }
        return P3;
    }

    polynomial operator-(polynomial const &P2){
        int newcap=max(this->capacity,P2.capacity);

        polynomial P3(newcap);
        for(int i=0;i<=newcap;i++){
            if(i<=capacity && P2.capacity)
                P3.degcoeff[i]=this->degcoeff[i]-P2.degcoeff[i];
            else if(i<=capacity)
                P3.degcoeff[i]=this->degcoeff[i];
            else
            {
                P3.degcoeff[i]=P2.degcoeff[i];
            }
            
        }
        return P3;
    }

    polynomial operator*(polynomial const &P2){
        int newcap=this->capacity+P2.capacity;
        polynomial P3(newcap);
        for(int i=0;i<=this->capacity;i++){
            for(int j=0;j<=P2.capacity;j++)
                P3.degcoeff[i+j]+=this->degcoeff[i]*P2.degcoeff[j];
        }
        return P3;
    }

    void operator=(polynomial const &p){
        int *newdeg=new int[p.capacity+1];
        //copy the contents
        for(int i=0;i<=p.capacity;i++)
            newdeg[i]=p.degcoeff[i];

        this->degcoeff=newdeg;
        this->capacity=p.capacity;
    }
    void print(){
        for(int i=0;i<=this->capacity;i++){
            if(degcoeff[i]!=0)
                cout<<degcoeff[i]<<"x"<<i<<" ";
            }
        cout<<"\n";
    }

};


int main(){
    int count1,count2,choice;
    cin>>count1;
    int *degree1=new int[count1];
    int *coeffient1=new int[count1];
    for(int i=0;i<count1;i++){
        cin>>degree1[i];
    }
    for(int i=0;i<count1;i++){
        cin>>coeffient1[i];
    }
    polynomial P1;
    for(int i=0;i<count1;i++){
        P1.setcoeffient(degree1[i],coeffient1[i]);
    }

    cin>>count2;
    int *degree2=new int[count2];
    int *coeffient2=new int [count2];
    for(int i=0;i<count2;i++){
        cin>>degree2[i];
    }
    for(int i=0;i<count2;i++){
        cin>>coeffient2[i];
    }
    polynomial P2;
    for(int i=0;i<count2;i++){
        P2.setcoeffient(degree2[i],coeffient2[i]);
    }

    cin>>choice;
    switch (choice)
    {
    case 1://Add
        {
        polynomial R1 = P1 + P2;
        R1.print();
        break;
        }
    case 2://Subtraction
        {
        polynomial R2=P1-P2;
        R2.print();
        break;
        }
    case 3://Multiplication
        {
        polynomial R3=P1*P2;
        R3.print();
        break;
        }
    case 4://copy constructor
        {
        polynomial R4(P1);
        if(R4.degcoeff==P1.degcoeff)
            cout<<"false"<<endl;
        else
        {
            cout<<"true"<<endl;
        }
        
        break;
        }
    case 5://copy assignment operator
        {
        polynomial R5=P1;
        if(R5.degcoeff==P1.degcoeff)
            cout<<"false"<<endl;
        else
        {
            cout<<"true"<<endl;
        }
        break;
        }
    default:
        break;
    }
}