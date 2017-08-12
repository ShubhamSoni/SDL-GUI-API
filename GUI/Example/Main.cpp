#include <iostream>
#include "Client.h"
using namespace Example;

int main(int argc, char* argcs[]) {
	std::cout <<"Starting..."<<std::endl;
	Client* client = Client::GetInstance();
	std::cout <<"Running..."<<std::endl;
	client->Run();
	delete client;
	std::cout <<"End..."<<std::endl;
	std::cin.ignore();
	return 0;
}