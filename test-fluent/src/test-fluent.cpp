#include <iostream>
#include <string>
#include <vector>


class Fluent
{
public:


	Fluent &operator()(const std::string &str)
	{
		strings.push_back(str);
		return *this;
	}

	void Print()
	{
		for(size_t i(0);i<strings.size();++i)
			std::cout<<strings[i]<<" ";
		std::cout<<std::endl;
	}

private:
	std::vector<std::string> strings;
};


int main() {
	Fluent()("0")("1")("2")("3")("4")("5")("6")("7")("8")("9").Print();
	return 0;
}
