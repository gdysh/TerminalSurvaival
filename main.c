#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int canBuy(float sum, float bitcoins) {
	if (sum <= bitcoins) {
		return 1;
	} else {
		return 0;
	}
	}

void buyGpu(float *ths, float *bitcoins) {
	printf("Выберете видеокарту:\n");
	printf("1. Oxy lite 0.5 th/s, 0.000300\n");
	printf("2. Oxy mine pp17 1 th/s, 0.000500\n");
	printf("3. Oxy mine pp19 2 th/s, 0.000750\n");
	printf("4. Oxy mine pp21 3 th/s, 0.001000\n");
	
	printf(">>");
	
	char choice[8];
	fgets(choice, sizeof(choice), stdin);
	choice[strcspn(choice, "\n")] = '\0';
	
	int nChoice = atoi(choice);
	
	switch (nChoice) {
		case 1:
			if (canBuy(0.000300, *bitcoins)) {
				*bitcoins -= 0.000300;
				*ths += 0.5;
				sleep(9);
			}
			break;
		case 2:
			if (canBuy(0.000500, *bitcoins)) {
				*bitcoins -= 0.000500;
				*ths += 1;
				sleep(9);
			}
			break;
		case 3:
			if (canBuy(0.000750, *bitcoins)) {
				*bitcoins -= 0.000750;
				*ths += 2;
				sleep(9);
			}
			break;
		case 4:
			if (canBuy(0.001000, *bitcoins)) {
				*bitcoins -= 0.001000;
				*ths += 3;
				sleep(9);
			}
			break;
		default:
			break;
		}
	}

int main() {
	float bitcoins = 0;
	float ths = 1;
	float programExp = 1;
	float hackerExp = 1;
	int hackerChance = 1;
	
	printf("Симулятор выживания в терминале 0.0.1\n");
	
	while (1) {
		printf("Bitcoins: %f, Общая сила видеокарт: %.1f th/s.", bitcoins, ths);
		printf("Выберете действие: \n");
		printf("1. Купить видеокарту\n");
		printf("2. Работать вводя капчи\n");
		printf("3. Работать программистом (Опыт %.2f)\n", programExp);
		printf("4. Работать хакером (Опыт %.2f) (Заметность: %d)\n", hackerExp, hackerChance);
		printf("5. Учиться\n");		
		printf(">>");
		
		char choice[8] = "0";
		
		fgets(choice, sizeof(choice), stdin);
		choice[strcspn(choice, "\n")] = '\0';
		
		int nChoice = atoi(choice);
		
		srand(time(NULL));
		
		switch (nChoice) {
			case 1:
			    buyGpu(&ths, &bitcoins);
				break;
			case 2:
				bitcoins += 0.000001;
				break;
			case 3:
				bitcoins += 0.000001 * programExp;
				programExp += 0.01f;
				sleep(1);
				break;
			case 4:
				bitcoins += 0.000010 * (hackerChance / 10 + hackerExp);
				hackerExp += 0.01f;
				hackerChance += 2;
				sleep(2);
				break;
			case 5:
				int which = rand() % 100;
				float learnRate = (rand() % 10);
				
				learnRate = learnRate / 100;
				
				if (which > 30) {
					programExp += learnRate;
				} else  {
					hackerExp += learnRate;
				}
				
				sleep(9);
			default:
				break;
		}
		
		if (hackerChance > 1) hackerChance -= 1;
		
		
		int exitChance = 0;
		
		exitChance = rand() % 100;
		
		if (hackerChance > 7 && exitChance > 50) {
			printf("Тебя поймали за хакерство\n");
			printf("exit(0);\n");
			exit(0);
			} else if (hackerChance > 4 && exitChance > 75) {
			printf("Тебя поймали за хакерство\n");
			printf("exit(0);\n");
			exit(0);
				} else if (hackerChance > 1 && exitChance > 95) {
			printf("Тебя поймали за хакерство\n");
			printf("exit(0);\n");
			exit(0);
					}
		
		
		if (hackerChance > 9) {
			printf("Тебя поймали за хакерство\n");
			printf("exit(0);\n");
			exit(0);
			}
			
		sleep(1);
		
		bitcoins += ths / 10000000;
		}
}
