int len(char str[])
{
    int l = 0;
    while (str[l] != '\0')
        l++;

    return l;
}

int concate(char s1[], char s2[])
{
    int l1 = len(s1), l2 = len(s2);
    printf("%d %d \n", l1, l2);
    int l = 0;
    char final[1000];

    while (l != l1)
    {
        final[l] = s1[l];
        l++;
    }

    while (l - l1 != l2 + 1)
    {
        final[l] = s2[l - l1];
        l++;
    }
    int ptr = (int) final;
    return ptr;
}

void copy(char s1[], char s2[])
{
    int l = len(s1);

    while (l + 1)
    {
        s2[l] = s1[l];
        l--;
    }
}

int compare(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] > s2[i]) ? 1 : -1;
        i++;
    }
    return 0;
}

int findC(char s[])
{
    int i = 0;
    while (s[i] != 'c' && s[i] != '\0')
        i++;

    return (i == len(s)) ? -1 : i + 1;
}

int chackSubstring(char s1[], char s2[])
{
    int l1 = len(s1), ch;
    int l2 = len(s2);

    for (int i = 0; i < l1; i++)
    {
        if (s1[i] == s2[0])
        {
            ch = 1;
            for (int j = 0; j < l2; j++)
            {
                if (s1[i + j] != s2[j])
                    ch = 0;
            }
            if (ch)
                return 1;
        }
    }

    return 0;
}

void reverse(char s[])
{
    int l = len(s);
    l--;
    int i = 0;
    while (i <= l / 2)
    {
        char d = s[i];
        s[i] = s[l - i];
        s[l - i] = d;
        i++;
    }
}

void coded(char s1[])
{
    int l = len(s1);
    char a = 'a', e = 'e', i = 'i', o = 'o', u = 'u';

    while (--l + 1)
    {
        if (s1[l] == a || s1[l] == e || s1[l] == i || s1[l] == o || s1[l] == u)
            s1[l] = '*';
        else
            s1[l] = '#';
    }
}