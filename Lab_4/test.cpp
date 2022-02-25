#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int          data;
    struct Node *next;
} Node;
Node* headNode = NULL;
Node* createNode(int value)
{
    Node*   newNode = NULL;
    //  Create new node
    newNode = (Node *) malloc(sizeof(Node));
    if( newNode != NULL )
    {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}
//  Add a Node to the end of the list
void addNode(Node* newNode)
{
    Node* currentNode = headNode;
    //  Check for empty list
    if( headNode == NULL )
    {
        headNode = newNode;
        return;
    }
    //  Loop to end of list
    while( currentNode->next != NULL )
        currentNode = currentNode->next;
    //  Add new node to end
    currentNode->next = newNode;
}
//  Insert a node into the list
void insertNode(Node* afterNode, Node* newNode)
{
    //  Update the newNode next
    newNode->next = afterNode->next;
    //  Update afterNode next
    afterNode->next = newNode;
}
//  Delete a node from the list
void deleteNode(Node* deleteNode)
{
    Node* currentNode = headNode;
    Node* prevNode;
    //  Check if node is the head
    if( headNode == deleteNode )
    {
        headNode = headNode->next;
        free( deleteNode );
        return;
    }
    //  Find the node to delete
    while( currentNode != NULL && currentNode != deleteNode )
    {
        prevNode = currentNode;
    }
    //  If node found, unlink it
    if( currentNode != NULL )
    {
        prevNode->next = currentNode->next;
    }
    free( deleteNode );
}
void printNodes()
{
    Node*   node = headNode;
    int     position = 0;
    
    while( node != NULL )
    {
        printf("Node pos = %d  data = %d\n", position++, node->data );
        node = node->next;
    }
}
int main()
{
    Node    *newNode;
 
    newNode = createNode(10);
    if( newNode )
        addNode(newNode);
    newNode = createNode(20);
    if( newNode )
        addNode(newNode);
    newNode = createNode(30);
    if( newNode )
        addNode(newNode);
    printf("After create\n");
    printNodes();
    printf("\n");
    newNode = createNode(100);
    if( newNode )
        insertNode(headNode, newNode);
    printf("After insertNode\n");
    printNodes();
    printf("\n");
    deleteNode(headNode);
    printf("After deleteNode\n");
    printNodes();
    printf("\n");
 
    return 0;
}