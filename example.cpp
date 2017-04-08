#include "CGeoExtension.cpp"
#include <bits/stdc++.h>
using namespace std;
struct node
{
  double data;
  struct node *left;
  struct node *right;
};
bool sortfunc(Point i,Point j) { return (i.x<j.x); }
vector<Point> result;
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                         malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct node* cstBST(vector<Point> points, int start, int end)
{
    if (start > end)
      return NULL;
    int mid = (start + end)/2;
    int pt=points[mid].x;
    struct node *root = newNode(pt);

    root->left =  cstBST(points, start, mid-1);
    root->right = cstBST(points, mid+1, end);

    return root;
}
void insert_subtree(struct node *root){
    if(root==NULL)return;
    Point po;
    po.x=root->data;
    po.y=po.z=0;
    result.push_back(po);
    insert_subtree(root->left);
    insert_subtree(root->right);
}

class OneDSearch
{
    struct node *root;
	OneDSearch(vector<Point> points)
	{
	    int n=points.size();
        sort(points.begin(),points.end(),sortfunc);
        root=cstBST(points,0,n-1);
	}

	vector<Point> searchQuery(Point A, Point B)
	{
	    struct node *ne;       /*ne is split node*/
	    ne=root;
	    while((ne->left)->data>=B.x || (ne->right)->data<=A.x){
                Point po;
                po.x=ne->data;
                po.y=po.z=0;
                if(ne->data>=A.x && ne->data<=B.x){
                        result.push_back(po);
                        }
                 if((ne->left)->data>=B.x)ne=ne->left;
                 else ne=ne->right;
	    }
                Point po;
                po.x=ne->data;
                po.y=po.z=0;
                if(ne->data>=A.x && ne->data<=B.x){
                        result.push_back(po);
                        }
	    struct node *le,*ri;
	    le=ne->left;
	    ri=ne->right;


	    //left node
	    while(le->left!=NULL && le->right!=NULL){
                Point po;
                po.x=le->data;
                po.y=po.z=0;
            if(le->data>=A.x && le->data<=B.x){
                        result.push_back(po);
                        }
            if(A.x<=le->data){
               insert_subtree(le->right);
                le=le->left;
            }
            else le=le->right;
	    }
                po.x=le->data;
                po.y=po.z=0;
            if(le->data>=A.x && le->data<=B.x){
                        result.push_back(po);
                        }


                  //Right node
	     while(ri->left!=NULL && ri->right!=NULL){
                Point po;
                po.x=ri->data;
                po.y=po.z=0;
            if(ri->data>=A.x && ri->data<=B.x){
                        result.push_back(po);
                        }
            if(B.x>=ri->data){
              insert_subtree(ri->left);
                ri=ri->right;
                        }
            else ri=ri->left;
	    }
         po.x=ri->data;
         po.y=po.z=0;
         if(ri->data>=A.x && ri->data<=B.x){
                        result.push_back(po);
                        }

		return result;
	}
};

int main(void)
{
	return 0;
}
