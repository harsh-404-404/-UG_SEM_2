#include <iostream>
#include <vector>

int fibonacci(std::size_t i){
	static std::vector<int> storage { 0,1 };
	if(i < storage.size()){
		return storage[i];
	}
	storage.push_back(fibonacci(i-1) + fibonacci(i-2));
	return storage.back();
}

int main(){
	
	for(int i = 0; i < 12; ++i){
		std::cout << fibonacci(i) << ' ';
	}
}