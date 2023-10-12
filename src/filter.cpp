#include "filter.h"
std::vector<std::string> split(const std::string& input, char divide)
{
	std::string::size_type start = 0,end = 0;
	std::vector<std::string> out;
	end = input.find_first_of(divide);
	while (end != std::string::npos)
	{
		out.push_back(input.substr(start, end - start));
		start  = end+1;
		end = input.find_first_of(divide,start);
	}
	out.push_back(input.substr(start));
	return out;
}
std::ostream& operator<<(std::ostream& os, pool& pool)
{
	for (auto ip = pool.cbegin(); ip < pool.cend(); ++ip)
	{
		for (auto ip_part = ip->cbegin(); ip_part < ip->cend(); ++ip_part) {
			if (ip_part != ip->cbegin())
				os << '.';
			os << *ip_part;
		}
		os << std::endl;
	}
	return os;
}
pool sort_reverse(pool IP_pool)
{
	pool sorted = IP_pool;
	std::sort(sorted.begin(), sorted.end(), std::greater<std::vector<int>>());
	return sorted;
}
pool filter(pool IP_pool,size_t first)
{
	pool filtered;
	std::copy_if(IP_pool.begin(),
		IP_pool.end(),
		std::back_inserter(filtered),
		[first](const auto& input)
		{return input[0] == first; });
	std::sort(filtered.begin(), filtered.end(), std::greater<std::vector<int>>());
	return filtered;
}
pool filter(pool IP_pool, size_t first,size_t second)
{
	pool filtered;
	std::copy_if(IP_pool.begin(),
		IP_pool.end(),
		std::back_inserter(filtered),
		[&first,&second](const auto& input)
		{return ((input[0] == first) &&
				 (input[1] == second)); });
	std::sort(filtered.begin(), filtered.end(), std::greater<std::vector<int>>());
	return filtered;
}
pool filter_any(pool IP_pool,size_t any)
{
	pool filtered;
	std::copy_if(IP_pool.begin(),
		IP_pool.end(),
		std::back_inserter(filtered),
		[&any](const auto& input)
		{return ((input[0] == any) ||
				 (input[1] == any) ||
				 (input[2] == any) || 
				 (input[3] == any)); });
	std::sort(filtered.begin(), filtered.end(), std::greater<std::vector<int>>());
	return filtered;
}
