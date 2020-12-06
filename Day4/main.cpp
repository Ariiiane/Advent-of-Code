#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
using namespace std;

int main() {
    ifstream input;
    input.open("C:/Users/aridr/CLionProjects/Advent-of-Code/Day4/input.txt");

    string line;
    size_t pos;
    int points = 0;
    int counter = 0;
    string birthYear;
    string issueYear;
    string expirationYear;
    string height;
    string hairColor;
    string eyeColor;
    string passportID;
    int eyr;
    int iyr;
    int byr;
    int hgt;

    if (input.is_open())
    {
        while(!input.eof())
        {
            getline(input, line);
            if (line == "")
            {
                if (points != 7)
                {
                    points = 0;
                }
                else
                {
                    counter++;
                    points = 0;
                }
            }
            pos = line.find("byr");
            if(pos!=string::npos)
            {
                birthYear = line.substr(pos+4, 4);
                byr = stoi(birthYear);
                if(byr >= 1920 && byr <= 2002)
                {
                    points++;
                }
            }
            pos = line.find("iyr");
            if(pos!=string::npos)
            {
                issueYear = line.substr(pos+4, 4);
                iyr = stoi(issueYear);
                if(iyr >= 1910 && iyr <= 2020)
                {
                    points++;
                }
            }
            pos = line.find("eyr");
            if(pos!=string::npos)
            {
                expirationYear = line.substr(pos+4, 4);
                eyr = stoi(expirationYear);
                if(eyr >= 2020 && eyr <= 2030)
                {
                    points++;
                }
            }
            pos = line.find("hgt");
            if(pos!=string::npos)
            {
                pos = line.find("in");
                if(pos!=string::npos)
                {
                    for (int i = 1 ; i<5 ; i++)
                    {
                        if (line[pos-i]==':')
                        {
                            height = line.substr(pos-i+1,i-1);
                            hgt = stoi(height);
                            if(hgt>=59 && hgt<=76)
                            {
                                points++;
                                break;
                            }
                        }
                    }
                }

                pos = line.find("cm");
                if(pos!=string::npos)
                {
                    for (int i = 1 ; i<5 ; i++)
                    {
                        if (line[pos-i]==':')
                        {
                            height = line.substr(pos-i+1,i-1);
                            hgt = stoi(height);
                            if(hgt>=150 && hgt<=193)
                            {
                                points++;
                                break;
                            }
                        }
                    }
                }
            }
            pos = line.find("hcl");
            if(pos!=string::npos)
            {
                    if(line[pos+4]=='#')
                    {
                        hairColor = line.substr(pos+5, 6);

                        for(int u = 0; u < 7; u++)
                        {
                            if (!(hairColor[u]>='a' && hairColor[u]<='f')||!isdigit(hairColor[u]))
                            {
                                break;
                            }
                        }

                        points++;
                    }
            }
            pos = line.find("ecl");
            if(pos!=string::npos)
            {
            
                eyeColor = line.substr(pos+4, 3);

                pos = eyeColor.find("amb");
                if(pos!=string::npos)
                {
                    points++;
                }
                pos = eyeColor.find("blu");
                if(pos!=string::npos)
                {
                    points++;
                }
                pos = eyeColor.find("brn");
                if(pos!=string::npos)
                {
                    points++;
                }
                pos = eyeColor.find("gry");
                if(pos!=string::npos)
                {
                    points++;
                }
                pos = eyeColor.find("grn");
                if(pos!=string::npos)
                {
                    points++;
                }
                pos = eyeColor.find("hzl");
                if(pos!=string::npos)
                {
                    points++;
                }
                pos = eyeColor.find("oth");
                if(pos!=string::npos)
                {
                    points++;
                }
            }
            pos = line.find("pid");
            if(pos!=string::npos)
            {
                passportID = line.substr(pos+4,9);
                if (pos+13==line.size()||line[pos+13]==' ')
                {

                    for (int w = 0; w < 9; w++)
                    {
                        if(!isdigit(passportID[w]))
                        {
                            break;
                        }
                    }

                    points++;
                }
            }
        }

    }

    cout << counter << endl;
    return 0;
}
