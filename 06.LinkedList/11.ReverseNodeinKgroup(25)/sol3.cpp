#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x): val(x), next(NULL) {}
};

Node* getKth(Node* curr, int k) {
    while (curr && k > 0) {
        curr = curr->next;
        k--;
    }
    return curr;
}

Node* reverseInK(Node* head, int k) {
    if (!head || k == 1) return head;

    Node dummy(0);
    dummy.next = head;

    Node* prevGroup = &dummy;

    while (true) {
        Node* kth = getKth(prevGroup, k);
        if (!kth) break;

        Node* nextGroup = kth->next;

        // reverse group
        Node* prev = nextGroup;
        Node* curr = prevGroup->next;

        while (curr != nextGroup) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        Node* temp = prevGroup->next;
        prevGroup->next = kth;
        prevGroup = temp;
    }

    return dummy.next;
}

Node* createLL(int n) {
    if (n == 0) return NULL;
    int x;
    cin >> x;

    Node* head = new Node(x);
    Node* curr = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        curr->next = new Node(x);
        curr = curr->next;
    }
    return head;
}

void printLL(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = createLL(n);

    int k;
    cin >> k;

    head = reverseInK(head, k);

    printLL(head);
    return 0;
}
