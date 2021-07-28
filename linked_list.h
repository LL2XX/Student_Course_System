#pragma once
#include "basic_var.h"

void add_course_list(Course_list*, Course*);
void delete_list(Course_list*, Course*);
void add_student_list(Student_list* stu_list, Student* stu);
void free_course_list(Course_list*);
void free_student_list(Student_list*);
