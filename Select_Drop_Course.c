#include "basic_var.h"
#include "read_file.h"
#include "linked_list.h"
#include "Student_Manage.h"
#include "course_manage.h"
#include <stdio.h>
#include <string.h>

void select(char [], char []);
void drop(char[], char[]);

void select_drop() {
	int x;
	char stu_num[20], cour_num[10];
	printf("请选择要进行的操作：\n");
	printf("1、选课\n2、退课\n3、返回上一级\n");
	printf("请在1-3中选择一个数字输入：");
	scanf("%d", &x); printf("\n");
	while (x != 3) {
		printf("请输入学号和课程编号：\n");
		printf("学号："); scanf("%s", stu_num);
		printf("课程编号："); scanf("%s", cour_num);
		if (x == 1) select(stu_num, cour_num);
		if (x == 2) drop(stu_num, cour_num);
		printf("请选择要进行的操作：\n");
		printf("1、选课\n2、退课\n3、返回上一级\n");
		printf("请在1-3中选择一个数字输入：");
		scanf("%d", &x); printf("\n");
	}
}

void select(char stu_num[], char cour_num[]) {
	Student_list stu_list;
	Student *p_stu;
	Course_list cour_list;
	Course* p_cour;
	int i;
	FILE* fp;
	stu_list = read_student();
	cour_list = read_course();
	for (p_cour = cour_list.head; p_cour && strcmp(p_cour->cour_num, cour_num) != 0; p_cour = p_cour->next);
	for (p_stu = stu_list.head; p_stu && strcmp(p_stu->stu_num, stu_num) != 0; p_stu = p_stu->next);
	if(p_stu) for (i = 0; i < MAX_COURSE && p_stu->sel_cour[i][0] != '\0' && strcmp(p_stu->sel_cour[i], cour_num)!=0; i++);
	if (p_stu == NULL) printf("查无此人\n");
	else if (p_cour == NULL) printf("查无此课程\n");
	else if (i == MAX_COURSE) printf("您可选的课程已满(5门)\n");
	else if (p_stu->sel_cour[i][0] != '\0') printf("该课程已在您的课表中\n");
	else {
		strcpy(p_stu->sel_cour[i], cour_num);
		p_cour->now_stu += 1;

		fp = fopen("student.txt", "w");
		fclose(fp);
		for (p_stu = stu_list.head; p_stu != NULL; p_stu = p_stu->next) add_student(p_stu);
		printf("已选择课程：%s %s %d %s %d %d\n", p_cour->cour_num, p_cour->cour_name, p_cour->credit, p_cour->teacher, p_cour->max_stu, p_cour->now_stu);
		
		fp = fopen("course.txt", "w");
		fclose(fp);
		for (p_cour = cour_list.head; p_cour != NULL; p_cour = p_cour->next) add_course(p_cour);
	}
	printf("\n\n");

	free_course_list(&cour_list);
	free_student_list(&stu_list);
}

void drop(char stu_num[], char cour_num[]) {
	Student_list stu_list;
	Student* p_stu;
	Course_list cour_list;
	Course* p_cour;
	int i;
	FILE* fp;
	stu_list = read_student();
	cour_list = read_course();
	for (p_cour = cour_list.head; p_cour && strcmp(p_cour->cour_num, cour_num) != 0; p_cour = p_cour->next);
	for (p_stu = stu_list.head; p_stu && strcmp(p_stu->stu_num, stu_num) != 0; p_stu = p_stu->next);
	if (p_stu) for (i = 0; i < MAX_COURSE && strcmp(p_stu->sel_cour[i], cour_num)!=0; i++);
	if (p_stu == NULL) printf("查无此人\n");
	else if (i == MAX_COURSE) printf("在您的课表中未找到该课程，请先选课\n");
	else {
		for (; i < MAX_COURSE && p_stu->sel_cour[i][0] != '\0'; i++) strcpy(p_stu->sel_cour[i], p_stu->sel_cour[i + 1]);
		for (; i < MAX_COURSE; i++) p_stu->sel_cour[i][0] = '\0';
		p_stu->sel_cour[MAX_COURSE - 1][0] = '\0';
		if (p_cour) p_cour->now_stu -= 1;
		
		fp = fopen("student.txt", "w");
		fclose(fp);
		for (p_stu = stu_list.head; p_stu != NULL; p_stu = p_stu->next) add_student(p_stu);
		if (p_cour) printf("已退选课程：%s %s %d %s %d %d\n", p_cour->cour_num, p_cour->cour_name, p_cour->credit, p_cour->teacher, p_cour->max_stu, p_cour->now_stu);
		else printf("已退选已取消课程：%s", cour_num);

		fp = fopen("course.txt", "w");
		fclose(fp);
		for (p_cour = cour_list.head; p_cour != NULL; p_cour = p_cour->next) add_course(p_cour);
	}
	printf("\n\n");
	free_course_list(&cour_list);
	free_student_list(&stu_list);
}