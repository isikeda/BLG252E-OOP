/* @Author
 * Student Name:  Eda Işık
 * Student ID : 150200089
 */

#ifndef _student
#define _student

#include <string>
#include <iostream>

class Student{
    public:
        Student(const std::string, const double, const int, const int);
        Student(const Student&); 
        ~Student();
        void set_name(const std::string);
        std::string get_name() const;
        double get_GPA() const;
        int get_GRE() const;
        int get_TOEFL() const;
        void update_applications() const;
    private:
        //private attributes of a student object
        //GPA, GRE and TOEFL values are are initially zero.
        std::string name;
        double GPA = 0.0;
        int GRE = 0;
        int TOEFL = 0;
        mutable int num_of_applications = 0;
};

#endif