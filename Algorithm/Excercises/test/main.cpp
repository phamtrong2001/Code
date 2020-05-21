#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <direct.h>
#include <cstring>
#include <sstream>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define maxn 1000000

using namespace std;

int sltype = 0, n = 0;
string filetype[100];
string path_source[maxn];
string path_dest[maxn];
int dd[maxn];
bool alltype = false;

void make_list(string s)
{
    string u;
    stringstream ss;
    ss.str(s);
    while (ss >> u)
    {
        if (u[0] != '.') u = "." + u;
        if (u.find(".*") != -1) alltype = true;
        filetype[++sltype] = u;
    }
}

bool ok( string s)
{
    return (s != "." && s != "..");
}

bool isfile( string s)
{
    return (s.find(".") != -1);
}

bool hople( string s)
{
    //return (s.find(".cpp") != -1);
    FOR(i,1,sltype)
    {
        int p = s.find(filetype[i]);
        if (p == int(s.length()) - filetype[i].length()) return true;
    }
    return alltype;
}

int Searchfile_to_copy(string source, string dest)
{
    path_source[++n] = source;
    path_dest[n] = dest;
    int vt = n;
    int p = 0;
    char *argv =  &source[0];
    char path[MAX_PATH];
    WIN32_FIND_DATA ffd;

    if (_tcslen(argv) > MAX_PATH - 4)
    {
        //cerr << _T("Your path is too long.") << endl;
        return 0;
    }

    _tcsncpy(path, argv, MAX_PATH);
    if (path[_tcslen(path) - 1] != '\\')
        _tcscat(path, _T("\\"));
    _tcscat(path, _T("*.*"));

    HANDLE hFind = FindFirstFile(path, &ffd);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        //cerr << _T("Invalid handle value.") << GetLastError() << endl;
        return 0;
    }

    bool finished = false;
    //bool have_file = false;

    while (!finished)
    {
        string tenfile =ffd.cFileName;
        if (ok(tenfile))
        if (isfile(tenfile))
        {
            if(hople(tenfile))
            {
            string s1 = source + '\\' + tenfile;
            string s2 = dest + '\\' + tenfile;
            path_source[++n] = s1;
            path_dest[n] = s2;
            dd[n] = 2;
            p = 1;
            }

        } else
            p |= Searchfile_to_copy(source + '\\' + tenfile, dest + '\\' + tenfile);
        if (!FindNextFile(hFind, &ffd))
            finished = true;
    }
    return (dd[vt] = p);
}



int main()
{
    string source, dest, type;
    cout << "Source: ";
    getline(cin, source);
    cout << "Dest:";
    getline(cin, dest);
    cout << "File Type: ";
    getline(cin, type);
    if (source.size() < 2 || dest.size() < 2)
        {
            cout << " Duong dan khong hop le!";
            return 0;
        }
    make_list(type);
    memset(dd, 0, sizeof(dd));

    Searchfile_to_copy(source, dest);
//    FOR(i,1,n)
//        cout << path_source[i] << " " << dd[i] << endl;
    int sofile = 0;
    FOR(i,1,n)
        if (dd[i] == 1) mkdir(&path_dest[i][0]);
            else if (dd[i] == 2)
            {
                //cout << path_source[i] << endl;
                CopyFile(&path_source[i][0], &path_dest[i][0], true);
                sofile ++;
            }

    cout << "Copied "<< sofile << " files!";
    system("pause");
    return 0;
}
