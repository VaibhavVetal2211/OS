#include<bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int tat;
    int st;
    int ct;
    int wt;

};

void SRTF()
{
    process p[100];

    int n;

    int burst_remaining[100];
    int is_completed[100];
    int total_tat = 0 ;
    int total_wt = 0;

    float avg_tat ;
    float avg_wt;
    
    vector<int>gantt_process;
    vector<int>gantt_time;

    memset(is_completed, 0 , sizeof(is_completed));   // setting all elements of is_completed to 0



    cout<<"Enter the number of process"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter arrival time of "<<i+1<<" process"<<endl;
        cin>>p[i].at;

        cout<<"Enter burst time of "<<i+1<<" process"<<endl;
        cin>>p[i].bt;

        p[i].pid = i+1;

        burst_remaining[i] = p[i].bt;

        cout<<endl;
    }

        int completed = 0;
        int current_time = 0;

        int prev = -1;
        while(completed!=n)
        {
            int idx = -1;
            int mn = 1e9;

            for(int i=0;i<n;i++)
            {
                    if(p[i].at <= current_time && !is_completed[i])  
                    {
                            
                            if(burst_remaining[i] < mn )
                            {
                                mn = burst_remaining[i];
                                idx = i;
                            }
                            if(burst_remaining[i] == mn )
                            {
                                if(p[i].at < p[idx].at)
                                {
                                    mn = burst_remaining[i];
                                    idx = i;
                                }
                            }
                    }
            }       

             if(idx != -1)  // there is process imn the ready queue
             {
                 if(burst_remaining[idx] == p[idx].bt)  //process get CPU for 1st time
                    {
                        p[idx].st = current_time;

                    }

                    burst_remaining[idx] -- ;
                    current_time ++ ;

                    if(burst_remaining[idx] == 0)  // process is completed
                    {
                        p[idx].ct = current_time;
                        p[idx].tat = p[idx].ct  - p[idx].at;
                        p[idx].wt = p[idx].tat - p[idx].bt;


                        gantt_process.push_back(p[idx].pid);
                        gantt_time.push_back(p[idx].ct);
                        is_completed[idx] = 1;
                        completed ++ ;

                        total_tat += p[idx].tat;
                        total_wt  += p[idx].wt;
                    }
                   
             } 
            
              else
             {
                current_time ++;
             }     
            
            
        }

        avg_tat = (float)total_tat / n;
        avg_wt = (float)total_wt / n;

        cout<<endl;

        cout<<"PNO\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;
        
        for(int i=0;i<n;i++)
        {
             cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n"<<endl;
        }

            cout<<"Average waiting time"<<avg_wt<<endl;
            cout<<"Average Turn around time"<<avg_tat<<endl;
            
 


        cout<<"GANTT CHART : "<<endl;

        for(int i=0;i<n;i++)
        {
            
            cout<<"|P"<<gantt_process[i]<<"\t";
        }
        cout<<endl;
        cout<<0<<"\t";
        for(int i=0;i<n;i++)
        {
            cout<<gantt_time[i]<<"\t";
        }
          

}

bool compare1(process p1 , process p2)
{
    return p1.at < p2.at;
}

bool compare2(process p1 , process p2)
{
    return p1.pid < p2.pid;
}

void RR()
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

    cout<<endl;

    cout<<"PNO\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;
        
        for(int i=0;i<n;i++)
        {
             cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n"<<endl;
        }

            cout<<"Average waiting time"<<avg_wt<<endl;
            cout<<"Average Turn around time"<<avg_tat<<endl;
}
int main()
{
    int choice;
    while (true) {
        cout << "1. SJF (Preemptive)" << endl;
        cout << "2. Round Robin" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                SRTF();
                break;
            case 2:
                RR();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;

}   
