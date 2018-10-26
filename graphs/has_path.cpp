#include <iostream>
#include<queue>
using namespace std;

bool hasPathDFS(int** edges, int n, int sv, int ev, bool* visited)
{
  if(edges[sv][ev]==1)
  {
    return true;
  }
  visited[sv]=true;
  
  for(int i=0;i<n;i++)
  {
    if(edges[sv][i]==1 && !visited[i])
    {
      bool ans=hasPathDFS(edges,n,i, ev, visited);
      if(ans==true)
        return ans;
    }
  }
  return false;
}

bool hasPathBFS(int** edges, int n, int sv, int ev)
{
  bool* visited=new bool[n];
  for(int i=0;i<n;i++)
  {
    visited[i]=false;
  }
  
  queue<int> pendingVertices;
  pendingVertices.push(sv);
  visited[sv]=true;
  
  while(!pendingVertices.empty())
  {
    int p=pendingVertices.front();
    if(p==ev)
    {
      return true;
    }
    
    pendingVertices.pop();
    for(int i=0;i<n;i++)
    {
      if(edges[p][i]==1 && !visited[i])
      {
        pendingVertices.push(i);
        visited[i]=true;
      }
    }
  }
  delete [] visited;
  return false;
  
}
int main() {
    int n, e;
  	cin>>n>>e;
  
  	int** edges=new int*[n];
  	for(int i=0;i<n;i++)
    {
      edges[i]=new int[n];
      for(int j=0;j<n;j++)
      {
        edges[i][j]=0;
      }
    }
  
  	for(int i=0;i<e;i++)
    {
      int f, t;
      cin>>f>>t;
      edges[f][t]=1;
      edges[t][f]=1;
    }
  
  	bool* visited=new bool[n];
  	for(int i=0;i<n;i++)
    {
      visited[i]=false;
    }
  
  	int sv, ev;
  	cin>>sv>>ev;
  	if(hasPathBFS(edges, n, sv, ev)==1)
    {
      cout<<"true";
    }
  
  	else cout<<"false";
  	return 0;
}
