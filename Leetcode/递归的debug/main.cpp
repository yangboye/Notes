#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() :val(0), next(nullptr) {}
  ListNode(int _val) :val(_val), next(nullptr) {}
};

void CreateList(ListNode** head, const vector<int>& vec) {
  *head = new ListNode();
  ListNode* p = *head;
  for (auto& v : vec) {
    ListNode* temp = new ListNode(v);
    p->next = temp;
    p = p->next;
  }
  *head = (*head)->next;
}

void Print(ListNode* head) {
  ListNode* p = head;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
}

ListNode* ReverseList(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode* new_list = ReverseList(head->next);
  ListNode* t1 = head->next;
  t1->next = head;
  head->next = nullptr;
  return new_list;
}

int main() {
  ListNode* head;
  vector<int> vec = { 1,2,3,4 };
  CreateList(&head, vec);
  Print(head);
  cout << endl;
  ListNode* new_head = ReverseList(head);
  Print(new_head);
  cout << endl;
}