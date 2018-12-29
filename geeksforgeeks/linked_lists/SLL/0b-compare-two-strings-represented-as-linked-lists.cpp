/*
 * Author : Jatin Rohilla
 * Date   : 1-07-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *

practice - https://practice.geeksforgeeks.org/problems/compare-two-linked-lists/1
link - https://www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists/

approach -
similar to 'check if two linked lists are identical'
just note some edge cases

Input -
2
5
a b a b a
4
a b a a
3
a a b
3
a a b

Output -
1
0

*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// Compare two strings represented as linked lists
/*Linked List Node Structure
struct Node
{
    char c;
    struct Node*next;
};
*/
int compare(struct Node* list1,struct Node* list2)
{
    while(list1 && list2){
        if(list1->c > list2->c){
            return 1;
        }
        else if(list2->c > list1->c){
            return -1;
        }
        else{
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    if(list1){
        return 1;
    }
    else if(list2){
        return -1;
    }
    else{
        return 0;
    }
}
