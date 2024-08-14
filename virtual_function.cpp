#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static int professor_id = 0;
static int student_id = 0;
class Person{
public:
    string name;
    int age;
    virtual void getdata() = 0;
    virtual void putdata() const = 0;
};
class Professor: public Person{
    int publications;
    int cur_id;
public:
    void getdata(){
        cin >> name >> age >> publications;
        professor_id++;
        cur_id = professor_id;
    }
    void putdata() const {
        cout << name <<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
    }
};
class Student: public Person{
    int marks[6];
    int cur_id;
    int sum_marks() const{
        int ret = 0;
        for (int i = 0; i < 6; ++i) {
            ret+=marks[i];
        }
        return ret;
    }
public:
    void getdata(){
        cin >> name >> age;
        for (int i = 0; i < 6; ++i) {
            cin >> marks[i];
        }
        student_id++;
        cur_id=student_id;
    }
    void putdata() const {
        cout << name <<" "<<age<<" "<<sum_marks()<<" "<<cur_id<<endl;
    }
};
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
