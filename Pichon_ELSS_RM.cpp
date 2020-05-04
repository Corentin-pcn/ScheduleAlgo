#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

class Task{
public :
    int R0;
    int C;
    int D;
    int P;
    double Prio;

    Task(int, int, int, int);
    void RM_Prio();

};

Task::Task(int r0, int c, int d, int p)
{
    R0 = r0;
    C = c;
    D = d;
    P = p;
}

void Task::RM_Prio()
{
    Prio = 1.0/float(P);
}

int nb_task(){
    int n;
    cout<<"How many Task ? ";
    cin>>n;
    return(n);
}

void enter_task(Task *T[], int n){
    int i;
    int r0;
    int c;
    int d;
    int p;
    for(i=0; i < n ;i++){
        cout<<"Task "<<i<<endl;
        cout<<"R0 ?"<<endl;
        cin>>r0;
        cout<<"C ?"<<endl;
        cin>>c;
        cout<<"D ?"<<endl;
        cin>>d;
        cout<<"P ?"<<endl;
        cin>>p;
        T[i] = new Task(r0,c,d,p);
    }
}

bool A_test(Task *T[], int n){
    double sum = 0;
    double cond = n*(pow(2,1/n)-1);
    for(int i=0;i < n;i++){
        sum += T[i]->C/T[i]->P;
    }
    if (sum <= cond){
        return true;
    }
    else
        return false;
}

void calc_Prio(Task *T[], int n){
    for(int i=0;i < n;i++){
        T[i]->RM_Prio();
    }
}

main()
{
    int n = nb_task();
    Task *T[n];
    enter_task(T,n);
    bool a = A_test(T,n);
    if (a == true){
        calc_Prio(T,n);
    }
    Sort_Prio(T,n);
    for(int i=0;i < n;i++){
        cout<<(T[i]->Prio)<<endl;
    }
}
