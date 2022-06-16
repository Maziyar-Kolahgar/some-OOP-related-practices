#include <iostream>
#include <vector>
#include <string>
using namespace std;

void read_input(int n, int m, vector<string> ar, vector<int> inp)
{
    for (int i = 0; i < n; ++i)
    {
        string a;
        cin >> a;
        ar.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        inp.push_back(b);
    }
}
bool is_valid_network(int i, int j, bool err, vector<string> ar, int cnt)
{
    if (ar[i][j] < 'a' || ar[i][j] > 'z' || cnt != 2)
    {
        cout << "Invalid Network\n";
        return true;
    }
}

void process(int n, int m, vector<string> ar, vector<int> inp, bool err)
{
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n - 1; i++)
            if (ar[i][j] != '-')
            {
                int cnt=1;
                bool err = is_valid_network(i, j, err, ar, cnt);
                if (!err)
                    for (int k = i + 1; k < n; k++)
                    {
                        if (ar[i][j] == ar[k][j])
                        {
                            cnt++;
                            if (inp[i] > inp[k])
                            {
                                char temp = inp[i];
                                inp[i] = inp[k];
                                inp[k] = temp;
                            }
                        }
                        err= is_valid_network(i, j, err, ar, cnt);
                    }
            }
}

void generate_output(int n, vector<int> inp, bool err)
{
    bool flag = false;
    if (!err)
    {
        for (int i = 0; i < n - 1; i++)
            if (inp[i] > inp[i + 1])
            {
                cout << "Not sorted\n";
                flag = true;
            }
        if (!flag)
            cout << "Sorted\n";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ar;
    vector<int> inp;
    bool err = false;
    read_input(n, m, ar, inp);
    process(n, m, ar, inp, err);
    generate_output(n, inp, err);
}