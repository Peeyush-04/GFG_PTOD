#include <iostream>
#include <vector>
using namespace std;

// Node structure definition
struct Node
{
  int data;
  Node *right;
  Node *down;

  Node(int x) : data(x), right(NULL), down(NULL) {}
};

// Function to create a new node
Node *createNode(int value)
{
  return new Node(value);
}

// Function to link horizontally (right pointers)
void linkRight(Node *&prevNode, Node *&newNode)
{
  if (prevNode)
  {
    prevNode->right = newNode;
  }
  else
    prevNode = newNode;
}

// Function to link vertically (down pointers)
void linkDown(Node *&topNode, Node *&newNode, int colIndex)
{
  if (topNode)
  {
    // Traverse horizontally to the same column index
    for (int k = 0; k < colIndex; ++k)
    {
      topNode = topNode->right;
    }
    topNode->down = newNode;
  }
}

// Function to construct the entire linked matrix
Node *constructLinkedMatrix(vector<vector<int>> &mat)
{
  if (mat.empty())
    return NULL;

  Node *head = NULL;    // Head node of the matrix (top-left corner)
  Node *prevRow = NULL; // Head node of the previous row

  // Loop through each row
  for (int i = 0; i < mat.size(); ++i)
  {
    Node *rowHead = NULL; // Head of the current row
    Node *prevCol = NULL; // Previous column node for horizontal linking

    // Loop through each column in the row
    for (int j = 0; j < mat[0].size(); ++j)
    {
      // Create a new node for the current matrix element
      Node *newNode = createNode(mat[i][j]);

      // Link nodes horizontally (right)
      linkRight(prevCol, newNode);
      if (j == 0)
        rowHead = newNode; // Set rowHead if this is the first column node

      // Link nodes vertically (down) to the node in the previous row
      linkDown(prevRow, newNode, j);
    }

    // If this is the first row, set the head of the matrix
    if (i == 0)
    {
      head = rowHead;
    }

    // Move to the next row (current row becomes previous row)
    prevRow = rowHead;
  }

  return head;
}

// Helper function to print the matrix row-wise
void printMatrix(Node *head)
{
  Node *row = head;
  while (row != NULL)
  {
    Node *col = row;
    while (col != NULL)
    {
      cout << col->data << " ";
      col = col->right;
    }
    cout << endl;
    row = row->down;
  }
}

// Main function to test the linked matrix construction
int main()
{
  vector<vector<int>> mat = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  Node *matrixHead = constructLinkedMatrix(mat);

  // Print the constructed matrix
  printMatrix(matrixHead);

  return 0;
}
