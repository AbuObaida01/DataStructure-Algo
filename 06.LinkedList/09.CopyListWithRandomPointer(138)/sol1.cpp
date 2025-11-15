#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int x) : val(x), next(NULL), random(NULL) {}
};

// Function to deep copy linked list with random pointers
Node* deepCopy(Node* head) {
    if (!head) return NULL;

    unordered_map<Node*, Node*> mp;

    Node* temp = head;

    // STEP 1: Create copy of each node and store in map
    while (temp) {
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }

    // STEP 2: Assign next and random pointers to copied nodes
    temp = head;
    while (temp) {
        mp[temp]->next = mp[temp->next];         // copy next pointer
        mp[temp]->random = mp[temp->random];     // copy random pointer
        temp = temp->next;
    }

    return mp[head];
}

// Print the list (value + random)
void printList(Node* head) {
    while (head) {
        cout << "Val=" << head->val << ", Random=";
        if (head->random)
            cout << head->random->val;
        else
            cout << "NULL";
        cout << " | ";

        head = head->next;
    }
    cout << endl;
}

// Create input list with random pointers from user
Node* createRandomList() {
    int n;
    cin >> n;
    if (n == 0) return NULL;

    vector<Node*> nodes(n);

    // step 1: read values
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        nodes[i] = new Node(x);
    }

    // step 2: connect next pointers
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    // step 3: read random pointers (as index)
    for (int i = 0; i < n; i++) {
        int idx;
        cin >> idx; // -1 means NULL
        if (idx == -1) nodes[i]->random = NULL;
        else nodes[i]->random = nodes[idx];
    }

    return nodes[0];
}

int main() {

    // CREATE ORIGINAL LIST
    Node* head = createRandomList();

    cout << "Original List: " << endl;
    printList(head);

    // DEEP COPY
    Node* copied = deepCopy(head);

    cout << "Copied List: " << endl;
    printList(copied);

    return 0;
}
