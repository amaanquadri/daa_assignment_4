#include <iostream>
#include <string>

using namespace std;

int bf_string_matching(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}

int main()
{
    string text = "this is a test string";
    string pattern = "test";

    int result = bf_string_matching(text, pattern);
    if (result == -1)
        cout << "Pattern not found in text" << endl;
    else
        cout << "Pattern found at index " << result << endl;

    return 0;
}