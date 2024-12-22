#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    map<char, int> mp;
    for (char c : s)
        mp[c]++;

    priority_queue<pair<int, char>> maxHeap;

    for (auto i : mp)
    {
        maxHeap.push({i.second, i.first});
    }

    string ans = "";

    while (maxHeap.size() > 1)
    {
        pair<int, char> a = maxHeap.top();
        maxHeap.pop();
        pair<int, char> b = maxHeap.top();
        maxHeap.pop();

        ans += a.second;
        ans += b.second;

        a.first--;
        b.first--;

        if (a.first > 0)
            maxHeap.push(a);
        if (b.first > 0)
            maxHeap.push(b);
    }

    if (maxHeap.size() > 0 && (maxHeap.top().first > 1 || maxHeap.top().second == ans[ans.size() - 1]))
        return "";

    if (maxHeap.size())
        ans += maxHeap.top().second;

    return ans;
}

int main()
{
    string s = "abbabbaaab";
    cout << reorganizeString(s);
}
