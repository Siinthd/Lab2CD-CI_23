#include "filter.h"

int main(int argc, char * argv[]) {
	try{
		pool IP_pool;
		for (std::string line;std::getline(std::cin,line);)
		{
			std::vector<std::string> tempVectr;
			tempVectr = split(split(line, '\t').at(0), '.');
			std::vector<int> ip_int;
			std::transform(tempVectr.begin(),
				tempVectr.end(),
				std::back_inserter(ip_int),
				[](const auto& input) {return std::stoi(input); });
			IP_pool.push_back(ip_int);
		}
		pool sorted = sort_reverse(IP_pool);
		pool first = filter(IP_pool,1);
		pool second = filter(IP_pool,46,70);
		pool any = filter_any(IP_pool, 46);
		std::cout<<sorted<<first<<second<<any;
	}
	catch(const std::exception &e)
	{
	std::cerr <<e.what() << std::endl;
	}
}
/*
1. Полный список адресов после сортировки. Одна строка - один адрес.
2. Сразу следом список адресов, первый байт которых равен 1. Порядок сортировки не меняется. Одна строка - один адрес. Списки ничем не разделяются.
3. Сразу продолжается список адресов, первый байт которых равен 46, а второй 70. Порядок сортировки не меняется. Одна строка - один адрес. Списки ничем не разделяются.
4. Сразу продолжается список адресов, любой байт которых равен 46. Порядок сортировки не меняется. Одна строка - один адрес. Списки ничем не разделяются.*/

