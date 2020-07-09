#include <iostream>
using namespace std;

class treeNode {
private:
int _value;
int _count;
treeNode * leftChild;
treeNode * rightChild;
public:
treeNode();
treeNode( int );
treeNode * * Right(){ return & rightChild; }
treeNode * * Left() { return & leftChild; }
void setLeft(treeNode *);
void setRight(treeNode *);
int Value() {return _value; }
int Count() {return _count; }
void Increment() { _count++; }
};

void treeNode::setLeft(treeNode * tPrt) {
	leftChild = tPrt;
}

void treeNode::setRight(treeNode * tPrt) {
	rightChild = tPrt;
}

treeNode::treeNode( ){
	_value = 0;
	_count = 1;
	leftChild = 0;
	rightChild = 0;
}

treeNode::treeNode( int value ){
	_value = value;
	_count = 1;
	leftChild = 0;
	rightChild = 0;
}

// End of treeNode class

void treeInsert( int, treeNode * *);

void printTree(treeNode *);

int minTree(treeNode *);

int maxTree(treeNode *);

int main(){
	treeNode * treeRoot = 0;
	int inPutValue = 0;
	
	cout << " -> " << flush;
	cin >> inPutValue;
	
	while ( inPutValue ) {
		treeInsert( inPutValue, & treeRoot );
		cout << " -> " << flush;
		cin >> inPutValue;
	}
	
	printTree(treeRoot);

	cout << "\n\nminimun value is: " << flush;
	cout << minTree( treeRoot ) << endl;

	cout << "\n\nmaxmum value is: " << flush;
	cout << maxTree( treeRoot ) << endl;

}

void treeInsert( int ivalue, treeNode * * tNode ){
	/*
	Supply missing code.
	*/
	if (*tNode == 0) {
		*tNode = new treeNode(ivalue);
	}
	else if ((*tNode)->Value() > ivalue) {
		treeInsert( ivalue, (*tNode)->Left() );
	}
	else if ((*tNode)->Value() < ivalue) {
		treeInsert( ivalue, (*tNode)->Right() );
	}
	else { // if ((*tNode)->Value() == ivalue) 
		(*tNode)->Increment();
	}
	
}

/*
//You may use a repeatPrint function as a
//helper funcion for printTree.
void repeatPrint(int value, int times) {
}
*/
void repeatPrint(int value, int times) {
	for (int i = 0; i < times; i++) {
		cout << value << ' '; // or '\n'
	}
}

void printTree(treeNode * tRoot){
/*
Supply missing code.
*/
	if (tRoot) {
		// print left child subtree
		printTree( *(tRoot->Left()) );
		// print current node 
		for (int i = 0; i < tRoot->Count(); i++) {
			cout << tRoot->Value() << ' '; // or '\n'
		}
		// print right subtree
		printTree( *(tRoot->Right()) );
	}
}

int minTree(treeNode * tRoot ) {
	/*
	Supply missing code.
	*/
	if (*(tRoot->Left()) == 0) {
		return tRoot->Value();
	}
	else {
		return minTree ( *(tRoot->Left()) );
	}
}

int maxTree(treeNode * tRoot ) {
/*
Supply missing code.
*/
	if (*(tRoot->Right()) == 0) {
		return tRoot->Value();
	}
	else {
		return maxTree ( *(tRoot->Right()) );
	}
}

