#include "bst.h"

using namespace std;



table::table()
{
    root = NULL;

}

table::~table()
{

    destroy(root);

}

int table::destroy(node * & root)
{
	if (!root) return 0;
	
	else
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
		root = NULL;
		return 1;
	}
}





int table::insert(node * & root_2, char key [],  nominee & to_add, int num)
{

	if (!root_2)
	{
		root_2 = new node;
		root_2 -> data.name = new char[strlen(key) +1];
		strcpy(root_2 -> data.name,key);
        root_2 -> data.vote = num;
		root_2 -> left = root_2 -> right = NULL;
        
		
	}
	
	else if (root_2->data.name >= key)//
		insert(root_2->left, key, to_add, num);
	else
		insert(root_2->right, key, to_add, num);
	return 1;
	

}


int table::add(nominee & to_add, char key [], int num)
{


    insert(root,key, to_add, num);



}






int table::displayall(node * root_2)
{
	if (!root_2)
		return 0;

	cout << root_2 -> data.name << " has " << root_2 -> data.vote << " votes " << endl;

	displayall(root_2->left);
	
	displayall(root_2->right);
	return 1;

}



int table::displayall()
{


    displayall(root);


}



//This function takes an input from the user through the application and searches for match from the list
int table::retrieve(nominee & found, char * match)
{
    retrieve(root, found, match);
    
}



int table::retrieve(node * & root_2, nominee & found, char * match)
{
    if(!root_2)
        return 0;
    
    else if (strcmp(root_2->data.name, match)==0)
    {
        cout << " Match found : " << root_2->data.name <<endl;
        cout << " Nominee has " << root_2->data.vote << " votes " <<endl;
        
        return 1;
    }
    else if (strcmp(root_2->data.name , match) < 0)
       {
           
           retrieve(root_2 -> left, found, match);


          // cout << " Match found : " << root_2->data.name <<endl;
          // cout << " Nominee has " << root_2->data.vote << " votes " <<endl;
          // return 1;
    }
	else
    {

        retrieve(root_2 -> right, found, match);

        
        //cout << " Match found : " << root_2->data.name <<endl;
        //cout << " Nominee has " << root_2->data.vote << " votes " <<endl;
        //return 1;
    }
    
    

    

    
    
    return 1;
}



int table::vote(nominee & to_add, int num)
{

    vote(root, to_add, num);
    
}



int table::vote(node * & root_2, nominee & to_add, int num)
{

    if(!root_2)
        return 0;
    root_2 -> data.vote = num;


}








//Wrapper function for remove function
int table::remove(char * match)
{
	remove(root, match);
}





// This function removes a song with the right match as supplied
int table::remove(node * & root_2, char * match)
{


	if(!root_2)// nothing to remove case 1: empty tree or case 2: match is not found
		return 0;
	remove(root_2->left,match);
	remove(root_2->right,match);


		if(strcmp(root_2->data.name,match) == 0)// match is found*/
		{
			

            node * temp;
			if(!root_2->left && !root_2->right)// case 3a: root is a leaf
			{
				delete root_2;
				root_2 = NULL;
			}
		
		else if(!root_2->left && root_2->right)// case 3b: no left child and a right child
			{
	cout<<" Gets here :"<<endl;
				temp = root_2->right;// temporary pointer so we don't lose the rest of tree
				delete root_2;
				root_2 = temp;// connection is made after deletion
			}
		
		else if(root_2->left && !root_2->right)// case 3c: no right child and aleft child
			{
	cout<<" Gets here :"<<endl;
				temp = root_2->left;
				delete root_2;
				root_2 = temp;

			}

			else // case 3d:  right child and left child
			{

				if(!root_2->right->left)//case 3di: right child has only right child
	
			{
	cout<<" Gets here :"<<endl;
					temp = root_2->right->right;// temporary pointer to hold the rest of the tree
					root_2->data.name = root_2 -> right -> data.name; // copy contents of 
					delete root_2->right;
					root_2->right = temp;// connection made after deletion


				}
				else //case 3dii: right cild has left child
				{
	cout<<" Gets here :"<<endl;
					node * current = root->right;
					node * previous;
					while (current->left)// traverse until last
					{
						previous = current;
						current = current->left;

					}
					previous = current->right;
					root_2->data.name = current->data.name;
					delete current;
					current = NULL;

				}
			}
		}



}
