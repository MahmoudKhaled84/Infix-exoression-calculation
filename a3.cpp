 
#include <cmath>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function prototypes
int evalInfix(string expr);
int evalPostfix(string expr);
bool isOperator(char letter);
int precedence(char op);
string infixToPostfix(string expr);

int main(int argc, char const *argv[])
{
  string line;
  line = "7 + (4 - 2(()";

  try {
      cout << evalInfix(line) << endl;
    } catch (char const* e) {
      cerr << e << endl;
    }

  while (cin) {
    getline(cin, line);
    // skip empty lines
    if (line.size() == 0) {
      continue;
    }
    try {
      cout << evalInfix(line) << endl;
    } catch (char const* e) {
      cerr << e << endl;
    }
  }
  return 0;
}

// Infix evaluator. Simply uses postfix eval underneath.
int evalInfix(string expr)
{
  return evalPostfix(infixToPostfix(expr));
}

// Converts an infix expression to postfix. So we can use the previously
// written postfix evaluator. This function also generates errors for invalid
// expressions.
string infixToPostfix(string expr)
{
  string postfix;
  stack<char> stack;
  char previous;
  int openParens = 0;

  for (string::iterator it = expr.begin(); it != expr.end(); it++) {
    char letter = *it;
    // skip whitespaces
    if (isspace(letter)) {
      continue;
    }
    if (isdigit(letter)) {
      postfix.append(1, letter);
    } else if (letter == '(') {
      openParens++;
      stack.push(letter);
    } else if (isOperator(letter)) {
      if (stack.empty()) {
        stack.push(letter);
      } else {
        char op = stack.top();
        while (precedence(op) > precedence(letter)) {
          stack.pop();
          postfix.append(1, op);
        }
        stack.push(letter);
      }
    } else if (letter == ')') {
      openParens--;
      while (!stack.empty() && stack.top() != '(') {
        postfix.append(1, stack.top());
        stack.pop();
      }
      if (!stack.empty()) {
        stack.pop();
      }
    } else {
      // Operator or operand error?
      if (isOperator(previous) || previous == '(' || previous == ')') {
        throw "operand error";
      } else {
        throw "operator error";
      }
    }
    previous = letter;
  }

  // Check paranthesis
  if (openParens > 0) {
    throw "imbalanced paranthesis error";
  }

  // Add stacked elements to output string
  while (!stack.empty()) {
    postfix.append(1, stack.top());
    stack.pop();
  }

  return postfix;
}

// Eval function implementation
int evalPostfix(string expr)
{
  // stack is holding input numbers
  stack<int> stack;

  for (string::iterator it = expr.begin(); it != expr.end(); it++) {
    char letter = *it;
    // simply push digits to stack
    if (isdigit(letter)) {
      // char -> int conversion
      stack.push(letter - '0');
    } else {
      // doing actual operations
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      int result;
      switch (letter) {
        case '+': result = b + a; break;
        case '-': result = b - a; break;
        case '*': result = b * a; break;
        case '^': result = (int) pow((double) b, a); break;
      }
      stack.push(result);
    }
  }
  return stack.top();
}

// Helper function to test if we have an operator
bool isOperator(char letter)
{
  return letter == '+' || letter == '-' || letter == '*' || letter == '^';
}

// Precendence table for the operators.
// TODO A static precendence table will probably work better.
int precedence(char op)
{
  switch (op) {
    case '+': return 1;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    case '^': return 4;
  }
  return 0;
}
