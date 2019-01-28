#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main(void)
{
	List test;
	init(&test);
	while (1) {
		intro();
		int choice, result;
		scanf("%d", &choice);
		getchar();
		switch (choice) {
			int num;
		case 1:
			system("cls");
			printf("          ***INSERT***\n");
			char iptName[10];
			int iptSex;
			printf("Enter the name (less than 10 characters) : ");
			scanf("%s", iptName);
			printf("Enter the gender (\"male\" or \"female\") : ");
			char tmp[10];
			scanf("%s", tmp);
			printf("Enter the position : ");
			scanf("%d", &num);
			if (tmp[0] == 'm') iptSex = 0;
			if (tmp[0] == 'f') iptSex = 1;
			result = insert(&test, num, iptName, iptSex);
			if (result) {
				printf("Succeeded.\n");
			}
			else {
				printf("Failed.\n");
			}
			break;
		case 2:
			system("cls");
			printf("          ***DELETE***\n");
			printf("Enter the position : ");
			scanf("%d", &num);
			result = deletenode(&test, num);
			if (result) {
				printf("Succeeded.\n");
			}
			else {
				printf("Failed.\n");
			}
			break;
		case 3:
			system("cls");
			printf("          ***PRINT***\n");
			print(&test);
			break;
		default:
			system("cls");
			printf("Wrong choice!\n");
		}
	}
	return 0;
}
void intro(void)
{
	printf("1 for insert. 2 for delete. 3 for print.\n");
}