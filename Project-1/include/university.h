/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#ifndef _university
#define _university

#include <string>
#include <iostream>
#include <student.h>

class University{
    public:
        University(std::string, double, double, double, double, std::string = ""); //'std::string = "" ' because of this, there is no error even if the country value is not given as parameter, "" is given as a default parameter
        void evaluate_student(const Student&);
    private:
        //private attributes of an university object
        std::string name;
        double GPA;
        double GRE;
        double TOEFL;
        double bias;
        std::string country;
};

#endif