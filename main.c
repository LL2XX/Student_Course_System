#include "basic_var.h"
#include "course_manage.h"
#include "Select_Drop_Course.h"
#include "Search_Course.h"
#include <stdio.h>

int main() {
	int x;
	Course_list cour_list;
	cour_list.head = NULL;
	cour_list.tail = NULL;
	printf("��ѡ��Ҫ���еĲ�����\n");
	printf("1���γ̹���\n2���ˡ�ѡ��\n3����ѯ�γ�\n4���˳�\n");
	printf("����1-4��ѡ��һ���������룺");
	scanf("%d", &x); printf("\n");
	while (x != 4) {
		if (x == 1) course_manage();
		if (x == 2) select_drop();
		if (x == 3) search_course();
		if (x == 4) break;
		printf("��ѡ��Ҫ���еĲ�����\n");
		printf("1���γ̹���\n2���ˡ�ѡ��\n3����ѯ�γ�\n4���˳�\n");
		printf("����1-4��ѡ��һ���������룺");
		scanf("%d", &x); printf("\n");
	}

	return 0;
}