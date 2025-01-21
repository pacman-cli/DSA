#include <iostream>     // For input/output operations
#include <vector>       // For dynamic arrays
#include <algorithm>    // For sort and max functions
#include <bits/stdc++.h> // For other standard libraries
using namespace std;

// Structure to represent a question with marks, time, index, and marks/time ratio
struct Question {
    int marks, time;
    int index;
    double ratio;
};

// Vector to store original questions for reference
vector<Question> original;  

// Function to compare two questions based on their marks/time ratio and marks
bool compare(const Question &a, const Question &b) {
    // If ratios are equal, compare marks in descending order
    if (a.ratio == b.ratio) {
        return a.marks > b.marks;
    }
    // Otherwise, compare ratios in descending order
    return a.ratio > b.ratio;
}

// Function to solve the problem when answering alone
void solveAlone(vector<Question> questions, int totalTime) {
    // Sort questions based on their marks/time ratio and marks
    sort(questions.begin(), questions.end(), compare);
    
    double totalMarks = 0;  // Track total marks obtained
    vector<pair<int, pair<double, double>>> answers;  // Store question index, percentage, and marks
    int remainingTime = totalTime;  // Track remaining time
    
    // Consider each question in sorted order
    for (const Question &q : questions) {
        // If no time left, stop considering more questions
        if (remainingTime <= 0) break;
        
        double percentage = 100.0;  // Initialize percentage to 100%
        // If question time exceeds remaining time, calculate percentage
        if (q.time > remainingTime) {
            percentage = (remainingTime * 100.0) / q.time;
        }
        
        double marksGot = (percentage * q.marks) / 100.0;  // Calculate marks obtained
        // If marks obtained are positive, store question index, percentage, and marks
        if (marksGot > 0) {
            answers.push_back({q.index, {percentage, marksGot}});
            totalMarks += marksGot;  // Update total marks
        }
        
        remainingTime -= min(remainingTime, q.time);  // Reduce remaining time
    }
    
    // Print maximum marks possible when answering alone
    cout << "Maximum " << fixed << setprecision(0) << totalMarks << " marks answering alone\n";
    // Print question index, percentage, and marks for each selected question
    for (const auto &ans : answers) {
        cout << "ques " << ans.first << " " << fixed << setprecision(0) 
             << ans.second.first << "% done -- " << fixed << setprecision(0) 
             << ans.second.second << " marks\n";
    }
}

// Function to solve the problem when answering with a friend
void solveWithFriend(vector<Question> questions, int totalTime) {
    // Sort questions based on their marks/time ratio and marks
    sort(questions.begin(), questions.end(), compare);
    
    double totalMarks = 0;  // Track total marks obtained
    int remainingTime = totalTime * 2;  // Double time when answering with a friend
    
    // Consider each question in sorted order
    for (const Question &q : questions) {
        // If no time left, stop considering more questions
        if (remainingTime <= 0) break;
        
        double percentage = 100.0;  // Initialize percentage to 100%
        // If question time exceeds remaining time, calculate percentage
        if (q.time > remainingTime) {
            percentage = (remainingTime * 100.0) / q.time;
        }
        
        double marksGot = (percentage * q.marks) / 100.0;  // Calculate marks obtained
        totalMarks += marksGot;  // Update total marks
        
        remainingTime -= min(remainingTime, q.time);  // Reduce remaining time
    }
    
    // Print maximum marks possible when answering with a friend
    cout << "Maximum " << fixed << setprecision(0) << totalMarks 
         << " marks answering with a friend\n";
}

int main() {
    int M, T, N;  // Input values for M, T, and N
    cin >> M >> T >> N;
    
    // Vector to store questions
    vector<Question> questions(N);
    // Input marks and time for each question
    for (int i = 0; i < N; i++) {
        cin >> questions[i].marks >> questions[i].time;
        questions[i].index = i + 1;  // Set question index
        questions[i].ratio = (double)questions[i].marks / questions[i].time;  // Calculate marks/time ratio
    }
    original = questions;  // Store original questions
    
    // Solve the problem when answering alone and with a friend
    solveAlone(questions, T);
    solveWithFriend(questions, T);
    
    return 0;  // Program completed successfully
}
