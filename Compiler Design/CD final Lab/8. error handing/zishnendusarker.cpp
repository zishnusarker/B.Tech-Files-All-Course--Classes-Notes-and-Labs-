#include <bits/stdc++.h>
using namespace std;
vector<string> split (string s)
{
vector<string> v;
int i;
for (i=0;i<s.length (0 && s[i] != ';'; i++)
{
string word="";
if (s [i]'') == '_')
continue;
 while (true)
{
if (isalnum (s [i]) ||s[i] == =='_')
word += s[i];
else if (s [i]=='+'||s[i]=='-'||s[i]=='*' ||s [i]=='=')
{
string op="";
op += s[i];
if (s [i-1] !='')
v.push_back (word);
v.push_back (op);
break;
 }
else if (s [i] == '(')
{                                
string p= "";
if (s (i-1]!=' ')
v.push_back (word);
p+= 3[i];
while (s [i++] != ')')
p+= s[i];
p+= s[i];
v.push_back (p);
break;
}
i++;
if (s[i] ==
{
     ',' || s[i] ==.|| s[i] == ';')
v.push_back (word);
break;
}
}
}
return v;
}
bool is_keyword (string s)
{
set<string, greater<string>>keywords;
keywords.insert ("void");
keywords.insert ("return");
keywords.insert ("namespace");
if (keywords.find (s) != keywords.end ()) return true;
else return false;
               keywords.insert ("int");
               keywords.insert ("using");
bool is_keyword (string s)
        set<string, greater<string>>keywords;
        keywords.insert ("void");
        keywords.insert ("return");
        keywords.insert ("namespace");
        if (keywords.find (s) != keywords.end ()) return true;
        else return false;
                                         keywords.insert ("int");
                                        keywords.insert ("using");
}
bool is operator (string s)
{
        set<string, greater<string>>oper;
        oper.insert ("+");
        oper.insert ("*");
         oper.insert ("=");
        oper.insert (" () ");
       if (oper.find (s) != oper.end ()) return true;
        else return false;
                                oper.insert ("-");
                                oper.insert ("/");
                                 oper.insert ("");
                                 oper.insert (";");
}
bool is valid_id (string s)
        int i;
                                   =='')) return false; if (! (isalpha (s [0]) Ils[0]
        for (i=0;i<3.length ();i+7)
                if (! (isalnum (s [i]) |ls[i] == '_'))
                        return false;
        return true;
}
bool is num const (string s)
{
        int i;
        for (i=0;i!= s.length (); i++)
                if (!isdigit (s [1]))
                        return false;
        return true;
}
int main ()
{
        ifstream fin ("prog.txt");
        string line;
        vector<string> program;
        vector<string>::iterator ptr;
        set<string, greater<string>>keywords, oper;
        set<string, greater<string> >::iterator itr;
        vector<string> cons;
        int id no=1;
        map <string, int> id;
map <string, int>::iterator idtr;
if (fin.is_open ())
{
        while (getline (fin, line))
                program.push_back (line);
        fin.close ();
for (ptr-program.begin (); ptr!=program.end (); ptr++)
{
  line=*ptr;
 if (line [0]=='#'||line.compare ("{")==01|line.compare ("}") == 0)
                continue;
  vector<string> words=split (line);
  for (vector<string>::iterator it=words.begin ();it!=words.end ();
        it++)
  {
       string word=*it;
        if (word.compare ("}") ==01lword.compare ("{")==0)
                        break;
        if (is_keyword (word))
        {
                keywords.insert (word);
                cout<<"<"<<word<<">";
else if (is_valid_id (word))
{
        idtr=id.find (word);
        if(idtr == id.end ())
        {
                id.insert (make_pair (word, id_no));
                cout<<"<id, "<<id_no<<">";
                id_not+;
        }
        else
        cout<<"<id, "<<idtr->second<<">";
}
else if (is_operator (word))
         oper.insert (word);
        if (word.compare (";") != 0)
                cout<<"<op,"<<word<<">";
}
else if (is_num_const (word))
         cons.push_back (word);
        cout<<"<const, "<<word<<">";
}
}
cout<<"\n";
}
ofstream fout ("symbol.txt");
fout<<"\nKeywords:\n";
for (itr=keywords.begin (); itr != keywords.end (); itr++)
                     fout<<*itr<<"\n";
fout<<"\nOperators:\n";
for (itr=oper.begin (); itr != oper.end (); itr++)
                     fout<<*itr<<"\n";
fout<<"\nIdentifiers:\n";
 for (idtr=id.begin (); idtr != id.end (); idtr++)
                     fout<< idtr->first <<"\t <id,"<< idtr->second <<">\n";
fout.close ();
return 0;
}
