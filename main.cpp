#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct node
{
	char word[128];
	char meaning[256];
	node *left;
	node *right;
};
node *root=NULL;


node* create(char *word ,char *meaning){
	node *newNode = new node ;
	strcpy (newNode->word , word);
	strcpy (newNode->meaning , meaning);
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}


void insert(char *word ,char *meaning){
	node *newNode = create(word , meaning);
	if (root==NULL)
	{
		root = newNode;
		return;
	}
	node *parent = NULL , *current = NULL ;
	int cmp = 0;
	current = root;
	while (current != NULL)
	{
		parent = current;
		cmp =strcmp(word,current->word);
		if (cmp > 0)
		{
			current = current->right;
		}
		else if (cmp < 0)
		{
			current = current ->left;
		}
		else
		{
			cout<<"Duplicate entry \n";
			return;
		}

	}

	if (cmp > 0)
	{
		parent->right = newNode;
	}
	else
	{
		parent->left = newNode;
	}
}

node* findMin(node*root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node* remove( node* root,char* word)
{
	int cmp = strcmp(word,root->word);
		if (root == NULL){
			return root;

		}
		else if (cmp < 0){
			root->left = remove(root->left, word);
		}
		else if (cmp > 0){
			root->right = remove(root->right, word);
		}

	// Node deletion
	else
	{
		//case 1: Leaf Node
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}

		//case 2: one child
		else if(root->left==NULL)
		{
			node* temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			node* temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		//case 3: 2 child
		else
		{
			node*temp=findMin(root->right);
			char val[128];
			strcpy(val , temp->word);
			strcpy( root->word ,val);
			//root->word=temp->word;
			root->right=remove(root->right,temp->word);
		}
	}
	return root;
}

void findElement(char *word) {
        node *temp = NULL;
        int flag = 0, cmp = 0;
        if (root == NULL) {
                cout << "Dictionary is empty!!\n";
                return;
        }
        temp = root;

		while (temp!=NULL) {
                if ((cmp = strcmp( word,temp->word)) == 0) {
					cout << setw (10);
					cout<<"Word : " << word<<"       ";
					string len1 = word ;
					int len2 = len1.length();
					cout << setw (15-len2)<<"|"<<setw (15);
					cout<<"meaning : " << temp->meaning<<"\n";
                    flag = 1;
                        break;
                }
				if (cmp > 0)
				{
					temp = temp->right;
				}
				else
				{
					temp = temp->left;
				}
        }
		if (flag!=1)
                cout << "Search Element not found in Dictionary\n";
        return;
  }

void inorderTraversal(node *root) {
	if (root!=NULL){
                inorderTraversal(root->left);
				cout << setw (10);
                cout<<"Word : " << root->word<<"       ";
				string len1 = root->word ;
				int len2 = len1.length();
				cout << setw (15-len2)<<"|"<<setw (15);
				cout<<"meaning : " << root->meaning<<"\n";
                inorderTraversal(root->right);
	}
  }

  int main(){

	// Letter N
	insert("Nail","a small, thin piece of metal with one pointed end and one flat end ");
	insert("Net-worker","someone who tries to meet people who might be useful to know");
	insert("Nearly","almost, or not completely");
	// Letter G
	insert("Good" ,"items for sale, or possessions that can be moved");
	insert("Garage","a building where a car is kept, built next to or as part of a house ");
	insert("Garb","clothes of a particular type");
	// Letter U
	insert("unclog","to clear something by removing something that is blocking it");
	insert("uncouth","behaving in a rude, unpleasant way");
	insert("uncritically","in an uncritical way 😊 accepting something too easily)");
	insert("undercut","to damage something or to make it fail");
	insert("unemotional","not having or expressing strong feelings");
	// letter D
	insert("Data" ,"information collected to be examined help decision-making");
	insert("Dash","to go somewhere quickly");
	insert("Deaf" ,"unable to hear, either completely or partly");
	insert("Dealer" ,"a person who trades in something");
    // Letter J
    insert("Java","a computer programming language that is often used on the Internet");
    insert("Jotter","the act of traveling from one place to another, especially in a vehicle");
    insert("Jolly","happy and smiling");
	// Letter Q
	insert("quack","a person who dishonestly pretends to have medical skills or knowledge");
	insert("quaff","to drink something quickly or in large amounts");
	insert("quantity","the amount or number of something, especially that can be measured");
	insert("query","a question, often expressing doubt about something ");
	insert("quiet","making very little noise");
	insert("quiz","a game or competition in which you answer questions");\
    // Letter Y
	insert("Your","belonging or relating to the person or group of people being spoken ");
	insert("Youth","the period of your life when you are young, or the state of being young");
    // letter B
	insert("Burst", "to break open or apart suddenly, or to make something do this");
	insert("Biology" , "the scientific study of the natural processes of living things");
	insert("Butcher" , "a person who sells meat in a shop");
	insert("Bug"," a very small insect");
	insert("Bionic" ,"artificial materials and methods to produce activity ");
	// letter E
	insert("Episode","a single event or group of related events");
	insert("Element", "a part of something");
	insert("Environment" ,"the air, water, and land in or on which people, and plants live");
	insert("Elegant" , "graceful and attractive in appearance or behaviour");
	 // Letter I
    insert("Impress","to cause someone to admire or respect you");
    insert("Illustrative","helping to explain or prove something:");
    insert("Inquire","to ask for information");
    insert("Improbability","the quality of not being likely to happen or be true");
    insert("Imagine","to form or have a mental picture or idea of something");
    // Letter  L
    insert("Latter","near or towards the end of something");
    insert("Launch","an event to celebrate or introduce something new");
    insert("Large","big in size or amount");
    insert("Laser","a powerful, narrow beam of light that can be used as a tool to cut metal");
	// Letter P
	insert("Park","a large area of land with grass and trees");
	insert("Poor","having little money and/or few possessions");
	insert("Pool","a small area of usually still water");
	// Letter S
	insert("snorer","a person who snores 😊 breathes in a noisy way while sleeping)");
	insert("salesclerk","someone who serves customers in a shop");
	insert("software","the instructions that control what a computer does; computer programs");
	insert("sap","to make someone weaker or take away strength ");
	insert("sonic","of sound or the speed at which sound travels in air");
	// Letter W
	insert("workplace","a building or room where people perform their jobs");
	insert("wader","a bird with long legs and a long neck");
	insert("WAP","abbreviation for Wireless Application Protocol");
	insert("wipe","a piece of soft, wet cloth or paper that you use for wiping");
	// Letter Z
	insert("Z-score","a figure that shows how likely a business is to fail");
	insert("Zimbabwe","a country in Southern Africa");
	insert("zest","enthusiasm, eagerness, energy, and interest");
	insert("zoom","to move very quickly");
	insert("zoo","an area in which animals, especially wild animals");
	// Letter A
	insert("Abutment","the act of helping or encouraging someone to do something wrong");
	insert("Able","to have the necessary physical strength, mental power, skill");
	insert("Above","in or to a higher position than something else");
	insert("Administration","the arrangements and tasks needed to control the operation of a plan");
	insert("Adjudicator","a person or group that makes an official decision about something,");
	// C Letter
	insert("Capacity" , "the total amount that can be contained or produced");
	insert("Canteen" , "a place in a factory, office, etc. where food and meals are sold");
	insert("Cape", "a very large piece of land sticking out into the sea");
	// Letter F
	insert("Factor" ,"a fact or situation that influences the result of something");
	insert("Facile" ,"A facile remark or theory is too simple and has not been  ");
	insert("Factorial" ,"the product of  a whole number and all the whole numbers below it");
	//Letter H
	insert("hardware","the physical and electronic parts of a computer ");
	insert("half-light","a low light in which you cannot see things well");
	insert("hard-working","always doing a lot of work");
    // Letter K
    insert("Kitty","amount of money that is made upOf small amounts given by different people");
    insert("Knockout","in boxing, the act of hitting the other fighter");
    insert("Keyhole","a hole in a lock that you put a key into");
    insert("Keyboard","the set of keys on a computer or typewriter ");
    // Letter M
    insert("Maker","the people or company that make something");
    insert("Malcontent","a person who is not satisfied with the way things are");
    insert("Milk","the white liquid produced by cows, goats, and sheep ");
    insert("Mile","a unit of distance equal to 1,760 yards or 1.6 kilometers");
	// Letter O
	insert("Off-site","an occasion when employees go somewhere away from their office together");
	insert("Ordinate","the second number in a pair");
	insert("Often","many times");
	// Letter S
	insert("reversion","a change back to a previous and often worse condition");
	insert("reprocessed","past simple and past participle of reprocess");
	insert("raunchiness","the quality of being connected with sex in a clear and obvious way");
	insert("retrievable","that can be found and made available to be used");
	insert("reason","the cause of an event or situation ");
	insert("recipe","a set of instructions telling you how to prepare and cook food");
	// Letter T
	insert("tardy","slow or late in happening or arriving");
	insert("tailback","a line of vehicles that have stopped or are moving only very slowly");
	insert("tangle","an untidy mass of things that are not in a state of order");
	insert("title","the name of a film, book, painting, piece of music, etc");
	insert("took","past simple of take");
	insert("topic","a subject that is discussed, written about, or studied");
	insert("trace","to find someone or something that was lost");
	// Letter V
	insert("velum","the soft area at the top in the mouth");
	insert("virtual","almost a particular thing or quality");
	insert("visa","an official mark, usually made in a passport, that allows you to enter");
	// Letter X
	insert("Xerox","a brand name for a copy of a document ");
	insert("XML","abbreviation for extensible mark up language");
	/////////////////
	int  n;
	cout<<"Enter your choice (-1 to exit) : "<<"\n"<<"1 - To edit "<<"\n"<<"2 - To display "<<"\n"<<"3 - To search"<<"\n";
	cin>>n;
	while (n!=-1)
	{
		switch (n )
		{
		case 1 :
			int n2;
		    cout<<"Enter your choice (-1 to exit) : "<<"\n"<<"1 - To insert "<<"\n"<<"2 - To delete "<<"\n";
			cin>>n2;
			while (n2!=-1)
	        {

				switch (n2)
				{
				case 1 :
					char word1[128];
					char meaning1[256];
					cout<<"Enter the word \n";
					cin>>word1;
					cout<<"Enter the meaning \n";
					cin>>meaning1;
					insert(word1,meaning1);
			        cout<<"Enter your choice (-1 to exit) : "<<"\n"<<"1 - To insert "<<"\n"<<"2 - To delete "<<"\n";
					cin>>n2;
					break;
				case 2:
					char word2[128];
					cout<<"Enter the word \n";
					cin>>word2;
					remove(root, word2);
			        cout<<"Enter your choice (-1 to exit) : "<<"\n"<<"1 - To insert "<<"\n"<<"2 - To delete "<<"\n";
					cin>>n2;
					break;

				}

			}
			cout<<"Enter your choice (-1 to exit) : "<<"\n"<<"1 - To edit "<<"\n"<<"2 - To display "<<"\n"<<"3 - To search"<<"\n";
			cin>>n;

			break;

		case 2 :
			cout<<"\n";
			cout<<"                                            ENGLISH DECTIONARY  "<<"\n"<<"\n";
			inorderTraversal(root);
			cout<<"Enter your choice (-1 to exit) : "<<"\n"<<"1 - To edit "<<"\n"<<"2 - To display "<<"\n"<<"3 - To search"<<"\n";
			cin>>n;
			break;
		case 3 :
			char word1[128];
			cout<<"Enter the word \n";
			cin>>word1;
			findElement(word1);
	        cout<<"Enter your choice (-1 to exit) : "<<"\n"<<"1 - To edit "<<"\n"<<"2 - To display "<<"\n"<<"3 - To search"<<"\n";
			cin>>n;

		}
	}

	return 0;
}
