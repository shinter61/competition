#include <iostream>

using namespace std;

class NumberList {
  private:
    struct ListNode
    {
      double value;
      struct ListNode *next;
    };

    ListNode *head;

  public:
    // コンストラクタ
    NumberList() {
      head = NULL;
    }
    // デストラクタ
    ~NumberList() {
      ListNode *nodePtr;
      ListNode *nextNode;

      nodePtr = head;

      while (nodePtr != NULL) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
      }
    };

    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayNode() const; // constを付けるとメンバを変更せず参照するだけの関数となる
};

void NumberList::appendNode(double num) {
  ListNode *newNode; 
  ListNode *nodePtr; // リストを移動するためのノード

  newNode = new ListNode;
  newNode->value = num;
  newNode->next = NULL;

  if (!head) {
    head = newNode; // リストにノードがなければnewNodeを最初のノードにセット
  } else {
    nodePtr = head; // nodePtrをリストの先頭で初期化
    while (nodePtr->next) { // リストの最後（nodePtr->nextがNULL）を見つける
      nodePtr = nodePtr->next;
    }
    nodePtr->next = newNode;
  }
}

void NumberList::insertNode(double num) {
  ListNode *newNode;
  ListNode *nodePtr;
  ListNode *previousNode;

  newNode = new ListNode;
  newNode->value = num;

  if (!head) {
    head = newNode;
  } else {
    nodePtr = head;
    while(nodePtr != NULL && nodePtr->value < num) {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if (previousNode == NULL) {
      head = newNode;
      newNode->next = nodePtr;
    } else {
      previousNode->next = newNode;
      newNode->next = nodePtr;
    }
  }
}

void NumberList::deleteNode(double num) {
  ListNode *nodePtr;
  ListNode *previousNode;

  if (!head) return;
  
  if (head->value == num) {
    nodePtr = head->next;
    delete head;
    head = nodePtr;
  } else {
    nodePtr = head;
    while (nodePtr != NULL && nodePtr->value != num) {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if (nodePtr) {
      previousNode->next = nodePtr->next;
      delete nodePtr;
    }
  }
}

void NumberList::displayNode() const {
  ListNode *nodePtr;
  if (!head) {
    cout << "Empty" << endl;
  } else {
    nodePtr = head;
    while (nodePtr->next) {
      cout << nodePtr->value << ", ";
      nodePtr = nodePtr->next;
    }
    cout << nodePtr->value << endl;
  }
}

int main(int argc, char *argv[]) {
  NumberList list;
  list.appendNode(2.5);
  list.appendNode(7.9);
  list.appendNode(12.6);
  list.displayNode();

  list.insertNode(6);
  list.insertNode(11);
  list.displayNode();

  list.deleteNode(9);
  list.displayNode();

  list.deleteNode(6);
  list.displayNode();

  return EXIT_SUCCESS;
}
