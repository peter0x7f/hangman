#include <iostream>
#include <string>
using namespace std;

int main()
{
    /* 1.variables */

    string words[5] = {"house", "river","cloud","grass","fence"};
    int num;
    cout << "Enter number 0-4:";
    cin >> num;
    string word = words[num];
    int correct = 0;
    int incorrect = 0;
    string user_word = "_____";
    string hangman[5][5]=  {{"+","-","+"," ", " \n"},
                          {"|"," ","o"," ", "\n"},/*1[1][2]*/
                          {"|","/","|",">", "\n"},/*2[2][1],3[2][2],4[2][3]*/
                          {"|"," ","n"," ", "\n"},/*5[3][2]*/
                          {"|"," "," "," ", "\n"}};
    //2. loop
    while (incorrect < 5 && correct < (word.size()))
    {
        string user_input;
        bool tof = true;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++)
            {
                cout << hangman[y][x];
            }
        }
        cout << "============================================================";
        cout << " \nYou have: " << int(5-incorrect) << " number of lives." << endl;
        cout << "============================================================\n";
        cout << "Enter letter:";
        cin >> user_input;
        for (int i = 0; i < word.length(); ++i)
        {
            string index(1, word[i]);
            int res = user_input.compare(index);
            if(res == 0)
            {
                //found
                tof = false;
                user_word[i] = word[i];
                cout << user_word << endl;
                correct++;
            }
        }
        if (tof)
        {
            incorrect = incorrect + 1;
            //edit hangmna
            if (incorrect == 1)
            {
                hangman[3][2] = " ";
            }
            else if (incorrect == 2)
            {
                hangman[2][1] = " ";
            }
            else if (incorrect == 3)
            {
                hangman[2][3] = " ";
            }
            else if (incorrect == 4)
            {
                hangman[2][2] = " ";
            }
            else if (incorrect == 5)
            {
                hangman[1][2] = " ";
            }
            cout << user_word << endl;

        }
    }
        cout << endl;
        if (correct == 5) {
            cout << "YOU WON!";
        }
        else if (incorrect == 5){
            cout << "YOU LOST";
        }

    return(0);
}
