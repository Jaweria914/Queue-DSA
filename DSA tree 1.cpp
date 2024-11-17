 #include<iostream>
using namespace std;
class tree
{
	public:
		int data;
		tree *left;
		tree *right;
	tree(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}	
	void inorder(tree *temp)
	{
		if(temp!=NULL)
		{
			inorder(temp->left);
			cout<<temp->data<<" ";
			inorder(temp->right);
		}
	}
	void postorder(tree *temp)
	{	
		if(temp!=NULL)
		{
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<" ";
		}
	}
	void preorder(tree *temp)
	{
	
		if(temp!=NULL)
		{
			cout<<temp->data<<" ";
			preorder(temp->left);
			preorder(temp->right);
		}
	}
};
int main()
{
	tree *temp= new tree(12);
	temp->left=new tree(7);
	temp->left->left=new tree(9);
	temp->left->right=new tree(10);
	temp->right=new tree(22);
	temp->right->left=new tree(24);
	temp->right->right=new tree(30);
	temp->right->right=new tree(18);
	temp->right->right->left=new tree(3);
	temp->right->right->right=new tree(14);
	temp->left->left->left=new tree(20);
	cout<<"Pre Order"<<endl;
	temp->preorder(temp);
	cout<<endl;
	cout<<"In Order"<<endl;
	temp->inorder(temp);
	cout<<endl;
	cout<<"Post Order"<<endl;
	temp->postorder(temp);
	cout<<endl;
	return 0;
}

