using namespace std;
#include <bits/stdc++.h>

pair<int, int> next_time(int hr, int mnt)
{
    if (hr == 23 && mnt == 59)
    {
        hr = 0;
        mnt = 0;
    }
    else if (mnt == 59)
    {
        ++hr;
        mnt = 0;
    }
    else ++mnt;

    return make_pair(hr, mnt);
}
int main()
{
    int n, hr, mnt, i, j; cin>>n;
    string s1, s2, s3, tmp;

    while (n--)
    {
        s1 = s2 = s3 = "";
        scanf("%d:%d", &hr, &mnt);


        while(1)
        {
            pair<int, int> p;
            p = next_time(hr, mnt);
            hr = p.first;
            mnt = p.second;

            s1 = to_string(hr);
            s2 = to_string(mnt);
            if (s1 == "0") s1 = "";
            else if (mnt < 10) s2 = "0" + s2;
            //if (s2[0] == '0') s2 = s2[1];
            s3 = s1 + s2;
            tmp = s3;
            reverse(tmp.begin(), tmp.end());
            if (tmp == s3) break;
        }
        if (s1.size() == 1) s1 = "0" + s1;
        else if (s1 == "") s1 = "00";
        if (s2.size() == 1) s2 = "0" + s2;

        cout<<s1<<':'<<s2<<endl;
    }

    return 0;
}
