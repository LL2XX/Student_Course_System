#include "basic_var.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_student_list(Student_list* stu_list, Student* stu) {
	if (stu_list->head) {
		stu_list->tail->next = stu;
		stu_list->tail = stu;
	}
	else {
		stu_list->head = stu;
		stu_list->tail = stu;
	}
}

void add_course_list(Course_list* cour_list, Course* course) {
	if (cour_list->head) {
		cour_list->tail->next = course;
		cour_list->tail = course;
	}
	else {
		cour_list->head = course;
		cour_list->tail = course;
	}
}

void delete_list(Course_list* cour_list, Course* course) {
	Course* p = cour_list->head;
	if (strcmp(p->cour_num, course->cour_num)==0) {
		cour_list->head = p->next;
		printf("已删除课程：%s %s %d %s %d %d\n\n\n", p->cour_num, p->cour_name, p->credit, p->teacher, p->max_stu, p->now_stu);
		free(p);
	}
	else {
		while (strcmp(p->next->cour_num, course->cour_num)!=0) p = p->next;
		p->next = course->next;
		printf("已删除课程：%s %s %d %s %d %d\n\n\n", course->cour_num, course->cour_name, course->credit, course->teacher, course->max_stu, course->now_stu);
		free(course);
	}
}

void free_course_list(Course_list* cour_list) {
	Course* p=cour_list->head->next;
	while (cour_list->head) {
		free(cour_list->head);
		cour_list->head = p;
		if(p) p = p->next;
	}
	cour_list->head = NULL;
	cour_list->tail = NULL;
}

void free_student_list(Student_list* stu_list) {
	Student* p = stu_list->head->next;
	while (stu_list->head) {
		free(stu_list->head);
		stu_list->head = p;
		if(p) p = p->next;
	}
	stu_list->head = NULL;
	stu_list->tail = NULL;
}