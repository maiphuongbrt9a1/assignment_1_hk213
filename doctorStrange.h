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

void set_win_information(string & HP, string & maxHP, string & LV, string & EXP, int exp)
{
    EXP = to_string(atoi(EXP) + exp);
    if (atoi(LV) >= 10 && atoi(EXP) >= 100)
    {
        LV = to_string(10);
        EXP = to_string(100);
    }
    else if (atoi(EXP) >= 100)
    {
        EXP = to_string(atoi(EXP) - 100);
        LV = to_string(atoi(LV) + 1);
        maxHP = to_string(atoi(maxHP) + 50);
        HP = to_string(atoi(HP) + 10);
        if (atoi(HP) > atoi(maxHP)) HP = maxHP;
        if (atoi(HP) > 999) HP = to_string(999);
        if (atoi(maxHP) > 999) maxHP = to_string(999);
    }
}

void set_defeat_information(string & HP, string maxHP, int LVo, float baseDamage, string & TS)
{
    int HP_temp = int(atoi(HP) * 1.0 - (baseDamage * LVo * 10));
    HP = to_string(int(atoi(HP) * 1.0 - (baseDamage * LVo * 10)));
    // cout << HP << endl;
    if (HP_temp <= 0)
    {
        if (atoi(TS) == 0)
        {
            HP = to_string(0);
        }
        else
        {
            TS = to_string(atoi(TS) - 1);
            HP = maxHP;
        }
        
    }
    
}

void set_information(string & HP, string & LV, string & EXP, string & TS, string & maxHP, int LVo, float baseDamage, int exp)
{
    if (atoi(LV) > LVo)
    {
        set_win_information(HP, maxHP, LV, EXP, exp);
    }
    else if (atoi(LV) < LVo)
    {
        set_defeat_information(HP, maxHP, LVo, baseDamage, TS);
    }
    else
    {
        exp /= 2;
        set_win_information(HP, maxHP, LV, EXP, exp);
    }
}

int set_LVo(int count_event)
{
    int b = count_event % 10;
    int result = count_event > 6 ? (b > 5 ? b : 5) : b;
    return result;
}

int handleEvents(string & HP, string & LV, string & EXP, string & TS, string & events) {
    ///Students have to complete this function and DO NOT modify any parameters in this function.
    int result = 0;
    cout << HP << " " << LV << " " << EXP << " " << TS << endl;
    cout << events << endl;

    string maxHP = HP;
    int count_event = 0;
    int index = 1;

    // 1-->5 events
    while (events[index] != '!' && events[index] != '6') // lam sao do chi lay cac ma su kien la 1-->5
                                            //  dk nay chua chuan cho cac truong hop 10.11.12.13.14.15
                                            // can sua chua lai sau
    {                                           
        if (events[index] != '#')
        {
            count_event++;
            int LVo = set_LVo(count_event);

            // if (count_event < 6)
            // {
                if (atoi(events[index]) == 1)
                {
                    float baseDamage = 1.5f;
                    int exp = 10;

                    set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp);
      
                }
                else if (atoi(events[index]) == 2)
                {
                    float baseDamage = 2.5f;
                    int exp = 20;
                    
                    set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp);
                    
                }
                else if (atoi(events[index]) == 3)
                {
                    float baseDamage = 4.5f;
                    int exp = 40;

                    set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp);
                    
                }
                else if (atoi(events[index]) == 4)
                {
                    float baseDamage = 7.5f;
                    int exp = 50;
                    set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp);
                    
                }
                else if (atoi(events[index]) == 5)
                {
                    float baseDamage = 9.5f;
                    int exp = 70;
                    set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp);
                    
                }

                if (atoi(HP) == 0) return result = -1;
                index++;
            // }
        }
        else index++;    
    }

    if (events[index] == '6') // lam su kien so 6
    {
        count_event++;
        int LVo = set_LVo(count_event);
        index += 2; // di chuyen con tro den vi tri dau tien co chu cai sau ma su kien 6
        string magic_work = "";
        while (events[index] != '#' && events[index] != '!')
        {
            magic_work += events[index];
            index++;
        }
        
        // cout << magic_work << endl;
        // chuan hoa chuoi magic_work ve dang hoa / thuong
        // sau do dem so lan xuat hien chuoi attack / defense
        // sau do cap nhat thong tjn theo yeu cau

        

    }
    
    
    result = atoi(HP) + atoi(LV) + atoi(EXP) + atoi(TS);
    // cout << HP << " " << LV << " " << EXP << " " << TS << endl;


    return result;
}

///END OF STUDENT'S ANSWER

#endif /* studyInPink_h */
