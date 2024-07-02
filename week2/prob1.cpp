#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *myList = new ListNode(0);
    ListNode *currentMyList = myList;
    int toCarry = 0;

    while (l1 != nullptr || l2 != nullptr)
    {
        int val1;
        int val2;
        if (l1 != nullptr)
        {
            val1 = l1->val;
        }
        else
        {
            val1 = 0;
        }
        if (l2 != nullptr)
        {
            val2 = l2->val;
        }
        else
        {
            val2 = 0;
        }

        int sum = val1 + val2 + toCarry; // calculates the sum with the carry from the previous node

        toCarry = sum / 10; // finds the value to carry over
        sum = sum % 10;     // makes sure the sum value accounts for a carry

        currentMyList->next = new ListNode(sum);
        currentMyList = currentMyList->next;

        if (l1 != nullptr)
        {
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            l2 = l2->next;
        }
    }

    if (toCarry > 0)
    {
        currentMyList->next = new ListNode(toCarry); // create next node if carry exists after we get out of the while loop
    }

//take care of leading head?
    ListNode *newList = myList->next;
    delete myList; 

    return newList;
}

int main(int argc, char const *argv[])
{
    // Manually creating linked list l1 with values [2, 4, 3]
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Manually creating linked list l2 with values [5, 6, 4]
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *current = addTwoNumbers(l1, l2);
    while (current != nullptr)
    {
        std::cout << "Current value: " << current->val << std::endl;
        current = current->next;
    }
    return 0;
}
