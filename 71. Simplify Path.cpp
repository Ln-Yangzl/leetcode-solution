#include <iostream>
#include <list>
#include <fstream>

using namespace std;

string simplifyPath(string path)
{
    list<string> record;
    record.push_back("$");
    string::iterator begin = path.begin(), end = path.begin();
    int len = 0;
    while (end != path.end())
    {
        begin = end;
        while (begin != path.end() &&*begin == '/')
            begin++;
        end = begin;
        if (end == path.end()) break;
        while (end != path.end() && *end != '/')
        {
            end++;
        }
        string current(begin, end);
        if (current == ".." && record.size() != 1) {
            len -= (record.back().size() + 1);
            record.pop_back();
        }
        else if (current != "."&& current != "..") {
            record.push_back(current);
            len += current.size() + 1;
        }
    }
    if (len == 0) return "/";
    string result(len, '0');
    int indx = 0;
    for (list<string>::iterator cur = ++record.begin(); cur != record.end(); cur++) {
        result[indx++] = '/';
        for (int i = 0; i < (*cur).size(); i++) {
            result[indx++] = (*cur)[i];
        }
    }
    return result;
}