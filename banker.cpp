#include <iostream>
#include <vector>
using namespace std;

// Function to check if the system is in a safe state
bool is_safe(int n, int m, vector<vector<int>>& alloc, vector<vector<int>>& need, vector<int>& avail) {
    vector<int> work(avail);
    vector<int> finish(n, 0);
    vector<int> safe_seq(n);

    int count = 0;

    while (count < n) {
        bool found = false;
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
                        work[k] += alloc[i][k];  // give back all allocated resources
                    }
                    safe_seq[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "System is not in a safe state.\n";
            return false;
        }
    }

    cout << "System is in a safe state.\nSafe sequence: ";
    for (int i = 0; i < n; i++) {
        cout << "P" << safe_seq[i] << " ";
    }
    cout << endl;

    return true;
}

// Function to handle resource request
bool resource_request(int n, int m, vector<vector<int>>& alloc, vector<vector<int>>& max, 
                      vector<vector<int>>& need, vector<int>& avail, int process_id, vector<int>& req) {
    for (int i = 0; i < m; i++) {
        if (req[i] > need[process_id][i]) {
            cout << "Error: Process " << process_id << " has exceeded its maximum claim.\n";
            return false;
        }
        if (req[i] > avail[i]) {
            cout << "Process " << process_id << " must wait since resources are not available.\n";
            return false;
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
        cout << "Resources allocated to Process " << process_id << " successfully.\n";
        return true;
    } else {
        // If the system is not safe, revert the allocation
        cout << "Request cannot be granted. Reverting changes.\n";
        for (int i = 0; i < m; i++) {
            avail[i] += req[i];
            alloc[process_id][i] -= req[i];
            need[process_id][i] += req[i];
        }
        return false;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<int> avail(m);
    vector<vector<int>> need(n, vector<int>(m));

    // Input allocation matrix
    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i << ":\n";
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    // Input max matrix
    cout << "Enter the max need matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i << ":\n";
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
            need[i][j] = max[i][j] - alloc[i][j]; // Calculate need matrix
        }
    }

    // Input available resources
    cout << "Enter the available resources:\n";
    for (int i = 0; i < m; i++) {
        cin >> avail[i];
    }

    // Check if the system is initially in a safe state
    is_safe(n, m, alloc, need, avail);

    // Handle resource request
    int process_id;
    vector<int> req(m);
    cout << "Enter process ID making the request: ";
    cin >> process_id;
    cout << "Enter the requested resources for process " << process_id << ":\n";
    for (int i = 0; i < m; i++) {
        cin >> req[i];
    }
    resource_request(n, m, alloc, max, need, avail, process_id, req);

    return 0;
}
