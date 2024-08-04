#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

void TowerOfHanoi(int numDisks, stack<int>& source, stack<int>& destination, stack<int>& helper) {
    int totalMoves = pow(2, numDisks) - 1;

    for (int move = 1; move <= totalMoves; move++) {
        if (move % 3 == 1) {
            if (!source.empty() && (helper.empty() || source.top() < helper.top())) {
                helper.push(source.top());
                source.pop();
                cout << "Move disk from source to helper" << endl;
            } else {
                source.push(helper.top());
                helper.pop();
                cout << "Move disk from helper to source" << endl;
            }
        } else if (move % 3 == 2) {
            if (!source.empty() && (destination.empty() || source.top() < destination.top())) {
                destination.push(source.top());
                source.pop();
                cout << "Move disk from source to destination" << endl;
            } else {
                source.push(destination.top());
                destination.pop();
                cout << "Move disk from destination to source" << endl;
            }
        } else {
            if (!helper.empty() && (destination.empty() || helper.top() < destination.top())) {
                destination.push(helper.top());
                helper.pop();
                cout << "Move disk from helper to destination" << endl;
            } else {
                helper.push(destination.top());
                destination.pop();
                cout << "Move disk from destination to helper" << endl;
            }
        }
    }
}

int main() {
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;
    stack<int> source, destination, helper;
    for (int i = numDisks; i >= 1; i--) {
        source.push(i);
    }
    TowerOfHanoi(numDisks, source, destination, helper);
    return 0;
}

