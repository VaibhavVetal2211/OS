#include <stdio.h>
// Function to check if the system is in a safe state
int is_safe(int n, int m, int alloc[][m], int need[][m], int avail[]) {
int work[m], finish[n], safe_seq[n];
for (int i = 0; i < m; i++) {
work[i] = avail[i];
}
for (int i = 0; i < n; i++) {
finish[i] = 0;
}
int count = 0;
while (count < n) {
int found = 0;
for (int i = 0; i < n; i++) {
if (finish[i] == 0) {
int j;
for (j = 0; j < m; j++) {
if (need[i][j] > work[j]) {
break;
}
}
if (j == m) {
for (int k = 0; k < m; k++) {
work[k] += alloc[i][k];
}
safe_seq[count++] = i;
finish[i] = 1;
found = 1;
}
}
}
if (found == 0) {
printf("System is not in a safe state.\n");
return 0;
}
}
printf("System is in a safe state.\nSafe sequence: ");
for (int i = 0; i < n; i++) {
printf("P%d ", safe_seq[i]);
}
printf("\n");

return 1;
}
// Function to handle resource request
int resource_request(int n, int m, int alloc[][m], int max[][m], int need[][m], int avail[], int
process_id, int req[]) {
for (int i = 0; i < m; i++) {
if (req[i] > need[process_id][i]) {
printf("Error: Process %d has exceeded its maximum claim.\n", process_id);
return 0;
}
if (req[i] > avail[i]) {
printf("Process %d must wait since resources are not available.\n", process_id);
return 0;
}
}
// Temporarily allocate resources to the process
for (int i = 0; i < m; i++) {
avail[i] -= req[i];
alloc[process_id][i] += req[i];
need[process_id][i] -= req[i];
}
// Check if the system is still in a safe state
if (is_safe(n, m, alloc, need, avail)) {
printf("Resources allocated to Process %d successfully.\n", process_id);
return 1;
} else {
// If the system is not safe, revert the allocation
printf("Request cannot be granted. Reverting changes.\n");
for (int i = 0; i < m; i++) {
avail[i] += req[i];                                     
alloc[process_id][i] -= req[i];
need[process_id][i] += req[i];
}
return 0;
}
}
int main() {
int n, m;
printf("Enter the number of processes: ");
scanf("%d", &n);
printf("Enter the number of resources: ");
scanf("%d", &m);
int alloc[n][m], max[n][m], avail[m], need[n][m];
// Input allocation matrix
printf("Enter the allocation matrix:\n");
for (int i = 0; i < n; i++) {

printf("Process %d:\n", i);
for (int j = 0; j < m; j++) {
scanf("%d", &alloc[i][j]);
}
}
// Input max matrix
printf("Enter the max need matrix:\n");
for (int i = 0; i < n; i++) {
printf("Process %d:\n", i);
for (int j = 0; j < m; j++) {
scanf("%d", &max[i][j]);
need[i][j] = max[i][j] - alloc[i][j]; // Calculate need matrix
}
}
// Input available resources
printf("Enter the available resources:\n");
for (int i = 0; i < m; i++) {
scanf("%d", &avail[i]);
}
// Check if the system is initially in a safe state
is_safe(n, m, alloc, need, avail);
// Handle resource request
int process_id, req[m];
printf("Enter process ID making the request: ");
scanf("%d", &process_id);
printf("Enter the requested resources for process %d:\n", process_id);
for (int i = 0; i < m; i++) {
scanf("%d", &req[i]);
}
resource_request(n, m, alloc, max, need, avail, process_id, req);
return 0;
}



