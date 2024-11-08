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
int main()
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
