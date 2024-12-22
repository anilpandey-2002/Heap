typedef pair<int, Node *> pin;

class Solution
{
public:
    Node *mergeKLists(Node *arr[], int k)
    {
        priority_queue<pin, vector<pin>, greater<pin>> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i]->data, arr[i]});
        }

        Node *ans = new Node(0);
        Node *finalAns = ans;

        while (!pq.empty())
        {
            pin curr = pq.top();
            pq.pop();

            ans->next = curr.second;
            ans = ans->next;

            if ((curr.second)->next != NULL)
                pq.push({(curr.second)->next->data, (curr.second)->next});
        }

        return finalAns->next;
    }
};
