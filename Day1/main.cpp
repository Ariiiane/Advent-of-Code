#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    string line;
    int array[200];
    short loop;
    short loop2;
    short loop3;
    short loop4;
    int num;
    int add;
    int result;

    ifstream input;
    input.open("C:/Users/aridr/CLionProjects/Advent-of-Code/Day1/input.txt");

    if (input.is_open())
    {
            for (loop=0; loop<200;loop++)
            {
                getline (input,line);
                num = stoi(line);
                array[loop]=num;
            };
            for(loop2=0;loop2<200;loop2++)
            {

                for(loop3=loop2+1;loop3<200;loop3++)
                {
                    for(loop4=loop3+1;loop4<200;loop4++) {
                        add = array[loop2] + array[loop3]+ array[loop4];

                        if (add == 2020) {
                            result = array[loop2] * array[loop3]* array[loop4];

                            cout << result << endl << array[loop2] << endl << array[loop3]<< endl<<array[loop4];
                            return 0;
                        }
                    }
                }
            }

        input.close();
    }

   return 0;
}