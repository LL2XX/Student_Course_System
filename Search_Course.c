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
	printf("��ѡ��Ҫ���еĲ�����\n");
	printf("1����ѯ��ѡ�γ�\n2����ѯ��ѡ�γ�\n3��������һ��\n");
	printf("����1-3��ѡ��һ���������룺");
	scanf("%d", &x); printf("\n");
	while (x != 3) {
		printf("������ѧ�ţ�");
		scanf("%s", stu_num);
		if (x == 1) search_selected(stu_num);
		if (x == 2) search_selective(stu_num);
		printf("��ѡ��Ҫ���еĲ�����\n");
		printf("1����ѯ��ѡ�γ�\n2����ѯ��ѡ�γ�\n3��������һ��\n");
		printf("����1-3��ѡ��һ���������룺");
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
	if (p_stu == NULL) printf("���޴���\n\n\n");
	else {
		printf("%s��ѡ�γ̣�\n", p_stu->stu_num);
		printf("%10s %20s %4s %8s %10s %10s\n", "�γ̱��", "�γ�����", "ѧ��", "�ο���ʦ", "�༶���ѧ����", "Ŀǰ��ѡ����");
		for (int i = 0; i < MAX_COURSE; i++) {
			for (p_cour = cour_list.head; p_cour && strcmp(p_cour->cour_num, p_stu->sel_cour[i]) != 0; p_cour = p_cour->next);
			if (p_cour) {
				total_credit += p_cour->credit;
				printf("%10s %20s %4d %8s %10d %10d\n", p_cour->cour_num, p_cour->cour_name, p_cour->credit, p_cour->teacher, p_cour->max_stu, p_cour->now_stu);
			}
			else if(p_stu->sel_cour[i][0]!='\0') printf("%10s���ÿγ���ȡ��������ѡ\n", p_stu->sel_cour[i]);
		}
		printf("��ѧ�֣�%d\n", total_credit);
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
	if (p_stu == NULL) printf("���޴���\n\n\n");
	else if (p_stu->sel_cour[MAX_COURSE-1][0] != '\0') printf("��ѡ��Ŀγ��Ѵ�����(5��)\n\n\n");
	else {
		printf("%s��ѡ�γ̣�\n", stu_num);
		printf("%10s %20s %4s %8s %10s %10s\n", "�γ̱��", "�γ�����", "ѧ��", "�ο���ʦ", "�༶���ѧ����", "Ŀǰ��ѡ����");
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