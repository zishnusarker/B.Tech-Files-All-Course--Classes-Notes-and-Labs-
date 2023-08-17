#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
#define TSIZE 128
int table[100][TSIZE];
char terminal[TSIZE];
char nonterminal[26];
struct product {
  char str[100];
  int len;
}
pro[20];
int no_pro;
char first[26][TSIZE];
char follow[26][TSIZE];
char first_rhs[100][TSIZE];
int isNT(char c) {
  return c >= 'A' && c <= 'Z';
}
void readFromFile() {
  int n;
  cin >> n;
  int i;
  int j;
  for (int k = 0; k < n; ++k) {
    string buffer;
    cin >> buffer;
    j = 0;
    nonterminal[buffer[0] - 'A'] = 1;
    for (i = 0; i < buffer.length(); ++i) {
      if (buffer[i] == '|') {
        ++no_pro;
        pro[no_pro - 1].str[j] = '\0';
        pro[no_pro - 1].len = j;
        pro[no_pro].str[0] = pro[no_pro - 1].str[0];
        pro[no_pro].str[1] = pro[no_pro - 1].str[1];
        pro[no_pro].str[2] = pro[no_pro - 1].str[2];
        j = 3;
      } else {
        pro[no_pro].str[j] = buffer[i];
        ++j;
        if (!isNT(buffer[i]) && buffer[i] != '-' && buffer[i] != '>') {
          terminal[buffer[i]] = 1;
        }
      }
    }
    pro[no_pro].len = j;
    ++no_pro;
  }
}
void add_FIRST_A_to_FOLLOW_B(char A, char B) {
  int i;
  for (i = 0; i < TSIZE; ++i) {
    if (i != '^')
      follow[B - 'A'][i] = follow[B - 'A'][i] || first[A - 'A'][i];
  }
}
void add_FOLLOW_A_to_FOLLOW_B(char A, char B) {
  int i;
  for (i = 0; i < TSIZE; ++i) {
    if (i != '^')
      follow[B - 'A'][i] = follow[B - 'A'][i] || follow[A - 'A'][i];
  }
}
void FOLLOW() {
  int t = 0;
  int i, j, k, x;
  while (t++ < no_pro) {
    for (k = 0; k < 26; ++k) {
      if (!nonterminal[k]) continue;
      char nt = k + 'A';
      for (i = 0; i < no_pro; ++i) {
        for (j = 3; j < pro[i].len; ++j) {
          if (nt == pro[i].str[j]) {
            for (x = j + 1; x < pro[i].len; ++x) {
              char sc = pro[i].str[x];
              if (isNT(sc)) {
                add_FIRST_A_to_FOLLOW_B(sc, nt);
                if (first[sc - 'A']['^'])
                  continue;
              } else {
                follow[nt - 'A'][sc] = 1;
              }
              break;
            }
            if (x == pro[i].len)
              add_FOLLOW_A_to_FOLLOW_B(pro[i].str[0], nt);
          }
        }
      }
    }
  }
}
void add_FIRST_A_to_FIRST_B(char A, char B) {
  int i;
  for (i = 0; i < TSIZE; ++i) {
    if (i != '^') {
      first[B - 'A'][i] = first[A - 'A'][i] || first[B - 'A'][i];
    }
  }
}
void FIRST() {
  int i, j;
  int t = 0;
  while (t < no_pro) {
    for (i = 0; i < no_pro; ++i) {
      for (j = 3; j < pro[i].len; ++j) {
        char sc = pro[i].str[j];
        if (isNT(sc)) {
          add_FIRST_A_to_FIRST_B(sc, pro[i].str[0]);
          if (first[sc - 'A']['^'])
            continue;
        } else {
          first[pro[i].str[0] - 'A'][sc] = 1;
        }
        break;
      }
      if (j == pro[i].len)
        first[pro[i].str[0] - 'A']['^'] = 1;
    }
    ++t;
  }
}
void add_FIRST_A_to_FIRST_RHS__B(char A, int B) {
  int i;
  for (i = 0; i < TSIZE; ++i) {
    if (i != '^')
      first_rhs[B][i] = first[A - 'A'][i] || first_rhs[B][i];
  }
}
void FIRST_RHS() {
  int i, j;
  int t = 0;
  while (t < no_pro) {
    for (i = 0; i < no_pro; ++i) {
      for (j = 3; j < pro[i].len; ++j) {
        char sc = pro[i].str[j];
        if (isNT(sc)) {
          add_FIRST_A_to_FIRST_RHS__B(sc, i);
          if (first[sc - 'A']['^'])
            continue;
        } else {
          first_rhs[i][sc] = 1;
        }
        break;
      }
      if (j == pro[i].len)
        first_rhs[i]['^'] = 1;
    }
    ++t;
  }
}
int main() {
  readFromFile();
  string input_string;
  cin >> input_string;
  follow[pro[0].str[0] - 'A']['$'] = 1;
  FIRST();
  FOLLOW();
  FIRST_RHS();
  int i, j, k;
  printf("\n");
  for (i = 0; i < no_pro; ++i) {
    if (i == 0 || (pro[i - 1].str[0] != pro[i].str[0])) {
      char c = pro[i].str[0];
      printf("FIRST OF %c: ", c);
      for (j = 0; j < TSIZE; ++j) {
        if (first[c - 'A'][j]) {
          printf("%c ", j);
        }
      }
      printf("\n");
    }
  }
  printf("\n");
  for (i = 0; i < no_pro; ++i) {
    if (i == 0 || (pro[i - 1].str[0] != pro[i].str[0])) {
      char c = pro[i].str[0];
      printf("FOLLOW OF %c: ", c);
      for (j = 0; j < TSIZE; ++j) {
        if (follow[c - 'A'][j]) {
          printf("%c ", j);
        }
      }
      printf("\n");
    }
  }
  printf("\n");
  for (i = 0; i < no_pro; ++i) {
    printf("FIRST OF %s: ", pro[i].str);
    for (j = 0; j < TSIZE; ++j) {
      if (first_rhs[i][j]) {
        printf("%c ", j);
      }
    }
    printf("\n");
  }
  terminal['$'] = 1;
  terminal['^'] = 0;

  // printing parse table
  printf("\n");
  printf("\n\t****** LL(1) PARSING TABLE *******\n");
  printf("\t--------------------------------------------------------\n");
  printf("%-10s", "");
  for (i = 0; i < TSIZE; ++i) {
    if (terminal[i]) printf("%-10c", i);
  }
  printf("\n");
  int p = 0;
  for (i = 0; i < no_pro; ++i) {
    if (i != 0 && (pro[i].str[0] != pro[i - 1].str[0]))
      p = p + 1;
    for (j = 0; j < TSIZE; ++j) {
      if (first_rhs[i][j] && j != '^') {
        table[p][j] = i + 1;
      } else if (first_rhs[i]['^']) {
        for (k = 0; k < TSIZE; ++k) {
          if (follow[pro[i].str[0] - 'A'][k]) {
            table[p][k] = i + 1;
          }
        }
      }
    }
  }
  k = 0;
  map < char, map < char, string >> table_2;
  for (i = 0; i < no_pro; ++i) {
    if (i == 0 || (pro[i - 1].str[0] != pro[i].str[0])) {
      printf("%-10c", pro[i].str[0]);
      for (j = 0; j < TSIZE; ++j) {
        if (table[k][j]) {
          table_2[pro[i].str[0]][(char) j] = pro[table[k][j] - 1].str;
          printf("%-10s", pro[table[k][j] - 1].str);
        } else if (terminal[j]) {
          printf("%-10s", "");
        }
      }
      ++k;
      printf("\n");
    }
  }
  stack < char > s;
  s.push('$');
  s.push('T');
  input_string.push_back('$');
  int ptr = 0;
  bool parsed_successfully = true;
  cout << "INPUT STRING = " << input_string << endl;
  while (ptr < (int) input_string.length() and s.empty() == false) {
    char curr = s.top();
    s.pop();
    bool isnt = (curr >= 'A'
      and curr <= 'Z');
    if (!isnt) {
      if (input_string[ptr] == curr) {
        ptr++;
      } else {
        parsed_successfully = false;
        break;
      }
    } else {
      string ss = table_2[curr][input_string[ptr]];
      bool found = false;
      string ss2;
      for (int i = 0; i < ss.length(); ++i) {
        if (found) {
          ss2.push_back(ss[i]);
        }
        if (ss[i] == '>') {
          found = true;
        }
      }
      if (ss.length() == 0) {
        parsed_successfully = false;
        break;
      } else {
        if (ss2[0] == '^') {
          continue;
        }
        for (int i = ss2.length() - 1; i >= 0; --i) {
          s.push(ss2[i]);
        }
      }
    }
  }
  if (s.empty() == true) {
    cout << "STRING PARSED SUCCESSFULLY!" << endl;
  }
}