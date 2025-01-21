#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Item {
    string name;
    double value;
    double weight;
    double originalWeight;

    Item(string n, double v, double w) : name(n), value(v), weight(w) {
        originalWeight = weight;
    }
};

bool compare(const Item &a, const Item &b) {
    return (a.value / a.originalWeight) > (b.value / b.originalWeight);
}

double stealItems(vector<Item> &items, double capacity,
                  vector<pair<string, pair<double, double>>> &itemsTaken) {
    double totalProfit = 0.0;

    for (auto &item : items) {
        if (capacity <= 0) break;

        if (item.weight > 0) {
            double fraction = min(capacity, item.weight);
            capacity -= fraction;
            double itemProfit = (fraction / item.originalWeight) * item.value;
            totalProfit += itemProfit;
            itemsTaken.push_back({item.name, {fraction, itemProfit}});
            item.weight -= fraction;
        }
    }

    return totalProfit;
}

void printWithPrecision(double value) {
    int scaledValue = static_cast<int>(value * 10 + 0.5);
    cout << scaledValue / 10 << "." << scaledValue % 10;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items;
    for (int i = 0; i < n; i++) {
        string name;
        double value, weight;
        cin >> name >> value >> weight;
        items.emplace_back(name, value, weight);
    }

    int K;
    cout << "Enter number of thieves: ";
    cin >> K;

    vector<double> capacities(K);
    for (int i = 0; i < K; i++) {
        cin >> capacities[i];
    }

    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    int thievesUsed = 0;

    cout << "\nStealing process:\n";

    for (int i = 0; i < K && !items.empty(); i++) {
        vector<pair<string, pair<double, double>>> itemsTaken;
        double profit = stealItems(items, capacities[i], itemsTaken);

        if (profit > 0) {
            thievesUsed++;
            totalProfit += profit;
            for (const auto &item : itemsTaken) {
                cout << "Taking " << item.first << ": ";
                printWithPrecision(item.second.first);
                cout << " kg ";
                printWithPrecision(item.second.second);
                cout << " taka\n";
            }
            cout << "Thief " << thievesUsed << " profit: ";
            printWithPrecision(profit);
            cout << " taka\n";
        }
    }

    cout << "\nTotal " << thievesUsed << " thieves stole from the warehouse.\n";

    bool hasRemaining = false;
    for (const auto &item : items) {
        if (item.weight > 0) {
            if (!hasRemaining) {
                cout << "Still following items are left:\n";
                hasRemaining = true;
            }
            double remainingProfit = (item.weight / item.originalWeight) * item.value;
            cout << item.name << " ";
            printWithPrecision(item.weight);
            cout << " kg ";
            printWithPrecision(remainingProfit);
            cout << " taka\n";
        }
    }

    return 0;
}
