#include<bits/stdc++.h>

using namespace std;

template<typename T>

class binaryTreeNode{
	
	public:
	T data;
	binaryTreeNode<T>* left;
	binaryTreeNode<T>* right;
	
	binaryTreeNode(T data)
	{
		this->data = data;
		right = NULL;
		left = NULL;
	}
	
	~binaryTreeNode()
	{
		delete left;
		delete right;
	}
};

int height(binaryTreeNode<int>* root)
{	
	if(root==NULL)return 0;
	
	int lh = height(root->left);
	int rh = height(root->right);
	
	return max(lh,rh)+1;
}

class dH{
	public:
	int height;
	int diameter;
};

dH diameter(binaryTreeNode<int>* root)
{
	if(root==NULL)
	{
		dH ans;
		ans.height=0;
		ans.diameter=0;
		return ans;
	}
	
	dH ans1 = diameter(root->left);
	dH ans2 = diameter(root->right);
	
	int option1 = ans1.height+ans2.height+1;
	int option2 = ans1.diameter;
	int option3 = ans2.diameter;
	
	dH ans;
	ans.height = max(ans1.height,ans2.height)+1;
	ans.diameter = max(option1,max(option2,option3));
	
	return ans;
}

int diameter1(binaryTreeNode<int>* root)
{
	if(root==NULL)
	return 0;
	
	int lh = height(root->left);
	int rh = height(root->right);
	int option1 = lh+rh+1;
	int ld = diameter1(root->left);
	int rd = diameter1(root->right);
	
	return max(option1,max(ld,rd));
}

void printLevel(binaryTreeNode<int>* root)
{
	queue<binaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(!pendingNodes.empty())
	{
		binaryTreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<":";
		if(front->left!=NULL)
		{
			pendingNodes.push(front->left);
			cout<<"L:"<<front->left->data;
		}
		
		if(front->right!=NULL)
		{
			pendingNodes.push(front->right);
			cout<<"R:"<<front->right->data;
		}
		cout<<endl;
	}
}

binaryTreeNode<int>* mirror(binaryTreeNode<int>* root)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	binaryTreeNode<int>* mroot = new binaryTreeNode<int>(root->data);
	mroot->left = mirror(root->right);
	mroot->right = mirror(root->left);
	return mroot;
}

binaryTreeNode<int>* takeInput()
{
	queue<binaryTreeNode<int>*> pendingNodes;
	int data;
	cout<<"Please enter root data:";
	cin>>data;
	if(data==-1)return NULL;
	binaryTreeNode<int>* root = new binaryTreeNode<int>(data);
	pendingNodes.push(root);
	while(!pendingNodes.empty())
	{
		binaryTreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Please enter data for left child:";
		cin>>data;
		if(data!=-1)
		{
			binaryTreeNode<int>* node = new binaryTreeNode<int>(data);
			front->left = node;
			pendingNodes.push(node);
		}
		
		cout<<"Please enter data for right child:";
		cin>>data;
		if(data!=-1)
		{
			binaryTreeNode<int>* node = new binaryTreeNode<int>(data);
			front->right = node;
			pendingNodes.push(node);
		}
	}
	return root;	
}

int main()
{
	binaryTreeNode<int>* root = takeInput();
	/*binaryTreeNode<int>* mroot = mirror(root);
	printLevel(mroot);*/
	dH ans = diameter(root);
	cout<<ans.diameter<<endl;
}
