#include <stdio.h>
#include "basic_var.h"
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"

Course_list read_course() {
	FILE* fp = fopen("course.txt", "r");
	Course_list cour_list;
	Course* course;
	char temp[10];
	cour_list.head = NULL;
	cour_list.tail = NULL;

	while (fscanf(fp, "%s", temp) != EOF) {
		course = (Course*)malloc(sizeof(Course));
		strcpy(course->cour_num, temp);
		fscanf(fp, "%s", course->cour_name);
		fscanf(fp, "%d", &course->credit);
		fscanf(fp, "%s", course->teacher);
		fscanf(fp, "%d", &course->max_stu);
		fscanf(fp, "%d", &course->now_stu);
		course->next = NULL;
		add_course_list(&cour_list, course);
	}
	fclose(fp);

	return cour_list;
}

Student_list read_student() {
	FILE* fp = fopen("student.txt", "r");
	Student_list stu_list;
	Student* stu;
	char temp[20];
	int i;
	stu_list.head = NULL;
	stu_list.tail = NULL;
	while (fscanf(fp, "%s", temp) != EOF) {
		stu = (Student*)malloc(sizeof(Student));
		strcpy(stu->stu_num, temp);
		for(i=0;getc(fp)==' ';i++) 
			fscanf(fp, "%s", stu->sel_cour[i]);
		for (; i < MAX_COURSE; i++) stu->sel_cour[i][0] = '\0';
		stu->next = NULL;
		add_student_list(&stu_list, stu);
	}
	fclose(fp);

	return stu_list;
}