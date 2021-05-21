#include <bits/stdc++.h>
using namespace std;
class sem1
{
public:
    int subj1 = 10;
    int subj2 = 20;
    int subj3 = 30;
    int retrun_sum_1()
    {
        return subj1 + subj2 + subj3;
    }
    float get_average(){
        return (subj1 + subj2 + subj3)/3;
    }
};
class sem2 : public sem1
{
public:
    int subj1 = 20;
    int subj2 = 30;
    int subj3 = 40;
    int retrun_sum_2()
    {
        return sem1::retrun_sum_1() + subj1 + subj2 + subj3;
    }
    float get_average()
    {
        return (subj1 + subj2 + subj3) / 3;
    }
    float get_sem1_avg(){
        return sem1::get_average();
    }
};
class sem3 : public sem2
{
public:
    int subj1 = 30;
    int subj2 = 40;
    int subj3 = 50;
    float getaverage_all()
    {
        return (sem2::retrun_sum_2()+subj1+subj2+subj3)/9;
    }
    float get_average()
    {
        return (subj1 + subj2 + subj3) / 3;
    }
    string get_max(){
        float sem_1=sem2::get_sem1_avg();
        float sem_2=sem2::get_average();
        float sem_3=get_average();
        float ss=max(sem_1,max(sem_2,sem_3));
        if(ss==sem_1){
            return "sem 1 has highest average";
        }
        if (ss == sem_2)
        {
            return "sem 2 has highest average";
        }
        return "sem 3 has highest average";
    }
};

int main()
{
    sem3 s;
    cout << s.getaverage_all()<<endl;
    cout<<s.get_max()<<endl;
    return 0;
}