#pragma once
#define MAX_COURSE 5

typedef struct Course_Info {
	char cour_num[10];
	char cour_name[20];
	int credit;
	char teacher[10];
	int max_stu;
	int now_stu;
	struct Course_Info* next;
} Course;

typedef struct Student_Course {
	char stu_num[20];
	char sel_cour[MAX_COURSE][10];
	struct Student_Course* next;
} Student;

typedef struct {
	Course* head;
	Course* tail;
} Course_list;

typedef struct {
	Student* head;
	Student* tail;
} Student_list;
