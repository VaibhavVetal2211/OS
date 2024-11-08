// =====================================================ass 3=============================================
// #include<bits/stdc++.h>
// using namespace std;

// struct process
// {
//     int pid;
//     int at;
//     int bt;
//     int tat;
//     int st;
//     int ct;
//     int wt;

// };

// void SRTF()
// {
//     process p[100];

//     int n;

//     int burst_remaining[100];
//     int is_completed[100];
//     int total_tat = 0 ;
//     int total_wt = 0;

//     float avg_tat ;
//     float avg_wt;
    
//     vector<int>gantt_process;
//     vector<int>gantt_time;

//     memset(is_completed, 0 , sizeof(is_completed));   // setting all elements of is_completed to 0



//     cout<<"Enter the number of process"<<endl;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         cout<<"Enter arrival time of "<<i+1<<" process"<<endl;
//         cin>>p[i].at;

//         cout<<"Enter burst time of "<<i+1<<" process"<<endl;
//         cin>>p[i].bt;

//         p[i].pid = i+1;

//         burst_remaining[i] = p[i].bt;

//         cout<<endl;
//     }

//         int completed = 0;
//         int current_time = 0;

//         int prev = -1;
//         while(completed!=n)
//         {
//             int idx = -1;
//             int mn = 1e9;

//             for(int i=0;i<n;i++)
//             {
//                     if(p[i].at <= current_time && !is_completed[i])  
//                     {
                            
//                             if(burst_remaining[i] < mn )
//                             {
//                                 mn = burst_remaining[i];
//                                 idx = i;
//                             }
//                             if(burst_remaining[i] == mn )
//                             {
//                                 if(p[i].at < p[idx].at)
//                                 {
//                                     mn = burst_remaining[i];
//                                     idx = i;
//                                 }
//                             }
//                     }
//             }       

//              if(idx != -1)  // there is process imn the ready queue
//              {
//                  if(burst_remaining[idx] == p[idx].bt)  //process get CPU for 1st time
//                     {
//                         p[idx].st = current_time;

//                     }

//                     burst_remaining[idx] -- ;
//                     current_time ++ ;

//                     if(burst_remaining[idx] == 0)  // process is completed
//                     {
//                         p[idx].ct = current_time;
//                         p[idx].tat = p[idx].ct  - p[idx].at;
//                         p[idx].wt = p[idx].tat - p[idx].bt;


//                         gantt_process.push_back(p[idx].pid);
//                         gantt_time.push_back(p[idx].ct);
//                         is_completed[idx] = 1;
//                         completed ++ ;

//                         total_tat += p[idx].tat;
//                         total_wt  += p[idx].wt;
//                     }
                   
//              } 
            
//               else
//              {
//                 current_time ++;
//              }     
            
            
//         }

//         avg_tat = (float)total_tat / n;
//         avg_wt = (float)total_wt / n;

//         cout<<endl;

//         cout<<"PNO\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;
        
//         for(int i=0;i<n;i++)
//         {
//              cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n"<<endl;
//         }

//             cout<<"Average waiting time"<<avg_wt<<endl;
//             cout<<"Average Turn around time"<<avg_tat<<endl;
            
 


//         cout<<"GANTT CHART : "<<endl;

//         for(int i=0;i<n;i++)
//         {
            
//             cout<<"|P"<<gantt_process[i]<<"\t";
//         }
//         cout<<endl;
//         cout<<0<<"\t";
//         for(int i=0;i<n;i++)
//         {
//             cout<<gantt_time[i]<<"\t";
//         }
          

// }

// bool compare1(process p1 , process p2)
// {
//     return p1.at < p2.at;
// }

// bool compare2(process p1 , process p2)
// {
//     return p1.pid < p2.pid;
// }

// void RR()
// {
//         process p[100];
//     int n;
//     int tq;
//     cout<<"Enter the number of process"<<endl;
//     cin>>n;
//     cout<<"Enter the time quantum"<<endl;
//     cin>>tq;

//     int total_wt;
//     int total_tat;

//     float avg_wt;
//     float avg_tat;
//     int burst_remaining[100];
//     for(int i=0;i<n;i++)
//     {
//         cout<<"Enter the arrival time of process "<<i+1<<endl;
//         cin>>p[i].at;
//         cout<<"Enter the burst time of the process "<<i+1<<endl;
//         cin>>p[i].bt;
//         burst_remaining[i] = p[i].bt;
//         p[i].pid = i+1;
//     }

//     sort(p,p+n,compare1);
    

//     int mark[100];
//     memset(mark , 0 , sizeof(mark));

//     int idx = -1;
//     int completed = 0;
//     int current_time = 0;
//     queue<int>q;

//     q.push(0);

//     mark[0]=1;

//     while(completed != n)
//     {
//             idx = q.front();
//             q.pop();

//             if(burst_remaining[idx] == p[idx].bt)   // process got CPU for  1st time
//             {
//                 p[idx].st = max(current_time , p[idx].at);
//                 current_time = p[idx].st;
//             }

//             if(burst_remaining[idx] - tq >0)   // burst time is greater than the tq
//             {
//                 current_time += tq;
//                 burst_remaining[idx] -= tq;
//             } 

//             else
//             {
//                 current_time += burst_remaining[idx];
//                 burst_remaining[idx] = 0;
                 
//                  completed ++;

//                  p[idx].ct = current_time;
//                  p[idx].tat = p[idx].ct - p[idx].at;
//                  p[idx].wt = p[idx].tat - p[idx].bt;

//                  total_tat +=  p[idx].tat ;
//                  total_wt  +=  p[idx].wt;

//             }

//             for(int i=1;i<n;i++)
//             {
//                 if(burst_remaining[i] > 0 && p[i].at <= current_time && mark[i]==0)
//                 {
//                     q.push(i);
//                     mark[i] = 1;
//                 }
//             }

//             if(burst_remaining[idx] > 0)
//             {
//                 q.push(idx);
                
//             }

//             if(q.empty())
//             {
//                 for(int i=1;i<n;i++)
//                 {
//                     if(burst_remaining[i] > 0 )
//                     {
//                         q.push(i);
//                         mark[i] = 1;
//                         break;
//                     }
//                 }
//             }
//     }
//     avg_tat = (float)total_tat/n;
//     avg_wt = (float)total_wt/n;

//     cout<<endl;

//     cout<<"PNO\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;
        
//         for(int i=0;i<n;i++)
//         {
//              cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n"<<endl;
//         }

//             cout<<"Average waiting time"<<avg_wt<<endl;
//             cout<<"Average Turn around time"<<avg_tat<<endl;
// }
// int main()
// {
//     int choice;
//     while (true) {
//         cout << "1. SJF (Preemptive)" << endl;
//         cout << "2. Round Robin" << endl;
//         cout << "3. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice) {
//             case 1:
//                 SRTF();
//                 break;
//             case 2:
//                 RR();
//                 break;
//             case 3:
//                 exit(0);
//             default:
//                 cout << "Invalid choice. Please try again." << endl;
//         }
//     }
//     return 0;

// }   
// =====================================================4(producer consumer )===============================================
// #include<stdio.h>
// #include<stdlib.h>
// #include<pthread.h>
// #include<semaphore.h>

// #define maxItems 5
// #define buffersize 5

// int buffer[buffersize];
// int in = 0;
// int out = 0;
// pthread_mutex_t mutex ;
// sem_t empty;
// sem_t full;


// void *producer( void*pno)
// {
//     int item ;
//    for(int i=0;i<maxItems;i++)
//    {
//          item = rand();
//             sem_wait(&empty); //empty -1

//             pthread_mutex_lock(&mutex);

//             buffer[in] = item;
//             printf("Producer %d inserted item %d at %d\n" ,*((int*)pno),buffer[in],in );
//             in = (in+1) % buffersize ;

//             pthread_mutex_unlock(&mutex);

//             sem_post(&full);   // full+1


//    }
// }

// void *consumer(void*cno)
// {
//         for(int i=0;i<maxItems;i++)
//         {
//             sem_wait(&full);  //full-1
//             pthread_mutex_lock(&mutex);
//             int item = buffer[out];
            
//             printf("Consumer %d removes item %d from %d \n",*((int *)cno) , buffer[out] , out);  
//             out = (out + 1) % buffersize;

//             pthread_mutex_unlock(&mutex);

//             sem_post(&empty); //empty+1
//         }
// }

// int main()
// {
//     pthread_t pro[5] , con[5];
//     pthread_mutex_init(&mutex,NULL);

//     sem_init(&empty , 0 , buffersize);
//     sem_init(&full , 0 , 0);

//     int a[5] = {1,2,3,4,5};

//     for(int i=0;i<5;i++)
//     {
//         pthread_create(&pro[i],NULL,(void *)producer ,(void *) &a[i] );

//     }

//     for(int i=0 ; i<5;i++)
//     {
//         pthread_create(&con[i],NULL,(void *)consumer , (void * ) &a[i]);
//     }

//     for(int i=0;i<5;i++)
//     {
//         pthread_join(pro[i] , NULL);
//     }

//     for(int i=0;i<5;i++)
//     {
//         pthread_join(con[i] , NULL);
//     }

//     pthread_mutex_destroy(&mutex);
//     sem_destroy( &empty);
//     sem_destroy(& full);

//     return 0;


// }
// ============================================== 5 banker algorithm====================================================

// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to check if the system is in a safe state
// bool is_safe(int n, int m, vector<vector<int>>& alloc, vector<vector<int>>& need, vector<int>& avail) {
//     vector<int> work(avail);
//     vector<int> finish(n, 0);
//     vector<int> safe_seq(n);

//     int count = 0;

//     while (count < n) {
//         bool found = false;
//         for (int i = 0; i < n; i++) {
//             if (finish[i] == 0) {
//                 int j;
//                 for (j = 0; j < m; j++) {
//                     if (need[i][j] > work[j]) {
//                         break;
//                     }
//                 }
//                 if (j == m) {
//                     for (int k = 0; k < m; k++) {
//                         work[k] += alloc[i][k];  // give back all allocated resources
//                     }
//                     safe_seq[count++] = i;
//                     finish[i] = 1;
//                     found = true;
//                 }
//             }
//         }
//         if (!found) {
//             cout << "System is not in a safe state.\n";
//             return false;
//         }
//     }

//     cout << "System is in a safe state.\nSafe sequence: ";
//     for (int i = 0; i < n; i++) {
//         cout << "P" << safe_seq[i] << " ";
//     }
//     cout << endl;

//     return true;
// }

// // Function to handle resource request
// bool resource_request(int n, int m, vector<vector<int>>& alloc, vector<vector<int>>& max, 
//                       vector<vector<int>>& need, vector<int>& avail, int process_id, vector<int>& req) {
//     for (int i = 0; i < m; i++) {
//         if (req[i] > need[process_id][i]) {
//             cout << "Error: Process " << process_id << " has exceeded its maximum claim.\n";
//             return false;
//         }
//         if (req[i] > avail[i]) {
//             cout << "Process " << process_id << " must wait since resources are not available.\n";
//             return false;
//         }
//     }

//     // Temporarily allocate resources to the process
//     for (int i = 0; i < m; i++) {
//         avail[i] -= req[i];
//         alloc[process_id][i] += req[i];
//         need[process_id][i] -= req[i];
//     }

//     // Check if the system is still in a safe state
//     if (is_safe(n, m, alloc, need, avail)) {
//         cout << "Resources allocated to Process " << process_id << " successfully.\n";
//         return true;
//     } else {
//         // If the system is not safe, revert the allocation
//         cout << "Request cannot be granted. Reverting changes.\n";
//         for (int i = 0; i < m; i++) {
//             avail[i] += req[i];
//             alloc[process_id][i] -= req[i];
//             need[process_id][i] += req[i];
//         }
//         return false;
//     }
// }

// int main() {
//     int n, m;
//     cout << "Enter the number of processes: ";
//     cin >> n;
//     cout << "Enter the number of resources: ";
//     cin >> m;

//     vector<vector<int>> alloc(n, vector<int>(m));
//     vector<vector<int>> max(n, vector<int>(m));
//     vector<int> avail(m);
//     vector<vector<int>> need(n, vector<int>(m));

//     // Input allocation matrix
//     cout << "Enter the allocation matrix:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "Process " << i << ":\n";
//         for (int j = 0; j < m; j++) {
//             cin >> alloc[i][j];
//         }
//     }

//     // Input max matrix
//     cout << "Enter the max need matrix:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "Process " << i << ":\n";
//         for (int j = 0; j < m; j++) {
//             cin >> max[i][j];
//             need[i][j] = max[i][j] - alloc[i][j]; // Calculate need matrix
//         }
//     }

//     // Input available resources
//     cout << "Enter the available resources:\n";
//     for (int i = 0; i < m; i++) {
//         cin >> avail[i];
//     }

//     // Check if the system is initially in a safe state
//     is_safe(n, m, alloc, need, avail);

//     // Handle resource request
//     int process_id;
//     vector<int> req(m);
//     cout << "Enter process ID making the request: ";
//     cin >> process_id;
//     cout << "Enter the requested resources for process " << process_id << ":\n";
//     for (int i = 0; i < m; i++) {
//         cin >> req[i];
//     }
//     resource_request(n, m, alloc, max, need, avail, process_id, req);

//     return 0;
// }


// =======================ass 6 FIFO ================================================================

// // C++ implementation of FIFO page replacement 
// // in Operating Systems. 
// #include<bits/stdc++.h> 
// using namespace std; 

// // Function to find page faults using FIFO 
// int pageFaults(int pages[], int n, int capacity) 
// { 
// 	// To represent set of current pages. We use 
// 	// an unordered_set so that we quickly check 
// 	// if a page is present in set or not 
// 	unordered_set<int> s; 

// 	// To store the pages in FIFO manner 
// 	queue<int> indexes; 

// 	// Start from initial page 
// 	int page_faults = 0; 
// 	for (int i=0; i<n; i++) 
// 	{ 
// 		// Check if the set can hold more pages 
// 		if (s.size() < capacity) 
// 		{ 
// 			// Insert it into set if not present 
// 			// already which represents page fault 
// 			if (s.find(pages[i])==s.end())    // page fault is there
// 			{ 
// 				// Insert the current page into the set 
// 				s.insert(pages[i]); 

// 				// increment page fault 
// 				page_faults++; 

// 				// Push the current page into the queue 
// 				indexes.push(pages[i]); 
// 			} 
// 		} 

// 		// If the set is full then need to perform FIFO 
// 		// i.e. remove the first page of the queue from 
// 		// set and queue both and insert the current page 
// 		else
// 		{ 
// 			// Check if current page is not already 
// 			// present in the set 
// 			if (s.find(pages[i]) == s.end())   // page not found
// 			{ 
// 				// Store the first page in the 
// 				// queue to be used to find and 
// 				// erase the page from the set 
// 				int val = indexes.front(); 
				
// 				// Pop the first page from the queue 
// 				indexes.pop(); 

// 				// Remove the indexes page from the set 
// 				s.erase(val); 

// 				// insert the current page in the set 
// 				s.insert(pages[i]); 

// 				// push the current page into 
// 				// the queue 
// 				indexes.push(pages[i]); 

// 				// Increment page faults 
// 				page_faults++; 
// 			} 
// 		} 
// 	} 

// 	return page_faults; 
// } 

// // Driver code 
// int main() 
// { 
//     int n;
//     cout<<"Enter number of pages"<<endl;
//     cin>>n;
// 	int pages[n] ;
//     cout<<"Enter the page"<<endl;
// 	for(int i=0;i<n;i++)
//     {
//         cin>>pages[i];
//     }
// 	int capacity;
//     cout<<"Enter the capacity"<<endl;
//     cin>>capacity;
// 	cout << "Number of page Faults: "<<pageFaults(pages, n, capacity); 
// 	return 0; 
// } 
// ===================================== 6 LRU ======================================

// //C++ implementation of above algorithm 
// #include<bits/stdc++.h> 
// using namespace std; 

// // Function to find page faults using indexes 
// int pageFaults(int pages[], int n, int capacity) 
// { 
// 	// To represent set of current pages. We use 
// 	// an unordered_set so that we quickly check 
// 	// if a page is present in set or not 
// 	unordered_set<int> s; 

// 	// To store least recently used indexes 
// 	// of pages. 
// 	unordered_map<int, int> indexes; 

// 	// Start from initial page 
// 	int page_faults = 0; 
// 	for (int i=0; i<n; i++) 
// 	{ 
// 		// Check if the set can hold more pages 
// 		if (s.size() < capacity) 
// 		{ 
// 			// Insert it into set if not present 
// 			// already which represents page fault 
// 			if (s.find(pages[i])==s.end()) 
// 			{ 
// 				s.insert(pages[i]); 

// 				// increment page fault 
// 				page_faults++; 
// 			} 

// 			// Store the recently used index of 
// 			// each page 
// 			indexes[pages[i]] = i; 
// 		} 

// 		// If the set is full then need to perform lru 
// 		// i.e. remove the least recently used page 
// 		// and insert the current page 
// 		else
// 		{ 
// 			// Check if current page is not already 
// 			// present in the set 
// 			if (s.find(pages[i]) == s.end()) 
// 			{ 
// 				// Find the least recently used pages 
// 				// that is present in the set 
// 				int lru = INT_MAX, val; 
// 				for (auto it=s.begin(); it!=s.end(); it++) 
// 				{ 
// 					if (indexes[*it] < lru) 
// 					{ 
// 						lru = indexes[*it]; 
// 						val = *it; 
// 					} 
// 				} 

// 				// Remove the indexes page 
// 				s.erase(val); 

// 				// insert the current page 
// 				s.insert(pages[i]); 

// 				// Increment page faults 
// 				page_faults++; 
// 			} 

// 			// Update the current page index 
// 			indexes[pages[i]] = i; 
// 		} 
// 	} 

// 	return page_faults; 
// } 

// // Driver code 
// int main() 
// { 
// 	 int n;
//     cout<<"Enter number of pages"<<endl;
//     cin>>n;
// 	int pages[n] ;
//     cout<<"Enter the page"<<endl;
// 	for(int i=0;i<n;i++)
//     {
//         cin>>pages[i];
//     }
// 	int capacity;
//     cout<<"Enter the capacity"<<endl;
//     cin>>capacity;
// 	cout << "Number of page Faults: "<<pageFaults(pages, n, capacity); 
// 	return 0; 
// } 

// =================================== 6 optimal ================================

// // CPP program to demonstrate optimal page
// // replacement algorithm.
// #include <bits/stdc++.h>
// using namespace std;

// // Function to check whether a page exists
// // in a frame or not
// bool search(int key, vector<int>& fr)
// {
// 	for (int i = 0; i < fr.size(); i++)
// 		if (fr[i] == key)
// 			return true;
// 	return false;
// }

// // Function to find the frame that will not be used
// // recently in future after given index in pg[0..pn-1]
// int predict(int pg[], vector<int>& fr, int pn, int index)
// {
// 	// Store the index of pages which are going
// 	// to be used recently in future
// 	int res = -1, farthest = index;
// 	for (int i = 0; i < fr.size(); i++) {
// 		int j;
// 		for (j = index; j < pn; j++) {
// 			if (fr[i] == pg[j]) {
// 				if (j > farthest) {
// 					farthest = j;
// 					res = i;
// 				}
// 				break;
// 			}
// 		}

// 		// If a page is never referenced in future,
// 		// return it.
// 		if (j == pn)
// 			return i;
// 	}

// 	// If all of the frames were not in future,
// 	// return any of them, we return 0. Otherwise
// 	// we return res.
// 	return (res == -1) ? 0 : res;
// }

// void optimalPage(int pg[], int pn, int fn)
// {
// 	// Create an array for given number of
// 	// frames and initialize it as empty.
// 	vector<int> fr;

// 	// Traverse through page reference array
// 	// and check for miss and hit.
// 	int hit = 0;
// 	for (int i = 0; i < pn; i++) {

// 		// Page found in a frame : HIT
// 		if (search(pg[i], fr)) {
// 			hit++;
// 			continue;
// 		}

// 		// Page not found in a frame : MISS

// 		// If there is space available in frames.
// 		if (fr.size() < fn)
// 			fr.push_back(pg[i]);

// 		// Find the page to be replaced.
// 		else {
// 			int j = predict(pg, fr, pn, i + 1);
// 			fr[j] = pg[i];
// 		}
// 	}
// 	cout << "No. of hits = " << hit << endl;
// 	cout << "No. of misses = " << pn - hit << endl;
// }

// // Driver Function
// int main()
// {
// 	 int n;
//     cout<<"Enter number of pages"<<endl;
//     cin>>n;
// 	int pages[n] ;
//     cout<<"Enter the page"<<endl;
// 	for(int i=0;i<n;i++)
//     {
//         cin>>pages[i];
//     }
// 	int capacity;
//     cout<<"Enter the capacity"<<endl;
//     cin>>capacity;
// 	optimalPage(pages, n, capacity); 
// 	return 0; 
// }

// ============================7a  pipe (FIFO message passing) =================================

// // fifo1.c

// #include <stdio.h>
// #include <fcntl.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <sys/types.h>

// int main() 
// {
//     int fd1, fd2;
//     char myfifo1[] = "file1";
//     char str1[100], str2[100];
//     char myfifo2[] = "file2";

//     mkfifo(myfifo1, 0666);
//     mkfifo(myfifo2, 0666);

//     printf("\n enter string : ");
//     fgets(str1, 100, stdin);

//     // Write to first fifo pipe
//     fd1 = open(myfifo1, O_WRONLY);
//     write(fd1, str1, strlen(str1) + 1);
//     close(fd1);

//     // Read from second fifo pipe
//     fd2 = open(myfifo2, O_RDONLY);
//     read(fd2, str2, 100);
//     printf("message from fifo2 :\n %s", str2);
//     close(fd2);

//     return 0;
// }


// // fifo2.c

// #include <stdio.h>
// #include <fcntl.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <sys/types.h>

// int main()
// {
//     int fd1, fd2;
//     char myfifo1[] = "file1";
//     char myfifo2[] = "file2";
//     char str1[100] , str2[100] ;
//     int l = 0, w = 1, c = 0;
//     int i=0;
//     char ch;
//     // Read from myfifo1
//     fd1 = open(myfifo1, O_RDONLY);
    

//     read(fd1, str1, sizeof(str1));
//     printf("\n pipe1: %s", str1);
//     close(fd1); // Close after reading

//     while(str1[i]!='\0')
//     {
//         if(str1[i]=='.'|| str1[i]=='\n')
//         {
//             l++;
//         }
//         else if(str1[i]==' ')
//         {
//             w++;
//         }
//         else
//         {
//             c++;
//         }
//         i++;
//     }


//     printf("\nno of lines = %d", l);
//     printf("\nno of words = %d", w);
//     printf("\nno of characters = %d", c);

//     FILE *fp = fopen("kp.txt", "w");
    
//     fprintf(fp, "\nno of lines = %d", l);
//     fprintf(fp, "\nno of words = %d", w);
//     fprintf(fp, "\nno of characters = %d", c);
//     fclose(fp);

//     // Read from the file
//     fp=fopen("kp.txt","r");
//     ch=fgetc(fp);
//     i=0;
//     while(ch!=EOF)
//     {
//         str2[i]=ch;
//         i++;
//         ch=fgetc(fp);
//     }
//     str2[i]='\0';

//     fclose(fp);

//     // Write to second fifo pipe
//     fd2 = open(myfifo2, O_WRONLY);
   
//     write(fd2, str2, strlen(str2) + 1);
//     close(fd2);
    
//     return 0;
// }


// ============================ 7b client server (shared memory)=================================


// //server.c

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <unistd.h>

// #define SHM_SIZE 1024  // Size of shared memory segment

// int main() {
//     int shmid;
//     key_t key = ftok("shmfile", 65); // Generate a unique key
//     char *str;

//     shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
//     if (shmid == -1) {
//         perror("shmget failed");
//         exit(1);
//     }

//     str = (char*) shmat(shmid, NULL, 0);
//     if (str == (char*)(-1)) {
//         perror("shmat failed");
//         exit(1);
//     }

//     // Write a message to the shared memory
//     sprintf(str, "Hello from Server!");
//     printf("Server: Message written to shared memory: %s\n", str);

//     // Detach from the shared memory segment
//     shmdt(str);
//     return 0;
// }



// //client.c

// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <unistd.h>

// #define SHM_SIZE 1024  // Size of shared memory segment

// int main() {
//     int shmid;
//     key_t key = ftok("shmfile", 65); // Generate the same key as server
//     char *str;

//     // Get shared memory segment
//     shmid = shmget(key, SHM_SIZE, 0666);
//     if (shmid == -1) {
//         perror("shmget failed");
//         exit(1);
//     }

//     // Attach to the shared memory segment
//     str = (char*) shmat(shmid, NULL, 0);
//     if (str == (char*)(-1)) {
//         perror("shmat failed");
//         exit(1);
//     }

//     // Read the message from shared memory
//     printf("Client: Read from shared memory: %s\n", str);

//     // Detach from the shared memory segment
//     shmdt(str);

//     // Optionally, you can remove the shared memory segment
//     shmctl(shmid, IPC_RMID, NULL);

//     return 0;
// }




