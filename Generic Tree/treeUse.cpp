#include"treeNode.h"
#include<bits/stdc++.h>

using namespace std;

treeNode<int>* takeInput()
{
	int data;
	cout<<"Please enter root data:";
	cin>>data;
	
	treeNode<int> * root = new treeNode<int>(data);
	int children;
	cout<<"Please enter the number of children of "<<root->data<<" node:";
	cin>>children;
	
	for(int i=0;i<children;i++)
	{
		root->children.push_back(takeInput());
	}
	
	return root;
}

int max(treeNode<int>* root)
{
	int maxans = INT_MIN;
	for(int i=0;i<root->children.size();i++)
	{
		int cans = max(root->children[i]);
		if(cans>maxans)maxans = cans;
	}
	
	if(root->data>maxans)return root->data;
	else return maxans;
}

treeNode<int>* takeInputLevelWise()
{
	int data;
	cout<<"Please enter root data:";
	cin>>data;
	
	treeNode<int> * root = new treeNode<int>(data);
	queue<treeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty())
	{
		treeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int numchildren;
		cout<<"Please enter the number of children of "<<front->data<<" node:";
		cin>>numchildren;
		for(int i=0;i<numchildren;i++)
		{
			int child;
			cout<<"Please enter data of "<<i+1<<"th child of "<<front->data<<":";
			cin>>child;
			treeNode<int> * node = new treeNode<int>(child);
			front->children.push_back(node);
			pendingNodes.push(node);
		}
	}
	
	return root;
	
}
void printTreeRecursive(treeNode<int> * root)
{
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<" ";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		printTreeRecursive(root->children[i]);
	}
}

void printTreeSimple(treeNode<int> * root)
{
	cout<<root->data<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		printTreeSimple(root->children[i]);
	}
}
void printTreeInOrder(treeNode<int>* root)
{
	queue<treeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty())
	{
		treeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<":";
		for(int i=0;i<front->children.size();i++)
		{
			cout<<front->children[i]->data<<" ";
			pendingNodes.push(front->children[i]);
		}
		cout<<endl;
	}
}

int height(treeNode<int>* root)
{
	int maxh=0;
	for(int i=0;i<root->children.size();i++)
	{
		int sans = height(root->children[i]);
		if(sans>maxh)maxh = sans;
		
	}
	
	return maxh+1;
}

void printAtdepthRecursive(treeNode<int>* root, int depth)
{
	if(depth==0)
	{
		cout<<root->data<<endl;
		return;
	}
	
	for(int i=0;i<root->children.size();i++)
	{
		printAtdepthRecursive(root->children[i],depth-1);
	}
}

void printAtDepthIterative(treeNode<int>* root, int k)
{
	queue<treeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	queue<treeNode<int>*> pendingLevels;
	while(k!=0)
	{
		while(!pendingNodes.empty())
		{
			pendingLevels.push(pendingNodes.front());
			pendingNodes.pop();
		}
		
		while(!pendingLevels.empty())
		{
			treeNode<int> * front = pendingLevels.front();
			pendingLevels.pop();
			for(int i=0;i<front->children.size();i++)
			{
				pendingNodes.push(front->children[i]);
			}
			
		}
		k--;
				
	}
	
	while(!pendingNodes.empty())
		{
			cout<<pendingNodes.front()->data<<" ";
			pendingNodes.pop();
		}
		cout<<endl;

}

class maxSumClass{

	public:
	treeNode<int> * max;
	int maxSum;
};

maxSumClass maxChildSumAux(treeNode<int>* root)
{
	int currentSum=0;
	for(int i=0;i<root->children.size();i++)
	{
		currentSum+=root->children[i].data;
	}
	currentSum+=root->data;
	
	maxSumClass ans;
	ans.max = root;
	ans.maxSum = currentSum;
	for(int i=0;i<root->children.size();i++)
	{
		maxSumClass sans = maxChildSum(root->children[i]);
		if(sans.maxSum>ans.maxSum)
		{
			ans.max = sans.max;
			ans.maxSum = sans.maxSum;
		}
	}
	
	return ans;
}

treeNode<int>* maxchildsum(treeNode<int>* root)
{
	return maxChildSumAux(root).max;
}
int main()
{
	treeNode<int>* root = takeInputLevelWise();
	/*cout<<max(root)<<endl;
	cout<<height(root)<<endl;*/
	//printTreeInOrder(root);
	printAtDepthIterative(root,3);
}
