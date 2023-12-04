#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void partOne(ifstream& file);
void partTwo(ifstream& file);


int main (){
	ifstream file;
	file.open("input/1.input");
	partTwo(file);
	file.close();
	return 0;
}


void partOne(ifstream& file)
{
	int sum = 0;
	int x;
	string in;
	while (file >> in){
		for (int i=0;i<in.length();i++){
			x = (int)in[i];
			x = x-(int)'0';
			if (x>=0 && x<10){
				sum += x*10;
				break;
			}
		}
		for (int i=in.length();i>=0;i--){
			x = (int)in[i];
			x = x-(int)'0';
			if (x>=0 && x<10){
				sum += x;
				break;
			}
			
		}
	}
	cout << sum;
}

string nums[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int find(string& in, bool firstFlag)
{
	int x = 0;
	for (int i=0;i<in.length();i++){
	//search i
		if (in[i]>48 && in[i]<58) {
			x = (int)in[i]-'0';
			if(firstFlag) return x;
			continue;
		}
	//search string i
		for (int j=0;j<9;j++) {
			if (nums[j] == in.substr(i, nums[j].length())) {
				x = j+1;
				if(firstFlag) return x;
			}
		}
	}
	return x;
}

void partTwo(ifstream& file){
	int sum = 0;
	string in;
	int temp = 0;
	while (file >> in){
		temp = find(in, true)*10+find(in, false);
		sum += temp;
	}
	cout << sum;
}
