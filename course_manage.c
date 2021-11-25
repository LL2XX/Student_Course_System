#include "basic_var.h"
#include "read_file.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_course(Course*);
void delete_course(char[]);

void course_manage() {
	int x;
	char num[10];
	Course_list cour_list = read_course();
	Course* course;

	printf("���пγ��б�\n");
	printf("%10s %20s %4s %8s %10s %10s\n", "�γ̱��", "�γ�����", "ѧ��", "�ο���ʦ", "�༶���ѧ����", "Ŀǰ��ѡ����");
	for (course = cour_list.head; course; course = course->next)
		printf("%10s %20s %4d %8s %10d %10d\n", course->cour_num, course->cour_name, course->credit, course->teacher, course->max_stu, course->now_stu);
	printf("\n");

	printf("��ѡ��Ҫ���еĲ�����\n");
	printf("1�������γ�\n2��ɾ���γ�\n3��������һ��\n");
	printf("����1-3��ѡ��һ���������룺");
	scanf("%d", &x); printf("\n");

	while (x != 3) {
		course = (Course*)malloc(sizeof(Course));
		if (x == 1) {
			printf("������γ���Ϣ����ʽ���£�(�����ݼ��ÿո�ֿ�)\n");
			printf("�γ̱�� �γ����� ѧ�� �ο���ʦ �༶���ѧ���� Ŀǰ��ѡ����\n");
			scanf("%s", course->cour_num);
			scanf("%s", course->cour_name);
			scanf("%d", &course->credit);
			scanf("%s", course->teacher);
			scanf("%d", &course->max_stu);
			scanf("%d", &course->now_stu);
			course->next = NULL;
			add_course(course);
			printf("����ӿγ�\n\n\n");
		}
		if (x == 2) {
			printf("������γ̱�ţ�");
			scanf("%s", num);
			delete_course(num);
		}
		printf("��ѡ��Ҫ���еĲ�����\n");
		printf("1�������γ�\n2��ɾ���γ�\n3��������һ��\n");
		printf("����1-3��ѡ��һ���������룺");
		scanf("%d", &x); printf("\n");

		free(course);
	}

	free_course_list(&cour_list);
}

void add_course(Course *course) {
	FILE* fp=fopen("course.txt", "a");
	fprintf(fp, "%s %s %d %s %d %d\n", course->cour_num, course->cour_name, course->credit, course->teacher, course->max_stu, course->now_stu);
	fclose(fp);
}

void delete_course(char num[]) {
	FILE* fp;
	Course_list cour_list;
	Course *p;

	cour_list = read_course();
	p = cour_list.head;

	while (p!=NULL&&strcmp(p->cour_num, num) != 0) p = p->next;
	if (p) {
		delete_list(&cour_list, p);
		fp = fopen("course.txt", "w");
		fclose(fp);
		for (p = cour_list.head; p != NULL; p = p->next) add_course(p);
		free_course_list(&cour_list);
	}
	else printf("δ�ҵ��ÿγ�\n\n");
}