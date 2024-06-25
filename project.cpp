#include <iostream>
#include <vector>
using namespace std;

class Student {
    private:
        int rollnum, age;
        string name;

    public:
        //constructor
        Student(int rollnum, string name, int age){
            this->rollnum = rollnum;
            this->name = name;
            this->age = age;
        }

        //Getters & Setters
        int getRollNum(){
            return rollnum;
        }
        void setRollNum(int rollnum){
            this->rollnum = rollnum;
        }

        void setName(string name){
            this->name = name;
        }
        string getName(){
            return name;
        }

        void setAge(int age){
            this->age = age;
        }
        int getAge(){
            return age;
        }
        void displayStudent(){
            cout<<"Roll Number: "<<rollnum<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }
};

//Add new student
void addNewStudent(vector<Student> &students){
    int rollnum,age;
    string name;
    cout << "Enter Rollno : " <<endl;
    cin>>rollnum;

    for(int j=0;j<students.size();j++){
        if(students[j].getRollNum()==rollnum){
            cout << "\t\tThis Student Already Exists.. " << endl;
            return;
        }
    }

    cout << "Enter Name : " <<endl;
    cin>>name;
    cout << "Enter Age : " <<endl;
    cin>>age;

    Student newStudent(rollnum,name,age);
    students.push_back(newStudent);

    cout << "\t\t-----Student Added Successfully!!------" << endl;
}

//Display all students
void DisplayAllStudent(vector<Student> &students){
    if(students.empty()){
        cout<<"\t\tNo student data found.."<<endl;
        return;
    }
    for(int i=0;i<students.size();i++){
        students[i].displayStudent();
        cout<<endl;
    }

}

//Search all students
void SearchStudent(vector<Student> &students){
    int rollnum;
    cout<<"\t\tEnter RollNumber: ";
    cin >> rollnum;

    for(int i=0;i<students.size();i++){
        if(students[i].getRollNum() == rollnum){
            cout<<"\t\t-----Student Found-----"<<endl;
            students[i].displayStudent();
            return;
        }
    }
}

//Update student record
void updateStudent(vector<Student> &students){
    string sname;
    bool found = false;
    int choice;

    cout<<"\t\tEnter The Name To Update Record :";
    cin.ignore();
    getline(cin,sname);

    for(int i=0;i<students.size();i++){
        if(students[i].getName()==sname){
            found = true;
            cout<<"\t\t----Student Found----"<<endl;
            cout<<"\t\t 1. Update Rollno "<<endl;
            cout<<"\t\t 2. Update Name "<<endl;
            cout<<"\t\t 3. Update Age "<<endl;
            cout<<"\t\tEnter Your Choice : ";
            cin>>choice;

            switch (choice)
            {
                case 1:{
                    int rno;
                    cout<<"\t\tEnter New Roll Num : ";
                    cin>>rno;
                    students[i].setRollNum(rno);
	       	    cout<<"\t\tRoll No Updated Successfully!!!"<<endl;
                    break;
                }
                case 2:{
                    string name;
                    cout<<"\t\tEnter New Name : ";
                    cin.ignore();
                    getline(cin,name);
                    students[i].setName(name);
		    cout<<"\t\tName Updated Successfully!!!"<<endl;
                    break;
                }
                case 3:{
                    int age;
                    cout<<"\t\tEnter New Age : ";
                    cin>>age;
                    students[i].setAge(age);
                    cout<<"\t\tAge Updated Successfully!!!"<<endl;
                    break;
                }
                default:{
                    cout<<"\t\tInvalid Number"<<endl;
                }
            }
        }
	if(!found){
            cout<<"\t\tRecord Not Found"<<endl;
            return;
        }
    }
}

//Delete Student Record
void deleteStudent(vector<Student> &students){
    string name;
    cout<<"Enter Name to Delete : ";
    cin.ignore();
    getline(cin, name);

    for(int i=0;i<students.size();i++){
        if(students[i].getName() == name){
            students.erase((students.begin()+i));
            cout<<"\t\tStudent Removed Successfully"<<endl;
        }
	else{
	    cout<<"\t\tNo Student Found"<<endl;
    	}
    }
}

int main(){
    vector<Student> students;
    students.push_back(Student(1,"Vijaya", 20));
    char option;

    //user choice
    while(true){
        int choice;
        cout << "\t\tStudent Management System"<< endl;
        cout << "\t\t1. Add New Student" << endl;
        cout << "\t\t2. Display All Students" << endl;
        cout << "\t\t3. Search Student" << endl;
        cout << "\t\t4. Update Student" << endl;
        cout << "\t\t5. Delete Student" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "please enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                addNewStudent(students);
                break;
            case 2:
                DisplayAllStudent(students);
                break;
            case 3:
                SearchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                exit(1);
            default:
                cout << "\t\tInvalid Entry...";
        }
    }
}
