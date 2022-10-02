#include<iostream>
#include<string>
using namespace std;

struct Node{
    char data;
    struct Node * next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if(top==NULL){
        return 1;
    }
    return 0;
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct Node** top, char x){
    if(isFull(*top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = *top;
        *top = n;
    }
    // cout<<"Pushed : "<<x<<endl;
}
 
char pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        char x = n->data;
        free(n);
        // cout<<"Popped : "<<x<<endl;
        return x; 
    }
    return 0;
}

char Top(struct Node* top){
    if(isEmpty(top)){
        return '~';
    }
    return top->data;
}

int height(Node* top){
    Node* ptr = top;
    int count = 0;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

int precedenceCheck(char c){
    if(c=='/' || c=='*'){
        return 3;
    }
    else if(c=='-' || c=='+'){
        return 2;
    }
    return 0;
}

string InfixToPostfix(struct Node* top, string exp){
    string s = "";
    for(int i = 0 ; exp[i]!='\0' ; i++){
        if(exp[i]=='/' || exp[i]=='+' || exp[i]=='-' || exp[i]=='*'){
                if(precedenceCheck(Top(top))>=precedenceCheck(exp[i])){
                        s+=pop(&top);
                        if(precedenceCheck(Top(top))>=precedenceCheck(exp[i])){
                            s+=(pop(&top));
                            push(&top,exp[i]);
                        }                
                        else{
                            push(&top,exp[i]);
                        } 
                    }
                else{
                    push(&top,exp[i]);
                }
            }
        else{
            s+=exp[i];
            }
        }

        while(top!=NULL){
            s+=pop(&top);
    }
    return s;
}

int main()
{
    string s;
    struct Node* stk = NULL;

    cout<<("Enter the Expression in Infix : ");
    getline(cin,s);

    s = InfixToPostfix(stk,s);
    cout<<s<<endl;
    return 0;
}