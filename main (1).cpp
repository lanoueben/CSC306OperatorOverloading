#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class IntMatrix{
private: 
    int x[3][4];
public:
    
    //default constructor, sets the x[i][j] as i+j
    
    IntMatrix(){
        for (int i = 0; i != 3; i++)
        {
            for(int j = 0; j != 4; j++)
            {
                x[i][j] = i + j;
            }
        }
    }
    
    //Tests to see if 2 IntMatrix(es) are equal
    
    bool operator==(const IntMatrix& y)const{
        for (int i = 0; i != 3; i++){
            for (int j = 0; j != 4; j++){
                if(this->x[i][j] != y.x[i][j])
                    return false;
            }
        }
        return true;
    };
    
    //Print method
    
    void Print(){
        for(int i = 0; i != 3; i++){
            for(int j = 0; j != 4; j++){
                cout << x[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    //operator overload that overloads the [] function.
    //returns the array of int*
    
    int* operator[](const int b){
        return x[b];
    }
    
    //operator overload that overloads the () function,
    //the parameters are (int a,int b).
    //This returns changes all of a's values in the 2d array
    //with b
    
    void operator()(const int a, const int b){
        for(int i = 0; i != 3; i++){
            for(int j = 0; j != 4; j++){
                if(x[i][j] == a){
                    x[i][j] = b;
                }
            }
        }
    }
    
    //This returns an IntMatrix where the 2
    //IntMatrix(es) added add each 2d array element with
    //each other.
    
    IntMatrix operator+(const IntMatrix& b){
        IntMatrix z;
        for(int i = 0; i != 3; i++){
            for(int j = 0; j != 4; j++){
                z[i][j] = x[i][j] + b.x[i][j];
            }
        }
        return z;
    }
    
    
    
};

class WordMatrix{
private:
    char* x[5];
    int _ctr;
public:
    
    //Constructor, sets all the array char* to nullptr
    
    WordMatrix(){
        _ctr = 0;
        for(int i = 0; i !=5; i++){
            x[i] = nullptr;  
        }
    }
    
    //Collaborated with Jake and Alex
    //Adds a char array to the char*
    //array
    
    void AddWord(char* b){
        x[_ctr] = b;
        _ctr++;
    }
    
    //print method
    
    void Print(){
        for(int i = 0; i != 5; i++){
            if(x[i] != nullptr){
                cout << x[i] << " ";
            }
        }
        cout << endl;
    }
    
    //operator overload that overloads the assignment operator.
    //This makes whatever the explicit argument add an element
    //to the implicit argument's char* array
    
    const WordMatrix& operator=(char* b){
        AddWord(b);
    }
    
    //collaborated with Alex and Jake
    //operator overload that overloads the [] on a 
    //WordMatrix object. Returns the pointer at location
    //x[b] with b being the explicit argument
    char*& operator[](int b) {
        return x[b];
    }
};


int  main(){	
    
    IntMatrix m, n;
    cout << "*** Printing if M == N" << endl;
    cout << (m == n) << endl;
    cout << "\n*** Printing M" << endl;
    m.Print();
    m[1][1] = 14;
    cout << "\n*** Printing M - changed to 14" << endl;
    m.Print();
    m(2,17);  // replace all 2's with a 17
    cout << "\n*** Printing M - changed 2 to 17" << endl;
    m.Print();
    cout << "\n*** Printing if M == N" << endl;
    cout << (m == n) << endl;
    IntMatrix p = m+n;
    cout << "\n*** Printing P" << endl;
    p.Print();
    {WordMatrix a;
     a.AddWord("hello");
     cout << "\n*** Printing A" << endl;
     a.Print();
    }
    WordMatrix a;
    a.AddWord("today");
    a.AddWord("hello");
    cout << "\n*** Printing A" << endl;
    a.Print();
    a = "world";
    cout << "\n*** Printing A" << endl;
    a.Print(); 
    WordMatrix b = a;
    cout << "\n*** Printing B" << endl;
    b.Print();
    cout << "\n*** Adding Homework" << endl;
    a.AddWord("homework");
    a.Print();
    b.Print();
    cout << "\n*** b[0] = a[3]" << endl;
    b[0] = a[3];
    a.Print();
    b.Print();
    WordMatrix c;
    c = b = a;
    cout << "\n*** Printing A" << endl;
    a.Print();
    cout << "\n*** Printing B" << endl;
    b.Print();
    cout << "\n*** Printing C" << endl;
    c.Print();
  
    return 0;
}
