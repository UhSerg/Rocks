/*
 * main.cc
 *
 *  Created on: 28 сент. 2020 г.
 *      Author: inform
 */


#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>

void exit()
{
	std::cout << "You lost your rocks!";
}

int read_int (const char*prompt)
{
	int result;
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	std::stringstream input_ss {input};
	input_ss >> result;
	if (input_ss.fail())
	{
		std::cerr << "I'm not surprised ha-ha" << std::endl;
		exit(1);
	}
	return result;
}

char read_char ()
{
	char result;
	std::string input;
	std::getline(std::cin, input);
	std::stringstream input_ss {input};
	input_ss >> result;
	if (input_ss.fail())
	{
		std::cerr << "I'm not surprised ha-ha" << std::endl;
		exit(1);
	}
	return result;
}

void note ()
{
	std::cout <<
			"These are the rules:" << std::endl <<
			"1. Machine feels boring alone, so it wants to play with you with SOME rocks. You'll see all rocks when START." << std::endl <<
			"2. You have to decide what numbers of rocks you're taking: 1, or 2, or 3." << std::endl <<
			"3. The one who making last move is lose." << std::endl;
}

void play_easy()
{
	std::cout << "Let's play rocks! "
				"There are SOME" << std::endl;
	std::random_device rd;
	std::ranlux48 rnd { rd() };
	int a;
	std::uniform_int_distribution<> dist1(15, 25);
	std::cout << (a = dist1(rnd))
			<<std::endl <<
			"Take yours!"
			<<std::endl;
	std::cout << "Do you want to be the first? Doesn't matter cause machine will choose." << std::endl;
	std::uniform_int_distribution<> c (0, 1);
	if (c == 0)
	{
		int player, machine;
		while (a > 0)
		{
			player = read_int ("Please, choose the way you come\n");
			a = a - player;
			if (a <= 0)
			{
				std::cout << "YOU LOSE :(" << std::endl;
				break;
			}
			std::uniform_int_distribution<> dist2(1, 3);
			machine = dist2(rnd);
			std::cout << "Machine move"
					<< std::endl <<
					machine <<
					std::endl;
			a = a - machine;
			std::cout << a << " left" << std::endl;
			if (a <= 0 )
				std::cout << "CONGRATULATIONS!" << std::endl;
		}
	}
	else
	{
		if ((a-1)%4 == 0)
			std::cout << "Good luck ha-ha" << std::endl;
		int player, machine;
		while (a > 0)
		{
			std::uniform_int_distribution<> dist2(1, 3);
			machine = dist2(rnd);
			std::cout << "Machine move"
					<< std::endl <<
					machine <<
					std::endl;
			a = a - machine;
			std::cout << a << " left" << std::endl;
			if (a <= 0 )
				std::cout << "CONGRATULATIONS!" << std::endl;
			player = read_int ("Please, choose the way you come\n");
			a = a - player;
			if (a < 0)
			{
				std::cout << "YOU LOSE :(" << std::endl;
				break;
			}
		}
	}
}

void play_medium()
{
	std::cout <<
			"Let's play rocks! "
			"There are SOME" << std::endl;
	std::random_device rd;
	std::ranlux48 rnd { rd() };
	int a;
	std::uniform_int_distribution<> dist1(15, 25);
	std::cout <<
			(a = dist1(rnd)) << std::endl <<
			"Take yours!" << std::endl;
	std::cout << "Do you want to be the first? Doesn't matter cause machine will choose." << std::endl;
	std::uniform_int_distribution<> c (0, 1);
	if (c == 0)
	{
		int player, machine;
		while (a >= 10)
		{
			player = read_int ("Please, choose the way you come\n");
			a = a - player;
			std::uniform_int_distribution<> dist2(1, 3);
			machine = dist2(rnd);
			std::cout <<
					"Machine move" << std::endl <<
					machine << std::endl;
			a = a - machine;
		}
		while (a > 0)
		{
			player = read_int ("Please, choose the way you come\n");
			a = a - player;

			if (a <= 0)
			{
				std::cout << "YOU LOSE :(" << std::endl;
				break;
			}

			if ((a-1)%4 == 0)
			{

			}
			else
			{

			}
			std::uniform_int_distribution<> dist2(1, 3);
			machine = dist2(rnd);
			std::cout << "Machine move"
					<< std::endl <<
					machine <<
					std::endl;
			a = a - machine;
			std::cout << a << " left" << std::endl;
			if (a <= 0 )
				std::cout << "CONGRATULATIONS!" << std::endl;
		}
	}
	else
	{
		if ((a-1)%4 == 0)
			std::cout << "Good luck ha-ha" << std::endl;
		int player, machine;
		while (a > 0)
		{
			std::uniform_int_distribution<> dist2(1, 3);
			machine = dist2(rnd);
			std::cout << "Machine move"
					<< std::endl <<
					machine <<
					std::endl;
			a = a - machine;
			std::cout << a << " left" << std::endl;
			if (a <= 0 )
				std::cout << "CONGRATULATIONS!" << std::endl;
			player = read_int ("Please, choose the way you come\n");
			a = a - player;
			if (a < 0)
			{
				std::cout << "YOU LOSE :(" << std::endl;
				break;
			}
		}
	}
}

void play_hard()
{

}

void quality ()
{
	int q = read_int("Please, choose the way you come\n 1 - easy\n2 - medium\n3 - hard\n");
	if (q == 1)
	{

		play_easy();
	}
	if (q == 2)
		play_medium();
	if (q == 3)
		play_hard();
}

int main()
{
	int q;
	do
	{
		std::cout <<
				"Press 0 to leave the room." << std::endl <<
				"Press 1 to check the rules." << std::endl <<
				"Press 2 to choose quality." << std::endl <<
				"Press 3 to START\n" << std::endl;


		q = read_int ("Please, choose the way you come\n");
		switch (q)
		{
			case 0: exit(); break;
			case 1: note(); break;
			case 2: quality(); break;
			case 3: play(); break;
		}

	} while (q != 0);

	return 0;
}

