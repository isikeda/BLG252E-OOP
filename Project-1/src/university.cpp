/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#include <string>
#include <iostream>

#include "university.h"

University::University(std::string name, double GPA, double GRE, double TOEFL, double bias, std::string country){
    //The constructor with parameters of universty object
    //country parameter is defaulted with empty string
    this->name = name;
    this->GPA = GPA;
    this->GRE = GRE;
    this->TOEFL = TOEFL;
    this->bias = bias;
    this->country = country;
};
        
void University::evaluate_student(const Student& student){
    //The perceptron value is calculated with this method
    //According to the perceptron, a student can be admitted to a university of rejected from it
    double perceptron = this->GPA * student.get_GPA() + this->GRE * student.get_GRE() + this->TOEFL * student.get_TOEFL() + this->bias;

    if(perceptron >= 0){
        std::cout << student.get_name() << " is admitted to " << this->name << "." << std::endl;
    }else{
        std::cout << student.get_name() << " is rejected from " << this->name << "." << std::endl;
    }
    student.update_applications();
};