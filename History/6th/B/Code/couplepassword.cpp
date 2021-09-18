#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

void CountAndSay(long long &n, const long long &progress, string &result);
void Count(string &result);

int main()
{
    long long n, progress = 1;
    string result = "1";
    cin >> n;
    CountAndSay(n, progress, result);
    cout << result;
} // main()

void CountAndSay(long long &n, const long long &progress, string &result)
{
    if (n == 1 || n == progress)
        return;
    else if (n == 0)
        result = "10";
    else
    {
        Count(result);
        CountAndSay(n, progress + 1, result);
    } //else
} // count-and-say()

void Count(string &result)
{
    string temp;
    long long previous = 0;
    for (long long i = 0; i < result.length(); i++)
        if (result[i] != result[i + 1])
        {
            temp = temp + to_string(i + 1 - previous) + result[i];
            previous = i + 1;
        } //if
    result = temp;
} // Count()
