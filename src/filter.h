#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using pool = std::vector<std::vector<int>>;

std::vector<std::string> split(const std::string& input, char divide);
std::ostream& operator<<(std::ostream& os, pool& pool);
pool sort_reverse(pool IP_pool);
pool filter(pool IP_pool,size_t first);
pool filter(pool IP_pool, size_t first,size_t second);
pool filter_any(pool IP_pool,size_t any);
