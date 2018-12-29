/*
 * Author : Jatin Rohilla
 * Date   : 26-06-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
question - https://www.geeksforgeeks.org/adding-two-polynomials-using-linked-list/
practice - https://practice.geeksforgeeks.org/problems/polynomial-addition/1

Input -
2
1
1 2
1
1 3
2
1 3 2 2
2
3 3 4 2

Expected output -
1x^3 + 1x^2
4x^3 + 6x^2

*/

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node{
    int coeff;
    int pow;
    struct Node* next;
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data, int new_data1){
    struct Node* new_node = new Node;
    new_node->coeff  = new_data;
    new_node->pow  = new_data1;
    new_node->next = NULL;
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


void printList(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff,temp->pow);
       temp  = temp->next;
    }
}

void addPolynomial(Node *p1, Node *p2);

void create_node(int x, int y, struct Node **temp){
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r =(struct Node*)malloc(sizeof(struct Node));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->coeff = x;
        r->pow = y;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}

/* Driver program to test above function*/
int main(){
    int t;
    cin>>t;
    while(t--){
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }

         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }

        //show(poly2);
        // printList(poly1);
        // cout<<endl;
        // printList(poly2);

        addPolynomial(poly1,poly2);

        cout<<endl;

    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of Node used
struct Node
{
    int coeff;  // coefficient of the polynomial
    int pow;   // power of the polynomial
    Node* next;
};
*/
/* The below method print the required sum of polynomial
p1 and p2 as specified in output  */
void addPolynomial(Node *p1, Node *p2)
{
    Node* resH = NULL;
    Node* resT = NULL;

    // add
    int p1pow, p2pow;
    while(p1 || p2){
        p1pow = p1 ? p1->pow : -1;
        p2pow = p2 ? p2->pow : -1;

        if(p1pow > p2pow){
            append(&resH, &resT, p1->coeff, p1->pow );
            p1 = p1 ? p1->next : NULL;
        }
        else if(p2pow > p1pow){
            append(&resH, &resT, p2->coeff, p2->pow );
            p2 = p2 ? p2->next : NULL;
        }
        else{
            if( p1pow == -1){
                break;
            }
            else{
                append(&resH, &resT, p1->coeff + p2->coeff, p1->pow );
                p1 = p1 ? p1->next : NULL;
                p2 = p2 ? p2->next : NULL;
            }
        }
    }

    // display
    while(resH->next){
        cout << resH->coeff << "x^" << resH->pow <<  " + " ;
        resH = resH->next;
    }
    cout << resH->coeff << "x^" << resH->pow ;
}

