#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string hexadecimal(int RGB[])
{
    string color_code = "";
    char look_up_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < 3; i++)
    {
        color_code.push_back(look_up_table[RGB[i] / 16]);
        color_code.push_back(look_up_table[RGB[i] % 16]);
    }
    return color_code;
}

int main()
{
    ifstream duom("Duomenys.txt");
    ofstream rez("Rezultatai.txt");
    int length = 0, width = 0, RGB[3] = { 0 };
    duom >> length >> width;
    for (int x = 0; x < length; x++)
    {
        for (int y = 0; y < width; y++)
        {
            duom >> RGB[0] >> RGB[1] >> RGB[2];
            if (y != 0) rez << ';';
            rez << hexadecimal(RGB);
        }
        rez << '\n';
    }
    duom.close();
    rez.close();
    return 0;
}
