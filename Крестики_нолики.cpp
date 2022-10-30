#include <iostream>
#include <String>
#include <random>
#include <time.h>

bool play(const std::string& n1, const std::string& n2, int& st,char mas[3][3]);
bool prov(char mas[3][3]);
bool win(char mas[3][3],int& step);

enum Players
{
	player1 = 0,
	player2 = 1,
	dead_heat=3
};

int main()
{
	std::string name1{ "" }, name2{ "" };
	int step,win_pl=0;
	int ct = 0;
	char a[3][3];
	for (int i{ 0 }; i < 3; ++i)
	{
		for (int j{ 0 }; j < 3; ++j)
		{
			a[i][j] = char(49+ct);
			ct++;
		}
	}
	std::cout << "Name 1 :";
	std::cin >> name1;
	std::cout << "Name 2 :";
	std::cin >> name2;
	system("cls");
	srand(time(NULL));
	if (rand() & 1)
		step = player1;
	else
		step = player2;
	
	while (!win_pl)
	{
		if (!play(name1, name2, step, a))
		{
			std::cout << "Error" << std::endl;
			system("pause");
		}
		win_pl = win(a,step);
			
		system("cls");
	}
	if (step==player2)
		std::cout << "Win player " + name1 << std::endl;
	else if (step==player1)
		std::cout << "Win player " + name2 << std::endl;
	else  
		std::cout << "Dead heat" << std::endl;
    return 0;
}

bool play(const std::string& n1, const std::string& n2, int& st, char mas[3][3])
{
	//Вывод поля на экран
	for (int i{ 0 }; i < 3; ++i)
	{
		for (int j{ 0 }; j < 3; ++j)
		{
			std::cout << '|' << mas[i][j];

		}
		std::cout << '|' << std::endl;
	}
	if (st)
		std::cout << "Player " << n2 << ":";
	else
		std::cout << "Player " << n1 << ":";
	int n,i,j;
	std::cin >> n;
	if (n<0 || n>9)
		return false;
	
	if (n%3==0)
	{
		i = n / 3 - 1;
		j = 2;
	}
	else
	{
		i = n / 3;
		j = n % 3 - 1;
	}
	if (mas[i][j] == '0' || mas[i][j] == 'X')
	{
		return false;
	}
	if (st== player2)
	{
		mas[i][j] = 'X';
		st = player1;
	}
	else
	{
		mas[i][j] = '0';
		st = player2;
	}
	
	return true;
}
//Проверка на ничью
bool prov(char mas[3][3])
{
	
	for (int i {0}; i < 3; ++i)
	{
		for (int j{ 0 }; j < 3; ++j)
		{
			if ((mas[i][j] != 'X') && (mas[i][j] != '0'))
			{
				return false;
			}
		}
	}
	return true;
}

bool win(char mas[3][3],int& step)
{

	for (int i {0}; i < 3; ++i)
	{
		if ((mas[i][0] == mas[i][1]) && (mas[i][0] == mas[i][2]))
			return true;
		else if ((mas[0][i] == mas[1][i]) && (mas[0][i] == mas[2][i]))
			return true;
		else if (((mas[0][0] == mas[1][1]) && (mas[0][0] == mas[2][2])) || ((mas[0][2] == mas[1][1]) && (mas[0][2] == mas[2][0])))
			return true;
		else if (prov(mas) && i == 2) {
			step = dead_heat;
			return true;
		}
			
	}
	return false;
}
