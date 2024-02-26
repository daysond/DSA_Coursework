/**************************************************************************/
/*                                                                        */
/*   Experiment 1                                                         */
/*                                                                        */
/*   To compile: g++ experiment.cpp timer.cpp -std=c++0x                 */
/*   Alter this main to help answer your first experiment question        */
/*                                                                        */
/**************************************************************************/

#include "table.h"
#include "timer.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <fcntl.h>
const int maxRecords = 200000;

void createData(std::string keys[], int data[], int max);
int main(int argc, char* argv[]) {

    //this makes it easier to supply values on command line without recompiling
    //alternatively you can also just hard code the values and perhaps even loop 
    //through the values to create a csv
    // if (argc != 3) {
    //     std::cout << "usage: a.out numrecords capacity" << std::endl;
    //     return 0;
    // }

    std::string* keys = new std::string[maxRecords];        //list of test cases. 
    int* data = new int[maxRecords];
    createData(keys, data, maxRecords);

    // int numrecords = atoi(argv[1]);
    // size_t cap = atoi(argv[2]);

    int numrecords;
    size_t cap;

    
    const int numLF = 20;
    // list of loading factores to be tested
    double lf_list[numLF] = {0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1.0};
    cap = 150000; // fixed capacity
    numrecords = cap * 0.05;    
    std::cout << "number of records: " << numrecords << std::endl;
    std::cout << "capacity: " << cap << std::endl;

    LPTable<int> table1(cap);
    ChainingTable<int> table2(cap);


    //create a timer
    Timer T;
    Timer T2;
    // for (int i = 0; i < numrecords; i++) {
    //     //start the timer.  think of this like its a stop watch.
    //     //this is like pressing the start button
    //     T.start();
    //     table1.insert(keys[i], data[i]);

    //     //stop the timer.  this is like pressing pause on a stop watch
    //     T.stop();
    // }
    // //currtime reads the time on the stop watch
    // std::cout << "LP Table Time: " << T.currtime() << std::endl;
  

    // Timer T2;
    // for (int i = 0; i < numrecords; i++) {
    //     T2.start();
    //     table2.insert(keys[i], data[i]);
    //     T2.stop();
    // }
    // std::cout << "Chaining Table Time: " << T2.currtime() << std::endl;



    // Test code
    int lpfd, scfd, len;    // file descriptors for result outputing
    
    const int numTest = 10000; // number of elements to find for each loading factor
    const char lpfile[] = "lpdata.txt"; // file to store LP table result
    const char scfile[] = "scdata.txt"; // file to store SC table result
    
    lpfd = open(lpfile, O_WRONLY | O_CREAT , 0777);
    scfd = open(scfile, O_WRONLY | O_CREAT , 0777);
    
    const int BUF_LEN = 256;
    char buf[BUF_LEN];
    int index = 0;  // index of the key to be searched
    int j = 0; // controls the number of records to be added into the table
    double lpavg = 0; 
    double scavg = 0; 

    for(int i = 0; i < numLF; i++) {
        std::cout << "current LF: " << lf_list[i] << std::endl;
        for (; j < numrecords; j++) {
            table1.insert(keys[j], data[j]);
            table2.insert(keys[j], data[j]);
        }

        std::cout << "Table1 number of records: " << table1.numRecords() << std::endl;
        std::cout << "Table2 number of records: " << table2.numRecords() << std::endl;

        // does the test for 30 repetition, for each repetition, searches 10000 elements
        for(int s = 0; s< 30; s++) {
            for(int k = 0; k< numTest; k++) {
                srand(time(NULL));
                index = rand() % int(numrecords * 1.2); // generate a key randomly, * 1.2 will make sure keys that are not in the tables will be searched as well
                T.start();
                table1.find(keys[index], data[index]);
                T.stop();
                T2.start();
                table2.find(keys[index], data[index]);
                T2.stop();
            }
        }
        lpavg=T.currtime();
        scavg=T2.currtime();
        T.reset();
        T2.reset();
        lpavg/=30.0;
        scavg/=30.0;
        std::cout << "Table1 : " << lpavg << std::endl;
        std::cout << "Table2 : " << scavg << std::endl;
        // outputs the result to file
        memset(buf, 0, BUF_LEN);
        len =sprintf(buf, "%f", lpavg)+1;
        buf[len-1] = '\n';
        write(lpfd, buf, len);

        memset(buf, 0, BUF_LEN);
        len =sprintf(buf, "%f", scavg)+1;
        buf[len-1] = '\n';
        write(scfd, buf, len);

        numrecords += cap * 0.05;
        lpavg = 0;
        scavg = 0;
    }

    close(lpfd);
    close(scfd);


}




void createData(std::string keys[], int data[], int max) {
    FILE* fp = fopen("dictionary.txt", "r");
    int i = 0;
    std::string front = "A_";
    char curr[50];
    while (fscanf(fp, "%s\n", curr) == 1) {
        keys[i] = curr;
        data[i] = rand() % 100;
        i++;
    }
    int numWords = i;
    int j = 0;
    while (i < max) {
        keys[i] = front + keys[j];
        data[i] = rand() % 100;
        i++;
        j++;
        if (j == numWords) {
            front[0] += 1;
            j = 0;
        }
    }
}


