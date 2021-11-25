#include "basic_var.h"
#include <stdio.h>

void add_student(Student* stu) {
	FILE* fp = fopen("student.txt", "a");
	fprintf(fp, "%s", stu->stu_num);
	for (int i = 0; i < MAX_COURSE && stu->sel_cour[i][0] != '\0'; i++) fprintf(fp, " %s", stu->sel_cour[i]);
	fprintf(fp, "\n");
	fclose(fp);
}