class Solution
{
public:
    string findSum(string str1, string str2)
    {
        if (str1.length() > str2.length())
            swap(str1, str2);

        string str = "";
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;
        int carry = 0;

        for (int i = n1 - 1; i >= 0; i--)
        {
            int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        for (int i = n2 - n1 - 1; i >= 0; i--)
        {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)
            str.push_back(carry + '0');
        reverse(str.begin(), str.end());
        return str;
    }

    string solve(int arr[], int n)
    {
        sort(arr, arr + n);
        string a, b;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                continue;
            if (i & 1)
                a += (char)(arr[i] + '0');
            else
                b += (char)(arr[i] + '0');
        }
        return findSum(a, b);
    }
};

int solve(int arr[], int n)
{
    sort(arr, arr + n);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            a = a * 10 + arr[i];
        else
            b = b * 10 + arr[i];
    }
    return a + b;
}

int minSum(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    string num1, num2;

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    while (!pq.empty())
    {
        num1 += (48 + pq.top());
        pq.pop();
        if (!pq.empty())
        {
            num2 += (48 + pq.top());
            pq.pop();
        }
    }

    int a = atoi(num1.c_str());
    int b = atoi(num2.c_str());
    return a + b;
}

int main()
{
    int arr[] = {6, 8, 4, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum is " << solve(arr, n);
    return 0;
}
