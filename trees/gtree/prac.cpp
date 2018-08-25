#include<iostream>
#include<climits>
#include<vector>
#include<queue>

using namespace std;

template<typename T>

class treeNode{

	public:
	
	T data;
	vector<treeNode*> children;
	
	treeNode(T data)
	{
		this->data = data;
	}	
	
	~treeNode()
	{
		for(int i=0;i<children.size();i++)
		{
			delete children[i];
		}
	}
	
};

void printTreeAtDepthK(treeNode<int>* root,int k)
{
	queue<treeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	int loop=k;
	while(loop!=0)
	{
		queue<treeNode<int>*> pendingLevels;
		
		while(!pendingNodes.empty())
		{
			treeNode<int>* front = pendingNodes.front();
			pendingNodes.pop();
			pendingLevels.push(front);
		}
		
		while(!pendingLevels.empty())
		{
			treeNode<int>* front = pendingLevels.front();
			pendingLevels.pop();
			for(int i=0;i<front->children.size();i++)
			{
				pendingNodes.push(front->children[i]);
			}
		}
		loop--;
	}
	
	while(!pendingNodes.empty())
	{
		treeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<" ";
	}
	cout<<endl;
}

int countLeafNodes(treeNode<int>* root)
{
	if(root->children.size()==0)
	return 1;
	
	int sum = 0;
	for(int i=0;i<root->children.size();i++)
	{
		sum+=countLeafNodes(root->children[i]);
	}
	
	return sum;
}

treeNode<int>* takeInputR()
{
	int data;
	cout<<"data:";
	cin>>data;
	treeNode<int>* root = new treeNode<int>(data);
	
	int children;
	cout<<"numChildren:";
	cin>>children;
	
	for(int i=0;i<children;i++)
	{
		root->children.push_back(takeInputR());
	}
	
	return root;
}

treeNode<int>* takeInputInOrder()
{
	queue<treeNode<int>*> pendingNodes;
	int data;
	cin>>data;
	treeNode<int>* root = new treeNode<int>(data);
	pendingNodes.push(root);
	
	while(!pendingNodes.empty())
	{
		treeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cout<<"Please enter the num of Children for "<<front->data<<":";
		cin>>numChild;
		for(int i=0;i<numChild;i++)
		{
			cout<<"Data:";
			cin>>data;
			treeNode<int> * node = new treeNode<int>(data);
			front->children.push_back(node);
			pendingNodes.push(node);
		}
	}	
	return root;
}

void printTreeR(treeNode<int>* root)
{
	cout<<root->data<<":";
	
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<" ";
	}
	cout<<endl;
	
	for(int i=0;i<root->children.size();i++)
	{
		printTreeR(root->children[i]);
	}
}


int heightTree(treeNode<int>* root)
{
	int height = 0;
	int compare = 0;
	for(int i=0;i<root->children.size();i++)
	{
		compare = heightTree(root->children[i]);
		if(compare>height)height = compare;
	}
	
	return height+1;
}

void printInOrder(treeNode<int>* root)
{
	queue<treeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(!pendingNodes.empty())
	{
		treeNode<int>* front = pendingNodes.front();
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

int main()
{

	treeNode<int>* root = takeInputInOrder();
	printInOrder(root);
	//cout<<heightTree(root)<<endl;
	//printTreeAtDepthK(root,2);
	cout<<countLeafNodes(root)<<endl;
	delete root;
	
}
