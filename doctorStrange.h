//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef doctorStrange_h
#define doctorStrange_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

///STUDENT'S ANSWER BEGINS HERE
///STUDENTS CAN ADD HELPER FUNCTIONS

int atoi(string s)
{
    int result = 0;
    if (s.length() == 1)
    {
        return result += int(s[0]) - 48;
    }
    else 
    {
        result += int(s[0]) - 48;
        for (int i = 1; i < s.length(); i++)
        {
            result = result * 10 + (int(s[i]) - 48); 
        }
    }   
    
    return result;
}

int atoi(char s)
{
    int result = int(s) - 48;
    return result;
}

string set_win_information(string & HP, int & maxHP, string & LV, string & EXP)
{
    if (atoi(LV) >= 10 && atoi(EXP) >= 100)
    {
        LV = '10';
        EXP = '100';
    }
    else if (atoi(EXP) >= 100)
    {
        EXP = to_string(atoi(EXP) - 100);
        LV = to_string(atoi(LV) + 1);
        maxHP += 50;
        HP = to_string(atoi(HP) + 10);
        if (atoi(HP) > maxHP) HP = to_string(maxHP);
        if (atoi(HP) > 999) HP = to_string(999);
        if (maxHP > 999) maxHP = 999;
    }
    

    return HP;
    return LV;
    return EXP;
}

int handleEvents(string & HP, string & LV, string & EXP, string & TS, string & events) {
    ///Students have to complete this function and DO NOT modify any parameters in this function.
    int result = 0;
    cout << HP << " " << LV << " " << EXP << " " << TS << endl;
    cout << events << endl;

    int maxHP = atoi(HP);
    int count_event = 0;
    int index = 0;
    while (events[index])
    {
        if (events[index] != '!' && events[index] != '#')
        {
            count_event++;
            index++;
            int b = count_event % 10;
            int LVo = count_event > 6 ? (b > 5 ? b : 5) : b;


            // 1-->5 events
            if (count_event < 6)
            {
                if (atoi(events[index]) == 1)
                {
                    float baseDamage = 1.5f;
                    int exp = 10;

                    if (atoi(LV) > LVo)
                    {
                        EXP = to_string(atoi(EXP) + 10);

                    }
                    
                }
                else if (atoi(events[index]) == 2)
                {
                    float baseDamage = 2.5f;
                    int exp = 20;
                }
                else if (atoi(events[index]) == 3)
                {
                    float baseDamage = 4.5f;
                    int exp = 40;
                }
                else if (atoi(events[index]) == 4)
                {
                    float baseDamage = 7.5f;
                    int exp = 50;
                }
                else if (atoi(events[index]) == 5)
                {
                    float baseDamage = 9.5f;
                    int exp = 70;
                }
            }
            
        }
        else index++;
        
    }
    
    return result;
}

///END OF STUDENT'S ANSWER

#endif /* studyInPink_h */
