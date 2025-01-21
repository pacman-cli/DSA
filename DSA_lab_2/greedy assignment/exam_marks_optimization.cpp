#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Question {
    int marks, time;
    int index;
    double ratio;
};

bool compare(const Question &a, const Question &b) {
    if (a.ratio == b.ratio) {
        return a.marks > b.marks;
    }
    return a.ratio > b.ratio;
}

void solveAlone(vector<Question> &questions, int totalTime) {
    sort(questions.begin(), questions.end(), compare);

    int totalMarks = 0;
    vector<pair<int, pair<int, int>>> answers;
    int remainingTime = totalTime;

    for (const Question &q : questions) {
        if (remainingTime <= 0) break;

        int percentage = 100;
        if (q.time > remainingTime) {
            percentage = (remainingTime * 100) / q.time;
        }

        int marksGot = (percentage * q.marks) / 100;
        if (marksGot > 0) {
            answers.push_back({q.index, {percentage, marksGot}});
            totalMarks += marksGot;
        }

        remainingTime -= min(remainingTime, q.time);
    }

    cout << "Maximum " << totalMarks << " marks answering alone\n";
    for (const auto &ans : answers) {
        cout << "ques " << ans.first << " " << ans.second.first << "% done -- " << ans.second.second
             << " marks\n";
    }
}

void solveWithFriend(vector<Question> &questions, int totalTime) {
    sort(questions.begin(), questions.end(), compare);

    int totalMarks = 0;
    int remainingTime = totalTime * 2;

    for (const Question &q : questions) {
        if (remainingTime <= 0) break;

        int percentage = 100;
        if (q.time > remainingTime) {
            percentage = (remainingTime * 100) / q.time;
        }

        int marksGot = (percentage * q.marks) / 100;
        totalMarks += marksGot;

        remainingTime -= min(remainingTime, q.time);
    }

    cout << "Maximum " << totalMarks << " marks answering with a friend\n";
}

int main() {
    int M, T, N;
    cin >> M >> T >> N;

    vector<Question> questions(N);
    for (int i = 0; i < N; i++) {
        cin >> questions[i].marks >> questions[i].time;
        questions[i].index = i + 1;
        questions[i].ratio = (double)questions[i].marks / questions[i].time;
    }

    solveAlone(questions, T);
    solveWithFriend(questions, T);

    return 0;
}
