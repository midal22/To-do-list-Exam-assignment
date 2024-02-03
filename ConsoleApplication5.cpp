#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct hour
{
	string name;
	int proritet = 0;
	string opisanie;
};
struct day //дела в дне
{
	hour h[24];
};

struct monht
{
	bool week5 = true;
	int w1 = 0;
	bool week1 = false;
	int w5 = 3;
	int dey;  // дней в месяце
	day x[31];
};

void fIutput(monht m[], int d, int i, int ho);
void fOutput(monht m[], int d, int i,int ho);
void fHeader();
void fPoisk(monht M[]);
void fRedact(monht m[]);
int fDell(monht M[], int mon, int day, int hoyr, int YN);


const int m = 100;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);

	int arr[12]{ 31,29,31,30,31,30,31,31,30,31,30,31 };

	monht m[12];
		for (size_t i = 0; i < 12; i++)
		{
			m[i].dey = arr[i];
		}
			int ost;
	for (int i = 1; i < 12; i++)
	{
		if (m[i - 1].week5 == true)
		{
			m[i].week1 = true;
			m[i].w1 = 7 - m[i - 1].w5;
			ost = arr[i] - m[i].w1;
		}
		else
			ost = arr[i];

		m[i].w5 = ost % 7; // дней в 5 неполной неделе
		if (ost % 7 > 0)
			m[i].week5 = true; // не полная нелеля
		else
			m[i].week5 = false; //полная нелеля
	}
	int mon = 1; // месяц
	int d = 1; // день
	int ho;  // час
	int menu;
	bool ClosetProgram = false;
	int YN;
	do {
		cout << "1 Добавить дело.\n";
		cout << "2 Просмотреть список дел.\n";
		cout << "3 Поиск.\n";
		cout << "4 Редактировния дела.\n";
		cout << "5 Удаление дела.\n";
		cout << "Выберите вариант.\n";
		cin >> menu;

		switch (menu)
		{
		case 1: //добавление дел
		do{
			cout << "Введите номер месяца.\n";
			cin >> mon;
		} while (mon < 0 && mon >= 12);
		mon -= 1;
		do{
			cout << "Введите день.\n";
			cin >> d;
		}while (d < 0 && d >= m[mon].dey);
		d -= 1;
		do {
			cout << "Введите час.\n";
			cin >> ho;
		} while (ho < 0 && ho >= 24);
			ho -= 1;
				if (m[mon].x[d].h[ho].proritet == 0)
				{
					fIutput(m, d,mon,ho); //добавление дел
					system("cls");
					break;
				}
			break;

		case 2:   //вывод 
			int vibor;
			int napr, var;
			do{
			cout << "1 посмотреть один день\n";
			cout << "2 посмотреть неделю\n";
			cout << "3 посмотреть месяц\n";
			cin >> vibor;
		} while (vibor < 0 && vibor >= 3);
			switch (vibor)
			{
			case 1: // по дням
				do {
					cout << "Введите номер месяца.\n";
					cin >> mon;
				} while (mon < 0 && mon >= 12);
				mon -= 1;
				do {
					cout << "Введите день.\n";
					cin >> d;
				} while (d < 0 && d >= m[mon].dey);
				d -= 1;
				
				do {
					cout << "Выберите способ сортировки:\n";
					cout << "1 по приоритету.\n";
					cout << "2 по дате.\n";
					cin >> napr;
				} while (napr < 0 && napr >= 2);
				do {
					cout << "сортировать по\n";
					cout << "1 возрастанию\n";
					cout << "2 убыванию\n";
					cin >> var;
				} while (var < 0 && var >= 2);
				int a;
				int a1;
				if (napr == 1)
				{
					if (var == 1)
					{
						a = 1;
						a1 = 5;
					}
					else
					{
						a1 = 1;
						a = 5;
					}
				}
				else
				{
					if (var == 2)
					{
						a = 24;
						a1 = 0;
					}
					else
					{
						a1 = 24;
						a = 0;
					}
				}
				fHeader();
					if (var == 1)
					{
						for( a; a <  a1; a++)
						{
							
								if (napr == 1)
								{
									for (int i = 0; i < 24; i++)
									{
										if (m[mon].x[d].h[a].proritet == a && m[mon].x[d].h[a].proritet != 0)
											fOutput(m, d, mon, i);
									}
								}
								else
								{
									if (m[mon].x[d].h[a].proritet != 0)
									fOutput(m, d, mon, a);
								}
							
						}
					}
					else
						for (a; a > a1; a--)
						{
							
								if(napr == 1)
								{
									for (int i = 23; i <= 0; i--)
									{
										if (m[mon].x[d].h[a].proritet == a && m[mon].x[d].h[a].proritet != 0)
											fOutput(m, d, mon, i);
									}
								}
								else
								{
									if (m[mon].x[d].h[a].proritet != 0)
									fOutput(m, d, mon, a);
								}
							
						}
			break;
			case 2:  // по неделям
				do {
					cout << "Введите номер месяца.\n";
					cin >> mon;
				} while (mon < 0 && mon >= 12);
				mon -= 1;
				do {
					cout << "Введите неделю.\n";
					cin >> d;
				} while (d < 0 && 5 >= d);

				do {
					cout << "Выберите способ сортировки:\n";
					cout << "1 по приоритету.\n";
					cout << "2 по дате.\n";
					cin >> napr;
				} while (napr < 0 && napr >= 2);
				do {
					cout << "сортировать по\n";
					cout << "1 возрастанию.\n";
					cout << "2 убыванию.\n";
					cin >> var;
				} while (var < 0 && var >= 2);
					if (var == 1 && napr == 1)
					{
						a = 1;
						a1 = 5;
					}
					else
					{
						a1 = 1;
						a = 5;
					}
				int b,b1;
				
					fHeader();
					if (d == 1 && m[mon].week1) //1 неделя не полная
					{
						if (var == 1)
						{
							a = m[mon - 1].dey - m[mon - 1].w5;
							a1 = m[mon - 1].dey;
						}
						else
						{
							a = m[mon].w1 - 1;
							a1 = 0;
						}
						for (int z = 0; z < 2; z++)
						{
							if (var == 1) // возростание
							{

								for (a; a < a1; a++)
								{
									if (napr == 1)  // приоритет
									{
										b = m[mon - 1].dey - m[mon - 1].w5;
										b1 = m[mon - 1].dey;
										for (b; b < b1; b++)
										{
											for (int i = 0; i < 24; i++)
											{

												if (m[mon].x[b].h[i].proritet == a && m[mon].x[b].h[i].proritet != 0)
													fOutput(m, b, mon, i);
											}
										}
										if (d == 1 && m[mon].week1 == true || d == 5 && m[mon].week5 == true)
										{
											b = 0;
											b1 = m[mon].w1;
											for (b; b < b1; b++)
											{
												for (int i = 0; i < 24; i++)
												{
													if (m[mon].x[b].h[i].proritet == a && m[mon].x[b].h[i].proritet != 0)
														fOutput(m, b, mon, i);
												}
											}
										}

									}
									else // дата
									{
										for (int i = 0; i < 24; i++)
										{
											if (m[mon].x[a].h[i].proritet != 0)
											fOutput(m, a, mon, i);
										}
									}

								}
								a = 0;
								a1 = m[mon].w1;
							}
							else  // убывание
							{
								for (a; a >= a1; a--)
								{

									if (napr == 1) // приоритет 
									{
										b1 = 0;
										b = m[mon].w1 - 1;
										for (int d = b; d >= b1; d--)
										{
											for (int i = 23; i >= 0; i--)
											{
												if (m[mon].x[d].h[i].proritet == a && m[mon].x[d].h[i].proritet != 0)
												fOutput(m, d, mon, i);
											}
										}
										if (d == 1 && m[mon].week1 == true || d == 5 && m[mon].week5 == true)
										{
											b = m[mon - 1].dey - 1;
											b1 = m[mon - 1].dey - m[mon - 1].w5;
											for (int d = b; d >= b1; d--)
											{
												for (int i = 23; i >= 0; i--)
												{
													if (m[mon].x[d].h[i].proritet == a && m[mon].x[d].h[i].proritet != 0)
													fOutput(m, d, mon, i);
												}
											}
										}
									}
									else // дата
									{
										for (int i = 23; i >= 0; i--)
										{
											if (m[mon].x[a].h[i].proritet != 0)
											fOutput(m, a, mon, i);
										}
									}
								}
								a = m[mon-1].dey-1;
									a1 = m[mon - 1].dey - m[mon - 1].w5;
							}
						}
					}
					else if (d == 5 && m[mon].week5 == true) //5 неделя не полная
					{
						if (var == 1)
						{
							a = m[mon].dey - m[mon].w5;
							a1 = m[mon].dey;
						}
						else
						{
							a = m[mon+1].w1;
							a1 = 0;
						}
							for (int z = 0; z < 2; z++)
							{
								if (var == 1) // возростание
								{

									for (a; a < a1; a++)
									{
										if (napr == 1)  // приоритет
										{
											b = m[mon].dey - m[mon].w5;
											b1 = m[mon].dey;
											for (b; b < b1; b++)
											{
												for (int i = 0; i < 24; i++)
												{

													//if (m[mon].x[b].h[i].proritet == a && m[mon].x[b].h[i].proritet != 0)
														fOutput(m, b, mon, i);
												}
											}
											
												b = 0;
												b1 = m[mon+1].w1;
												for (b; b <= b1; b++)
												{
													for (int i = 0; i < 24; i++)
													{
														//if (m[mon].x[b].h[i].proritet == a && m[mon].x[b].h[i].proritet != 0)
															fOutput(m, b, mon, i);
													}
												}

										}
										else // дата
										{
											for (int i = 0; i < 24; i++)
											{
												//if (m[mon].x[a].h[i].proritet != 0)
													fOutput(m, a, mon, i);
											}
										}

									}
									a = 0;
									a1 = m[mon+1].w1;
								}
								else  // убывание
								{
									for (a; a >= a1; a--)
									{
										if (napr == 1) // приоритет 
										{
											b1 = 0;
											b = m[mon+1].w1 - 1;
											for (int d = b; d >= b1; d--)
											{
												for (int i = 23; i >= 0; i--)
												{
													//if (m[mon+1].x[d].h[i].proritet == a && m[mon+1].x[d].h[i].proritet != 0)
													fOutput(m, d, mon, i);
												}
											}
											if (d == 1 && m[mon].week1 == true || d == 5 && m[mon].week5 == true)
											{
												b = m[mon].dey - 1;
												b1 = m[mon].dey - m[mon].w5;
												for (int d = b; d >= b1; d--)
												{
													for (int i = 23; i >= 0; i--)
													{
														//if (m[mon].x[d].h[i].proritet == a && m[mon].x[d].h[i].proritet != 0)
														fOutput(m, d, mon, i);
													}
												}
											}
										}
										else // дата
										{
											for (int i = 23; i >= 0; i--)
											{
												//if (m[mon].x[a].h[i].proritet != 0)
												fOutput(m, a, mon, i);
											}
										}
									}
									a = m[mon].dey - 1;
									a1 = m[mon].dey - m[mon].w5;
								}
							}
					}
					else  //недели полные
					{
						d -= 1;
						int LeftBorder;
						int RightBorder;
						int ost = m[mon].dey;
						if (var == 2 && napr == 2)
						{
							a1 = m[mon].w1 + 7 * (d - 1);
							a = m[mon].w1 + 7 * d-1;
						}
						else
						{
							a1 = 7 * (d - 1);
							a = 7 * d;
						}

						
						if (var == 1) // возростание
						{
							for (a; a <= a1; a++)
							{
								if (napr == 1) // приоритет 
								{
									b1 = m[mon].w1 + 7 * d;
									b = m[mon].w1 + 7 * (d - 1);
									for (int d = b; d < b1; d++)
									{
										for (int i = 23; i >= 0; i--)
										{
											//if (m[mon + 1].x[d].h[i].proritet == a && m[mon + 1].x[d].h[i].proritet != 0)
											fOutput(m, d, mon, i);
										}
									}
								}
								else // дата
								{
									for (int i = 0; i < 24; i++)
									{
										//if (m[mon].x[a].h[i].proritet != 0)
										fOutput(m, a, mon, i);
									}
								}
							}
						}
							else
							{
								for (a; a > a1; a--)
								{
									if (napr == 1) // приоритет 
									{
											for (int i = 23; i >= 0; i--)
											{
												//if (m[mon + 1].x[d].h[i].proritet == a && m[mon + 1].x[d].h[i].proritet != 0)
													fOutput(m, a, mon, i);
											}
									}
									else // дата
									{
										for (int d = b; d < b1; d++)
										{
											for (int i = 23; i >= 0; i--)
											{
												//if (m[mon].x[d].h[i].proritet != 0)
												fOutput(m, d, mon, i);
											}
										}
									}
								}
								a = m[mon].dey - 1;
								a1 = m[mon].dey - m[mon].w5;
							}
					}
				
				break;

			case 3:  // по месяцам
				do {
					cout << "Введите номер месяца.\n";
					cin >> mon;
				} while (mon < 0 && mon >= 12);
				mon -= 1;


				do {
					cout << "Выберите способ сортировки\n";
					cout << "1 по приоритету\n";
					cout << "2 по дате\n";
					cin >> napr;
				} while (napr < 0 && napr >= 2);
				do {
					cout << "сортировать по\n";
					cout << "1 возрастанию\n";
					cout << "2 убыванию\n";
					cin >> var;
				} while (var < 0 && var >= 2);
				if (napr == 1)
				{
					if (var == 1)
					{
						a = 1;
						a1 = 5;
					}
					else
					{
						a1 = 1;
						a = 5;
					}
				}
				else
				{
					if (var == 2)
					{
						a = m[mon].dey;
						a1 = 0;
					}
					else
					{
						a1 = m[mon].dey;
						a = 0;
					}
				}


				fHeader();
				if (var == 1) // возростание
				{
					for (a; a < a1; a++)
					{

						if (napr == 1)  // приоритет
						{
							for(int d = 0; d < m[mon].dey; d++)
							{
								for (int i = 0; i < 24; i++)
								{
									if (m[mon].x[d].h[i].proritet == a && m[mon].x[d].h[i].proritet != 0)
										fOutput(m, d, mon, i);
								}
							}
						}
						else // дата
						{
							for (int i = 0; i < 24; i++)
							{
								if (m[mon].x[a].h[i].proritet != 0)
									fOutput(m, a, mon, i);
							}
						}

					}
				}
				else  // убывание
					for (a; a > a1; a--)
					{

						if (napr == 1) // приоритет 
						{
							for (int d = m[mon].dey; d > 0; d--)
							{
								for (int i = 24; i > 0; i--)
								{
									if (m[mon].x[d].h[i].proritet == a && m[mon].x[d].h[i].proritet != 0)
										fOutput(m, d, mon, i);
								}
							}
						}
						else // дата
						{
							for (int i = 23; i >= 0; i--)
							{
								if (m[mon].x[a].h[i].proritet != 0)
									fOutput(m, a, mon, i);
							}
						}

					}
				break;
			default:
				break;
			}
			break;
			case 3:
				fPoisk(m);
				break;
			case 4:
				fRedact(m);
				break;
			case 5:
				int mon;
				int day;
				int hoyr;
				do {
					cout << "Введите номер месяца.\n";
					cin >> mon;
				} while (mon < 0 && mon >= 12);
				mon -= 1;
				do {
					cout << "Введите день.\n";
					cin >> day;
				} while (day < 0 && day >= m[mon].dey);
				do {
					cout << "Введите час.\n";
					cin >> hoyr;
				} while (hoyr < 0 && day >= 24);
				cout << "вы уверены что хотите удалить это дело?\n";
				fOutput(m, day, mon, hoyr);
				cout << "1 да \\ 2 нет\n";
				YN = 1;
				fDell(m, mon, day, hoyr,YN);
		case 6:
			ClosetProgram = true;
		default:
			break;
		}
	} while (ClosetProgram == false);
}


void fIutput(monht m[], int d, int i,int ho)
{
	do
	{
		cout << "Введите приоретет дела от 1 до 5.\t";
		cin >> m[i].x[d].h[ho].proritet;
	} while (m[i].x[d].h[ho].proritet < 0 && m[i].x[d].h[ho].proritet >= 5);
	cin.ignore(32767, '\n');
	cout << "Введите названия дела.\t";
	getline(cin,m[i].x[d].h[ho].name);
	cout << "Введите описание дела.\t";
	getline(cin,m[i].x[d].h[ho].opisanie);
}

//void fIutput(monht m[], int d, int i, int ho)
//{
//	m[i].x[d].h[ho].proritet = 2;
//	m[i].x[d].h[ho].name = "a";
//	m[i].x[d].h[ho].opisanie = "a";
//
//	m[i].x[d+1].h[ho+1].proritet = 1;
//	m[i].x[d+1].h[ho+1].name = "b";
//	m[i].x[d+1].h[ho+1].opisanie = "b";
//}

void fOutput(monht m[], int d,int i, int ho) //1 структура 2 День 3 месяц 4 час
{
		cout << m[i].x[d].h[ho].proritet << "|\t\t";
		cout << m[i].x[d].h[ho].name << "\t\t";
		cout << m[i].x[d].h[ho].opisanie << "\t\t";
		cout << d+1 << "\\" << i+1 << "\\" << "2024";
		cout <<" " << ho+1 << ":00 AM";
		cout << endl;
}


void fHeader()
{
	cout << "Приоретет\t";
	cout << "Название\t";
	cout << "Описание\t";
	cout << "Дата\n";
}

void fPoisk(monht M[])
{
	int d = 0, i = 0;
	bool flag = false;
	bool chec = true;
	string a;
	int b;
	do {
		system("cls");
		cout << "выберети вариант поиска.\n";
		cout << "1 поиск по названию.\n";
		cout << "2 поиск по приоретету.\n";
		cout << "3 поиск по описанию.\n";
		cout << "4 поиск по дате.\n";
		cout << "5 закончить поиск.\n";
		int key = 0;
		cin >> key;
		switch (key)
		{
		case 1:  //поиск по названию
			cout << "Введите имя.\n";
			getline(cin,a);
			for (int i = 0; i < 12; i++)
			{
				for(int d = 0; d < M[i].dey; d++)
				{
					for (int h = 0; h < 24; h++)
					{
						if (a == M[i].x[d].h[h].name)
							fOutput(M, d, i,h);
						chec = true;
					}
				}
			}
			break;

		case 2:  //поиск по приоретету
			cout << "Введите приоритет.\n";
			cin >> b;
			for (int i = 0; i < 12; i++)
			{
				for (int d = 0; d < M[i].dey; d++)
				{
					for (int h = 0; h < 24; h++)
					{
						if (b == M[i].x[d].h[h].proritet)
						{
							fOutput(M, d, i, h);
							chec = true;
						}
					}
				}
			}
			break;
		case 3:  // поиск по описанию
			cout << "Введите описание.";
			getline(cin,a);
			for (int i = 0; i < 12; i++)
			{
				for (int d = 0; d < M[i].dey; d++)
				{
					for (int h = 0; h < 24; h++)
					{
						if (a == M[i].x[d].h[h].opisanie)
						{
							fOutput(M, d, i, h);
							chec = true;
						}
					}
				}
			}
			break;
		case 4:  //  поиск по дате 
			int mon;
			int day;
			int hoyr;
			do {
				cout << "Введите номер месяца.\n";
				cin >> mon;
			} while (mon < 0 && mon >= 12);
			mon -= 1;
			do {
				cout << "Введите день.\n";
				cin >> day;
			} while (day < 0 && day >= M[mon].dey);
			do {
				cout << "Введите час.\n";
			cin >> hoyr;
			} while (hoyr < 0 && day >= 24);
			if (b == M[i].x[d].h[hoyr].proritet != 0)
			{
				fOutput(M, day, mon, hoyr);
				chec = true;
			}
			break;
		case 5:
			flag = true;
			break;
		default:
			break;
		}
		if (chec == false)
		{
			cout << "К сожелению ничего не найдено.";
		}
		chec = false;
	} while (flag == false);
}

int fDell(monht M[], int mon, int day, int hoyr, int YN)
{
	do
	{
		cin >> YN;
	} while (hoyr < 0 && day >= 2);
	if (YN == 2)
	{
		return 0;
	}
	else
	{
		M[mon].x[day].h[hoyr].name.clear();
		M[mon].x[day].h[hoyr].opisanie.clear();
		M[mon].x[day].h[hoyr].proritet = 0;
	}
	cout << "дело удалено.";
}

void fRedact(monht m[])
{
	system("cls");
	int mon;
	int day;
	int hoyr;
	int flag;
	do{
		do {
			cout << "Введите номер месяца.\n";
			cin >> mon;
		} while (mon < 0 && mon >= 12);
		mon -= 1;
		do {
			cout << "Введите день.\n";
			cin >> day;
		} while (day < 0 && day >= m[mon].dey);
		do {
			cout << "Введите час.\n";
			cin >> hoyr;
		} while (hoyr < 0 && day >= 24);
		fOutput(m, day, mon, hoyr);
		cout << "вы уверены что хотите поменять это дело.\n";
		cout << "\t\t1 да \\ 2 нет\n";
		cin >> flag;
	} while (flag == 2);
	flag = 0;
	int a;
	cout << "Выберите что хотите поменять.\n";
	cout << "1 приоритет.\n";
	cout << "2 название.\n";
	cout << "3 описние.\n";
	cout << "4 Дату.";
	cout << "5 закончить.\n";
	cin >> a;
	cin.ignore(32767, '\n');
	int YN;
	do{
		system("cls");
		switch (a)
		{
		case 1:
			do
			{
				cout << "Введите приоретет дела от 1 до 5.\t";
				cin >> m[mon].x[day].h[hoyr].proritet;
			} while (m[mon].x[day].h[hoyr].proritet < 0 && m[mon].x[day].h[hoyr].proritet >= 5);
			break;
		case 2:
			cout << "Введите названия дела.\n";
			cin.ignore(32767, '\n');
			getline(cin, m[mon].x[day].h[hoyr].name);
			break;
		case 3:
			cout << "Введите описание дела.\t";
			getline(cin,m[mon].x[day].h[hoyr].opisanie);
			break;
		case 4:
			int m1;
			int d1;
			int h1;
			cout << "Введите дату куда хотите переписать дело.\n";
			do {
				cout << "Введите номер месяца.\n";
				cin >> m1;
			} while (mon < 0 && mon >= 12);
			mon -= 1;
			do {
				cout << "Введите день.\n";
				cin >> d1;
			} while (day < 0 && day >= m[mon].dey);
			do {
				cout << "Введите час.\n";
				cin >> h1;
			} while (hoyr < 0 && day >= 24);
			m[m1].x[d1].h[h1].proritet = m[mon].x[day].h[hoyr].proritet;
			m[m1].x[d1].h[h1].opisanie = m[mon].x[day].h[hoyr].opisanie;
			m[m1].x[d1].h[h1].name = m[mon].x[day].h[hoyr].name;
			YN = 1;
			fDell(m, mon, day, hoyr, YN);
			break;
		case 5:
			flag = 1;
		default:
			break;
		}
		fOutput(m, day, mon, hoyr);
	} while (flag == 0);
}