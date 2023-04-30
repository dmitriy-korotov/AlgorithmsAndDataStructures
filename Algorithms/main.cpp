#include <iostream>
#include <string>
#include <vector>



std::vector<int> init_arr() noexcept
{
    	size_t n = 0;
    	std::cin >> n;

    	std::vector<int> nums;
    	for (size_t i = 0; i < n; ++i)
    	{
        	int tmp = 0;
        	std::cin >> tmp;
        	nums.push_back(tmp);
    	}

    	return nums;
}



int main() 
{
    	std::vector<int> fst_nums = init_arr();
    	std::vector<int> scnd_nums = init_arr();
	
	

	return 0;
}
