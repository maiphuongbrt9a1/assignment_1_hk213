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
        int s_length = s.length();
        for (int i = 1; i < s_length; i++)
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
    EXP = to_string(std::stoi(EXP) + exp);
    if (std::stoi(LV) >= 10 && std::stoi(EXP) >= 100)
    {
        LV = to_string(10);
        EXP = to_string(100);
    }
    else if (std::stoi(EXP) >= 100)
    {
        while (std::stoi(EXP) >= 100)
        {
            EXP = to_string(std::stoi(EXP) - 100);
            LV = to_string(std::stoi(LV) + 1);
            if (std::stoi(LV) <= 10)
            {
                maxHP = to_string(std::stoi(maxHP) + 50);
                HP = to_string(std::stoi(HP) + 10);
                if (std::stoi(HP) > std::stoi(maxHP)) HP = maxHP;
                if (std::stoi(HP) > 999) HP = to_string(999);
                if (std::stoi(maxHP) > 999) maxHP = to_string(999);   
            }
        }
        
    }

    if (std::stoi(LV) >= 10)
    {
        LV = to_string(10);
    }
    
    if (event == '6')
    {
        TS = to_string(std::stoi(TS) + 1);
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
            int HP_temp = int(std::stoi(HP) - damage);
            HP = to_string(int(std::stoi(HP) - damage));
            cout << HP << endl;
            if (HP_temp <= 0)
            {
                if (std::stoi(TS) == 0)
                {
                    HP = to_string(0);
                }
                else
                {
                    TS = to_string(std::stoi(TS) - 1);
                    HP = maxHP;
                }
                
            }
        }
        else if (event == '6')
        {
            if (std::stoi(HP) < 100)
            {
                if (std::stoi(TS) == 0)
                {
                    HP = to_string(0);
                }
                else
                {
                    TS = to_string(std::stoi(TS) - 1);
                    HP = maxHP;
                }
            }
            else
            {   
                if (negative_damage < 100) 
                {
                    int HP_temp = int(std::stoi(HP) * 1.0f - (std::stoi(HP) * 1.0f * (100 - negative_damage - gy) / 100));
                    cout << "check HP khi thua tai sk 6 khi negative damage < 100: " ;
                    // << (std::stoi(HP) * 1.0f - (std::stoi(HP) * 1.0f * (100 - negative_damage) / 100)) << endl;
                    HP = to_string(int(std::stoi(HP) * 1.0f - (std::stoi(HP) * 1.0f * (100 - negative_damage - gy) / 100)));

                    if (HP_temp <= 0)
                    {
                        if (std::stoi(TS) == 0)
                        {
                            HP = to_string(0);
                        }
                        else
                        {
                            TS = to_string(std::stoi(TS) - 1);
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
            int HP_temp = int(std::stoi(HP) * 1.0f - (baseDamage * LVo * 10));
            HP = to_string(int(std::stoi(HP) * 1.0f - (baseDamage * LVo * 10)));
            cout << HP << endl;
            if (HP_temp <= 0)
            {
                if (std::stoi(TS) == 0)
                {
                    HP = to_string(0);
                }
                else
                {
                    TS = to_string(std::stoi(TS) - 1);
                    HP = maxHP;
                }
                
            }
        }
        else if (event == '6')
        {
            if (std::stoi(HP) < 100)
            {
                if (std::stoi(TS) == 0)
                {
                    HP = to_string(0);
                }
                else
                {
                    TS = to_string(std::stoi(TS) - 1);
                    HP = maxHP;
                }
            }
            else
            {
                if (negative_damage < 100) 
                {
                    int HP_temp = int(std::stoi(HP) * 1.0f - (std::stoi(HP) * 1.0f * (100 - negative_damage) / 100));
                    cout << "check HP khi thua tai sk 6 khi negative damage < 100: " << (std::stoi(HP) * 1.0f - (std::stoi(HP) * 1.0f * (100 - negative_damage) / 100)) << endl;
                    HP = to_string(int(std::stoi(HP) * 1.0f - (std::stoi(HP) * 1.0f * (100 - negative_damage) / 100)));

                    if (HP_temp <= 0)
                    {
                        if (std::stoi(TS) == 0)
                        {
                            HP = to_string(0);
                        }
                        else
                        {
                            TS = to_string(std::stoi(TS) - 1);
                            HP = maxHP;
                        }
                        
                    }
                }
            }
            
        }
    }
    if (coat_flag && invalid_coat) count_defeat++;
}

void set_information(string & HP, string & LV, string & EXP, string & TS, string & maxHP, int LVo,
                    float baseDamage, int exp, char event,int & negative_damage, bool coat_flag,
                    bool & invalid_coat, int count_events, int & count_defeat, int prime_big_than_hp)
{
    if (std::stoi(LV) > LVo)
    {
        set_win_information(HP, maxHP, LV, EXP, exp, TS, event);
    }
    else if (std::stoi(LV) < LVo)
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
    int result = std::stoi(HP);
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
    int result = std::stoi(HP);
    
    if (std::stoi(HP) > 0 && std::stoi(HP) <= 3)
    {
        return std::stoi(HP) - 1;
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

int BinarySearch(int a[],int n,int x)
{
	int left, right, mid, count_step; left=0; right=n-1; count_step = 0;
	do{
		mid=(left+right)/2;
		if(a[mid]==x){
            count_step++;
			return count_step;
		}
		else if(a[mid]<x){
			right=mid-1;
            
            count_step++;
		}
		else{
            left=mid+1;
            count_step++;
		}
	}while(left<=right);
	return -1;
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

    bool defeat_12nd_event = false;
    bool kill_Strange = false;

    string TS_temp = "";

    string find_HP_max = HP;
    int index_15th_event = 1;
    bool back = false;
    int back_index = 1;
    int index_event = 1;
    bool dangerous_chemical_15th_event = false;
    int count_events_after_11_event_15th_event = 0;
    int LV_deference_15th_event = 0;
    bool defeat_12nd_event_15th_event = false;
    bool kill_Strange_15th_event = false;
    string maxHP_15th_event = HP;
    int count_event_15th_event = 0;
    int count_defeat_15th_event = 0;
    bool invalid_coat_15th_event = false;
    bool coat_flag_15th_event = false;

    bool real_wong_15th_event = false;
    bool fake_wong_15th_event = false;
    bool is_first_meet_15th_event = true;
    int count_real_wong_help_15th_event = 0;
    int count_fake_wong_fight_15th_event = 0;
    int count_fake_wong_15th_event = 0;

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
                    if (events[index] == '1' && (events[index + 1] == '#' || events[index + 1] == '!'))
                    {
                        count_event++;

                        if (std::stoi(find_HP_max) <= std::stoi(HP))
                        {
                            find_HP_max = HP;
                            back_index = index;
                            count_defeat_15th_event = count_defeat;
                            invalid_coat_15th_event = invalid_coat;
                            coat_flag_15th_event = coat_flag;

                            real_wong_15th_event = real_wong;
                            fake_wong_15th_event = fake_wong;
                            is_first_meet_15th_event = is_first_meet;
                            count_real_wong_help_15th_event = count_real_wong_help;
                            count_fake_wong_fight_15th_event = count_fake_wong_fight;
                            count_fake_wong_15th_event = count_fake_wong;
                            
                            dangerous_chemical_15th_event = dangerous_chemical;
                            count_events_after_11_event_15th_event = count_events_after_11_event;
                            LV_deference_15th_event = LV_deference;

                            defeat_12nd_event_15th_event = defeat_12nd_event;
                            kill_Strange_15th_event = kill_Strange;

                        }



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
                                LV = to_string(std::stoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(std::stoi(LV) + 2);

                            if (fake_wong && std::stoi(LV) > 7)
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
                            int pre_TS = std::stoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (std::stoi(TS) == (pre_TS - 1))
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

                            if (fake_wong && std::stoi(LV) > 7)
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
                            if (std::stoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }
                        
                        
                        index += 2;
                    }
                    else if (events[index] == '2' && (events[index + 1] == '#' || events[index + 1] == '!'))
                    {
                        count_event++;

                        if (std::stoi(find_HP_max) <= std::stoi(HP))
                        {
                            find_HP_max = HP;
                            back_index = index;
                            count_defeat_15th_event = count_defeat;
                            invalid_coat_15th_event = invalid_coat;
                            coat_flag_15th_event = coat_flag;

                            real_wong_15th_event = real_wong;
                            fake_wong_15th_event = fake_wong;
                            is_first_meet_15th_event = is_first_meet;
                            count_real_wong_help_15th_event = count_real_wong_help;
                            count_fake_wong_fight_15th_event = count_fake_wong_fight;
                            count_fake_wong_15th_event = count_fake_wong;
                            
                            dangerous_chemical_15th_event = dangerous_chemical;
                            count_events_after_11_event_15th_event = count_events_after_11_event;
                            LV_deference_15th_event = LV_deference;

                            defeat_12nd_event_15th_event = defeat_12nd_event;
                            kill_Strange_15th_event = kill_Strange;

                        }

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
                                LV = to_string(std::stoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(std::stoi(LV) + 2);

                            if (fake_wong && std::stoi(LV) > 7)
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
                            int pre_TS = std::stoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (std::stoi(TS) == (pre_TS - 1))
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
                            if (fake_wong && std::stoi(LV) > 7)
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
                            if (std::stoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }
                        
                        index += 2;
                    }
                    else if (events[index] == '3' && (events[index + 1] == '#' || events[index + 1] == '!'))
                    {
                        count_event++;

                        if (std::stoi(find_HP_max) <= std::stoi(HP))
                        {
                            find_HP_max = HP;
                            back_index = index;
                            count_defeat_15th_event = count_defeat;
                            invalid_coat_15th_event = invalid_coat;
                            coat_flag_15th_event = coat_flag;

                            real_wong_15th_event = real_wong;
                            fake_wong_15th_event = fake_wong;
                            is_first_meet_15th_event = is_first_meet;
                            count_real_wong_help_15th_event = count_real_wong_help;
                            count_fake_wong_fight_15th_event = count_fake_wong_fight;
                            count_fake_wong_15th_event = count_fake_wong;
                            
                            dangerous_chemical_15th_event = dangerous_chemical;
                            count_events_after_11_event_15th_event = count_events_after_11_event;
                            LV_deference_15th_event = LV_deference;

                            defeat_12nd_event_15th_event = defeat_12nd_event;
                            kill_Strange_15th_event = kill_Strange;

                        }


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
                                LV = to_string(std::stoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(std::stoi(LV) + 2);
                            
                            if (fake_wong && std::stoi(LV) > 7)
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
                            int pre_TS = std::stoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (std::stoi(TS) == (pre_TS - 1))
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
                            if (fake_wong && std::stoi(LV) > 7)
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
                            if (std::stoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }

                        index += 2;
                    }
                    else if (events[index] == '4' && (events[index + 1] == '#' || events[index + 1] == '!'))
                    {
                        count_event++;

                        if (std::stoi(find_HP_max) <= std::stoi(HP))
                        {
                            find_HP_max = HP;
                            back_index = index;
                            count_defeat_15th_event = count_defeat;
                            invalid_coat_15th_event = invalid_coat;
                            coat_flag_15th_event = coat_flag;

                            real_wong_15th_event = real_wong;
                            fake_wong_15th_event = fake_wong;
                            is_first_meet_15th_event = is_first_meet;
                            count_real_wong_help_15th_event = count_real_wong_help;
                            count_fake_wong_fight_15th_event = count_fake_wong_fight;
                            count_fake_wong_15th_event = count_fake_wong;
                            
                            dangerous_chemical_15th_event = dangerous_chemical;
                            count_events_after_11_event_15th_event = count_events_after_11_event;
                            LV_deference_15th_event = LV_deference;

                            defeat_12nd_event_15th_event = defeat_12nd_event;
                            kill_Strange_15th_event = kill_Strange;

                        }
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
                                LV = to_string(std::stoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(std::stoi(LV) + 2);

                            if (fake_wong && std::stoi(LV) > 7)
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
                            int pre_TS = std::stoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (std::stoi(TS) == (pre_TS - 1))
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
                            if (fake_wong && std::stoi(LV) > 7)
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
                            if (std::stoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }

                        index += 2;
                    }
                    else if (events[index] == '5' && (events[index + 1] == '#' || events[index + 1] == '!'))
                    {
                        count_event++;

                        if (std::stoi(find_HP_max) <= std::stoi(HP))
                        {
                            find_HP_max = HP;
                            back_index = index;
                            count_defeat_15th_event = count_defeat;
                            invalid_coat_15th_event = invalid_coat;
                            coat_flag_15th_event = coat_flag;

                            real_wong_15th_event = real_wong;
                            fake_wong_15th_event = fake_wong;
                            is_first_meet_15th_event = is_first_meet;
                            count_real_wong_help_15th_event = count_real_wong_help;
                            count_fake_wong_fight_15th_event = count_fake_wong_fight;
                            count_fake_wong_15th_event = count_fake_wong;
                            
                            dangerous_chemical_15th_event = dangerous_chemical;
                            count_events_after_11_event_15th_event = count_events_after_11_event;
                            LV_deference_15th_event = LV_deference;

                            defeat_12nd_event_15th_event = defeat_12nd_event;
                            kill_Strange_15th_event = kill_Strange;

                        }

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
                                LV = to_string(std::stoi(LV) + 1);
                                LV_deference = 0;
                            }
                            else LV = to_string(std::stoi(LV) + 2);

                            if (fake_wong && std::stoi(LV) > 7)
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
                            int pre_TS = std::stoi(TS);
                            set_defeat_information(HP, maxHP, LVo, baseDamage, TS, events[index], 
                                                    negative_damage, coat_flag, invalid_coat, count_event,
                                                    count_defeat, prime);
                            count_fake_wong_fight++;
                            
                            if (std::stoi(TS) == (pre_TS - 1))
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
                            if (fake_wong && std::stoi(LV) > 7)
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
                            if (std::stoi(LV) < 3 && !invalid_coat)
                            {
                                LV = to_string(1);
                            }
                        }
                        index += 2;
                    }

                    if (std::stoi(HP) == 0) return result = -1;
                    // index++;
                // }
        //     }
        //     else index++;    
        // } // khi while thoat ra taj day
        //  index la vi tri cua su kien tiep theo (index da duyet qua vj trj co chua dau #)

        if (events[index] == '6') // lam su kien so 6
        {
            count_event++;
            if (std::stoi(find_HP_max) <= std::stoi(HP))
            {
                find_HP_max = HP;
                back_index = index;
                count_defeat_15th_event = count_defeat;
                invalid_coat_15th_event = invalid_coat;
                coat_flag_15th_event = coat_flag;

                real_wong_15th_event = real_wong;
                fake_wong_15th_event = fake_wong;
                is_first_meet_15th_event = is_first_meet;
                count_real_wong_help_15th_event = count_real_wong_help;
                count_fake_wong_fight_15th_event = count_fake_wong_fight;
                count_fake_wong_15th_event = count_fake_wong;
                
                dangerous_chemical_15th_event = dangerous_chemical;
                count_events_after_11_event_15th_event = count_events_after_11_event;
                LV_deference_15th_event = LV_deference;

                defeat_12nd_event_15th_event = defeat_12nd_event;
                kill_Strange_15th_event = kill_Strange;

            }
            int LVo = set_LVo(count_event);

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(std::stoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(std::stoi(LV) + 2);

                if (fake_wong && std::stoi(LV) > 7)
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
            
            cout << magic_work << endl;
            // chuan hoa chuoi magic_work ve dang hoa / thuong
            // sau do dem so lan xuat hien chuoi attack / defense
            // sau do cap nhat thong tjn theo yeu cau

            cout << "day la khuc kiem tra ham my_str_to_lower" << endl;
            my_str_to_lower(magic_work);
            cout << magic_work << endl;

            cout << "check count_attack_work() function: " << count_attack_work(magic_work) << endl;
            cout << "check count_defense_work() function: " << count_defense_work(magic_work) << endl;

            int fx = (count_event + magic_work.length()) % 100; // create fx function
            int win_percent = count_attack_work(magic_work) * 10;
            int negative_damage = 10 * count_defense_work(magic_work);

            cout << "day la fx: " << fx << endl;
            cout << "day la win_percent: " << win_percent << endl;
            cout << "day la negative damage: " << negative_damage << endl;
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

                if (fake_wong && std::stoi(LV) > 7)
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
                    if (std::stoi(LV) < 3 && !invalid_coat)
                    {
                        LV = to_string(1);
                    }
                }
                if (std::stoi(HP) == 0) return result = -1;
                
            }
        } // khi dong if nay thoat ra   
        //  thi index dang nam tai vi tri cua su kien tiep theo (index da duyet qua vj trj co chua dau #)
        else if (events[index] == '7')
        {
            count_event++;

            if (std::stoi(find_HP_max) <= std::stoi(HP))
            {
                find_HP_max = HP;
                back_index = index;
                count_defeat_15th_event = count_defeat;
                invalid_coat_15th_event = invalid_coat;
                coat_flag_15th_event = coat_flag;

                real_wong_15th_event = real_wong;
                fake_wong_15th_event = fake_wong;
                is_first_meet_15th_event = is_first_meet;
                count_real_wong_help_15th_event = count_real_wong_help;
                count_fake_wong_fight_15th_event = count_fake_wong_fight;
                count_fake_wong_15th_event = count_fake_wong;
                
                dangerous_chemical_15th_event = dangerous_chemical;
                count_events_after_11_event_15th_event = count_events_after_11_event;
                LV_deference_15th_event = LV_deference;

                defeat_12nd_event_15th_event = defeat_12nd_event;
                kill_Strange_15th_event = kill_Strange;

            }

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(std::stoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(std::stoi(LV) + 2);

                if (fake_wong && std::stoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
            }
            if (dangerous_chemical)
            {
                count_events_after_11_event++;
            }
            if (!coat_flag && !defeat_12nd_event)
            {
                coat_flag = true;
                if (count_defeat < 3) 
                {
                    invalid_coat = true;
                    LV = to_string(std::stoi(LV) + 2);
                    if (std::stoi(LV) > 10)
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

            if (std::stoi(find_HP_max) <= std::stoi(HP))
            {
                find_HP_max = HP;
                back_index = index;
                count_defeat_15th_event = count_defeat;
                invalid_coat_15th_event = invalid_coat;
                coat_flag_15th_event = coat_flag;

                real_wong_15th_event = real_wong;
                fake_wong_15th_event = fake_wong;
                is_first_meet_15th_event = is_first_meet;
                count_real_wong_help_15th_event = count_real_wong_help;
                count_fake_wong_fight_15th_event = count_fake_wong_fight;
                count_fake_wong_15th_event = count_fake_wong;
                
                dangerous_chemical_15th_event = dangerous_chemical;
                count_events_after_11_event_15th_event = count_events_after_11_event;
                LV_deference_15th_event = LV_deference;

                defeat_12nd_event_15th_event = defeat_12nd_event;
                kill_Strange_15th_event = kill_Strange;

            }

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(std::stoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(std::stoi(LV) + 2);

                if (fake_wong && std::stoi(LV) > 7)
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
                // if (invalid_coat)
                // {
                //     LV = to_string(std::stoi(LV) - 2);
                // }
                
                count_fake_wong_fight++;

                if (count_fake_wong_fight == 3)
                {
                    fake_wong = false;
                }
            }

            if (fake_wong && std::stoi(LV) > 7)
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
            
            cout << "ket qua sau cac su kien thu : " << count_event << endl;;
            cout << HP << " " << LV << " " << EXP << " " << TS << endl;

            index += 2;
        }

        else if (events[index] == '9')
        {
            count_event++;
            
            if (std::stoi(find_HP_max) <= std::stoi(HP))
            {
                find_HP_max = HP;
                back_index = index;
                count_defeat_15th_event = count_defeat;
                invalid_coat_15th_event = invalid_coat;
                coat_flag_15th_event = coat_flag;

                real_wong_15th_event = real_wong;
                fake_wong_15th_event = fake_wong;
                is_first_meet_15th_event = is_first_meet;
                count_real_wong_help_15th_event = count_real_wong_help;
                count_fake_wong_fight_15th_event = count_fake_wong_fight;
                count_fake_wong_15th_event = count_fake_wong;
                
                dangerous_chemical_15th_event = dangerous_chemical;
                count_events_after_11_event_15th_event = count_events_after_11_event;
                LV_deference_15th_event = LV_deference;

                defeat_12nd_event_15th_event = defeat_12nd_event;
                kill_Strange_15th_event = kill_Strange;

            }


            // if (count_events_after_11_event >= 3)
            // {
            //     count_events_after_11_event = 0;
            //     dangerous_chemical = false;
            //     if (LV_deference == 1)
            //     {
            //         LV = to_string(std::stoi(LV) + 1);
            //         LV_deference = 0;
            //     }
            //     else LV = to_string(std::stoi(LV) + 2);

            //     if (fake_wong && std::stoi(LV) > 7)
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
                LV = to_string(std::stoi(LV) + 1);
                LV_deference = 0;
            }
            else LV = to_string(std::stoi(LV) + 2);
            
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
                LV = to_string(std::stoi(LV) + 2);
                if (std::stoi(LV) > 10)
                {
                    LV = to_string(10);
                }
            }
            cout << "ket qua sau cac su kien thu : " << count_event << endl;;
            cout << HP << " " << LV << " " << EXP << " " << TS << endl;
            index += 2;
        }

        if (events[index] == '1' && events[index + 1] == '0')
        {
            count_event++;

            if (std::stoi(find_HP_max) <= std::stoi(HP))
            {
                find_HP_max = HP;
                back_index = index;
                count_defeat_15th_event = count_defeat;
                invalid_coat_15th_event = invalid_coat;
                coat_flag_15th_event = coat_flag;

                real_wong_15th_event = real_wong;
                fake_wong_15th_event = fake_wong;
                is_first_meet_15th_event = is_first_meet;
                count_real_wong_help_15th_event = count_real_wong_help;
                count_fake_wong_fight_15th_event = count_fake_wong_fight;
                count_fake_wong_15th_event = count_fake_wong;
                
                dangerous_chemical_15th_event = dangerous_chemical;
                count_events_after_11_event_15th_event = count_events_after_11_event;
                LV_deference_15th_event = LV_deference;

                defeat_12nd_event_15th_event = defeat_12nd_event;
                kill_Strange_15th_event = kill_Strange;

            }

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(std::stoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(std::stoi(LV) + 2);

                if (fake_wong && std::stoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
            }
            if (dangerous_chemical)
            {
                count_events_after_11_event++;
            }
            HP = to_string(std::stoi(HP) + fibonacci(HP));
            if (std::stoi(HP) > std::stoi(maxHP))
            {
                HP = maxHP;
            }
            cout << "ket qua sau cac su kien thu : " << count_event << endl;;
            cout << HP << " " << LV << " " << EXP << " " << TS << endl;
            index += 3;
        }
        else if (events[index] == '1' && events[index + 1] == '1')
        {
            count_event++;

            if (std::stoi(find_HP_max) <= std::stoi(HP))
            {
                find_HP_max = HP;
                back_index = index;
                count_defeat_15th_event = count_defeat;
                invalid_coat_15th_event = invalid_coat;
                coat_flag_15th_event = coat_flag;

                real_wong_15th_event = real_wong;
                fake_wong_15th_event = fake_wong;
                is_first_meet_15th_event = is_first_meet;
                count_real_wong_help_15th_event = count_real_wong_help;
                count_fake_wong_fight_15th_event = count_fake_wong_fight;
                count_fake_wong_15th_event = count_fake_wong;
                
                dangerous_chemical_15th_event = dangerous_chemical;
                count_events_after_11_event_15th_event = count_events_after_11_event;
                LV_deference_15th_event = LV_deference;

                defeat_12nd_event_15th_event = defeat_12nd_event;
                kill_Strange_15th_event = kill_Strange;

            }

            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(std::stoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(std::stoi(LV) + 2);

                if (fake_wong && std::stoi(LV) > 7)
                {
                    fake_wong = false;
                    count_fake_wong--;
                }
            }
            if (dangerous_chemical)
            {
                count_events_after_11_event++;
            }
            int pre_TS = std::stoi(TS);
            
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
                HP = to_string(std::stoi(HP) - 50);
                dangerous_chemical = true;
                int HP_temp = std::stoi(HP, 0, 10);
                if (HP_temp <= 0)
                {
                    if (std::stoi(TS) == 0)
                    {
                        HP = to_string(0);
                        
                    }
                    else
                    {
                        TS = to_string(std::stoi(TS) - 1);
                        HP = maxHP;
                    }
                    
                }

                if (std::stoi(HP) == 0)
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

                    if (fake_wong && std::stoi(TS) == (pre_TS - 1))
                    {
                        fake_wong = false;
                        count_fake_wong--;
                        dangerous_chemical = false;
                    }
                    
                    if (std::stoi(LV) < 3 && dangerous_chemical)
                    {
                        LV_deference = std::stoi(LV) - 1;
                        LV = to_string(1);
                    }
                    else if (std::stoi(LV) >= 3 && dangerous_chemical)
                    {
                        LV = to_string(std::stoi(LV) - 2);
                    }
                    
                    
                }
                
                
            }
            
            else if (!dangerous_chemical)
            {
                HP = to_string(std::stoi(HP) - 50);
                dangerous_chemical = true;
                int HP_temp = std::stoi(HP, 0, 10);
                if (HP_temp <= 0)
                {
                    if (std::stoi(TS) == 0)
                    {
                        HP = to_string(0);
                        
                    }
                    else
                    {
                        TS = to_string(std::stoi(TS) - 1);
                        HP = maxHP;
                    }
                    
                }

                if (std::stoi(HP) == 0)
                {
                    return -1;
                }

                if (std::stoi(LV) < 3 && dangerous_chemical)
                    {
                        LV_deference = std::stoi(LV) - 1;
                        LV = to_string(1);
                    }
                    else if (std::stoi(LV) >= 3 && dangerous_chemical)
                    {
                        LV = to_string(std::stoi(LV) - 2);
                    }
            }
            
            else if (dangerous_chemical)
            {
                HP = to_string(std::stoi(HP) - 50);
                int HP_temp = std::stoi(HP, 0, 10);
                if (HP_temp <= 0)
                {
                    if (std::stoi(TS) == 0)
                    {
                        HP = to_string(0);
                        
                    }
                    else
                    {
                        TS = to_string(std::stoi(TS) - 1);
                        HP = maxHP;
                    }
                    
                }

                if (std::stoi(HP) == 0)
                {
                    return -1;
                }
            }

            cout << "ket qua sau cac su kien thu : " << count_event << endl;;
            cout << HP << " " << LV << " " << EXP << " " << TS << endl;
            index += 3;
        }
        else if (events[index] == '1' && events[index + 1] == '2')
        {
            count_event++;
            
            if (std::stoi(find_HP_max) <= std::stoi(HP))
            {
                find_HP_max = HP;
                back_index = index;
                count_defeat_15th_event = count_defeat;
                invalid_coat_15th_event = invalid_coat;
                coat_flag_15th_event = coat_flag;

                real_wong_15th_event = real_wong;
                fake_wong_15th_event = fake_wong;
                is_first_meet_15th_event = is_first_meet;
                count_real_wong_help_15th_event = count_real_wong_help;
                count_fake_wong_fight_15th_event = count_fake_wong_fight;
                count_fake_wong_15th_event = count_fake_wong;
                
                dangerous_chemical_15th_event = dangerous_chemical;
                count_events_after_11_event_15th_event = count_events_after_11_event;
                LV_deference_15th_event = LV_deference;

                defeat_12nd_event_15th_event = defeat_12nd_event;
                kill_Strange_15th_event = kill_Strange;

            }
            
            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(std::stoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(std::stoi(LV) + 2);

                if (fake_wong && std::stoi(LV) > 7)
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
                if (std::stoi(LV) < 3 && !invalid_coat)
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
            string s_result = "";
            int found;
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
               if (s2.length() > 2)
               {
                    defeat_12nd_event = true;
                    coat_flag = false;
                    TS_temp = TS;
                    TS = to_string(0);
                    kill_Strange = true;
                    int exp = 15;
                    set_win_information(HP, maxHP, LV, EXP, exp, TS, '0');
                    
               }
               else
               {
                    translate_string(s1, s2);
                    found = s1.find(s2, 0);
                    if (found == -1)
                    {
                        defeat_12nd_event = true;
                        coat_flag = false;
                        TS_temp = TS;
                        TS = to_string(0);
                        kill_Strange = true;
                        int exp = 15;
                        set_win_information(HP, maxHP, LV, EXP, exp, TS, '0');
                    }
                    else
                    {
                        defeat_12nd_event = false;
                        kill_Strange = false;
                        HP = to_string(int(std::stoi(HP) * 1.0f - std::stoi(HP) * 10 * 1.0f / 100));
                        maxHP = to_string(int(std::stoi(maxHP) * 1.0f - std::stoi(maxHP) * 10 * 1.0f / 100));
                        if (std::stoi(HP) <= 0)
                        {
                            if (std::stoi(TS) == 0)
                            {
                                return -1;
                            }
                            else
                            {
                                TS = to_string(std::stoi(TS) - 1);
                                HP = maxHP;
                            }
                            
                        }
                        int exp = 30;
                        set_win_information(HP, maxHP, LV, EXP, exp, TS, '0');
                    }
                    
               }
            }
            else  
            {
                G_point = int ((s1.length() * 1.0f) / 2);
                string s1_right = "";
                string s1_left = "";
                for (int i = s1.length() - 1; i > G_point; i--)
                {
                    s1_right += s1[i];
                }
                
                for (int i = G_point - 1; i >= 0 ; i--)
                {
                    s1_left += s1[i];
                }
                
                s_result = s1_left + s1[G_point] + s1_right;

                translate_string(s_result, s2);
                found = s_result.find(s2, 0);
                if (found == -1)
                {
                    defeat_12nd_event = true;
                    coat_flag = false;
                    TS_temp = TS;
                    TS = to_string(0);
                    kill_Strange = true;

                    int exp = 15;
                    set_win_information(HP, maxHP, LV, EXP, exp, TS, '0');
                }
                else
                {
                    defeat_12nd_event = false;
                    kill_Strange = false;
                    HP = to_string(int(std::stoi(HP) * 1.0f - std::stoi(HP) * 10 * 1.0f / 100));
                    maxHP = to_string(int(std::stoi(maxHP) * 1.0f - std::stoi(maxHP) * 10 * 1.0f / 100));

                    int exp = 30;
                    set_win_information(HP, maxHP, LV, EXP, exp, TS, '0');
                }
            }

            cout << "ket qua sau cac su kien thu : " << count_event << endl;;
            cout << HP << " " << LV << " " << EXP << " " << TS << endl;
        }
        else if (events[index] == '1' && events[index + 1] == '3')
        {
            count_event++;
            
            if (std::stoi(find_HP_max) <= std::stoi(HP))
            {
                find_HP_max = HP;
                back_index = index;
                count_defeat_15th_event = count_defeat;
                invalid_coat_15th_event = invalid_coat;
                coat_flag_15th_event = coat_flag;

                real_wong_15th_event = real_wong;
                fake_wong_15th_event = fake_wong;
                is_first_meet_15th_event = is_first_meet;
                count_real_wong_help_15th_event = count_real_wong_help;
                count_fake_wong_fight_15th_event = count_fake_wong_fight;
                count_fake_wong_15th_event = count_fake_wong;
                
                dangerous_chemical_15th_event = dangerous_chemical;
                count_events_after_11_event_15th_event = count_events_after_11_event;
                LV_deference_15th_event = LV_deference;

                defeat_12nd_event_15th_event = defeat_12nd_event;
                kill_Strange_15th_event = kill_Strange;

            }
            
            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(std::stoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(std::stoi(LV) + 2);

                if (fake_wong && std::stoi(LV) > 7)
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
                if (std::stoi(LV) < 3 && !invalid_coat)
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

            int m = (count_event % 7) > 2 ? (count_event % 7) : 2;
            int min_matrix = 0;
            int col = 1;
            int row = 1;
            bool defense_13rd_event = true;
            
            int **arr = new int *[7];
            for (int i = 0; i < 7; i++)
            {
                arr[i] = new int [7];
            }
            
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    string number = "";
                    while (events[index] != ' ' && events[index] != '#' && events[index] != '!')
                    {
                        number += events[index];
                        index++;
                    }

                    arr[i][j] = std::stoi(number);

                    index++;
                }
                
            }
            
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    min_matrix += arr[i][j];
                }
                
            }
            

            for (int i = 0; i < 7 - m; i++)
            {
                for (int j = 0; j < 7 - m; j++)
                {
                    int min_temp = 0;
                    for (int r = i; r < i + m; r++)
                    {
                        for (int k = j; k < j + m; k++)
                        {
                            min_temp += arr[r][k];
                        }
                        
                    }

                    if (min_temp < min_matrix)
                    {
                        min_matrix = min_temp;
                        col = j + 1;
                        row = i + 1;
                    }
                    
                    
                }
                
            }

            for (int j = col - 1; j < col - 1 + m; j++)
            {
                for (int i = row - 1; i < row - 2 + m; i++)
                {
                    if (arr[i][j] > arr[i + 1][j]) 
                    {
                        defense_13rd_event = false;
                        break;
                    }
                }
                
                if (!defense_13rd_event)
                {
                    break;
                }
                
            }

            if (defense_13rd_event)
            {
                HP = to_string(std::stoi(HP) + min_matrix * (col + row));
                if (std::stoi(HP) > std::stoi(maxHP))
                {
                    HP = maxHP;
                }
                
            }
            else
            {
                int HP_temp = std::stoi(HP) - min_matrix * (col + row);
                HP = to_string(std::stoi(HP) - min_matrix * (col + row));
                if (HP_temp <= 0)
                {
                    if (!kill_Strange)
                    {
                        HP = to_string(1);
                    }
                    
                    else if (std::stoi(TS) == 0)
                    {
                        return -1;
                    }
                    else if (std::stoi(TS) != 0)
                    {
                        TS = to_string(std::stoi(TS) - 1);
                        HP = maxHP;
                    }
                    
                }
                
            }
            cout << "ket qua sau cac su kien thu : " << count_event << endl;;
            cout << HP << " " << LV << " " << EXP << " " << TS << endl;
        }
        else if (events[index] == '1' && events[index + 1] == '4')
        {
            count_event++;
            
            if (std::stoi(find_HP_max) <= std::stoi(HP))
            {
                find_HP_max = HP;
                back_index = index;
                count_defeat_15th_event = count_defeat;
                invalid_coat_15th_event = invalid_coat;
                coat_flag_15th_event = coat_flag;

                real_wong_15th_event = real_wong;
                fake_wong_15th_event = fake_wong;
                is_first_meet_15th_event = is_first_meet;
                count_real_wong_help_15th_event = count_real_wong_help;
                count_fake_wong_fight_15th_event = count_fake_wong_fight;
                count_fake_wong_15th_event = count_fake_wong;
                
                dangerous_chemical_15th_event = dangerous_chemical;
                count_events_after_11_event_15th_event = count_events_after_11_event;
                LV_deference_15th_event = LV_deference;

                defeat_12nd_event_15th_event = defeat_12nd_event;
                kill_Strange_15th_event = kill_Strange;

            }
            
            if (count_events_after_11_event >= 3)
            {
                count_events_after_11_event = 0;
                dangerous_chemical = false;
                if (LV_deference == 1)
                {
                    LV = to_string(std::stoi(LV) + 1);
                    LV_deference = 0;
                }
                else LV = to_string(std::stoi(LV) + 2);

                if (fake_wong && std::stoi(LV) > 7)
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
                if (std::stoi(LV) < 3 && !invalid_coat)
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

            int true_gate = atoi(events[index]);
            index += 2;

            int index_temp = index;
            string gates_str = "";
            while (events[index] != '#' && events[index] != '!')
            {
                gates_str += events[index];
                index++;
            }
            
            index++;
            int number_of_gates = 0;
            int length = gates_str.length();
            for (int i = 0; i < length; i++)
            {
                if (gates_str[i] == ' ')
                {
                    number_of_gates ++;
                }
                
            }
            
            number_of_gates ++;

            int gates_array[1024];

            for (int i = 0; i < number_of_gates; i++)
            {
                string number = "";
                while (events[index_temp] != ' ' && events[index_temp] != '#' && events[index_temp] != '!')
                {
                    number += events[index_temp];
                    index_temp++;
                }

                gates_array[i] = std::stoi(number);

                index_temp++;
            }
            
            int step = log2(number_of_gates);
            // bool wanda_win = false;
            int wanda_step = BinarySearch(gates_array, number_of_gates, true_gate);

            if (wanda_step > step || wanda_step == -1)
            {
                // wanda_win = false;
                int exp = 150;
                set_win_information(HP, maxHP, LV, EXP, exp, TS, '0');
                coat_flag = true;
                if (count_defeat < 3) 
                {
                    invalid_coat = true;
                    LV = to_string(std::stoi(LV) + 2);
                    if (std::stoi(LV) > 10)
                    {
                        LV = to_string(10);
                    }
                }
                if (defeat_12nd_event)
                {
                    TS = TS_temp;
                }
                
                
            }
            else 
            {
                LV = to_string(1);
                HP = to_string(std::stoi(HP) - wanda_step * (count_event % 10) * 7);
                if (std::stoi(HP) <= 0)
                {
                    if (std::stoi(TS) == 0)
                    {
                        return - 1;
                    }
                    else
                    {
                        TS = to_string(std::stoi(TS) - 1);
                        HP = maxHP;
                    }
                    
                }
            }
    
            cout << "ket qua sau cac su kien thu : " << count_event << endl;;
            cout << HP << " " << LV << " " << EXP << " " << TS << endl;
        }
        else if (events[index] == '1' && events[index + 1] == '5')
        {
            if (std::stoi(TS) != 0)
            {
                if (!back)
                {
                    count_event++;
                    if (count_events_after_11_event >= 3)
                    {
                        count_events_after_11_event = 0;
                        dangerous_chemical = false;
                        if (LV_deference == 1)
                        {
                            LV = to_string(std::stoi(LV) + 1);
                            LV_deference = 0;
                        }
                        else LV = to_string(std::stoi(LV) + 2);

                        if (fake_wong && std::stoi(LV) > 7)
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
                        if (std::stoi(LV) < 3 && !invalid_coat)
                        {
                            LV = to_string(1);
                        }
                    }
                    
                    if (fake_wong)
                    {
                        fake_wong = false;
                        count_fake_wong--;
                    }

                    // if (std::stoi(find_HP_max) < std::stoi(HP))
                    // {
                    //     index_15th_event = index;
                    //     back_index = index;
                    // }

                    if (std::stoi(find_HP_max) <= std::stoi(HP))
                    {
                        // find_HP_max = HP;
                        // back_index = index;
                        back = true;
                    }
                    else
                    {
                        TS = to_string(std::stoi(TS) - 1);
                        LV = to_string(10);
                        EXP = to_string(100);

                        back = true;
                        index = back_index;

                        count_defeat = count_defeat_15th_event;
                        invalid_coat = invalid_coat_15th_event;
                        coat_flag = coat_flag_15th_event;

                        real_wong = real_wong_15th_event;
                        fake_wong = fake_wong_15th_event;
                        is_first_meet = is_first_meet_15th_event;
                        count_real_wong_help = count_real_wong_help_15th_event;
                        count_fake_wong_fight = count_fake_wong_fight_15th_event;
                        count_fake_wong = count_fake_wong_15th_event;
                        
                        dangerous_chemical = dangerous_chemical_15th_event;
                        count_events_after_11_event = count_events_after_11_event_15th_event;
                        LV_deference = LV_deference_15th_event;

                        defeat_12nd_event = defeat_12nd_event_15th_event;
                        kill_Strange = kill_Strange_15th_event;

                        continue;
                    }

                }
                
            }
            
            index += 3;

            

            cout << "ket qua sau cac su kien thu : " << count_event << endl;;
            cout << HP << " " << LV << " " << EXP << " " << TS << endl;
        }
        
        
    }
    
    
    result = std::stoi(HP) + std::stoi(LV) + std::stoi(EXP) + std::stoi(TS);
    cout << "ket qua cuoi cung: " << endl;
    cout << HP << " " << LV << " " << EXP << " " << TS << endl;


    return result;
}

///END OF STUDENT'S ANSWER

#endif /* studyInPink_h */
