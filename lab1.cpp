#include "pch.h"
#include <conio.h> 
#include <stdio.h> 
#include <clocale> 
#include <ctime> 
#include <iostream> 
#include <cstdlib> 
int main()
{
	setlocale(LC_ALL, "Rus");
	bool FLAG2 = true; // для основного цикла 
	int str = 0; // размер массива 
	int stl = 0;
	int menu = 0; // для главного меню 
	char enter = '\n';
	bool trtflag = false;// флаг для обработки
	bool flag = true; // флаг для цикла
	bool masflag = false; // проверка заполненности
	int** mas = NULL;
	int i;
	int j;
	int otriz = 0;
	int otrflag = false;
	while (FLAG2)
	{ // Ввод размера массива 
		while (flag)
		{
			flag = false;
			printf(" Введите колличество строк и столбцов\n");
			if (scanf_s("%d %d%c", &str, &stl, &enter) != 3 || enter != '\n')
			{ // Защита от ввода отрицательного числа 
				printf(" ОШИБКА: Некорректные данные \n");
				while (getchar() != '\n');
				flag = true;
			}
			else
			{
				if (str < 1 || stl < 1)
				{
					printf("ОШИБКА: размер не может быть меньше 1 ");
					flag = true;
				}
			}
		}
		mas = new int*[str];
		for (int i = 0; i < str; i++)//выделение памяти под массив
		{
			mas[i] = new int[stl];
		}
		do
		{ // МЕНЮ. 
			flag = true;
			printf(" MENU \n");
			printf("---------------------------------------------\n");
			printf(" 1. Ввод элементов массива \n");
			printf(" 2. Вывод массива \n");
			printf(" 3. Сортировка строк \n");
			printf(" 4. Нахождение первого столбца имеющего хоть 1 отрицательный эллемент \n");
			printf(" 5. Вывод результата \n");
			printf(" 6. Перезапуск или Выход из программы \n");
			printf("---------------------------------------------\n");
			if (scanf_s("%d%c", &menu, &enter) != 2 || enter != '\n')
			{ // Защита от ввода букв и цифр 
				printf("\n|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
				while (getchar() != '\n');
			}
			else
			{
				if (menu <= 0 || menu > 6)
				{ // Защита от ввода отрицательного числа 
					printf("\n|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
				}
				else
				{
					switch (menu)
					{
					case 1:
						int menu2; // переменная для меню ввода массива 
						printf(" Меню ввода массива \n");
						printf("---------------------------------------------\n");
						printf(" 1. Заполнить массив cвоими значениями  \n");
						printf(" 2. Заполнить массив числами \n");
						printf(" 3. Выйти из данного пункта меню \n");
						printf("---------------------------------------------\n");
						if (scanf_s("%d%c", &menu2, &enter) != 2 || enter != '\n')
						{ // Защита от ввода букв и цифр, не в ходящих в диапозон
							printf("\n|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
							while (getchar() != '\n');
						}
						else
						{
							if (masflag == false)
							{
								if (menu2 < 0 || menu2 > 4)
								{ // Защита от ввода отрицательного числа 
									printf("\n|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
								}
								else
								{
									switch (menu2)
									{
									case 1: // Ввод в массив своих значений // Ввод массива 
									{
										for (i = 0; i < str; i++)
										{
											for (j = 0; j < stl; j++)
											{
												printf(" Введите целое значение элемента массива \n");
												while (scanf_s("%d%c", &mas[i][j], &enter) != 2 || enter != '\n')
												{
													while (getchar() != '\n');
													printf(" ОШИБКА: введены некорректные данные \n");
													continue;
												}
											}
										}
										masflag = true;
									}
									break;
									case 2: // Ввод массива случайные значения 
										for (int i = 0; i < str; i++)
										{
											for (int j = 0; j < stl; j++)
											{
												mas[i][j] = rand() % 10;
											}
										}
										masflag = true;
										break;
									case 3:
										break;
									}
								}
							}
							else
							{
								printf("\n\n Массив заполнен для ввода других значений перезапустите программу\n");
								printf(" Для продолжения нажмите ENTER \n");
								getchar();
							}
						}
						break;
					case 2:
						if (masflag == true)
						{
							for (int i = 0; i < str; i++)
							{
								for (int j = 0; j < stl; j++)
								{
									printf(" %d \t", mas[i][j]);
								}
								printf("\n");
							}
						}
						else
						{
							printf("ОШИБКА: Вы не ввели элементы массива \n");
							break;
						}
						break;
					case 3: //сортировка строк
						if (masflag == true)
						{
							int tempmas;
							int* sum = new int[str];
							for (i = 0; i < str; i++)
							{
								sum[i] = 0;
							}
							int temp;
							for (i = 0; i < str; i++)
							{
								for (j = 0; j < stl; j++)
								{
									sum[i] = sum[i] + abs(mas[i][j]);
								}
							}
							for (i = 0; i < str - 1; i++)
							{
								for (j = 0; j < str - i - 1; j++)
								{
									if (sum[j] > sum[j + 1])
									{
										temp = sum[j];
										sum[j] = sum[j + 1];//тут j на i изменено
										sum[j + 1] = temp;
										for (int q = 0; q < stl; q++)
										{
											tempmas = mas[j][q];
											mas[j][q] = mas[j + 1][q];
											mas[j + 1][q] = tempmas;
										}
									}
								}
							}
							delete[] sum;
						}
						else
						{

							printf("ОШИБКА: Вы не ввели элементы массива. Обработка массива недоступна\n");
							break;
						}
						break;
					case 4:
						if (masflag == true)
						{
								for (i = 0; i < str; i++)
								{
									for (j = 0; j < stl; j++)
									{
										while (trtflag == false)
										{
											if (mas[i][j] < 0)
											{
												otriz = j + 1;
												trtflag = true;
											}
											break;
										}
									}
			
								}
						}
						else
						{
							printf("ОШИБКА: Вы не ввели элементы массива. Обработка массива недоступна\n");
						}
						break;
					case 5: // Вывод результата 
						if (trtflag == true)
						{
							if (otriz > 0)
							{
								printf("\nНомер столбца: %d\n", otriz);
							}
							else
							{
								printf("Нет отрицательных эллементов\n\n");
							}
						}
						else
						{
							printf("ОШИБКА: Сначала выберите пункт 4\n");
							break;
						}
						break;
					case 6:
						printf(" Хотите начать программу сначала? \n");
						printf("---------------------------------------------\n");
						printf(" 1.Да (Перезапуск программы) \n");
						printf(" 2.Нет (Выход из программы) \n");
						printf("\n 3.Выйти из данного пункта меню \n");
						printf("---------------------------------------------\n");
						int menu3;
						if (scanf_s("%d%c", &menu3, &enter) != 2 || enter != '\n')
						{
							printf("|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
							while (getchar() != '\n');
						}
						else
						{
							if (menu3 < 0 || menu3 > 3)
							{
								printf("|************* НЕВЕРНЫЙ ПУНКТ МЕНЮ *************|\n\n");
								menu = 0;
							}
							else
							{
								switch (menu3)
								{
								case 1:
									break;
								case 2:
									return 0;
								case 3:
									menu = 0;
									break;
								}
							}
						}
					}
				}
			}
		} while (menu != 6);
		masflag = false;
		for (i = 0; i < str; i++)
		{
			delete[] mas[i];
		}
		delete[] mas;
	}
}