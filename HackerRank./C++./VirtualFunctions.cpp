#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include "memory.h"

class Person
{
protected: 
    std::string sName;
    unsigned int nAge;
    
    unsigned int nId;
    
public:
    Person() : sName(""), nAge(0), nId(0) {}
    
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person
{  
private:
    unsigned int nPublications;
    static unsigned int nIdCounter;
    
public:
    
    Professor() : nPublications(0) { nId = ++nIdCounter; }
    
    virtual void getdata()
    {
        char buf[256];
        memset(buf, 0, 256);
        
        scanf("%s", buf);
        sName = std::string(buf);
        
        scanf("%d", &nAge);
        scanf("%d", &nPublications);
    }
    
    virtual void putdata()
    {
        std::cout << sName << " " << nAge << " " << nPublications << " " << nId << std::endl;
    }
};

unsigned int Professor::nIdCounter = 0;

class Student : public Person
{  
private:
    unsigned int nSum;
    static unsigned int nIdCounter;
    
    
public:
    
    Student() : nSum(0) { nId = ++nIdCounter; }
    
    virtual void getdata()
    {
        char buf[256];
        memset(buf, 0, 256);
        
        scanf("%s", buf);
        sName = std::string(buf);
        
        scanf("%d", &nAge);
        
        for(int i=0; i<6; i++)
        {
            int temp = 0;
            scanf("%d", &temp);
            nSum += temp;
        }
    }
    
    virtual void putdata()
    {
        std::cout << sName << " " << nAge << " " << nSum << " " << nId << std::endl;
    }
};


unsigned int Student::nIdCounter = 0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
