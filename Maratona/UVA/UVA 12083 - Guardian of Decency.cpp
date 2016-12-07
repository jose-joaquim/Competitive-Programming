//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3235
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct pp{
  int heigth;
  char gender;
  char music[105];
  char sport[105];
};

vector<vi> AdjList;
vector<struct pp> persons;
vi match, vis;
int T, N;

int Aug(int l) {              
  if (vis[l]) return 0;                              
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;                      
    } }
  return 0;                                                
}

bool samePerson(const struct pp *a, const struct pp *b){
  return (fabs(a->heigth - b->heigth) <= 40) && (a->gender != b->gender) && !strcmp(a->music, b->music) && strcmp(a->sport, b->sport);
}

bool cmp(const struct pp &a, const struct pp &b){
  return a.gender > b.gender;
}

int main(){
  scanf("%d", &T);
  for(int cs = 1; cs <= T; cs++){
    scanf("%d", &N);
    AdjList.assign(N + 3, vi());
    persons.clear();
    int Vleft = 0, V = N;
    for(int i = 1; i <= N; i++){
      struct pp person;
      scanf("%d", &person.heigth);
      cin.ignore();
      scanf("%c", &person.gender);
      if(person.gender == 'M') Vleft++;
      scanf("%s", &person.music);
      scanf("%s", &person.sport);
      persons.push_back(person);
    }
    sort(persons.begin(), persons.end(), cmp);
    for(int i = 0; i < N; i++){
      if(persons[i].gender == 'F') break;
      for(int j = i+1; j < N; j++){
		if(samePerson(&persons[i], &persons[j])){
		  AdjList[i].push_back(j);
		}
      }
    }
    int MCBM = 0;
    match.assign(V, -1);  
    for (int l = 0; l < Vleft; l++) {   
      vis.assign(Vleft, 0);             
      MCBM += Aug(l);
    }

    printf("%d\n", V - MCBM);
  }
  return 0;
}
