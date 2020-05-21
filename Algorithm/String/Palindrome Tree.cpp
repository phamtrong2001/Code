struct PTNode
{
    int first, length, child[26], suffix;
    PTNod(int first = 0, int length = 0) : first(first), length(length)
    {
        suffix = 0;
        for (int i = 0; i < 26; i++) child[i] = 0;
    }
}node[N];

void add(int pos)
{
    int start;
    while (1)
    {
        start = pos - node[cur].length - 1;
        if (start >= 0 && s[start] == s[pos])
            break;
        cur = node[cur].suffix;
    }
    int z = s[pos] - 'a';
    if (node[cur].child[z])
    {
        cur = node[cur].child[z];
        return;
    }

    node[++sz] = PTNode(start, node[cur].length + 2);
    node[cur].child[z] = sz;
    if (node[sz].length == 1)
        node[sz].suffix = 2;
    else
    {
        while (1)
        {
            cur = node[cur].suffix;
            int start = pos - node[cur].length - 1;
            if (start >= 0 && s[pos] == s[start])
                break;
        }
        node[sz].suffix = node[cur].child[z];
    }
    cur = sz;
    return;
}

void main()
{
    node[1] = PTNode(0, -1); node[2] = PTNode(0, 0);

}
