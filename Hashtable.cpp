#include<iostream> // IO for Client Interface
#include<algorithm> // use for searching Linked List for particular key using find()
#include<string> //includes certain operators for String
#include<vector> //includes 

/*
Name: Patrick Poplawska		
UFID: 0716 9115
Section:
Assignment: Exercise 3: hashtable
Date: 03-25-2015
*/

class hashtable{

public:
	/* Our hashtable will use Chaining, employing vectors, provided by the STL, Newman Approved such usage. */
	int totalCap;
	std::vector<std::string>* backingArray;
	
	int hashFunc(std::string const& s){
		/* utilizing the well known DJB2 Hashing Algorithm */
		unsigned long hash = 5381;
		int i;
		for (i = 0; i < s.size(); i++)
		{
			hash = (hash << 5) + hash + s[i];
		}

		int returnValue = hash % totalCap;
		return (int)returnValue;  // modulo will restrict to the max size of our array

	}
	void insert(std::string s){
		int index = hashFunc(s);
		backingArray[index].push_back(s); // This will allow us to chain, as our method of collision mgmt
	}
	bool search(std::string s){
		int index = hashFunc(s);
		
		std::vector<std::string>::iterator findElement = std::find(backingArray[index].begin(), backingArray[index].end(), s);
		if (findElement == backingArray[index].end()){
			return false; // find() did not find a matching term in the list
		}
		else{

			return true; // find() was able to find the string
		}
	
	}
	hashtable(){
		/*

		Our backing array for the hashtable, holds strings values, and has 1000 slots. No restrictions on size in assignment schema so
		large size to prevent collisions.

		*/
		totalCap = 1009;
		backingArray = new std::vector<std::string>[1009];
	}
};

int main(){
	/* Client Application Interface*/
	hashtable ht; 
	int n; // number of entries into the hash table.
	int sw; // OP Code
	int counter = 0;

	/* The Exercise file is a little unclear abouyt what is ment with the number of entry in the hashtable. I am going to assume this means the total
	permissable amount of entries into the hashtable and therefore the while loop will break out of the program once this amount has been met.*/
	
	std::string temp; // used to hold temp strings
	std::cin >> n;

	while(counter <= n){
		temp = ""; //ensures that temp is clear
		std::cin >> sw >> temp; // OP code
		if (sw == 0){
			counter = n;
			break;
		}
		else if (sw == 1){
			ht.insert(temp);
			counter++;
		}
		else{

			if (ht.search(temp)){
				std::cout << "Yes" << std::endl;
			}
			else{
				std::cout << "No" << std::endl;
			}
		}
	}

}





