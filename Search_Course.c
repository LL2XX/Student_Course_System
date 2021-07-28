#include "basic_var.h"
#include "read_file.h"
#include "linked_list.h"
#include <stdio.h>
#include <string.h>

void search_selected(char[]);
void search_selective(char []);

void search_course() {
	int x;
	char stu_num[20];
	printf("请选择要进行的操作：\n");
	printf("1、查询已选课程\n2、查询可选课程\n3、返回上一级\n");
	printf("请在1-3中选择一个数字输入：");
	scanf("%d", &x); printf("\n");
	while (x != 3) {
		printf("请输入学号：");
		scanf("%s", stu_num);
		if (x == 1) search_selected(stu_num);
		if (x == 2) search_selective(stu_num);
		printf("请选择要进行的操作：\n");
		printf("1、查询已选课程\n2、查询可选课程\n3、返回上一级\n");
		printf("请在1-3中选择一个数字输入：");
		scanf("%d", &x); printf("\n");
	}
}

void search_selected(char stu_num[]) {
	Course_list cour_list = read_course();
	Student_list stu_list = read_student();
	Course* p_cour;
	Student* p_stu = stu_list.head;
	int total_credit=0;
	while (p_stu&&strcmp(p_stu->stu_num, stu_num) != 0) p_stu = p_stu->next;
	if (p_stu == NULL) printf("查无此人\n\n\n");
	else {
		printf("%s已选课程：\n", p_stu->stu_num);
		printf("%10s %20s %4s %8s %10s %10s\n", "课程编号", "课程名字", "学分", "任课老师", "班级最大学生数", "目前已选人数");
		for (int i = 0; i < MAX_COURSE; i++) {
			for (p_cour = cour_list.head; p_cour && strcmp(p_cour->cour_num, p_stu->sel_cour[i]) != 0; p_cour = p_cour->next);
			if (p_cour) {
				total_credit += p_cour->credit;
				printf("%10s %20s %4d %8s %10d %10d\n", p_cour->cour_num, p_cour->cour_name, p_cour->credit, p_cour->teacher, p_cour->max_stu, p_cour->now_stu);
			}
			else if(p_stu->sel_cour[i][0]!='\0') printf("%10s，该课程已取消，请退选\n", p_stu->sel_cour[i]);
		}
		printf("总学分：%d\n", total_credit);
		printf("\n\n");
	}
	free_course_list(&cour_list);
	free_student_list(&stu_list);
}

void search_selective(char stu_num[]) {
	Course_list cour_list = read_course();
	Student_list stu_list = read_student();
	Course* p_cour;
	Student* p_stu = stu_list.head;
	int temp;
	while (p_stu && strcmp(p_stu->stu_num, stu_num) != 0) p_stu = p_stu->next;
	if (p_stu == NULL) printf("查无此人\n\n\n");
	else if (p_stu->sel_cour[MAX_COURSE-1][0] != '\0') printf("您选择的课程已达上限(5门)\n\n\n");
	else {
		printf("%s可选课程：\n", stu_num);
		printf("%10s %20s %4s %8s %10s %10s\n", "课程编号", "课程名字", "学分", "任课老师", "班级最大学生数", "目前已选人数");
		for (p_cour = cour_list.head; p_cour; p_cour = p_cour->next) {
			temp = 1;
			for (int i = 0; i < MAX_COURSE && p_stu->sel_cour[i][0] != '\0'; i++)
				if (strcmp(p_cour->cour_num, p_stu->sel_cour[i]) == 0) {
					temp = 0; break;
				}
			if (temp && (p_cour->max_stu > p_cour->now_stu)) 
				printf("%10s %20s %4d %8s %10d %10d\n", p_cour->cour_num, p_cour->cour_name, p_cour->credit, p_cour->teacher, p_cour->max_stu, p_cour->now_stu);

		}
		printf("\n\n");
	}
	free_course_list(&cour_list);
	free_student_list(&stu_list);
}