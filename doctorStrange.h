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
// ktlt.bku@gmail.com
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

void set_win_information(string & HP, string & maxHP, string & LV, string & EXP, int exp,
                        string & TS, char event)
{
    EXP = to_string(atoi(EXP) + exp);
    if (atoi(LV) >= 10 && atoi(EXP) >= 100)
    {
        LV = to_string(10);
        EXP = to_string(100);
    }
    else if (atoi(EXP) >= 100)
    {
        while (atoi(EXP) >= 100)
        {
            EXP = to_string(atoi(EXP) - 100);
            LV = to_string(atoi(LV) + 1);
            if (atoi(LV) <= 10)
            {
                maxHP = to_string(atoi(maxHP) + 50);
                HP = to_string(atoi(HP) + 10);
                if (atoi(HP) > atoi(maxHP)) HP = maxHP;
                if (atoi(HP) > 999) HP = to_string(999);
                if (atoi(maxHP) > 999) maxHP = to_string(999);   
            }
        }
        
    }

    if (atoi(LV) >= 10)
    {
        LV = to_string(10);
    }
    
    if (event == '6')
    {
        TS = to_string(atoi(TS) + 1);
    }
    

}

void set_defeat_information(string & HP, string maxHP, int LVo, float baseDamage, string & TS,
                            char event, int negative_damage, bool coat_flag, bool invalid_coat,
                            int count_events,int & count_defeat, int prime_big_than_hp)
{
    if (coat_flag && invalid_coat)
    {
        int gy = (count_events + prime_big_than_hp) % 100;
        int damage = int(baseDamage * LVo * 10 * (100 - gy) / 100);
        if (event > '0' && event < '6')
        {
            int HP_temp = int(atoi(HP) - damage);
            HP = to_string(int(atoi(HP) - damage));
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
        else if (event == '6')
        {
            if (atoi(HP) < 100)
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
            else
            {   
                if (negative_damage < 100) 
                {
                    int HP_temp = int(atoi(HP) * 1.0f - (atoi(HP) * 1.0f * (100 - negative_damage - gy) / 100));
                    // cout << "check HP khi thua tai sk 6 khi negative damage < 100: " 
                    // << (atoi(HP) * 1.0f - (atoi(HP) * 1.0f * (100 - negative_damage) / 100)) << endl;
                    HP = to_string(int(atoi(HP) * 1.0f - (atoi(HP) * 1.0f * (100 - negative_damage - gy) / 100)));

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
            }
            
        }
    }
    else
    {
        if (event > '0' && event < '6')
        {
            int HP_temp = int(atoi(HP) * 1.0f - (baseDamage * LVo * 10));
            HP = to_string(int(atoi(HP) * 1.0f - (baseDamage * LVo * 10)));
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
        else if (event == '6')
        {
            if (atoi(HP) < 100)
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
            else
            {
                if (negative_damage < 100) 
                {
                    int HP_temp = int(atoi(HP) * 1.0f - (atoi(HP) * 1.0f * (100 - negative_damage) / 100));
                    // cout << "check HP khi thua tai sk 6 khi negative damage < 100: " << (atoi(HP) * 1.0f - (atoi(HP) * 1.0f * (100 - negative_damage) / 100)) << endl;
                    HP = to_string(int(atoi(HP) * 1.0f - (atoi(HP) * 1.0f * (100 - negative_damage) / 100)));

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
            }
            
        }
    }
    
    count_defeat++;
}

void set_information(string & HP, string & LV, string & EXP, string & TS, string & maxHP, int LVo,
                    float baseDamage, int exp, char event,int & negative_damage, bool coat_flag,
                    bool & invalid_coat, int count_events, int & count_defeat, int prime_big_than_hp)
{
    if (atoi(LV) > LVo)
    {
        set_win_information(HP, maxHP, LV, EXP, exp, TS, event);
    }
    else if (atoi(LV) < LVo)
    {
        set_defeat_information(HP, maxHP, LVo, baseDamage, TS, event, negative_damage, coat_flag,
                               invalid_coat, count_events, count_defeat, prime_big_than_hp);
    }
    else
    {
        exp /= 2;
        set_win_information(HP, maxHP, LV, EXP, exp, TS, event);
    }
}

int set_LVo(int count_event)
{
    int b = count_event % 10;
    int result = count_event > 6 ? (b > 5 ? b : 5) : b;
    return result;
}

void my_str_to_lower(string & s) // bjen chuoi hoa thanh chuoi thuong 
{
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = char(int(s[i]) + 32);
        }   
    }
    
}

int count_attack_work(string s)
{
    int result = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] == 'a')
        {
            for (int j = i + 1; j < length; j++)
            {
                if (s[j] == 't')
                {
                    for (int k = j + 1; k < length; k++)
                    {
                        if (s[k] == 't')
                        {
                            for (int m = k + 1; m < length; m++)
                            {
                                if (s[m] == 'a')
                                {
                                    for (int n = m + 1; n < length; n++)
                                    {
                                        if (s[n] == 'c')
                                        {
                                            for (int t = n + 1; t < length; t++)
                                            {
                                                if (s[t] == 'k')
                                                {
                                                    result++;
                                                }
                                                
                                            }
                                            
                                        }
                                        
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
    return result;
}

int count_defense_work(string s)
{
    int result = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] == 'd')
        {
            for (int j = i + 1; j < length; j++)
            {
                if (s[j] == 'e')
                {
                    for (int k = j + 1; k < length; k++)
                    {
                        if (s[k] == 'f')
                        {
                            for (int m = k + 1; m < length; m++)
                            {
                                if (s[m] == 'e')
                                {
                                    for (int n = m + 1; n < length; n++)
                                    {
                                        if (s[n] == 'n')
                                        {
                                            for (int t = n + 1; t < length; t++)
                                            {
                                                if (s[t] == 's')
                                                {
                                                    for (int v = t + 1; v < length; v++)
                                                    {
                                                        if (s[v] == 'e')
                                                        {
                                                            result++;
                                                        }
                                                        
                                                    }
                                                
                                                }
                                                
                                            }
                                            
                                        }
                                        
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    return result;
}

int find_prime_big_than_hp(string HP)
{
    int result = atoi(HP);
    while (true)
    {
        result ++;
        bool is_result = true;
        for (int i = 2; i < result; i++)
        {
            if (result % i == 0)
            {
                is_result = false;
                break;
            }
            
        }

        if (is_result)
        {
            break;
        }
        
        
    }
    
    return result;
}

int fibonacci (string HP)
{
    int result = atoi(HP);
    
    if (atoi(HP) > 0 && atoi(HP) <= 3)
    {
        return atoi(HP) - 1;
    }
    
    while (true)
    {
        int f0 = 0;
        int f1 = 1;
        int fn = 0;
        result--;
        
        while (fn <= result)
        {
            fn = f1 + f0;
            f0 = f1;
            f1 = fn;
            if (fn == result)
            {
                result = fn;
                break;
            }
            
        }
        
        if (fn == result)
        {
            break;
        }
        
    }
    
    return result;
}

void translate_string (string &s1, string s2)
{
    int ith = s2.length() % 10;
    int length_s1 = s1.length();
    for (int i = 0; i < length_s1; i++)
    {
        int position = ith;
            if (s1[i] >= 'A' && s1[i] <= 'Z')
            {
                if (int(s1[i]) + position > 90)
                {
                    position = position - (90 - int(s1[i])) - 1; 
                    s1[i] = 'A';
                    while (int(s1[i]) + position > 90)
                    {
                        position = position - (90 - int(s1[i])) - 1; 
                    }
                    
                    s1[i] = char(int(s1[i]) + position);
                }
                else
                {
                    s1[i] = char(int(s1[i]) + position);
                }
            }
            else if (s1[i] >= 'a' && s1[i] <= 'z')
            {
                if (int(s1[i]) + position > 122)
                {
                    position = position - (122 - int(s1[i])) - 1;
                    s1[i] = 'a';
                    while (int(s1[i]) + position > 122)
                    {
                        position = position - (122 - int(s1[i])) - 1; 
                    }
                    
                    s1[i] = char(int(s1[i]) + position);
                }
                else
                {
                    s1[i] = char(int(s1[i]) + position);
                }
            }   
        
    }
    
}


int handleEvents(string & HP, string & LV, string & EXP, string & TS, string & events) {
    ///Students have to complete this function and DO NOT modify any parameters in this function.
    int result = 0;
    cout << HP << " " << LV << " " << EXP << " " << TS << endl;
    cout << events << endl;


    string maxHP = HP;
    int count_event = 0;
    int index = 1;
    int length = events.length();
    int count_defeat = 0;
    bool invalid_coat = false;
    bool coat_flag = false;

    bool real_wong = false;
    bool fake_wong = false;
    bool is_first_meet = true;
    int count_real_wong_help = 0;
    int count_fake_wong_fight = 0;
    int count_fake_wong = 0;
    
    bool dangerous_chemical = false;
    int count_events_after_11_event = 0;
    int LV_deference = 0;




    for (; index < length - 1; )
    {
        // 1-->5 events
        // while (events[index] != '!' 
        //         && events[index] < '6'
        //         // && events[index + 1] == '#'
        //         )                       // lam sao do chi lay cac ma su kien la 1-->5
        //                                 //  dk nay chua chuan cho cac truong hop 10.11.12.13.14.15
        //                                 // can sua chua lai sau
        // {                                           
        //     if (events[index] != '#')
        //     {
        //         count_event++;
        //         int LVo = set_LVo(count_event);

                // if (count_event < 6)
                // {
                    if (atoi(events[index]) == 1 && events[index + 1] == '#')
                    {
                        count_event++;
                        int LVo = set_LVo(count_event);
                        float baseDamage = 1.5f;
                        int exp = 10;
                        int negative_damage = 0;
                        int prime = find_prime_big_than_hp(HP);

                        if (count_events_after_11_event >= 3)
                        {
                            count_events_after_11_event = 0;
                            dangerous_chemical = false;
                            if (LV_deference == 1)
                            {
                                LV = to_string(atoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(atoi(LV) + 2);

                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                        }
                        

                        if (real_wong)
                        {
                            set_win_information(HP, maxHP, LV, EXP, exp, TS, events[index]);
                            count_real_wong_help++;
                            if (count_real_wong_help == 3)
                            {
                                real_wong = false;
                            }
                        }
                        else if (fake_wong)
                        {
                            int pre_TS = atoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (atoi(TS) == (pre_TS - 1))
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                            
                            if (count_fake_wong_fight == 3)
                            {
                                fake_wong = false;
                            }
                            
                        }
                        else
                        {
                            set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp, events[index],
                                            negative_damage, coat_flag, invalid_coat, count_event,
                                            count_defeat, prime);

                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                            
                        }

                        if (dangerous_chemical)
                        {
                            count_events_after_11_event++;
                        }
                        

                        cout << "ket qua sau cac su kien thu : " << count_event << endl;
                        cout << HP << " " << LV << " " << EXP << " " << TS << endl;
                        if (count_defeat >= 3)
                        {
                            invalid_coat = false;
                            if (atoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }
                        
                        
                        index += 2;
                    }
                    else if (atoi(events[index]) == 2)
                    {
                        count_event++;
                        int LVo = set_LVo(count_event);
                        float baseDamage = 2.5f;
                        int exp = 20;
                        int negative_damage = 0;
                        int prime = find_prime_big_than_hp(HP);
                        
                        if (count_events_after_11_event >= 3)
                        {
                            count_events_after_11_event = 0;
                            dangerous_chemical = false;
                            if (LV_deference == 1)
                            {
                                LV = to_string(atoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(atoi(LV) + 2);

                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                        }

                        if (dangerous_chemical)
                        {
                            count_events_after_11_event++;
                        }

                        if (real_wong)
                        {
                            set_win_information(HP, maxHP, LV, EXP, exp, TS, events[index]);
                            count_real_wong_help++;
                            if (count_real_wong_help == 3)
                            {
                                real_wong = false;
                            }
                        }
                        else if (fake_wong)
                        {
                            int pre_TS = atoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (atoi(TS) == (pre_TS - 1))
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                            
                            if (count_fake_wong_fight == 3)
                            {
                                fake_wong = false;
                            }
                            
                        }
                        else
                        {
                            set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp, events[index],
                                            negative_damage, coat_flag, invalid_coat, count_event,
                                            count_defeat, prime);
                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                        }
                        
                        cout << "ket qua sau cac su kien thu : " << count_event << endl;
                        cout << HP << " " << LV << " " << EXP << " " << TS << endl;
                        if (count_defeat >= 3)
                        {
                            invalid_coat = false;
                            if (atoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }
                        
                        index += 2;
                    }
                    else if (atoi(events[index]) == 3)
                    {
                        count_event++;
                        int LVo = set_LVo(count_event);
                        float baseDamage = 4.5f;
                        int exp = 40;
                        int negative_damage = 0;
                        int prime = find_prime_big_than_hp(HP);
                        
                        if (count_events_after_11_event >= 3)
                        {
                            count_events_after_11_event = 0;
                            dangerous_chemical = false;
                            if (LV_deference == 1)
                            {
                                LV = to_string(atoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(atoi(LV) + 2);
                            
                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                        }

                        if (dangerous_chemical)
                        {
                            count_events_after_11_event++;
                        }

                        if (real_wong)
                        {
                            set_win_information(HP, maxHP, LV, EXP, exp, TS, events[index]);
                            count_real_wong_help++;
                            if (count_real_wong_help == 3)
                            {
                                real_wong = false;
                            }
                        }
                        else if (fake_wong)
                        {
                            int pre_TS = atoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (atoi(TS) == (pre_TS - 1))
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                            
                            if (count_fake_wong_fight == 3)
                            {
                                fake_wong = false;
                            }
                            
                        }
                        else
                        {
                            set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp, events[index],
                                            negative_damage, coat_flag, invalid_coat, count_event,
                                            count_defeat, prime);
                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                        }
                        
                        cout << "ket qua sau cac su kien thu : " << count_event << endl;
                        cout << HP << " " << LV << " " << EXP << " " << TS << endl;
                        
                        if (count_defeat >= 3)
                        {
                            invalid_coat = false;
                            if (atoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }

                        index += 2;
                    }
                    else if (atoi(events[index]) == 4)
                    {
                        count_event++;
                        int LVo = set_LVo(count_event);
                        float baseDamage = 7.5f;
                        int exp = 50;
                        int negative_damage = 0;
                        int prime = find_prime_big_than_hp(HP);
                        

                        if (count_events_after_11_event >= 3)
                        {
                            count_events_after_11_event = 0;
                            dangerous_chemical = false;
                            if (LV_deference == 1)
                            {
                                LV = to_string(atoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(atoi(LV) + 2);

                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                        }

                        if (dangerous_chemical)
                        {
                            count_events_after_11_event++;
                        }

                        if (real_wong)
                        {
                            set_win_information(HP, maxHP, LV, EXP, exp, TS, events[index]);
                            count_real_wong_help++;
                            if (count_real_wong_help == 3)
                            {
                                real_wong = false;
                            }
                        }
                        else if (fake_wong)
                        {
                            int pre_TS = atoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (atoi(TS) == (pre_TS - 1))
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                            
                            if (count_fake_wong_fight == 3)
                            {
                                fake_wong = false;
                            }
                            
                        }
                        else
                        {
                            set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp, events[index],
                                            negative_damage, coat_flag, invalid_coat, count_event,
                                            count_defeat, prime);
                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                        }

                        cout << "ket qua sau cac su kien thu : " << count_event << endl;
                        cout << HP << " " << LV << " " << EXP << " " << TS << endl;
                        if (count_defeat >= 3)
                        {
                            invalid_coat = false;
                            if (atoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }

                        index += 2;
                    }
                    else if (atoi(events[index]) == 5)
                    {
                        count_event++;
                        int LVo = set_LVo(count_event);
                        float baseDamage = 9.5f;
                        int exp = 70;
                        int negative_damage = 0;
                        int prime = find_prime_big_than_hp(HP);
                        
                        if (count_events_after_11_event >= 3)
                        {
                            count_events_after_11_event = 0;
                            dangerous_chemical = false;
                            if (LV_deference == 1)
                            {
                                LV = to_string(atoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(atoi(LV) + 2);

                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                        }
                        if (dangerous_chemical)
                        {
                            count_events_after_11_event++;
                        }
                        if (real_wong)
                        {
                            set_win_information(HP, maxHP, LV, EXP, exp, TS, events[index]);
                            count_real_wong_help++;
                            if (count_real_wong_help == 3)
                            {
                                real_wong = false;
                            }
                        }
                        else if (fake_wong)
                        {
                            int pre_TS = atoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (atoi(TS) == (pre_TS - 1))
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                            
                            if (count_fake_wong_fight == 3)
                            {
                                fake_wong = false;
                            }
                            
                        }
                        else
                        {
                            set_information(HP, LV, EXP, TS, maxHP, LVo, baseDamage, exp, events[index],
                                            negative_damage, coat_flag, invalid_coat, count_event,
                                            count_defeat, prime);
                            if (fake_wong && atoi(LV) > 7)
                            {
                                fake_wong = false;
                                count_fake_wong--;
                            }
                        }
                
                        cout << "ket qua sau cac su kien thu : " << count_event << endl;;
                        cout << HP << " " << LV << " " << EXP << " " << TS << endl;
                        if (count_defeat >= 3)
                        {
                            invalid_coat = false;
                            if (atoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }
                        index += 2;
                    }

                    if (atoi(HP) == 0) return result = -1;
                    // index++;
                // }
        //     }
        //     else index++;    
        // } // khi while thoat ra taj day
        //  index la vi tri cua su kien tiep theo (index da duyet qua vj trj co chua dau #)

        if (events[index] == '6') // lam su kien so 6
        {
            count_event++;
            int LVo = set_LVo(count_event);

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(atoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(atoi(LV) + 2);

                if (fake_wong && atoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
            }
            if (dangerous_chemical)
            {
                count_events_after_11_event++;
            }
            index += 2; // di chuyen con tro den vi tri dau tien co chu cai sau ma su kien 6
            string magic_work = "";
            while (events[index] != '#' && events[index] != '!')
            {
                magic_work += events[index];
                index++;
            }
            index++;  //  index la vi tri cua su kien tiep theo (index da duyet qua vj trj co chua dau #)
            
            // cout << magic_work << endl;
            // chuan hoa chuoi magic_work ve dang hoa / thuong
            // sau do dem so lan xuat hien chuoi attack / defense
            // sau do cap nhat thong tjn theo yeu cau

            // cout << "day la khuc kiem tra ham my_str_to_lower" << endl;
            my_str_to_lower(magic_work);
            // cout << magic_work << endl;

            // cout << "check count_attack_work() function: " << count_attack_work(magic_work) << endl;
            // cout << "check count_defense_work() function: " << count_defense_work(magic_work) << endl;

            int fx = (count_event + magic_work.length()) % 100; // create fx function
            int win_percent = count_attack_work(magic_work) * 10;
            int negative_damage = 10 * count_defense_work(magic_work);

            // cout << "day la fx: " << fx << endl;
            // cout << "day la win_percent: " << win_percent << endl;
            // cout << "day la negative damage: " << negative_damage << endl;
            if (coat_flag && invalid_coat)
            {
                int prime = find_prime_big_than_hp(HP);
                int gy = (count_event + prime) % 100;
                win_percent += gy;
                negative_damage += gy;
            }
            

            if (win_percent > fx)
            {
                set_win_information(HP, maxHP, LV, EXP, 200, TS, '6');

                if (fake_wong && atoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }

                cout << "ket qua sau cac su kien thu : " << count_event << endl;
                cout << HP << " " << LV << " " << EXP << " " << TS << endl;
                
            }
            else
            {
                int prime = find_prime_big_than_hp(HP);
                set_defeat_information(HP, maxHP, LVo, 0, TS, '6', negative_damage, coat_flag, invalid_coat,
                                       count_event, count_defeat, prime);
                
                cout << "ket qua sau cac su kien thu : " << count_event << endl;
                cout << HP << " " << LV << " " << EXP << " " << TS << endl;
                if (count_defeat >= 3)
                {
                    invalid_coat = false;
                    if (atoi(LV) < 3 && !invalid_coat)
                    {
                        LV = to_string(1);
                    }
                }
                if (atoi(HP) == 0) return result = -1;
                
            }
        } // khi dong if nay thoat ra   
        //  thi index dang nam tai vi tri cua su kien tiep theo (index da duyet qua vj trj co chua dau #)
        else if (events[index] == '7')
        {
            count_event++;

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(atoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(atoi(LV) + 2);

                if (fake_wong && atoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
            }
            if (dangerous_chemical)
            {
                count_events_after_11_event++;
            }
            if (!coat_flag)
            {
                coat_flag = true;
                if (count_defeat < 3) 
                {
                    invalid_coat = true;
                    LV = to_string(atoi(LV) + 2);
                    if (atoi(LV) > 10)
                    {
                        LV = to_string(10);
                    }
                }

                // if (fake_wong)
                // {
                //     coat_flag = false;
                //     count_fake_wong_fight++;
                //     if (count_fake_wong_fight >= 3)
                //     {
                //         fake_wong = false;
                //     }
                    
                // }

                if (fake_wong)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
                
                
            }
            cout << "ket qua sau cac su kien thu : " << count_event << endl;
            cout << HP << " " << LV << " " << EXP << " " << TS << endl;
            index += 2;
        }
        else if (events[index] == '8')
        {
            count_event++;

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(atoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(atoi(LV) + 2);

                if (fake_wong && atoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
            }
            if (dangerous_chemical)
            {
                count_events_after_11_event++;
            }

            if (is_first_meet)
            {
                is_first_meet = false;
                real_wong = true;
            }
            else if (!is_first_meet && count_fake_wong_fight < 3)
            {
                fake_wong = true;
                count_fake_wong++;
            }

            if (real_wong && fake_wong)
            {
                fake_wong = false;
                count_fake_wong--;
                count_real_wong_help++;

                if (count_real_wong_help == 3)
                {
                    real_wong = false;
                }
                
            }
            
            if (fake_wong && coat_flag)
            {
                coat_flag = false;
                if (invalid_coat)
                {
                    LV = to_string(atoi(LV) - 2);
                }
                
                count_fake_wong_fight++;

                if (count_fake_wong_fight == 3)
                {
                    fake_wong = false;
                }
            }

            if (fake_wong && atoi(LV) > 7)
            {
                fake_wong = false;
                count_fake_wong--;
            }
            
            
            if (fake_wong && count_fake_wong == 2)
            {
                count_fake_wong--;
                count_fake_wong_fight++;
                if (count_fake_wong_fight == 3)
                {
                    fake_wong = false;
                }
            }
            


            index += 2;
        }

        else if (events[index] == '9')
        {
            count_event++;
            
            // if (count_events_after_11_event >= 3)
            // {
            //     count_events_after_11_event = 0;
            //     dangerous_chemical = false;
            //     if (LV_deference == 1)
            //     {
            //         LV = to_string(atoi(LV) + 1);
            //         LV_deference = 0;
            //     }
            //     else LV = to_string(atoi(LV) + 2);

            //     if (fake_wong && atoi(LV) > 7)
            //     {
            //         fake_wong = false;
            //         count_fake_wong--;
            //     }
            // }
            // if (dangerous_chemical)
            // {
            //     count_events_after_11_event++;
            // }
            HP = maxHP;


            dangerous_chemical = false;
            count_events_after_11_event = 0;
            if (LV_deference == 1)
            {
                LV = to_string(atoi(LV) + 1);
                LV_deference = 0;
            }
            else LV = to_string(atoi(LV) + 2);
            
            if (fake_wong)
            {
                fake_wong = false;
                count_fake_wong--;
            }
            
            if (count_defeat != 0)
            {
                count_defeat = 0;
                invalid_coat = true;
            }

            if (!coat_flag)
            {
                coat_flag = true;
                LV = to_string(atoi(LV) + 2);
                if (atoi(LV) > 10)
                {
                    LV = to_string(10);
                }
            }
            
            index += 2;
        }

        if (events[index] == '1' && events[index + 1] == '0')
        {
            count_event++;

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(atoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(atoi(LV) + 2);

                if (fake_wong && atoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
            }
            if (dangerous_chemical)
            {
                count_events_after_11_event++;
            }
            HP = to_string(atoi(HP) + fibonacci(HP));
            if (atoi(HP) > atoi(maxHP))
            {
                HP = maxHP;
            }
            
            index += 3;
        }
        else if (events[index] == '1' && events[index + 1] == '1')
        {
            count_event++;

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(atoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(atoi(LV) + 2);

                if (fake_wong && atoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
            }
            if (dangerous_chemical)
            {
                count_events_after_11_event++;
            }
            int pre_TS = atoi(TS);
            
            if (real_wong)
            {
                count_real_wong_help++;
                if (count_real_wong_help >= 3)
                {
                    real_wong = false;
                }
                
            }
            else if (fake_wong)
            {
                HP = to_string(atoi(HP) - 50);
                dangerous_chemical = true;
                int HP_temp = std::stoi(HP, 0, 10);
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

                if (atoi(HP) == 0)
                {
                    return -1;
                }
                else
                {
                    // dangerous_chemical = true;
                    count_fake_wong_fight++;
                    if (count_fake_wong_fight >= 3)
                    {
                        fake_wong = false;
                        count_fake_wong--;
                    }

                    if (fake_wong && atoi(TS) == (pre_TS - 1))
                    {
                        fake_wong = false;
                        count_fake_wong--;
                        dangerous_chemical = false;
                    }
                    
                    if (atoi(LV) < 3 && dangerous_chemical)
                    {
                        LV_deference = atoi(LV) - 1;
                        LV = to_string(1);
                    }
                    else if (atoi(LV) >= 3 && dangerous_chemical)
                    {
                        LV = to_string(atoi(LV) - 2);
                    }
                    
                    
                }
                
                
            }
            
            else if (!dangerous_chemical)
            {
                HP = to_string(atoi(HP) - 50);
                dangerous_chemical = true;
                int HP_temp = std::stoi(HP, 0, 10);
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

                if (atoi(HP) == 0)
                {
                    return -1;
                }

                if (atoi(LV) < 3 && dangerous_chemical)
                    {
                        LV_deference = atoi(LV) - 1;
                        LV = to_string(1);
                    }
                    else if (atoi(LV) >= 3 && dangerous_chemical)
                    {
                        LV = to_string(atoi(LV) - 2);
                    }
            }
            
            else if (dangerous_chemical)
            {
                HP = to_string(atoi(HP) - 50);
                int HP_temp = std::stoi(HP, 0, 10);
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

                if (atoi(HP) == 0)
                {
                    return -1;
                }
            }

            index += 3;
        }
        else if (events[index] == '1' && events[index + 1] == '2')
        {
            count_event++;
            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(atoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(atoi(LV) + 2);

                if (fake_wong && atoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
            }
            if (dangerous_chemical)
            {
                count_events_after_11_event++;
            }

            if (count_defeat >= 3)
            {
                invalid_coat = false;
                if (atoi(LV) < 3 && !invalid_coat)
                {
                    LV = to_string(1);
                }
            }
            
            if (fake_wong)
            {
                fake_wong = false;
                count_fake_wong--;
            }

            index += 3;


            string s1 = "";
            string s2 = "";
            int G_point = 0;
            while (events[index] != ' ')
            {
                s1 += events[index];
                index++;
            }
            index++;

            while (events[index] != '#' && events[index] != '!')
            {
                s2 += events[index];
                index++;
            }

            index++; // da di qua den ma su kien moi 
                    // da duyet qua ky tu #

            if (s1.length() == 1 || s1.length() == 2)
            {
                // int ith = s2.length() % 10;

            }
            else  
            {
                G_point = int ((s1.length() * 1.0f) / 2);
            }
        }
        
        
        
    }
    
    
    result = atoi(HP) + atoi(LV) + atoi(EXP) + atoi(TS);
    cout << "ket qua cuoi cung: " << endl;
    cout << HP << " " << LV << " " << EXP << " " << TS << endl;


    return result;
}

///END OF STUDENT'S ANSWER

#endif /* studyInPink_h */
