#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using std::string;

class Course {
    private:
        std::string CourseName;
        int CourseID;
    public:
        Course(const std::string& name, int id) : CourseName(name), CourseID(id) {}
        std::string GetCourseName() const;
        int GetCourseID() const;
};

#endif