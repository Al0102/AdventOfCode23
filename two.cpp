#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void partOne(ifstream& file);
void partTwo(ifstream& file);


int main (){
	ifstream file;
	file.open("input/2.input");
	switch (currPart)
	{
		case 1:
			partOne(file);
			break;
		case 2:
			partTwo(file);
			break;
		default:
			cout << "no part selected";
	}
	file.close();
	return 0;
}


void partOne(ifstream& file)
{
	string line;
	int game;
	while (file >> line)
	{
		if (line == "Game")
		{
			file >> line;
			game = stoi(line);
		}
		cout << game << endl;
	}
			
}

void partTwo(ifstream& file){
}
