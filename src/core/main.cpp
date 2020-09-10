/*


	   ███████╗   █████╗  ███████╗  ███████╗  █████╗   █████╗ 
	   ╚██╔══██╗ ██╔══██╗ ╚██╔══██╗ ██╔════╝ ██╔══██╗ ██╔══██╗
		██║  ██║ ██║  ██║  ██║  ██║ █████╗   ██║  ╚═╝ ███████║
		██║  ██║ ██║  ██║  ██║  ██║ ██╔══╝   ██║  ██╗ ██╔══██║
	   ███████╔╝ ╚█████╔╝ ███████╔╝ ███████╗ ╚█████╔╝ ██║  ██║
	   ╚══════╝   ╚════╝  ╚══════╝  ╚══════╝  ╚════╝  ╚═╝  ╚═╝
		
		Multithreaded Open-Source Minimal C++ 2D Game Engine

		by ENDESGA

*/

















/*#include <iostream>
#include <vector>
#include <thread>
//#include <future>
#include <chrono>
//#include "omp.h"
//#include <string>

int MAP_SIZE = 1000000000;
std::vector<int> MAP;
bool ASYNC = true;

struct OBJECT_STRUCT {
	int id = 0;

	OBJECT_STRUCT()
	{

	}

	inline void collide()
	{
		if (MAP[rand() % 777] == 1)
		{
			//
		}
	}
};
std::vector<OBJECT_STRUCT> OBJECTS;

void obj_collide(int i, int range)
{

	for (int j = 0; j < range; j++)
	{
		OBJECTS[i + j].collide();
	}
}

int main() {
	
	std::cout << "INITIALISING..." << std::endl;

	for (int i = 0; i < 777; i++)
	{
		MAP.push_back(1);
	}

	for (int i = 0; i < MAP_SIZE; i++)
	{
		OBJECTS.push_back(OBJECT_STRUCT{});
	}

	std::vector<std::thread> threads;
	uint_fast8_t threads_n = std::thread::hardware_concurrency();
	std::cout << std::endl << std::thread::hardware_concurrency() << std::endl;

	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	/*threads.push_back(std::thread(obj_collide, 0, MAP_SIZE / 8));
	threads.push_back(std::thread(obj_collide, (MAP_SIZE / 8), MAP_SIZE / 8));
	threads.push_back(std::thread(obj_collide, (MAP_SIZE / 8) * 2, MAP_SIZE / 8));
	threads.push_back(std::thread(obj_collide, (MAP_SIZE / 8) * 3, MAP_SIZE / 8));
	threads.push_back(std::thread(obj_collide, (MAP_SIZE / 8) * 4, MAP_SIZE / 8));
	threads.push_back(std::thread(obj_collide, (MAP_SIZE / 8) * 5, MAP_SIZE / 8));
	threads.push_back(std::thread(obj_collide, (MAP_SIZE / 8) * 6, MAP_SIZE / 8));
	threads.push_back(std::thread(obj_collide, (MAP_SIZE / 8) * 7, MAP_SIZE / 8));* /
	std::cout << "START MULTITHREADING" << std::endl << "- - - - - - -";
	for (uint_fast8_t i = 0; i < threads_n; i++)
	{
		threads.push_back(std::thread(obj_collide, (MAP_SIZE / threads_n) * i, MAP_SIZE / threads_n));
		//std::cout << std::endl << "THREAD " << (int)i + 1 << ": BEGIN!";
	}

	/*for (auto& th : threads) {
		th.join();
	}* /

	//for (uint_fast8_t i = 0; i < (uint_fast8_t)threads.size(); i++)
	while (threads.size() > 0)
	{
		for (uint_fast8_t i = 0; i < (uint_fast8_t)threads.size(); i++)
		{
			if (threads[i].joinable())
			{
				std::cout << std::endl << "THREAD " << (int)i << ": DONE";
				threads[i].join();
				threads.erase(threads.begin() + i);
			}
		}
	}

	auto end = std::chrono::system_clock::now();
	auto diff = std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count();
	std::cout << std::endl << "time: " << (double)diff / 1000000.00 << "ms" << std::endl;
	
	/////////////////////////////////

	start = std::chrono::system_clock::now();
	std::cout << std::endl << "////////////////////////////" << std::endl << "START SINGLETHREAD" << std::endl << "- - - - - - -";
	for (int i = 0; i < OBJECTS.size(); i++) {
		OBJECTS[i].collide();
	}

	end = std::chrono::system_clock::now();
	diff = std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count();
	std::cout << std::endl << "time: " << (double)diff / 1000000.00 << "ms" << std::endl;

	while (true)
	{
		//
	}

	return 0;
}*/












/*
int MAP_SIZE = 100000;
std::vector<int> MAP;
bool ASYNC = true;

struct OBJECT_STRUCT {
	int id = 0;

	OBJECT_STRUCT()
	{

	}

	inline void collide()
	{
		if (MAP[rand() % MAP_SIZE] == 1)
		{
			//
		}
	}
};
std::vector<OBJECT_STRUCT> OBJECTS;

void obj_collide(int i, int range)
{
	//for (int j = 0; j < 1000; j++)
	//{
	//	OBJECTS[i + j].collide();
	//}

	std::cout << std::endl << "THREAD!";

	for (int j = 0; j < range; j++)
	{
		OBJECTS[i + j].collide();
	}
}

int main()
{
	std::cout << "HELLO WORLD!";

	/*for (int i = 0; i < MAP_SIZE; i++)
	{
		MAP.push_back(1);
	}

	for (int i = 0; i < 100000; i++)
	{
		OBJECTS.push_back(OBJECT_STRUCT{});
	}* /

	//std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

	/*if (ASYNC)
	{
		//for (int i = 0; i < OBJECTS.size(); i++)
		//{
			//std::async(std::launch::async, obj_collide, i * 1000);
			//std::thread t1(obj_collide, i);
			//t1.detach();
		//}

		//const auto end = cend(OBJECTS);
		//for (auto it = cbegin(OBJECTS); it != end; ++it) {
			//it.collide();
			//(*it).collide();
		//}
		//std::async(std::launch::deferred, obj_collide, 0, MAP_SIZE * 0.5);
		//obj_collide(0, MAP_SIZE * 0.5);

		//std::thread t1(obj_collide, 0, MAP_SIZE * 0.5);
		//t1.detach();

		//obj_collide(MAP_SIZE * 0.5, MAP_SIZE * 0.5);
		//t1.join();
		//std::async(std::launch::async, obj_collide, MAP_SIZE * 0.5, MAP_SIZE * 0.5);

		omp_set_num_threads(2);
		#pragma omp parallel for
		for (int i = 0; i < OBJECTS.size(); i++)
		{
			OBJECTS[i].collide();
		}

	}
	else
	{
		for (int i = 0; i < OBJECTS.size(); i++)
		{
			OBJECTS[i].collide();
		}
	}* /

	std::cout << std::endl;
	std::cout << std::endl;

	const int N = 100000000;// INT_MAX - 1;
	static long double A[N];
	for (int i = 0, sign = 1; i < N; i++, sign = -sign)
	{
		A[i] = sign * 4.0 / (1.0 + 2.0 * i);
	}

	//for (int nThreads = 1; nThreads <= 16; nThreads++)
	//{
		//clock_t start = clock();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		long double sum = 0.0;

#pragma omp parallel num_threads(8)
		{
			// This code will be executed by two threads.

			// Chunks of this loop will be divided amongst
			// the (two) threads of the current team.
#pragma omp for
			for (int n = 0; n < 100000000; ++n) sum += A[n];
		}

		auto end = std::chrono::system_clock::now();
		auto diff = std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count();
		std::cout << std::endl << sum << " :: " << 2 << " :: time: " << (double)diff / 1000000.00 << "ms" << std::endl;

		//clock_t end = clock();

		//std::cout << "Threads: " << nThreads << "     Sum: " << sum << "     Time: " << (double)(end - start) / CLOCKS_PER_SEC << " s\n";
	//}

	//auto end = std::chrono::system_clock::now();
	//auto diff = std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count();
	//std::cout << std::endl << "time: " << (double)diff / 1000000.00 << "ms" << std::endl;

	while (true)
	{
		//
	}

	return 0;
}*/