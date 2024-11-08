#include<bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int wt;
    int ct;
    int tat;
    int st;

};

bool compare1(process p1 , process p2)
{
    return p1.at < p2.at;
}

bool compare2(process p1 , process p2)
{
    return p1.pid < p2.pid;
}

int main()
{
    process p[100];
    int n;
    int tq;
    cout<<"Enter the number of process"<<endl;
    cin>>n;
    cout<<"Enter the time quantum"<<endl;
    cin>>tq;

    int total_wt;
    int total_tat;

    float avg_wt;
    float avg_tat;
    int burst_remaining[100];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the arrival time of process "<<i+1<<endl;
        cin>>p[i].at;
        cout<<"Enter the burst time of the process "<<i+1<<endl;
        cin>>p[i].bt;
        burst_remaining[i] = p[i].bt;
        p[i].pid = i+1;
    }

    sort(p,p+n,compare1);
    

    int mark[100];
    memset(mark , 0 , sizeof(mark));

    int idx = -1;
    int completed = 0;
    int current_time = 0;
    queue<int>q;

    q.push(0);

    mark[0]=1;

    while(completed != n)
    {
            idx = q.front();
            q.pop();

            if(burst_remaining[idx] == p[idx].bt)   // process got CPU for  1st time
            {
                p[idx].st = max(current_time , p[idx].at);
                current_time = p[idx].st;
            }

            if(burst_remaining[idx] - tq >0)   // burst time is greater than the tq
            {
                current_time += tq;
                burst_remaining[idx] -= tq;
            } 

            else
            {
                current_time += burst_remaining[idx];
                burst_remaining[idx] = 0;
                 
                 completed ++;

                 p[idx].ct = current_time;
                 p[idx].tat = p[idx].ct - p[idx].at;
                 p[idx].wt = p[idx].tat - p[idx].bt;

                 total_tat +=  p[idx].tat ;
                 total_wt  +=  p[idx].wt;

            }

            for(int i=1;i<n;i++)
            {
                if(burst_remaining[i] > 0 && p[i].at <= current_time && mark[i]==0)
                {
                    q.push(i);
                    mark[i] = 1;
                }
            }

            if(burst_remaining[idx] > 0)
            {
                q.push(idx);
                
            }

            if(q.empty())
            {
                for(int i=1;i<n;i++)
                {
                    if(burst_remaining[i] > 0 )
                    {
                        q.push(i);
                        mark[i] = 1;
                        break;
                    }
                }
            }
    }
    avg_tat = (float)total_tat/n;
    avg_wt = (float)total_wt/n;

    sort(p,p+n,compare2);

    cout<<endl;

    cout<<"PNO\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;
        
        for(int i=0;i<n;i++)
        {
             cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n"<<endl;
        }

            cout<<"Average waiting time"<<avg_wt<<endl;
            cout<<"Average Turn around time"<<avg_tat<<endl;



}