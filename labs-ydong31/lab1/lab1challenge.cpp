#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <fstream>

#define LINEWIDTH 5

using namespace std;

const int MAX = 1000;
size_t readLines(const char* fname, char* line[],int max);
void cleanLines(char* line[],size_t numLines);

/* This function finds the two values in the array data that
sum to goal and returns their product. */
unsigned int challenge(unsigned int data[], unsigned int numData, unsigned int goal){
    map<int, int> dict;
	bool found = false;
	unsigned int ret = 0;
   	for (int i = 0; i < numData && !found; i++)
	 {
		int key = goal - data[i];
	
		if (dict[data[i]]){
			ret = dict[data[i]] * data[i];
			found = true;
		}
		dict[key] = data[i];
	}
    return ret;
}


int main(int argc, char* argv[]){

    char* lines[2000]={0};
    int numLines=readLines("lab1challenge.txt",lines,1000);
    unsigned int values[2000];
    for(int i=0;i<numLines;i++){
        values[i]=atoi(lines[i]);
    }
    std::cout << challenge(values,numLines,2020) << std::endl;
    cleanLines(lines,numLines);
}


size_t readLines(const char* fname, char* line[],int max){
    std::ifstream fp(fname);
    int rc=0;
    if(!fp){
        std::cout << "unable to open " << fname << std::endl;
        return 0;
    }
    else{
        size_t len;
        char currLine[LINEWIDTH];
        while(rc<max && fp.getline(currLine, LINEWIDTH, '\n')){
            len=strlen(currLine);
            line[rc]=new char[len+1];
            strcpy(line[rc],currLine);
            rc++;
        }
        fp.close();
    }
    return rc;

}

void cleanLines(char* line[],size_t numLines){
    for(size_t i=0;i<numLines;i++){
        delete [] line[i];
    }
}
