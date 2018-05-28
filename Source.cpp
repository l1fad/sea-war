# include <stdio.h>
# include <conio.h>
# include <time.h>
# include <stdlib.h>
# include <ctype.h>
# include <Windows.h>
# include <math.h>
# include <string.h>
char symbolupfield = 205;
char symbolsidefield = 199;
char symbolship = 178;
char symboldeadship = 35;
char symbolhit = 88;
char field[10][11] = {
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
};   //# и | это поле
	 //1 корабль
	 //2 мертвый корабль
	 //3 попадание
void init();
void visual();
int test(int, int, int, int, int);
int main() {
	int i = 0, j = 0;
	init();
	printf("\nReady?\n");
	_getch();
	for (i = 0; i < 5; i++) {
		printf(". ");
		Sleep(800);
	}
	printf("\nGo!\n");
	Sleep(800);
	system("CLS");
	//размещение
	int x1, y1, x2, y2, type, position, k = 10;
	int ships[4];
	for (i = 0; i<4; i++) {
		ships[i] = 4 - i;
	}
	while (k) {
		visual();
		printf("You have:\n");
		for (j = 0; j<4; j++) {
			printf("Ship%d: %d\n", j + 1, ships[j]);
		}
		printf("Select ship(1,2,3,4):");
		scanf("%d", &type);
		printf("Beginning x,y of the ship:");
		scanf("%d %d", &x1, &y1);
		printf("End x,y of ship:");
		scanf("%d %d", &x2, &y2);
		//test(x1,y1,x2,y2);
		if (y1>y2) {
			int tmp = y1;
			y1 = y2;
			y2 = tmp;
		}
		if (x1>x2) {
			int tmp = x1;
			x1 = x2;
			x2 = tmp;
		}
		if (test(x1, y1, x2, y2, type)) {
			ships[type - 1]--;
			for (i = y1; i <= y2; i++) {
				for (j = x1; j <= x2; j++)
					field[i][j] = '1';
			}
			system("CLS");
			init();
			test(x1, y1, x2, y2, type);
			k--;
		}
		else {
			Sleep(1800);
			system("cls");
			printf("\n\tINVALID INPUT\n");
			Sleep(1800);
			system("cls");

		}
	}
	visual();
	_getch();
}
void init() {
	int i = 0, j = 0;
	for (i = 0; i<12; i++) {
		for (j = 0; j<13; j++) {
			char symb = field[i][j];
			switch (symb)
			{

			case '1':
			{
				field[i][j] = symbolship;
				break;
			}
			case '2':
			{
				field[i][j] = symboldeadship;
				break;
			}
			default:
			{
				field[i][j] = symb;
				break;
			}
			}
		}
	}
}
void visual() {
	int i = 0, j = 0;
	printf("\n\t");
	for (i = 0; i<13; i++)
		printf("%c", 205);
	printf("\n\t%c 0123456789%c\n", 199, 199);
	for (i = 0; i<10; i++) {
		printf("\t");
		printf("%c%d", 199, i);
		for (j = 0; j<10; j++)
			printf("%c", field[i][j]);
		printf("%c", 199);
		printf("\n");
	}
	printf("\t");
	for (i = 0; i<13; i++)
		printf("%c", 205);
	printf("\n\t");
}
int test(int x1, int y1, int x2, int y2, int type) {
	int i = 0, j = 0;
	if (x1>9 || y1>9 || x2>9 || y2>9) {
		return 0;

	}
	if (x1 != x2 && y1 != y2) {
		return 0;
	}
	if (x1 == x2) {
		if (((y2 - y1) + 1) != type) return 0;
	}
	if (y1 == y2) {
		if (((x2 - x1) + 1) != type) return 0;
	}
	for (i = y1; i <= y2; i++) {
		for (j = x1; j <= x2; j++) {
			if (field[i+1][j] == symbolship)  return 0;
			if (field[i-1][j] == symbolship)  return 0;
			if (field[i][j+1] == symbolship)  return 0;
			if (field[i][j-1] == symbolship)  return 0;
			if (field[i+1][j+1] == symbolship)  return 0;
			if (field[i+1][j-1] == symbolship)  return 0;
			if (field[i-1][j-1] == symbolship)  return 0;
			if (field[i-1][j+1] == symbolship)  return 0;
		}

	}
	return 1;
}
