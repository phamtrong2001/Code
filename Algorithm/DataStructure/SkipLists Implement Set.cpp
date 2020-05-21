#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

struct SkipLists;
struct Column;
struct Cell;

struct SkipLists
{
    static const int MAX_LEVEL = 20;
    Column *head, *tail;

    SkipLists();
    bool empty();
    Column *lower_bound(int);
    Column *upper_bound(int);
    void insert(int);
    void erase(int);
};

struct Column
{
    int value;
    vector<Cell> cells;
};

struct Cell
{
    Column *previous_column, *next_column;
};

SkipLists::SkipLists()
{
    head = new Column;
    tail = new Column;
    head->value = 0;
    tail->value = 0;
    for (int i = 0; i < MAX_LEVEL; i++)
    {
        head->cells.PB((Cell){NULL, tail});
        tail->cells.PB((Cell){head, NULL});
    }
}
bool SkipLists::empty()
{
    return head->cells[0].next_column == tail;
}

Column *SkipLists::lower_bound(int value)
{
    Column *iter = head;
    for (int level = MAX_LEVEL-1; level >= 0; level--)
    {
        while (iter->cells[level].next_column != tail && iter->cells[level].next_column->value < value)
            iter = iter->cells[level].next_column;
    }
    return iter->cells[0].next_column;
}
Column *SkipLists::upper_bound(int value)
{
    Column *iter = head;
    for (int level = MAX_LEVEL-1; level >= 0; level--)
    {
        while (iter->cells[level].next_column != tail && iter->cells[level].next_column->value <= value)
            iter = iter->cells[level].next_column;
    }
    return iter->cells[0].next_column;
}

void SkipLists::insert(int value)
{
    Column *temp = lower_bound(value);
    if (temp != tail && temp->value == value) return;
    Column *inserted_column = new Column;
    inserted_column->value = value;
    inserted_column->cells.PB((Cell){NULL, NULL});

    while (inserted_column->cells.size() < MAX_LEVEL && rand() % 2 == 0)
        inserted_column->cells.PB((Cell){NULL, NULL});

    Column *iter = head;
    for (int level = MAX_LEVEL-1; level >= 0; level--)
    {
        while (iter->cells[level].next_column != tail && iter->cells[level].next_column->value < value)
            iter = iter->cells[level].next_column;
        if (level < inserted_column->cells.size())
        {
            Column *next_iter = iter->cells[level].next_column;
            iter->cells[level].next_column = inserted_column;
            next_iter->cells[level].previous_column = inserted_column;
            inserted_column->cells[level].previous_column = iter;
            inserted_column->cells[level].next_column = next_iter;
        }
    }
}
void SkipLists::erase(int value)
{
    Column *erased_column = lower_bound(value);
    if (erased_column == tail || erased_column->value != value) return;

    Column *iter = head;
    for (int level = MAX_LEVEL-1; level >= 0; level--)
    {
        while (iter->cells[level].next_column != tail && iter->cells[level].next_column->value <= value)
            iter = iter->cells[level].next_column;
        if (iter == erased_column)
        {
            Column *previous_iter = iter->cells[level].previous_column;
            Column *next_iter = iter->cells[level].next_column;
            previous_iter->cells[level].next_column = next_iter;
            next_iter->cells[level].previous_column = previous_iter;
        }
    }
    delete erased_column;
}

SkipLists sl;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CPPSET.INP", "r", stdin);
    int type, value;
    while (cin >> type)
    {
        if (type == 0) return 0;
        if (type == 1)
        {
            cin >> value;
            sl.insert(value);
        }
        else if (type == 2)
        {
            cin >> value;
            sl.erase(value);
        }
        else if (type == 3)
        {
            if (sl.empty()) cout <<"empty\n";
            else cout <<sl.head->cells[0].next_column->value <<'\n';
        }
        else if (type == 4)
        {
            if (sl.empty()) cout <<"empty\n";
            else cout <<sl.tail->cells[0].previous_column->value <<'\n';
        }
        else if (type == 5)
        {
            cin >> value;
            if (sl.empty()) cout <<"empty\n";
            else
            {
                Column *found_column = sl.upper_bound(value);
                if (found_column == sl.tail) cout <<"no\n";
                else cout <<found_column->value<<'\n';
            }
        }
        else if (type == 6)
        {
            cin >> value;
            if (sl.empty()) cout <<"empty\n";
            else
            {
                Column *found_column = sl.lower_bound(value);
                if (found_column == sl.tail) cout <<"no\n";
                else cout <<found_column->value<<'\n';
            }
        }
        else if (type == 7)
        {
            cin >> value;
            if (sl.empty()) cout <<"empty\n";
            else
            {
                Column *found_column = sl.lower_bound(value)->cells[0].previous_column;
                if (found_column == sl.head) cout <<"no\n";
                else cout <<found_column->value<<'\n';
            }
        }
        else if (type == 8)
        {
            cin >> value;
            if (sl.empty()) cout <<"empty\n";
            else
            {
                Column *found_column = sl.upper_bound(value)->cells[0].previous_column;
                if (found_column == sl.head) cout <<"no\n";
                else cout <<found_column->value<<'\n';
            }
        }
    }
}
