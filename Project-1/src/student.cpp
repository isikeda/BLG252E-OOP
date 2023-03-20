/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#include <string>
#include <iostream>

#include "student.h"

Student::Student(const std::string name, const double GPA, const int GRE, const int TOEFL){
    //The constructer with parameters of student object
    //Every time that this method is invoked (means a student enters the system), a logging in message appears.
    this->name = name;
    this->GPA = GPA;
    this->GRE = GRE;
    this->TOEFL = TOEFL;
    this->num_of_applications = 0;

    std::cout << name << " logged in to the system." << std::endl;
};

Student::Student(const Student& original_student){
    //The copy constructer of student object
    //Every time this method is invoked, original student's values are copied to the new student that invokes the method.
    //Same message appears when the copy constructor invoked.
    this->name = original_student.name;
    this->GPA = original_student.GPA;
    this->GRE = original_student.GRE;
    this->TOEFL = original_student.TOEFL;
    this->num_of_applications = original_student.num_of_applications;

    std::cout << name << " logged in to the system." << std::endl;
};

Student::~Student(){
    //Destructor of student object
    //Every time this methos is invoked (means a student leaves the system),  a logging out message is appears.
    std::cout << this->name << " logged out of the system with " << this->num_of_applications << " application(s)." << std::endl;
};

void Student::set_name(const std::string new_name){
    //Set method of the name attribute of the student
    this->name = new_name;
};

std::string Student::get_name() const{
    //Get method of the name attribute of the student
    return this->name;
};

double Student::get_GPA() const{
    //Get method of the GPA attribute of the student
    return this->GPA;
};

int Student::get_GRE() const{
    //Get method of the GRE attribute of the student
    return this->GRE;
};

int Student::get_TOEFL() const{
    //Get method of the TOEFL attribute of the student
    return this->TOEFL;
};

void Student::update_applications() const{
    //This method update the num_of_applications variable when invoked
    //Since num_of_applications is mutable, const function can change it
    this->num_of_applications += 1;
};