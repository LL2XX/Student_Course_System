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
	printf("请选择要进行的操作：\n");
	printf("1、课程管理\n2、退、选课\n3、查询课程\n4、退出\n");
	printf("请在1-4中选择一个数字输入：");
	scanf("%d", &x); printf("\n");
	while (x != 4) {
		if (x == 1) course_manage();
		if (x == 2) select_drop();
		if (x == 3) search_course();
		if (x == 4) break;
		printf("请选择要进行的操作：\n");
		printf("1、课程管理\n2、退、选课\n3、查询课程\n4、退出\n");
		printf("请在1-4中选择一个数字输入：");
		scanf("%d", &x); printf("\n");
	}

	return 0;
}