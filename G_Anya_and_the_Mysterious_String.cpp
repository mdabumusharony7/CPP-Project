#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; ++i)
    {
        if (str[i] != str[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool isBeautiful(string s, int l, int r)
{
    for (int i = l; i <= r; ++i)
    {
        for (int j = i + 1; j <= r; ++j)
        {
            if (isPalindrome(s.substr(i, j - i + 1)))
            {
                return false;
            }
        }
    }
    return true;
}

void addSubstring(string &s, int l, int r, int x)
{
    for (int i = l - 1; i < r; ++i)
    {
        s[i] = 'a' + (s[i] - 'a' + x) % 26;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        while (m--)
        {
            int type, l, r, x;
            cin >> type >> l >> r;

            if (type == 1)
            {
                cin >> x;
                addSubstring(s, l, r, x);
            }
            else
            {
                if (isBeautiful(s, l - 1, r - 1))
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}
